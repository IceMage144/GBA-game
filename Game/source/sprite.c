#include "sprite.h"

static u16 free_sprite_mem_start = 1;

void load_sprite_4bpp(const u16 sprite[], u16 num_tiles, u16* start_tile)
{
    if (*start_tile == NEW_SPRITE_POS)
    {
        *start_tile = free_sprite_mem_start;
        free_sprite_mem_start += num_tiles;
    }
    vu16 *mem = tile_mem[4][*start_tile];
    u16 *sprite_mem = sprite;
    for (u16 i = 0; i < num_tiles; i++)
    {
        for (u16 j = 0; j < tile_4pp_size; j++)
        {
            *mem = *sprite_mem;
            mem++;
            sprite_mem++;
        }
    }
}

void clear_sprite_mem()
{
    vu16 *mem = (vu16*) tile_mem;
    for (u16 i = 0; i < free_sprite_mem_start * 16; i++)
    {
        mem[i] = 0x0000;
    }
    free_sprite_mem_start = 1;
}