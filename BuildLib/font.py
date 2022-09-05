import json
import os
import string
from typing import Dict

from PIL import ImageDraw, ImageFont, Image

from BuildLib.debug import *

pjoin = os.path.join

visible_chars = ''.join(sorted(set(string.printable) - set(string.whitespace)))

fonts_path = 'fonts'

font_header_model = """#ifndef __{file_name}_FONT__
#define __{file_name}_FONT_H__

#include "gba_types.h"
#include "sprite.h"

const u16 {file_name}_font_sheet[] __attribute__((aligned(4))) = {{
    {sheet_str}
}};

inline static void load_{file_name}_font_sheet(u16* sprite_pos, SimpleColor color)
{{
    load_sprite_1bpp({file_name}_font_sheet, {num_tiles}, sprite_pos, color);
}}

#endif"""

colors = [(0, 0, 0), (255, 0, 0), (0, 255, 0), (0, 0, 255)]

def generate_header_from_font(font_path: str):
    # https://stackoverflow.com/questions/5414639/python-imaging-library-text-rendering
    # https://www.dafont.com/press-start-2p.font
    print_log(f'Creating font header from \'{font_path}\' font')
    font_path = pjoin(fonts_path, f'{font_path}')
    with open(font_path + '-info.json', 'r') as info_file:
        font_info = json.load(info_file)

    char_sheet = generate_char_sheet(font_path, font_info)
    # char_sheet.save(font_path + '.png')

    header_content = build_font_header(font_path, char_sheet, font_info)

    print_success('SUCCESS')

def build_font_header(font_path: str, char_sheet: Image, font_info: Dict):
    pass

def generate_char_sheet(font_path: str, font_info: Dict) -> Image.Image:
    char_width = font_info['char_width']
    char_height = font_info['char_height']
    size = font_info['size']
    style = font_info['style']

    sheet = Image.new('RGBA', (char_width, len(visible_chars) * char_height), (0, 0, 0, 0))
    draw = ImageDraw.Draw(sheet)
    font = ImageFont.truetype(font_path + '.ttf', size)

    txt = get_text()
    if style == 'normal':
        draw_normal(txt, draw, font)
    else:
        draw_shadow(txt, draw, font)

    return sheet

def draw_normal(txt: str, image_draw: ImageDraw, font: ImageFont):
    image_draw.text((0, 0), txt, fill=colors[1], font=font, spacing=0)

def draw_shadow(txt: str, image_draw: ImageDraw, font: ImageFont):
    image_draw.text((1, 1), txt, fill=colors[2], font=font, spacing=0)
    image_draw.text((0, 0), txt, fill=colors[1], font=font, spacing=0)

def get_text() -> str:
    return '\n'.join(visible_chars)