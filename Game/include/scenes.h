#ifndef __SCENES_H__
#define __SCENES_H__

#include "gba_types.h"

typedef enum {
    NONE_SCENE = 0,
    START_SCENE = 1,
    TEST1_SCENE = 2,
    TEST2_SCENE = 3
} SceneId;

void load_scene(SceneId scene_id);
void update_current_scene();

#endif