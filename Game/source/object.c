#include "object.h"

static u16 free_objattr_mem_start = 0;

volatile OBJATTR* create_objattrs(u16 x, u16 y, u16 attr0, u16 attr1, u16 attr2)
{
    volatile OBJATTR *new_objattrs = &OAM[free_objattr_mem_start];
    new_objattrs->attr0 = attr0 | OBJ_Y(y);
    new_objattrs->attr1 = attr1 | OBJ_X(x);
    new_objattrs->attr2 = attr2;
    free_objattr_mem_start++;
    return new_objattrs;
}

void clear_objattr_mem()
{
    vu16 *mem = (vu16*) OAM;
    for (u16 i = 0; i < free_objattr_mem_start * sizeof(OBJATTR) / 2; i++)
    {
        mem[i] = 0x0000;
    }
    free_objattr_mem_start = 0;
}