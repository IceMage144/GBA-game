#include "gba_systemcalls.h"

#include "scenes.h"

int main()
{
    load_scene(TEST1_SCENE);

    while (true)
    {
        VBlankIntrWait();
        update_current_scene();
    }

    return 0;
}