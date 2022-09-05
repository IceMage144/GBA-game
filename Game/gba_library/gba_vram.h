// #ifndef __GBA_VRAM__
// #define __GBA_VRAM__

// #include "gba_library/gba_hardware.h"

// #define gba_vram ((volatile uint16*) GBA_VRAM_BEGIN)

// inline void write_vram_raw(uint8 row, uint8 col, uint16 data)
// {
//     gba_vram[SCREEN_WIDTH * row + col] = data;
// }

// inline void clear_vram()
// {
//     for (int i = 0; i < SCREEN_HEIGHT; i++)
//     {
//         for (int j = 0; j < SCREEN_WIDTH; j++)
//         {
//             gba_vram[SCREEN_WIDTH * i + j] = 0x0000;
//         }
//     }
// }

// #endif