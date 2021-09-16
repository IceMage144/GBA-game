#include "sprites.h"

void load_sprite_4bpp(const u16 sprite[], u16 num_tiles, u16 start_tile)
{
    vu16 *mem = tile_mem[4][start_tile];
    u16 *sprite_mem = sprite;
    for (u16 i = 0; i < num_tiles * tile_4pp_size; i++)
    {
        *mem = *sprite_mem;
        mem++;
        sprite_mem++;
    }
}

void load_sprite_8bpp(const u16 sprite[], u16 num_tiles, u16 start_tile)
{
    load_sprite_4bpp(sprite, num_tiles, start_tile);
}

void load_sprite_32bpp(const u32 sprite[], u16 num_tiles, u16 start_tile)
{

}
