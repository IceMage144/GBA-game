#include "scenes.h"
#include "object.h"
#include "palette.h"
#include "sprite.h"

#include "scenes/start_scene.h"
#include "scenes/test1_scene.h"
#include "scenes/test2_scene.h"

static SceneId current_scene = NONE_SCENE;
static (*current_update_func)() = NULL;

void load_scene(SceneId scene_id)
{
    unload_scene(current_scene);
    current_scene = scene_id;
    switch (scene_id)
    {
        case START_SCENE:
            StartScene_load_scene();
            current_update_func = &StartScene_update_scene;
            break;
        case TEST1_SCENE:
            Test1Scene_load_scene();
            current_update_func = &Test1Scene_update_scene;
            break;
        case TEST2_SCENE:
            Test2Scene_load_scene();
            current_update_func = &Test2Scene_update_scene;
            break;
        default:
            current_update_func = NULL;
    }
}

void update_current_scene()
{
    if (current_update_func == NULL)
    {
        return ;
    }
    current_update_func();
}

void unload_scene(SceneId scene_id)
{
    clear_objattr_mem();
    clear_palette_mem();
    clear_sprite_mem();
}