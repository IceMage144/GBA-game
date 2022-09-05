// #ifndef __GBA_DISPLAY_CONTROL__
// #define __GBA_DISPLAY_CONTROL__

// #include "gba_library/gba_video.h"

// #define GBA_DISPCNT_BG_MODE_MASK 0x0007
// #define GBA_DISPCNT_DISPLAY_FRAME_MASK 0x0010
// #define GBA_DISPCNT_DISPLAY_FRAME_SHIFT 4
// #define GBA_DISPCNT_H_BLANK_FREE_MASK 0x0020
// #define GBA_DISPCNT_H_BLANK_FREE_SHIFT 5
// #define GBA_DISPCNT_OBJ_VRAM_MAPPING_MASK 0x0040
// #define GBA_DISPCNT_OBJ_VRAM_MAPPING_SHIFT 6
// #define GBA_DISPCNT_FORCED_BLANK_MASK 0x0080
// #define GBA_DISPCNT_FORCED_BLANK_SHIFT 7
// #define GBA_DISPCNT_DISPLAY_BG_MASK 0x0F00
// #define GBA_DISPCNT_DISPLAY_BG_SHIFT 8
// #define GBA_DISPCNT_DISPLAY_OBJ_MASK 0x1000
// #define GBA_DISPCNT_DISPLAY_OBJ_SHIFT 12
// #define GBA_DISPCNT_WINDOW_DISPLAY_MASK 0x6000
// #define GBA_DISPCNT_WINDOW_DISPLAY_SHIFT 13
// #define GBA_DISPCNT_OBJ_WINDOW_DISPLAY_MASK 0x8000
// #define GBA_DISPCNT_OBJ_WINDOW_DISPLAY_SHIFT 15

// typedef enum gba_dispcnt_frame
// {
//     FRAME0 = 0x0,
//     FRAME1 = 0x1
// } GBADCFrame;

// // The table summarizes the facilities of the separate BG modes (video modes).

// //   Mode  Rot/Scal Layers Size               Tiles Colors       Features
// //   0     No       0123   256x256..512x515   1024  16/16..256/1 SFMABP
// //   1     Mixed    012-   (BG0,BG1 as above Mode 0, BG2 as below Mode 2)
// //   2     Yes      --23   128x128..1024x1024 256   256/1        S-MABP
// //   3     Yes      --2-   240x160            1     32768        --MABP
// //   4     Yes      --2-   240x160            2     256/1        --MABP
// //   5     Yes      --2-   160x128            2     32768        --MABP

// // Features: S)crolling, F)lip, M)osaic, A)lphaBlending, B)rightness, P)riority.

// // BG Modes 0-2 are Tile/Map-based. BG Modes 3-5 are Bitmap-based, in these modes 1 or 2 Frames (ie. bitmaps, or 'full screen tiles') exists, if two frames exist, either one can be displayed, and the other one can be redrawn in background.
// typedef enum gba_dispcnt_bg_mode
// {
//     MODE0 = 0x0,
//     MODE1 = 0x1,
//     MODE2 = 0x2,
//     MODE3 = 0x3,
//     MODE4 = 0x4,
//     MODE5 = 0x5
// } GBADCBGMode;

// typedef enum gba_dispcnt_obj_vram_mapping
// {
//     TWO_DIM = 0x0,
//     ONE_DIM = 0x1
// } GBADCObjVRAMMapping;

// typedef enum gba_dispcnt_bg_flag
// {
//     BG0 = 0x1,
//     BG1 = 0x2,
//     BG2 = 0x4,
//     BG3 = 0x8
// } GBADCBGFlag;

// typedef enum gba_dispcnt_window_flag
// {
//     WIDNOW0 = 0x1,
//     WINDOW1 = 0x2
// } GBADCWindowFlag;


// inline void set_display_control_bits(uint16 mask, uint16 shift, uint16 new_value)
// {
//     uint16 display_control = get_display_control();
//     display_control = (display_control & ~mask) |
//         ((new_value << shift) & mask);
//     set_display_control(display_control);
// }

// inline void set_bg_mode(GBADCBGMode mode)
// {
//     set_display_control_bits(GBA_DISPCNT_BG_MODE_MASK, 0, mode);
// }

// inline void set_display_frame(GBADCFrame frame)
// {
//     set_display_control_bits(GBA_DISPCNT_DISPLAY_FRAME_MASK,
//         GBA_DISPCNT_DISPLAY_FRAME_SHIFT, frame);
// }

// inline void set_free_hblank_interval(uint8 enabled)
// {
//     set_display_control_bits(GBA_DISPCNT_H_BLANK_FREE_MASK,
//         GBA_DISPCNT_H_BLANK_FREE_SHIFT, enabled);
// }

// inline void set_obj_vram_mapping(GBADCObjVRAMMapping mapping)
// {
//     set_display_control_bits(GBA_DISPCNT_OBJ_VRAM_MAPPING_MASK,
//         GBA_DISPCNT_OBJ_VRAM_MAPPING_SHIFT, mapping);
// }

// inline void set_enabled_bgs(GBADCBGFlag enabled_bgs /* Bitmask */)
// {
//     set_display_control_bits(GBA_DISPCNT_DISPLAY_BG_MASK,
//         GBA_DISPCNT_DISPLAY_BG_SHIFT, enabled_bgs);
// }

// inline void set_enabled_objs(uint8 enabled)
// {
//     set_display_control_bits(GBA_DISPCNT_DISPLAY_OBJ_MASK,
//         GBA_DISPCNT_DISPLAY_OBJ_SHIFT, enabled);
// }

// inline void set_enabled_windows(GBADCWindowFlag enabled_windows /* Bitmask */)
// {
//     set_display_control_bits(GBA_DISPCNT_WINDOW_DISPLAY_MASK,
//         GBA_DISPCNT_WINDOW_DISPLAY_SHIFT, enabled_windows);
// }

// inline void set_enabled_obj_window(uint8 enabled)
// {
//     set_display_control_bits(GBA_DISPCNT_OBJ_WINDOW_DISPLAY_MASK,
//         GBA_DISPCNT_OBJ_WINDOW_DISPLAY_SHIFT, enabled);
// }

// #endif