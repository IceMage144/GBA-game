#ifndef __SPRITE__
#define __SPRITE__

#include "gba_types.h"
#include "gba_sprites.h"

#define tile_mem ((volatile tile_block *)VRAM)

typedef u16       tile_4bpp[16];
typedef tile_4bpp tile_block[512];

static const u8 tile_4pp_size = sizeof(tile_4bpp) * sizeof(u8) / sizeof(u16);

#define NEW_SPRITE_POS 0x8000

// Sprite Attribute 0 masks
#define OBJ_Y_MASK            0x00FF
#define OBJ_ROT_SCALE_MASK    0x0100
#define OBJ_DISABLE_MASK      0x0200
#define OBJ_DOUBLE_MASK       0x0200
#define OBJ_MODE_MASK         0x0C00
#define OBJ_MOSAIC_MASK       0x1000
#define	OBJ_COLOR_MODE_MASK   0x2000
#define	OBJ_SHAPE_MASK        0xC000

// Sprite Attribute 1 masks
#define OBJ_X_FLAG            0x01FF
#define OBJ_ROT_SCALE_MASK    0x3E00
#define OBJ_HFLIP_MASK        0x1000
#define OBJ_VFLIP_MASK        0x2000
#define OBJ_SIZE_MASK         0xC000

// Sprite Attribute 2 masks
#define OBJ_CHAR_MASK         0x03FF
#define OBJ_PRIORITY_MASK     0x0C00
#define OBJ_PALETTE_MASK      0xF000


void load_sprite_4bpp(const u16 sprite[], u16 num_tiles, u16* start_tile);
void clear_sprite_mem();

#endif