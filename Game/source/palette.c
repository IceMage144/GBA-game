#include "palette.h"

static u16 free_palette_mem_start = 0;

void load_palette(const u16 palette[], u8 size, u8* palette_pos)
{
    if (*palette_pos == NEW_PALETTE_POS)
    {
        *palette_pos = free_palette_mem_start;
        free_palette_mem_start++;
    }
    vu16 *mem = palette_mem[*palette_pos];
    for (u8 i = 0; i < size; i++)
    {
        mem[i + 1] = palette[i];
    }
}

void clear_palette_mem()
{
    vu16 *mem = (vu16*) palette_mem;
    for (u16 i = 0; i < free_palette_mem_start * 16; i++)
    {
        mem[i] = 0x0000;
    }
    free_palette_mem_start = 0;
}