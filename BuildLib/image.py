import os
import json
from typing import Dict

from PIL import Image

from .debug import *
from .file_system import *

basename = os.path.basename
dirname = os.path.dirname
isfile = os.path.isfile
pjoin = os.path.join
splitext = os.path.splitext

palettes_dir = 'palettes'
sprites_dir = 'sprites'

sheet_header_model = """#ifndef __{file_name}_SHEET__
#define __{file_name}_SHEET__

#include "gba_types.h"
#include "palettes.h"
#include "sprites.h"

u16 {file_name}_palette[] = {{
    {palette_str}
}};

u16 {file_name}_sheet[] = {{
    {sheet_str}
}};

inline static void load_{file_name}_sheet(u16 start_tile, u8 palette_pos)
{{
    load_palette({file_name}_palette, {num_colors}, palette_pos);
    load_sprite_4bpp({file_name}_sheet, {num_tiles}, start_tile);
}}

#endif"""

def generate_header_from_sheet(sheet_path: str):
    print(f'Creating header from sheet {sheet_path}')
    sheet_path = pjoin(sprites_dir, sheet_path)
    sheet_name = basename(sheet_path)
    sheet_dir = dirname(sheet_path)
    sheet_info_path = pjoin(sheet_dir, sheet_name + '-info.json')
    if not isfile(sheet_info_path):
        print_fail(f'FAILED: Could not find sheet info at {sheet_info_path}')
        return

    sheet_info = json.load(open(sheet_info_path, 'r'))
    frame_w = sheet_info['width']
    frame_h = sheet_info['height']

    with Image.open(sheet_path + '.png') as sheet:
        palette = get_palette(sheet)
        encoded_sheet_data = get_encoded_image_data(sheet, frame_w, frame_h, palette)
    palette_data = get_palette_data(palette)
    
    header_dir = pjoin('include', sheet_dir)
    create_dir(header_dir)
    header_path = pjoin(header_dir, sheet_name + '.h')
    header_content = build_sheet_header(header_path, encoded_sheet_data, palette_data)
    with open(header_path, 'w+') as f:
        f.write(header_content)

    print_success('SUCCESS')

def get_palette(img: Image.Image) -> Dict:
    color_list = img.getpalette()
    palette = {}
    index = 0

    img_w, img_h = img.size
    for y in range(img_h):
        for x in range(img_w):
            r, g, b, a = img.getpixel((x, y))
            if a < 128:
                continue
            color_code = color_to_16_bits(r, g, b)
            if palette.get(color_code) is None:
                if index == 15:
                    print_warning(f'Image has palette of size {len(color_list)}, '
                        'reducing it to 15 colors.')
                    break
                palette[color_code] = index
                index += 1

    return palette

def get_encoded_image_data(img: Image.Image, frame_width: int, frame_height: int,
                           palette: Dict) -> list:
    data = []
    img_w, img_h = img.size
    for ty in range(0, img_h, 8):
        for tx in range(0, img_w, 8):
            for y in range(8):
                for x in range(8):
                    r, g, b, _ = img.getpixel((tx + x, ty + y))
                    color_code = color_to_16_bits(r, g, b)
                    encoded_pixel = palette.get(color_code)
                    if encoded_pixel is None:
                        encoded_pixel = 15
                    data.append(encoded_pixel + 1)
    return data

def get_palette_data(palette: Dict) -> list:
    palette_data = [0] * len(palette)
    for color_code, i in palette.items():
        palette_data[i] = color_code
    return palette_data

def build_sheet_header(file_path: str, sheet_data: list, palette_data: list,
                       extra_info: str = '') -> str:
    if len(sheet_data) % 2 == 1:
        sheet_data = sheet_data + [0]

    sheet_str = []
    line = []
    for i in range(0, len(sheet_data), 4):
        value = (sheet_data[i + 3] << 12) + (sheet_data[i + 2] << 8) + \
            (sheet_data[i + 1] << 4) + sheet_data[i]
        formatted_value = '0x{:04X}'.format(value)
        line.append(formatted_value)
        if len(line) == 8:
            sheet_str.append(', '.join(line))
            line = []
    if len(line) != 0:
        sheet_str.append(', '.join(line))
    sheet_str = ',\n    '.join(sheet_str)

    palette_str = []
    line = []
    for color in palette_data:
        formatted_color = '0x{:04X}'.format(color)
        line.append(formatted_color)
        if len(line) == 4:
            palette_str.append(', '.join(line))
            line = []
    if len(line) != 0:
        palette_str.append(', '.join(line))
    palette_str = ',\n    '.join(palette_str)

    file_name = splitext(basename(file_path))[0]
    file_content = sheet_header_model.format(
        file_name = file_name,
        sheet_str = sheet_str,
        palette_str = palette_str,
        num_tiles = int(len(sheet_data) / 64),
        num_colors = len(palette_data)
    )
    return file_content

def compress_image(img_raw_data: list):
    pass

def color_to_16_bits(r, g, b):
    return ((b >> 3) << 10) + ((g >> 3) << 5) + (r >> 3)