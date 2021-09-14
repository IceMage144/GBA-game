#ifndef __PALETTES__
#define __PALETTES__

#include "gba_types.h"
#include "gba_video.h"

typedef u16 palette16[16];
typedef u16 palette256[256];
#define palette_mem ((volatile palette16 *) SPRITE_PALETTE)

void load_palette(u16* palette, u8 size, u8 palette_pos);

#endif