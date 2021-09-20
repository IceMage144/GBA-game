#ifndef __allies_SHEET_GROUP_H__
#define __allies_SHEET_GROUP_H__

#include "sprites/allies/HumanBase.h"

#define HumanBase_SHEET 0

void load_allies_sheet(volatile OBJATTR* objattr, u8 sheet_id, u16* start_tile,
    u8* palette_pos)
{
    switch (sheet_id)
    {
        case HumanBase_SHEET:
            load_HumanBase_sheet(objattr, start_tile, palette_pos);
            break;
    }
}

void assign_allies_sheet_attrs(volatile OBJATTR* objattr, u8 sheet_id, u16 start_tile,
    u8 palette_pos)
{
    switch (sheet_id)
    {
        case HumanBase_SHEET:
            assign_HumanBase_sheet_attrs(objattr, start_tile, palette_pos);
            break;
    }
}

#endif