#include "gba_video.h"
#include "gba_systemcalls.h"

#include "debug/debug.h"
#include "palettes.h"
#include "sprites.h"

#include "sprites/HumanBase.h"
#include "sprites/Bonebeast.h"

int main()
{
    REG_DISPCNT = MODE_0 | OBJ_1D_MAP | OBJ_ON;

    load_HumanBase_sheet(1, 0);

    volatile OBJATTR *test_attrs = &OAM[0];
    test_attrs->attr0 = OBJ_Y(32) | ATTR0_COLOR_16 | ATTR0_SQUARE;
    test_attrs->attr1 = OBJ_X(32) | ATTR1_SIZE_32;
    test_attrs->attr2 = OBJ_CHAR(1) | ATTR2_PALETTE(0);

    while (true)
    {
        VBlankIntrWait();
    }

    return 0;
}