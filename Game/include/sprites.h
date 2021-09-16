#ifndef __SPRITES__
#define __SPRITES__

#include "gba_types.h"
#include "gba_sprites.h"

#define tile_mem ((volatile tile_block *)VRAM)

typedef u16       tile_4bpp[16];
typedef tile_4bpp tile_block[512];

static const u8 tile_4pp_size = sizeof(tile_4bpp) * sizeof(u8) / sizeof(u16);

void load_sprite_4bpp(const u16 sprite[], u16 num_tiles, u16 start_tile);
void load_sprite_8bpp(const u16 sprite[], u16 num_tiles, u16 start_tile);
void load_sprite_32bpp(const u32 sprite[], u16 num_tiles, u16 start_tile);

#endif