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

    volatile OBJATTR *objattr1 = create_objattrs(32, 32, 0, 0, 0);
    load_allies_sheet(objattr1, HumanBase_SHEET, &sprite_pos, &palette_pos);

    volatile OBJATTR *objattr2 = create_objattrs(64, 32, 0, 0, 0);
    assign_allies_sheet_attrs(objattr2, HumanBase_SHEET, sprite_pos, palette_pos);

    // clear_objattr_mem();
    // clear_palette_mem();
    // clear_sprite_mem();

    while (true)
    {
        VBlankIntrWait();
    }

    return 0;
}