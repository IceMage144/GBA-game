// #ifndef __GBA_OBJECT__
// #define __GBA_OBJECT__

// #include "gba_library/gba_hardware.h"

// typedef struct gba_obj {
// 	uint16 attr0;
// 	uint16 attr1;
// 	uint16 attr2;
// 	uint16 pad;
// } __attribute__((packed, aligned(4))) gba_obj;

// typedef gba_obj* GBAObject;

// // ATTR0
// #define GBA_OBJECT_Y_MASK 0x00FF
// #define GBA_OBJECT_ROTATION_SCALING_FLAG_MASK 0x0100
// #define GBA_OBJECT_ROTATION_SCALING_FLAG_SHIFT 8
// #define GBA_OBJECT_DOUBLE_SIZE_FLAG_MASK 0x0200
// #define GBA_OBJECT_DOUBLE_SIZE_FLAG_SHIFT 9
// #define GBA_OBJECT_ENABLED_FLAG_MASK 0x0200
// #define GBA_OBJECT_ENABLED_FLAG_SHIFT 9
// #define GBA_OBJECT_MODE_FLAG_MASK 0x0C00
// #define GBA_OBJECT_MODE_FLAG_SHIFT 10
// #define GBA_OBJECT_MOSAIC_FLAG_MASK 0x1000
// #define GBA_OBJECT_MOSAIC_FLAG_SHIFT 12
// #define GBA_OBJECT_COLORS_FLAG_MASK 0x2000
// #define GBA_OBJECT_COLORS_FLAG_SHIFT 13
// #define GBA_OBJECT_SHAPE_FLAG_MASK 0xC000
// #define GBA_OBJECT_SHAPE_FLAG_SHIFT 14
// // ATTR1
// #define GBA_OBJECT_X_MASK 0x01FF
// #define GBA_OBJECT_ROTATION_SCALING_TYPE_MASK 0x3E00
// #define GBA_OBJECT_ROTATION_SCALING_TYPE_SHIFT 9
// #define GBA_OBJECT_HORIZONTAL_FLIP_FLAG_MASK 0x1000
// #define GBA_OBJECT_HORIZONTAL_FLIP_FLAG_SHIFT 12
// #define GBA_OBJECT_VERTICAL_FLIP_FLAG_MASK 0x2000
// #define GBA_OBJECT_VERTICAL_FLIP_FLAG_SHIFT 13
// #define GBA_OBJECT_SIZE_FLAG_MASK 0xC000
// #define GBA_OBJECT_SIZE_FLAG_SHIFT 14
// // ATTR2
// #define GBA_OBJECT_NAME_MASK 0x02FF
// #define GBA_OBJECT_PRIORITY_MASK 0x0C00
// #define GBA_OBJECT_PRIORITY_SHIFT 10
// #define GBA_OBJECT_PALETTE_NUMBER_MASK 0xF000
// #define GBA_OBJECT_PALETTE_NUMBER_SHIFT 12

// typedef enum gba_obj_mode
// {
//     GBA_OBJECT_MODE_NORMAL = 0x00,
//     GBA_OBJECT_MODE_SEMI_TRANSPARENT = 0x01,
//     GBA_OBJECT_MODE_WINDOW = 0x02,
//     GBA_OBJECT_MODE_PROHIBITED = 0x03
// } GBAObjectMode;

// typedef enum gba_obj_shape
// {
//     GBA_OBJECT_SHAPE_SQUARE = 0x00,
//     GBA_OBJECT_SHAPE_HORIZONTAL = 0x01,
//     GBA_OBJECT_SHAPE_VERTICAL = 0x02,
//     GBA_OBJECT_SHAPE_PROHIBITED = 0x03
// } GBAObjectShape;

// inline void set_object_attr0(volatile GBAObject obj, uint16 mask, uint16 shift,
//     uint16 new_value)
// {
//     obj->attr0 = (obj->attr0 & ~mask) |
// 	             ((new_value << shift) & mask);
// }

// inline void set_object_attr1(volatile GBAObject obj, uint16 mask, uint16 shift,
//     uint16 new_value)
// {
//     obj->attr1 = (obj->attr1 & ~mask) |
// 	             ((new_value << shift) & mask);
// }

// inline void set_object_attr2(volatile GBAObject obj, uint16 mask, uint16 shift,
//     uint16 new_value)
// {
//     obj->attr2 = (obj->attr2 & ~mask) |
// 	             ((new_value << shift) & mask);
// }

// inline uint16 get_object_attr0(volatile GBAObject obj, uint16 mask, uint16 shift)
// {
//     return (obj->attr0 & mask) >> shift;
// }

// inline uint16 get_object_attr1(volatile GBAObject obj, uint16 mask, uint16 shift)
// {
//     return (obj->attr1 & mask) >> shift;
// }

