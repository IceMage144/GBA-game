import string

from PIL import ImageDraw, ImageFont, Image

visible_chars = ''.join(sorted(set(string.printable) - set(string.whitespace)))
char_size = 8

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

def generate_header_from_font(font_path: str):
    # https://stackoverflow.com/questions/5414639/python-imaging-library-text-rendering
    # https://www.dafont.com/press-start-2p.font
    char_sheet = generate_char_sheet(font_path)



def generate_char_sheet(font_path: str) -> Image.Image:
    sheet = Image.new('RGBA', (char_size, len(visible_chars) * char_size), (0, 0, 0, 0))
    draw = ImageDraw.Draw(sheet)
    font = ImageFont.truetype(font_path, char_size)

    txt = '\n'.join(visible_chars)
    draw.text((0, 0), txt, fill=(255, 255, 255), font=font, spacing=0)
    return sheet