#ifndef __GBA_DEBUG__
#define __GBA_DEBUG__

#include "gba_video.h"

static inline void write_vram_raw_mode3(u16 row, u16  col, u32 data)
{
    MODE3_FB[row][col] = data;
}

static inline void draw_one(u16 row, u16 col, u32 color)
{
    write_vram_raw_mode3(row, col + 1, color);
    write_vram_raw_mode3(row + 1, col + 1, color);
    write_vram_raw_mode3(row + 2, col + 1, color);
}

static inline void draw_zero(u16 row, u16 col, u32 color)
{
    write_vram_raw_mode3(row, col, color);
    write_vram_raw_mode3(row, col + 1, color);
    write_vram_raw_mode3(row, col + 2, color);
    write_vram_raw_mode3(row + 1, col, color);
    write_vram_raw_mode3(row + 1, col + 2, color);
    write_vram_raw_mode3(row + 2, col, color);
    write_vram_raw_mode3(row + 2, col + 1, color);
    write_vram_raw_mode3(row + 2, col + 2, color);
}

void draw_number(u16 num, u16 color);

#endif