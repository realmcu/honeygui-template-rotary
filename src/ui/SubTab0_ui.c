/**
 * SubTab0 UI Implementation (Auto-generated, do not modify manually)
 * Generated at: 2026-04-22T08:44:09.638Z
 */
#include "SubTab0_ui.h"
#include "../callbacks/SubTab0_callbacks.h"
#include "../user/SubTab0_user.h"
#include <stddef.h>

// Component handle definitions
gui_img_t *img_80 = NULL;


// Create SubTabMain0View (hg_view)
static void SubTabMain0View_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void SubTabMain0View_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    gui_view_switch_on_event(view, "RotaryTemplateMainView", SWITCH_OUT_TO_LEFT_USE_TRANSLATION, SWITCH_IN_FROM_RIGHT_USE_TRANSLATION, GUI_EVENT_TOUCH_CLICKED);


    // Create img_80 (hg_image)
    img_80 = gui_img_create_from_fs((gui_obj_t *)view, "img_80", "/home_16.bin", 205, 248, 50, 50);
    gui_obj_show((gui_obj_t *)img_80, true);
}
GUI_VIEW_INSTANCE("SubTabMain0View", false, SubTabMain0View_switch_in, SubTabMain0View_switch_out);
