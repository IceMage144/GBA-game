#include "debug/debug.h"

void draw_number(u16 num, u16 color)
{
    u16 char_size = 4;
    u16 row = 2;
    u16 col = 2 + char_size * 15;
    for (int i = 0; i < 16; i++)
    {
        u16 first_bit = (num & 1);
        if (first_bit == 1)
        {
            draw_one(row, col, color);
        }
        else
        {
            draw_zero(row, col, color);
        }
        col -= 4;
        num >>= 1;
    }
}