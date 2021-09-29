#include "gba_systemcalls.h"

#include "scenes.h"
#include "simple_palette.h"

int main()
{
    load_simple_palette();
    load_scene(TEST1_SCENE);

    while (true)
    {
        VBlankIntrWait();
        update_current_scene();
    }

    return 0;
}