#include "sprites.h"

void load_sprite_4bpp(u16* sprite, u16 num_tiles, u16 start_tile)
{
    vu16 *mem = tile_mem[4][start_tile];
    for (u16 i = 0; i < num_tiles * (sizeof(tile_4bpp) / 2); i++)
    {
        mem[i] = sprite[i];
    }
}

void load_sprite_8bpp(u16* sprite, u16 num_tiles, u16 start_tile)
{
    load_sprite_4bpp(sprite, num_tiles, start_tile);
}

void load_sprite_32bpp(u32* sprite, u16 num_tiles, u16 start_tile)
{

}
