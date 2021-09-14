#ifndef __Bonebeast_SHEET__
#define __Bonebeast_SHEET__

#include "gba_types.h"
#include "palettes.h"
#include "sprites.h"

u16 Bonebeast_palette[] = {
    0x0022, 0x112E, 0x0A38, 0x3B1D,
    0x77FF
};

u16 Bonebeast_sheet[] = {
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x2110, 0x11110, 0x2210,
    0x11110, 0x2211, 0x2110, 0x4322, 0x4210, 0x4444, 0x4320, 0x2455,
    0x11110, 0x11110, 0x10111, 0x11110, 0x11012, 0x11110, 0x11101, 0x2110,
    0x11011, 0x2210, 0x1113, 0x2321, 0x5322, 0x1234, 0x2342, 0x10112,
    0x11110, 0x11110, 0x11110, 0x11110, 0x10111, 0x11110, 0x11012, 0x11110,
    0x11101, 0x11110, 0x11101, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x2110, 0x11110, 0x2120, 0x11110, 0x3321,
    0x11110, 0x1441, 0x11110, 0x10141, 0x11110, 0x11020, 0x11110, 0x11110,
    0x4411, 0x2234, 0x2431, 0x4442, 0x1243, 0x3541, 0x4535, 0x1234,
    0x2424, 0x2111, 0x1111, 0x1111, 0x1210, 0x4312, 0x1210, 0x2211,
    0x1112, 0x11101, 0x10123, 0x11110, 0x11012, 0x11110, 0x1121, 0x10111,
    0x4112, 0x10123, 0x2421, 0x1312, 0x1245, 0x4531, 0x2111, 0x3221,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11101, 0x11110, 0x11012, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x2110, 0x11110, 0x2210, 0x11110, 0x3210,
    0x2110, 0x4212, 0x2110, 0x2211, 0x2110, 0x4121, 0x2210, 0x1111,
    0x1220, 0x1111, 0x1111, 0x1111, 0x1122, 0x2221, 0x10132, 0x3211,
    0x1245, 0x2112, 0x2111, 0x2012, 0x3224, 0x2101, 0x1342, 0x4210,
    0x10111, 0x4210, 0x1122, 0x2111, 0x2445, 0x2421, 0x1124, 0x3541,
    0x11013, 0x11110, 0x10144, 0x11110, 0x10142, 0x11110, 0x10125, 0x11110,
    0x11013, 0x11110, 0x11012, 0x11110, 0x11101, 0x11110, 0x11101, 0x11110,
    0x11110, 0x3210, 0x11110, 0x2110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x10132, 0x1111, 0x2011, 0x1122, 0x2210, 0x11012, 0x2210, 0x11101,
    0x1210, 0x11011, 0x1210, 0x10122, 0x2220, 0x1221, 0x1120, 0x1111,
    0x2111, 0x4441, 0x2220, 0x1111, 0x1431, 0x11110, 0x1441, 0x11110,
    0x3211, 0x11011, 0x3120, 0x10123, 0x1421, 0x1244, 0x1111, 0x1111,
    0x11101, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x2110,
    0x11110, 0x2210, 0x11110, 0x2211, 0x2110, 0x4322, 0x4210, 0x4444,
    0x11110, 0x11110, 0x11110, 0x11110, 0x10111, 0x11110, 0x11012, 0x11110,
    0x11101, 0x2110, 0x11011, 0x2210, 0x1113, 0x2321, 0x5322, 0x1234,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x10111, 0x11110,
    0x11012, 0x11110, 0x11101, 0x11110, 0x11101, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x2110, 0x11110, 0x2120,
    0x11110, 0x3321, 0x11110, 0x1441, 0x11110, 0x10141, 0x11110, 0x11020,
    0x4320, 0x2455, 0x4411, 0x2234, 0x2431, 0x4442, 0x1243, 0x3541,
    0x4535, 0x1234, 0x2424, 0x2111, 0x1111, 0x1111, 0x1210, 0x4312,
    0x2342, 0x10112, 0x1112, 0x11101, 0x10123, 0x11110, 0x11012, 0x11110,
    0x1121, 0x10111, 0x4112, 0x10123, 0x2421, 0x1312, 0x1245, 0x1531,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x1210, 0x2211, 0x1210, 0x4212, 0x1210, 0x2211, 0x2110, 0x4121,
    0x2110, 0x1111, 0x2110, 0x1111, 0x1210, 0x2111, 0x2210, 0x4121,
    0x2111, 0x1431, 0x1245, 0x1341, 0x1111, 0x10142, 0x1224, 0x10122,
    0x3142, 0x10125, 0x4411, 0x11012, 0x2224, 0x11101, 0x1135, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x2110, 0x11110, 0x2110,
    0x2210, 0x4111, 0x1210, 0x1121, 0x2210, 0x11012, 0x2220, 0x11101,
    0x1111, 0x11110, 0x2211, 0x11101, 0x2122, 0x11012, 0x1111, 0x11011,
    0x1144, 0x11110, 0x2111, 0x11101, 0x2120, 0x11012, 0x3210, 0x11014,
    0x1210, 0x1132, 0x2110, 0x2331, 0x2210, 0x4414, 0x1210, 0x1111,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11101, 0x11110, 0x11012, 0x11110, 0x11011, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x2110,
    0x11110, 0x2210, 0x11110, 0x2211, 0x2110, 0x4322, 0x4210, 0x4444,
    0x11110, 0x11110, 0x11110, 0x11110, 0x10111, 0x11110, 0x11012, 0x11110,
    0x11101, 0x2110, 0x11011, 0x2210, 0x1113, 0x2321, 0x5322, 0x1234,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x10111, 0x11110,
    0x11012, 0x11110, 0x11101, 0x11110, 0x11101, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x2110, 0x11110, 0x2120,
    0x11110, 0x3321, 0x11110, 0x1441, 0x11110, 0x10141, 0x11110, 0x11020,
    0x4320, 0x2455, 0x4411, 0x2234, 0x2431, 0x4442, 0x1243, 0x3541,
    0x4535, 0x1234, 0x2424, 0x2111, 0x1111, 0x1111, 0x1210, 0x4311,
    0x2342, 0x10112, 0x1112, 0x11101, 0x10123, 0x11110, 0x11012, 0x11110,
    0x1121, 0x10111, 0x4112, 0x10123, 0x2421, 0x1212, 0x1245, 0x4531,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11101, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x2110, 0x11110, 0x1120, 0x11110, 0x2221,
    0x1210, 0x2211, 0x2110, 0x4212, 0x2110, 0x2211, 0x2210, 0x4121,
    0x2220, 0x1111, 0x1221, 0x1111, 0x1111, 0x1120, 0x11011, 0x2221,
    0x2111, 0x3311, 0x1245, 0x1112, 0x2111, 0x11102, 0x3224, 0x11101,
    0x1342, 0x11110, 0x10111, 0x11110, 0x1122, 0x11110, 0x2445, 0x2110,
    0x11012, 0x11110, 0x10143, 0x11110, 0x1141, 0x11110, 0x1211, 0x11110,
    0x1520, 0x11110, 0x1341, 0x11110, 0x1211, 0x11110, 0x1242, 0x11110,
    0x11110, 0x3231, 0x11110, 0x3231, 0x11110, 0x1120, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11011, 0x3211, 0x11101, 0x1111, 0x11110, 0x1221, 0x11110, 0x3121,
    0x11110, 0x4120, 0x11110, 0x1120, 0x11110, 0x4211, 0x11110, 0x1111,
    0x1124, 0x2110, 0x2211, 0x2110, 0x1222, 0x11110, 0x10114, 0x11110,
    0x10114, 0x11110, 0x1233, 0x11110, 0x2441, 0x11101, 0x1111, 0x11101,
    0x1354, 0x11110, 0x1444, 0x11110, 0x10111, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x2110, 0x11110, 0x3210, 0x11110, 0x4120,
    0x11110, 0x1120, 0x11110, 0x10121, 0x2110, 0x11012, 0x2120, 0x10112,
    0x3221, 0x1134, 0x4444, 0x3224, 0x4554, 0x3422, 0x2344, 0x1122,
    0x11110, 0x11110, 0x11110, 0x1120, 0x11110, 0x10121, 0x2110, 0x11012,
    0x3211, 0x11012, 0x2345, 0x11101, 0x1122, 0x11110, 0x11011, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x4311, 0x1210, 0x2432, 0x3220, 0x5353, 0x4420, 0x4241,
    0x1420, 0x1120, 0x10210, 0x1120, 0x11110, 0x1211, 0x2110, 0x1111,
    0x4422, 0x1234, 0x5411, 0x10123, 0x2344, 0x11011, 0x1112, 0x1111,
    0x1221, 0x2341, 0x2111, 0x1224, 0x4543, 0x4112, 0x1122, 0x3121,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11101, 0x11110,
    0x11101, 0x11110, 0x11012, 0x11110, 0x11015, 0x11110, 0x11014, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x1210, 0x11110, 0x2220, 0x11110, 0x2320,
    0x2110, 0x1212, 0x2210, 0x1112, 0x2210, 0x2112, 0x2220, 0x1111,
    0x1121, 0x2101, 0x1111, 0x1210, 0x10112, 0x2210, 0x11013, 0x1210,
    0x4542, 0x1212, 0x1122, 0x1221, 0x2441, 0x1132, 0x4211, 0x2013,
    0x1111, 0x4201, 0x1211, 0x4111, 0x1522, 0x3242, 0x1432, 0x1354,
    0x11013, 0x11110, 0x10123, 0x11110, 0x10144, 0x11110, 0x10142, 0x11110,
    0x10125, 0x11110, 0x11013, 0x11110, 0x11101, 0x11110, 0x11110, 0x11110,
    0x11110, 0x2320, 0x11110, 0x1210, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11013, 0x1120, 0x11101, 0x1211, 0x2110, 0x10122, 0x2110, 0x11012,
    0x2110, 0x10111, 0x1210, 0x10122, 0x2220, 0x1221, 0x1120, 0x1111,
    0x1111, 0x1444, 0x1201, 0x10111, 0x4320, 0x11101, 0x4420, 0x11101,
    0x2120, 0x11013, 0x3120, 0x10123, 0x1421, 0x1244, 0x1111, 0x1111,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x10111, 0x2110, 0x11012, 0x2210, 0x11101, 0x2211, 0x11011,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x10111, 0x2110, 0x11012, 0x2210, 0x11101,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x2110, 0x11110, 0x4210, 0x11110, 0x4320, 0x11110, 0x4411,
    0x2110, 0x2431, 0x2120, 0x1243, 0x3321, 0x4535, 0x1441, 0x2424,
    0x4322, 0x1113, 0x4444, 0x5322, 0x2455, 0x2342, 0x2234, 0x1112,
    0x4442, 0x1123, 0x3541, 0x1112, 0x1234, 0x5431, 0x1111, 0x1221,
    0x2321, 0x11101, 0x1234, 0x11110, 0x10112, 0x11110, 0x1111, 0x11011,
    0x3411, 0x11012, 0x2242, 0x10131, 0x1124, 0x1453, 0x1211, 0x2322,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11011, 0x11110,
    0x1141, 0x1111, 0x11020, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x2210, 0x5421, 0x2110, 0x2211, 0x2110, 0x4121, 0x11110, 0x1111,
    0x2110, 0x1111, 0x1210, 0x1111, 0x2220, 0x2221, 0x2320, 0x3211,
    0x2124, 0x3111, 0x2111, 0x1112, 0x3224, 0x2101, 0x1342, 0x2110,
    0x10111, 0x2110, 0x1122, 0x1120, 0x2445, 0x4211, 0x1124, 0x5411,
    0x10123, 0x11110, 0x1443, 0x11110, 0x1421, 0x11110, 0x1254, 0x11110,
    0x10134, 0x11110, 0x10122, 0x11110, 0x11012, 0x11110, 0x11013, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x2320, 0x1111, 0x1210, 0x1221, 0x11110, 0x1221, 0x11110, 0x10121,
    0x11110, 0x1111, 0x11110, 0x2211, 0x2110, 0x2122, 0x2110, 0x1111,
    0x2111, 0x4411, 0x2201, 0x1111, 0x3210, 0x11014, 0x4210, 0x11014,
    0x1210, 0x1132, 0x2101, 0x2331, 0x2112, 0x4414, 0x1111, 0x1111,
    0x11014, 0x11110, 0x11101, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11101, 0x11110, 0x11012, 0x11110, 0x11011, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x1210, 0x11110, 0x2220, 0x11110, 0x4441, 0x2110, 0x5543,
    0x11110, 0x11110, 0x1210, 0x11101, 0x1220, 0x11110, 0x10121, 0x11110,
    0x1122, 0x11110, 0x1343, 0x2111, 0x2244, 0x3453, 0x4224, 0x1223,
    0x11110, 0x11110, 0x11110, 0x11110, 0x1210, 0x11101, 0x1220, 0x11110,
    0x10121, 0x11110, 0x10123, 0x11110, 0x11012, 0x11110, 0x11101, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x2110, 0x11110, 0x2210,
    0x11110, 0x4210, 0x11110, 0x4210, 0x11110, 0x2110, 0x11110, 0x11110,
    0x1210, 0x3444, 0x3120, 0x4224, 0x4321, 0x4112, 0x3533, 0x3445,
    0x2414, 0x1124, 0x1201, 0x1111, 0x2110, 0x3121, 0x2110, 0x2111,
    0x1222, 0x10111, 0x2344, 0x11101, 0x1235, 0x11110, 0x1112, 0x1111,
    0x1121, 0x1234, 0x4211, 0x3122, 0x2454, 0x5311, 0x1112, 0x2212,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11101, 0x11110, 0x11014, 0x11110, 0x10123, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x2110, 0x11110, 0x2210, 0x11110, 0x3210,
    0x11110, 0x2121, 0x2110, 0x2211, 0x2110, 0x4121, 0x2210, 0x1111,
    0x1220, 0x1120, 0x1111, 0x1111, 0x1122, 0x2221, 0x10132, 0x3211,
    0x2454, 0x1121, 0x2111, 0x11012, 0x3224, 0x11101, 0x1342, 0x2110,
    0x10111, 0x2110, 0x1122, 0x2111, 0x2445, 0x2421, 0x1124, 0x3541,
    0x1231, 0x11110, 0x1441, 0x11110, 0x1421, 0x11110, 0x1254, 0x11110,
    0x10134, 0x11110, 0x11012, 0x11110, 0x11101, 0x11110, 0x11101, 0x11110,
    0x11110, 0x3210, 0x11110, 0x2110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x10132, 0x1111, 0x2011, 0x1122, 0x2210, 0x11012, 0x2210, 0x11101,
    0x1120, 0x11101, 0x2120, 0x11012, 0x1221, 0x1122, 0x1111, 0x1111,
    0x2111, 0x4441, 0x2220, 0x1111, 0x1431, 0x11110, 0x1441, 0x11110,
    0x1321, 0x11101, 0x3311, 0x11012, 0x4142, 0x10124, 0x1111, 0x10111,
    0x11101, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110,
    0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110, 0x11110
};

inline static void load_Bonebeast_sheet(u16 start_tile, u8 palette_pos)
{
    load_palette(Bonebeast_palette, 5, palette_pos);
    load_sprite_4bpp(Bonebeast_sheet, 96, start_tile);
}

#endif