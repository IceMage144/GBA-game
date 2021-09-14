#include "gba_video.h"
#include "palettes.h"


void load_palette(u16* palette, u8 size, u8 palette_pos)
{
    vu16 *mem = palette_mem[palette_pos];
    for (u8 i = 0; i < size; i++)
    {
        mem[i + 1] = palette[i];
    }
}