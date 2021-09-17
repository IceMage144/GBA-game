#include "gba_video.h"
#include "gba_systemcalls.h"

#include "debug/debug.h"
#include "palette.h"
#include "sprite.h"
#include "object.h"

#include "sprites/allies.h"
#include "sprites/enemies.h"

int main()
{
    REG_DISPCNT = MODE_0 | OBJ_1D_MAP | OBJ_ON;

    u8 palette_pos = NEW_PALETTE_POS;
    u16 sprite_pos = NEW_SPRITE_POS;

    volatile OBJATTR *objattr1 = create_objattrs(
        OBJ_Y(32) | ATTR0_COLOR_16 | ATTR0_SQUARE,
        OBJ_X(32) | ATTR1_SIZE_32,
        0
    );
    load_allies_sheet(objattr1, HumanBase_SHEET, &sprite_pos, &palette_pos);

    volatile OBJATTR *objattr2 = create_objattrs(
        OBJ_Y(32) | ATTR0_COLOR_16 | ATTR0_SQUARE,
        OBJ_X(64) | ATTR1_SIZE_32,
        OBJ_CHAR(sprite_pos) | ATTR2_PALETTE(palette_pos)
    );

    // clear_objattr_mem();
    // clear_palette_mem();

    while (true)
    {
        VBlankIntrWait();
    }

    return 0;
}