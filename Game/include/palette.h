#ifndef __PALETTE__
#define __PALETTE__

#include "gba_types.h"
#include "gba_video.h"

typedef u16 palette16[16];
typedef u16 palette256[256];
#define palette_mem ((volatile palette16 *) SPRITE_PALETTE)

#define NEW_PALETTE_POS 0x10

void load_palette(const u16 palette[], u8 size, u8* palette_pos);
void clear_palette_mem();

#endif