// inline uint16 get_object_attr2(volatile GBAObject obj, uint16 mask, uint16 shift)
// {
//     return (obj->attr2 & mask) >> shift;
// }

// inline void set_object_pos(volatile GBAObject obj, uint16 x_pos, uint16 y_pos)
// {
//     set_object_attr1(obj, GBA_OBJECT_X_MASK, 0, x_pos);
//     set_object_attr0(obj, GBA_OBJECT_Y_MASK, 0, y_pos);
// }

// inline uint16 get_object_x_pos(volatile GBAObject obj)
// {
//     return get_object_attr1(obj, GBA_OBJECT_X_MASK, 0);
// }

// inline uint16 get_object_y_pos(volatile GBAObject obj)
// {
//     return get_object_attr0(obj, GBA_OBJECT_Y_MASK, 0);
// }

// inline void set_object_double_size(volatile GBAObject obj, uint16 enabled)
// {
//     set_object_attr0(obj, GBA_OBJECT_ROTATION_SCALING_FLAG_MASK,
//         GBA_OBJECT_ROTATION_SCALING_FLAG_SHIFT, 1);
//     set_object_attr0(obj, GBA_OBJECT_DOUBLE_SIZE_FLAG_MASK,
//         GBA_OBJECT_DOUBLE_SIZE_FLAG_SHIFT, enabled);
// }

// inline void set_object_enabled(volatile GBAObject obj, uint16 enabled)
// {
//     set_object_attr0(obj, GBA_OBJECT_ROTATION_SCALING_FLAG_MASK,
//         GBA_OBJECT_ROTATION_SCALING_FLAG_SHIFT, 0);
//     set_object_attr0(obj, GBA_OBJECT_ENABLED_FLAG_MASK,
//         GBA_OBJECT_ENABLED_FLAG_SHIFT, enabled);
// }

// inline void set_object_mode(volatile GBAObject obj, GBAObjectMode mode)
// {
//     set_object_attr0(obj, GBA_OBJECT_MODE_FLAG_MASK,
//         GBA_OBJECT_MODE_FLAG_SHIFT, mode);
// }

// inline void set_object_mosaic(volatile GBAObject obj, uint16 enabled)
// {
//     set_object_attr0(obj, GBA_OBJECT_MOSAIC_FLAG_MASK,
//         GBA_OBJECT_MOSAIC_FLAG_SHIFT, enabled);
// }

// inline void set_object_colors(volatile GBAObject obj, uint16 mode)
// {
//     set_object_attr0(obj, GBA_OBJECT_COLORS_FLAG_MASK,
//         GBA_OBJECT_COLORS_FLAG_SHIFT, mode);
// }

// inline void set_object_shape(volatile GBAObject obj, GBAObjectShape shape)
// {
//     set_object_attr0(obj, GBA_OBJECT_SHAPE_FLAG_MASK,
//         GBA_OBJECT_SHAPE_FLAG_SHIFT, shape);
// }

// // TODO: Discover how to deal with this one
// // inline void set_object_rotation_scaling_type(volatile GBAObject obj, uint16 param);

// inline void flip_object_horizontally(volatile GBAObject obj)
// {
//     set_object_attr0(obj, GBA_OBJECT_ROTATION_SCALING_FLAG_MASK,
//         GBA_OBJECT_ROTATION_SCALING_FLAG_SHIFT, 0);
//     set_object_attr1(obj, GBA_OBJECT_HORIZONTAL_FLIP_FLAG_MASK,
//         GBA_OBJECT_HORIZONTAL_FLIP_FLAG_SHIFT, 1);
// }

// inline void flip_object_vertically(volatile GBAObject obj)
// {
//     set_object_attr0(obj, GBA_OBJECT_ROTATION_SCALING_FLAG_MASK,
//         GBA_OBJECT_ROTATION_SCALING_FLAG_SHIFT, 0);
//     set_object_attr1(obj, GBA_OBJECT_VERTICAL_FLIP_FLAG_MASK,
//         GBA_OBJECT_VERTICAL_FLIP_FLAG_SHIFT, 1);
// }

// // TODO: Discover how to deal with this one too
// // inline void set_object_size(volatile GBAObject obj, uint16 size_mode);

// inline void set_object_name(volatile GBAObject obj, uint16 name)
// {
//     set_object_attr2(obj, GBA_OBJECT_NAME_MASK, 0, name);
// }

// inline void set_object_priority(volatile GBAObject obj, uint16 priority)
// {
//     set_object_attr2(obj, GBA_OBJECT_PRIORITY_MASK,
//         GBA_OBJECT_PRIORITY_SHIFT, priority);
// }

// inline void set_object_palette(volatile GBAObject obj, uint16 palette_num)
// {
//     set_object_attr2(obj, GBA_OBJECT_PALETTE_NUMBER_MASK,
//         GBA_OBJECT_PALETTE_NUMBER_SHIFT, palette_num);
// }

// #endif