#ifndef __enemies_SHEET_GROUP_H__
#define __enemies_SHEET_GROUP_H__

#include "sprites/enemies/Bonebeast.h"

#define Bonebeast_SHEET 0

static void load_enemies_sheet(volatile OBJATTR* objattr, u8 sheet_id, u16* start_tile,
    u8* palette_pos)
{
    switch (sheet_id)
    {
        case Bonebeast_SHEET:
            load_Bonebeast_sheet(objattr, start_tile, palette_pos);
            break;
    }
}

static void assign_enemies_sheet_attrs(volatile OBJATTR* objattr, u8 sheet_id, u16 start_tile,
    u8 palette_pos)
{
    switch (sheet_id)
    {
        case Bonebeast_SHEET:
            assign_Bonebeast_sheet_attrs(objattr, start_tile, palette_pos);
            break;
    }
}

#endif