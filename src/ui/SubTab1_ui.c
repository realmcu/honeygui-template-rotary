/**
 * SubTab1 UI Implementation (Auto-generated, do not modify manually)
 * Generated at: 2026-04-22T08:44:09.645Z
 */
#include "SubTab1_ui.h"
#include "../callbacks/SubTab1_callbacks.h"
#include "../user/SubTab1_user.h"
#include <stddef.h>

// Component handle definitions
gui_img_t *img_76 = NULL;
gui_img_t *img_77 = NULL;


// Create SubTabMain1View (hg_view)
static void SubTabMain1View_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void SubTabMain1View_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    gui_view_switch_on_event(view, "RotaryTemplateMainView", SWITCH_OUT_TO_LEFT_USE_TRANSLATION, SWITCH_IN_FROM_RIGHT_USE_TRANSLATION, GUI_EVENT_TOUCH_CLICKED);


    // Create img_76 (hg_image)
    img_76 = gui_img_create_from_fs((gui_obj_t *)view, "img_76", "/home_12.bin", 156, 290, 50, 50);
    gui_obj_show((gui_obj_t *)img_76, true);

    // Create img_77 (hg_image)
    img_77 = gui_img_create_from_fs((gui_obj_t *)view, "img_77", "/home_15.bin", 331, 347, 60, 60);
    gui_obj_show((gui_obj_t *)img_77, true);
}
GUI_VIEW_INSTANCE("SubTabMain1View", false, SubTabMain1View_switch_in, SubTabMain1View_switch_out);
