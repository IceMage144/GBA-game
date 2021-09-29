#ifndef __SIMPLE_PALETTE_H__
#define __SIMPLE_PALETTE_H__

#include "gba_types.h"
#include "palette.h"

#define SIMPLE_PALETTE_POS 0x0F

typedef enum simple_color
{
    TRANSPARENT = 0x00,
    BLACK = 0x01,
    WHITE = 0x02,
    RED = 0x03,
    GREEN = 0x04,
    BLUE = 0x05,
    ORANGE = 0x06,
    PURPLE = 0x07,
    YELLOW = 0x08,
    CYAN = 0x09,
    GRAY = 0x0A
} SimpleColor;

static const u16 simple_palette[] __attribute__((aligned(4))) = {
    0x0000, 0x7FFF, 0x7C00, 0x03E0,
    0x001F, 0x7DE0, 0x7C1F, 0x7FE0,
    0x03FF, 0x3DEF
};

inline static void load_simple_palette()
{
    u8 pos = SIMPLE_PALETTE_POS;
    load_palette(simple_palette, 9, &pos);
}

#endif