#include "gba_video.h"
#include "debug/debug.h"

int main()
{
    REG_DISPCNT = MODE_3 | BG2_ON;
    draw_number(0x1234, 0x001F);
    return 0;
}