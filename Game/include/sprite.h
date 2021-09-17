#ifndef __SPRITE__
#define __SPRITE__

#include "gba_types.h"
#include "gba_sprites.h"

#define tile_mem ((volatile tile_block *)VRAM)

typedef u16       tile_4bpp[16];
typedef tile_4bpp tile_block[512];

static const u8 tile_4pp_size = sizeof(tile_4bpp) * sizeof(u8) / sizeof(u16);

#define NEW_SPRITE_POS 0x8000

void load_sprite_4bpp(const u16 sprite[], u16 num_tiles, u16* start_tile);
void clear_sprite_mem();

#endif