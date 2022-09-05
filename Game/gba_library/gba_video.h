// #ifndef __GBA_VIDEO__
// #define __GBA_VIDEO__

// #include "gba_library/gba_hardware.h"

// #define GBA_VBLANK_LINE 160

// #define GBA_VIDEO_DISPLAY_CONTROL 0
// #define GBA_VIDEO_VCOUNT 3

// #define gba_lcd_io_registers ((volatile uint16*) GBA_IO_BEGIN)

// // #define gba_lcd_io_vcount 

// inline void set_display_control(uint16 display_control)
// {
//     gba_lcd_io_registers[GBA_VIDEO_DISPLAY_CONTROL] = display_control;
// }

// inline uint16 get_display_control()
// {
//     return gba_lcd_io_registers[GBA_VIDEO_DISPLAY_CONTROL];
// }

// inline uint16 get_vcount()
// {
//     return gba_lcd_io_registers[GBA_VIDEO_VCOUNT];
// }

// inline void wait_for_vblank()
// {
//     uint16 vcount = get_vcount();

//     while(vcount >= GBA_VBLANK_LINE);
//     while(vcount <  GBA_VBLANK_LINE);
// }

// #endif