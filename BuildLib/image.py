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
#define __{file_name}_SHEET_H__

#include "gba_types.h"
#include "palette.h"
#include "sprite.h"

{extra_info}

const u16 {file_name}_palette[] __attribute__((aligned(4))) = {{
    {palette_str}
}};

const u16 {file_name}_sheet[] __attribute__((aligned(4))) = {{
    {sheet_str}
}};

inline static void assign_{file_name}_sheet_attrs(volatile OBJATTR* objattr, u16 sprite_pos,
    u8 palette_pos)
{{
    objattr->attr0 = objattr->attr0 & ~OBJ_SHAPE_MASK | ATTR0_{sprite_shape};
    objattr->attr1 = objattr->attr1 & ~OBJ_SIZE_MASK | ATTR1_SIZE_{sprite_size};
    objattr->attr2 = objattr->attr2 & ~(OBJ_CHAR_MASK | OBJ_PALETTE_MASK) |
        OBJ_CHAR(sprite_pos) | ATTR2_PALETTE(palette_pos);
}}

inline static void load_{file_name}_sheet(volatile OBJATTR* objattr, u16* sprite_pos,
    u8* palette_pos)
{{
    load_palette({file_name}_palette, {num_colors}, palette_pos);
    load_sprite_4bpp({file_name}_sheet, {num_tiles}, sprite_pos);
    assign_{file_name}_sheet_attrs(objattr, *sprite_pos, *palette_pos);
}}

#endif"""
define_model = "#define {macro} {value}"

extra_info_to_group_name = {
    'sprite_names': 'SPRITE',
    'animation_sizes': 'ANIMATION_SIZE'
}

dimensions_to_attrs = {
    8: {
        8: ('SQUARE', 8),
        16: ('TALL', 8),
        32: ('TALL', 16)
    },
    16: {
        8: ('WIDE', 8),
        16: ('SQUARE', 16),
        32: ('TALL', 32)
    },
    32: {
        8: ('WIDE', 16),
        16: ('WIDE', 32),
        32: ('SQUARE', 32),
        64: ('TALL', 64)
    },
    64: {
        32: ('WIDE', 64),
        64: ('SQUARE', 64)
    }
}

def generate_header_from_sheet(sheet_path: str):
    print_log(f'Creating header from sheet {sheet_path}')
    sheet_path = pjoin(sprites_dir, sheet_path)
    sheet_name = basename(sheet_path)
    sheet_dir = dirname(sheet_path)
    sheet_info_path = pjoin(sheet_dir, sheet_name + '-info.json')
    if not isfile(sheet_info_path):
        print_fail('FAILED')
        print_log(f'Could not find sheet info at {sheet_info_path}')
        return

    sheet_info = json.load(open(sheet_info_path, 'r'))
    frame_w = sheet_info['width']
    frame_h = sheet_info['height']
    if frame_h % 8 != 0 or frame_w % 8 != 0:
        print_fail('FAILED')
        print_log('Frame size error: Frame sides must be multiple of 8, but '
                  'got a {frame_w}x{frame_h} frame.')
        return
    if frame_w > 64 or frame_h > 64 or frame_w < 8 or frame_h < 8:
        print_fail('FAILED')
        print_log('Frame size error: Frame sides must be in the range [8, 64], '
                  'but got a {frame_w}x{frame_h} frame.')
        return

    extra_info = get_extra_info(sheet_name, sheet_info)

    with Image.open(sheet_path + '.png') as sheet:
        palette = get_palette(sheet)
        encoded_sheet_data = get_encoded_image_data(sheet, frame_w, frame_h, palette)
    palette_data = get_palette_data(palette)
    
    header_dir = pjoin('include', sheet_dir)
    create_dir(header_dir)
    header_path = pjoin(header_dir, sheet_name + '.h')
    header_content = build_sheet_header(header_path, encoded_sheet_data, palette_data,
                                        frame_w, frame_h, extra_info)
    if header_content is None:
        return
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
            if is_transparent(a):
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
                    r, g, b, a = img.getpixel((tx + x, ty + y))
                    if is_transparent(a):
                        encoded_pixel = -1
                    else:
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
                       frame_w: int, frame_h: int, extra_info: str = '') -> str:
    file_name = splitext(basename(file_path))[0]
    if len(sheet_data) % 2 == 1:
        sheet_data = sheet_data + [0]

    sheet_str = []
    for i in range(0, len(sheet_data), 4):
        value = (sheet_data[i + 3] << 12) + (sheet_data[i + 2] << 8) + \
            (sheet_data[i + 1] << 4) + sheet_data[i]
        formatted_value = '0x{:04X}'.format(value)
        sheet_str.append(formatted_value)
    sheet_str = join_in_lines(sheet_str, 8)

    palette_str = []
    for color in palette_data:
        formatted_color = '0x{:04X}'.format(color)
        palette_str.append(formatted_color)
    palette_str = join_in_lines(palette_str, 4)

    attrs = dimensions_to_attrs[frame_w].get(frame_h)
    if attrs is None:
        print_fail('FAILED')
        print_log(f'Cannot not encode {frame_w}x{frame_h} frames.')
        return None

    sprite_shape, sprite_size = attrs
    file_content = sheet_header_model.format(
        file_name = file_name,
        sheet_str = sheet_str,
        palette_str = palette_str,
        num_tiles = int(len(sheet_data) / 64),
        num_colors = len(palette_data),
        sprite_shape = sprite_shape,
        sprite_size = sprite_size,
        extra_info = extra_info
    )
    return file_content

def join_in_lines(str_list: list, line_size: int) -> str:
    res_str = []
    line = []
    for el in str_list:
        line.append(el)
        if len(line) == line_size:
            res_str.append(', '.join(line))
            line = []
    if len(line) != 0:
        res_str.append(', '.join(line))
    return ',\n    '.join(res_str)

def get_extra_info(sheet_name: str, sheet_info: Dict) -> str:
    extra_info = []
    for info_key, group_identifier in extra_info_to_group_name.items():
        values_dict = sheet_info.get(info_key)
        if values_dict is not None:
            extra_info.append(build_define_lines(sheet_name, group_identifier,
                                                 values_dict))
    return '\n'.join(extra_info)

def build_define_lines(sheet_name: str, group_identifier: str, values: Dict) -> str:
    defines = []
    for name, value in values.items():
        define_macro = f'{sheet_name}_{name}_{group_identifier}'
        define = define_model.format(macro = define_macro, value = value)
        defines.append(define)
    return '\n'.join(defines)

def compress_hex_list(hex_list: list):
    pass

def color_to_16_bits(r, g, b):
    return ((b >> 3) << 10) + ((g >> 3) << 5) + (r >> 3)

def is_transparent(alpha_value):
    return alpha_value < 128