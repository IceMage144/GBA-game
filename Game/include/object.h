#ifndef __OBJECT__
#define __OBJECT__

#include "gba_sprites.h"

volatile OBJATTR* create_objattrs(u16 attr0, u16 attr1, u16 attr2);
void clear_objattr_mem();

#endif