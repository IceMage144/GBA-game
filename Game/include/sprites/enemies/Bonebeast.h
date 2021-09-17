#ifndef __Bonebeast_SHEET__
#define __Bonebeast_SHEET_H__

#include "gba_types.h"
#include "palette.h"
#include "sprite.h"

#define Bonebeast_WalkLeft_SPRITE 0
#define Bonebeast_Attack_SPRITE 3
#define Bonebeast_Walk_ANIMATION_SIZE 3
#define Bonebeast_Attack_ANIMATION_SIZE 3

const u16 Bonebeast_palette[] __attribute__((aligned(4))) = {
    0x0022, 0x112E, 0x0A38, 0x3B1D,
    0x77FF
};

const u16 Bonebeast_sheet[] __attribute__((aligned(4))) = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0x2100,
    0x0000, 0x2211, 0x1000, 0x4322, 0x4100, 0x4444, 0x4310, 0x2455,
    0x0000, 0x0000, 0x0111, 0x0000, 0x0012, 0x0000, 0x0001, 0x1000,
    0x0011, 0x2100, 0x1113, 0x2321, 0x5322, 0x1234, 0x2342, 0x0112,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0111, 0x0000, 0x0012, 0x0000,
    0x0001, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0x2110, 0x0000, 0x3321,
    0x0000, 0x1441, 0x0000, 0x0141, 0x0000, 0x0010, 0x0000, 0x0000,
    0x4411, 0x2234, 0x2431, 0x4442, 0x1243, 0x3541, 0x4535, 0x1234,
    0x2424, 0x2111, 0x1111, 0x1111, 0x1100, 0x4312, 0x1100, 0x2211,
    0x1112, 0x0001, 0x0123, 0x0000, 0x0012, 0x0000, 0x1121, 0x0111,
    0x4112, 0x0123, 0x2421, 0x1312, 0x1245, 0x4531, 0x2111, 0x3221,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0012, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0x2100, 0x0000, 0x3100,
    0x1000, 0x4212, 0x1000, 0x2211, 0x1000, 0x4121, 0x2100, 0x1111,
    0x1210, 0x1111, 0x1111, 0x1111, 0x1122, 0x2221, 0x0132, 0x3211,
    0x1245, 0x2112, 0x2111, 0x1012, 0x3224, 0x1001, 0x1342, 0x4100,
    0x0111, 0x4100, 0x1122, 0x2111, 0x2445, 0x2421, 0x1124, 0x3541,
    0x0013, 0x0000, 0x0144, 0x0000, 0x0142, 0x0000, 0x0125, 0x0000,
    0x0013, 0x0000, 0x0012, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000,
    0x0000, 0x3100, 0x0000, 0x1000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0132, 0x1111, 0x1011, 0x1122, 0x2100, 0x0012, 0x2100, 0x0001,
    0x1100, 0x0011, 0x1100, 0x0122, 0x2210, 0x1221, 0x1110, 0x1111,
    0x2111, 0x4441, 0x2210, 0x1111, 0x1431, 0x0000, 0x1441, 0x0000,
    0x3211, 0x0011, 0x3110, 0x0123, 0x1421, 0x1244, 0x1111, 0x1111,
    0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1000,
    0x0000, 0x2100, 0x0000, 0x2211, 0x1000, 0x4322, 0x4100, 0x4444,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0111, 0x0000, 0x0012, 0x0000,
    0x0001, 0x1000, 0x0011, 0x2100, 0x1113, 0x2321, 0x5322, 0x1234,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0111, 0x0000,
    0x0012, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0x2110,
    0x0000, 0x3321, 0x0000, 0x1441, 0x0000, 0x0141, 0x0000, 0x0010,
    0x4310, 0x2455, 0x4411, 0x2234, 0x2431, 0x4442, 0x1243, 0x3541,
    0x4535, 0x1234, 0x2424, 0x2111, 0x1111, 0x1111, 0x1100, 0x4312,
    0x2342, 0x0112, 0x1112, 0x0001, 0x0123, 0x0000, 0x0012, 0x0000,
    0x1121, 0x0111, 0x4112, 0x0123, 0x2421, 0x1312, 0x1245, 0x1531,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x1100, 0x2211, 0x1100, 0x4212, 0x1100, 0x2211, 0x1000, 0x4121,
    0x1000, 0x1111, 0x1000, 0x1111, 0x1100, 0x2111, 0x2100, 0x4121,
    0x2111, 0x1431, 0x1245, 0x1341, 0x1111, 0x0142, 0x1224, 0x0122,
    0x3142, 0x0125, 0x4411, 0x0012, 0x2224, 0x0001, 0x1135, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0x1000,
    0x2100, 0x4111, 0x1100, 0x1121, 0x2100, 0x0012, 0x2210, 0x0001,
    0x1111, 0x0000, 0x2211, 0x0001, 0x2122, 0x0012, 0x1111, 0x0011,
    0x1144, 0x0000, 0x2111, 0x0001, 0x2110, 0x0012, 0x3100, 0x0014,
    0x1100, 0x1132, 0x1000, 0x2331, 0x2100, 0x4414, 0x1100, 0x1111,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0001, 0x0000, 0x0012, 0x0000, 0x0011, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1000,
    0x0000, 0x2100, 0x0000, 0x2211, 0x1000, 0x4322, 0x4100, 0x4444,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0111, 0x0000, 0x0012, 0x0000,
    0x0001, 0x1000, 0x0011, 0x2100, 0x1113, 0x2321, 0x5322, 0x1234,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0111, 0x0000,
    0x0012, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0x2110,
    0x0000, 0x3321, 0x0000, 0x1441, 0x0000, 0x0141, 0x0000, 0x0010,
    0x4310, 0x2455, 0x4411, 0x2234, 0x2431, 0x4442, 0x1243, 0x3541,
    0x4535, 0x1234, 0x2424, 0x2111, 0x1111, 0x1111, 0x1100, 0x4311,
    0x2342, 0x0112, 0x1112, 0x0001, 0x0123, 0x0000, 0x0012, 0x0000,
    0x1121, 0x0111, 0x4112, 0x0123, 0x2421, 0x1212, 0x1245, 0x4531,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0x1110, 0x0000, 0x2221,
    0x1100, 0x2211, 0x1000, 0x4212, 0x1000, 0x2211, 0x2100, 0x4121,
    0x2210, 0x1111, 0x1221, 0x1111, 0x1111, 0x1110, 0x0011, 0x2221,
    0x2111, 0x3311, 0x1245, 0x1112, 0x2111, 0x0002, 0x3224, 0x0001,
    0x1342, 0x0000, 0x0111, 0x0000, 0x1122, 0x0000, 0x2445, 0x1000,
    0x0012, 0x0000, 0x0143, 0x0000, 0x1141, 0x0000, 0x1211, 0x0000,
    0x1510, 0x0000, 0x1341, 0x0000, 0x1211, 0x0000, 0x1242, 0x0000,
    0x0000, 0x3231, 0x0000, 0x3231, 0x0000, 0x1110, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0011, 0x3211, 0x0001, 0x1111, 0x0000, 0x1221, 0x0000, 0x3121,
    0x0000, 0x4110, 0x0000, 0x1110, 0x0000, 0x4211, 0x0000, 0x1111,
    0x1124, 0x1000, 0x2211, 0x1000, 0x1222, 0x0000, 0x0114, 0x0000,
    0x0114, 0x0000, 0x1233, 0x0000, 0x2441, 0x0001, 0x1111, 0x0001,
    0x1354, 0x0000, 0x1444, 0x0000, 0x0111, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0x3100, 0x0000, 0x4110,
    0x0000, 0x1110, 0x0000, 0x0121, 0x1000, 0x0012, 0x2110, 0x0112,
    0x3221, 0x1134, 0x4444, 0x3224, 0x4554, 0x3422, 0x2344, 0x1122,
    0x0000, 0x0000, 0x0000, 0x1110, 0x0000, 0x0121, 0x1000, 0x0012,
    0x3211, 0x0012, 0x2345, 0x0001, 0x1122, 0x0000, 0x0011, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x4311, 0x1100, 0x2432, 0x3210, 0x5353, 0x4410, 0x4241,
    0x1410, 0x1110, 0x0100, 0x1110, 0x0000, 0x1211, 0x1000, 0x1111,
    0x4422, 0x1234, 0x5411, 0x0123, 0x2344, 0x0011, 0x1112, 0x1111,
    0x1221, 0x2341, 0x2111, 0x1224, 0x4543, 0x4112, 0x1122, 0x3121,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000,
    0x0001, 0x0000, 0x0012, 0x0000, 0x0015, 0x0000, 0x0014, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x1100, 0x0000, 0x2210, 0x0000, 0x2310,
    0x1000, 0x1212, 0x2100, 0x1112, 0x2100, 0x2112, 0x2210, 0x1111,
    0x1121, 0x1001, 0x1111, 0x1100, 0x0112, 0x2100, 0x0013, 0x1100,
    0x4542, 0x1212, 0x1122, 0x1221, 0x2441, 0x1132, 0x4211, 0x1013,
    0x1111, 0x4101, 0x1211, 0x4111, 0x1522, 0x3242, 0x1432, 0x1354,
    0x0013, 0x0000, 0x0123, 0x0000, 0x0144, 0x0000, 0x0142, 0x0000,
    0x0125, 0x0000, 0x0013, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
    0x0000, 0x2310, 0x0000, 0x1100, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0013, 0x1110, 0x0001, 0x1211, 0x1000, 0x0122, 0x1000, 0x0012,
    0x1000, 0x0111, 0x1100, 0x0122, 0x2210, 0x1221, 0x1110, 0x1111,
    0x1111, 0x1444, 0x1101, 0x0111, 0x4310, 0x0001, 0x4410, 0x0001,
    0x2110, 0x0013, 0x3110, 0x0123, 0x1421, 0x1244, 0x1111, 0x1111,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0111, 0x1000, 0x0012, 0x2100, 0x0001, 0x2211, 0x0011,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0111, 0x1000, 0x0012, 0x2100, 0x0001,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1000, 0x0000, 0x4100, 0x0000, 0x4310, 0x0000, 0x4411,
    0x1000, 0x2431, 0x2110, 0x1243, 0x3321, 0x4535, 0x1441, 0x2424,
    0x4322, 0x1113, 0x4444, 0x5322, 0x2455, 0x2342, 0x2234, 0x1112,
    0x4442, 0x1123, 0x3541, 0x1112, 0x1234, 0x5431, 0x1111, 0x1221,
    0x2321, 0x0001, 0x1234, 0x0000, 0x0112, 0x0000, 0x1111, 0x0011,
    0x3411, 0x0012, 0x2242, 0x0131, 0x1124, 0x1453, 0x1211, 0x2322,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0011, 0x0000,
    0x1141, 0x1111, 0x0010, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x2100, 0x5421, 0x1000, 0x2211, 0x1000, 0x4121, 0x0000, 0x1111,
    0x1000, 0x1111, 0x1100, 0x1111, 0x2210, 0x2221, 0x2310, 0x3211,
    0x2124, 0x3111, 0x2111, 0x1112, 0x3224, 0x1001, 0x1342, 0x1000,
    0x0111, 0x1000, 0x1122, 0x1110, 0x2445, 0x4211, 0x1124, 0x5411,
    0x0123, 0x0000, 0x1443, 0x0000, 0x1421, 0x0000, 0x1254, 0x0000,
    0x0134, 0x0000, 0x0122, 0x0000, 0x0012, 0x0000, 0x0013, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x2310, 0x1111, 0x1100, 0x1221, 0x0000, 0x1221, 0x0000, 0x0121,
    0x0000, 0x1111, 0x0000, 0x2211, 0x1000, 0x2122, 0x1000, 0x1111,
    0x2111, 0x4411, 0x2101, 0x1111, 0x3100, 0x0014, 0x4100, 0x0014,
    0x1100, 0x1132, 0x1001, 0x2331, 0x2112, 0x4414, 0x1111, 0x1111,
    0x0014, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0001, 0x0000, 0x0012, 0x0000, 0x0011, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1100, 0x0000, 0x2210, 0x0000, 0x4441, 0x1000, 0x5543,
    0x0000, 0x0000, 0x1100, 0x0001, 0x1210, 0x0000, 0x0121, 0x0000,
    0x1122, 0x0000, 0x1343, 0x2111, 0x2244, 0x3453, 0x4224, 0x1223,
    0x0000, 0x0000, 0x0000, 0x0000, 0x1100, 0x0001, 0x1210, 0x0000,
    0x0121, 0x0000, 0x0123, 0x0000, 0x0012, 0x0000, 0x0001, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0x2100,
    0x0000, 0x4100, 0x0000, 0x4100, 0x0000, 0x1000, 0x0000, 0x0000,
    0x1100, 0x3444, 0x3110, 0x4224, 0x4321, 0x4112, 0x3533, 0x3445,
    0x2414, 0x1124, 0x1101, 0x1111, 0x1000, 0x3121, 0x1000, 0x2111,
    0x1222, 0x0111, 0x2344, 0x0001, 0x1235, 0x0000, 0x1112, 0x1111,
    0x1121, 0x1234, 0x4211, 0x3122, 0x2454, 0x5311, 0x1112, 0x2212,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0001, 0x0000, 0x0014, 0x0000, 0x0123, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0x2100, 0x0000, 0x3100,
    0x0000, 0x2121, 0x1000, 0x2211, 0x1000, 0x4121, 0x2100, 0x1111,
    0x1210, 0x1110, 0x1111, 0x1111, 0x1122, 0x2221, 0x0132, 0x3211,
    0x2454, 0x1121, 0x2111, 0x0012, 0x3224, 0x0001, 0x1342, 0x1000,
    0x0111, 0x1000, 0x1122, 0x2111, 0x2445, 0x2421, 0x1124, 0x3541,
    0x1231, 0x0000, 0x1441, 0x0000, 0x1421, 0x0000, 0x1254, 0x0000,
    0x0134, 0x0000, 0x0012, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000,
    0x0000, 0x3100, 0x0000, 0x1000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0132, 0x1111, 0x1011, 0x1122, 0x2100, 0x0012, 0x2100, 0x0001,
    0x1110, 0x0001, 0x2110, 0x0012, 0x1221, 0x1122, 0x1111, 0x1111,
    0x2111, 0x4441, 0x2210, 0x1111, 0x1431, 0x0000, 0x1441, 0x0000,
    0x1321, 0x0001, 0x3311, 0x0012, 0x4142, 0x0124, 0x1111, 0x0111,
    0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

inline static void load_Bonebeast_sheet(volatile OBJATTR* objattr, u16* sprite_pos, u8* palette_pos)
{
    load_palette(Bonebeast_palette, 5, palette_pos);
    load_sprite_4bpp(Bonebeast_sheet, 96, sprite_pos);
    objattr->attr2 = OBJ_CHAR(*sprite_pos) | ATTR2_PALETTE(*palette_pos);
}

#endif