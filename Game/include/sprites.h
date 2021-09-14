#ifndef __SPRITES__
#define __SPRITES__

#include "gba_types.h"
#include "gba_sprites.h"

typedef u16       tile_4bpp[16];
typedef tile_4bpp tile_block[512];
#define tile_mem ((volatile tile_block *)VRAM)

void load_sprite_4bpp(u16* sprite, u16 num_tiles, u16 start_tile);
void load_sprite_8bpp(u16* sprite, u16 num_tiles, u16 start_tile);
void load_sprite_32bpp(u32* sprite, u16 num_tiles, u16 start_tile);

#endif