/**
 * SubTab4 UI Implementation (Auto-generated, do not modify manually)
 * Generated at: 2026-04-22T08:44:09.651Z
 */
#include "SubTab4_ui.h"
#include "../callbacks/SubTab4_callbacks.h"
#include "../user/SubTab4_user.h"
#include <stddef.h>

// Component handle definitions
gui_img_t *img_78 = NULL;
gui_img_t *img_79 = NULL;
gui_text_t *lbl_6 = NULL;


// Create SubTabMain2View (hg_view)
static void SubTabMain2View_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void SubTabMain2View_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    gui_view_switch_on_event(view, "RotaryTemplateMainView", SWITCH_OUT_TO_LEFT_USE_TRANSLATION, SWITCH_IN_FROM_RIGHT_USE_TRANSLATION, GUI_EVENT_TOUCH_CLICKED);


    // Create img_78 (hg_image)
    img_78 = gui_img_create_from_fs((gui_obj_t *)view, "img_78", "/home_13.bin", 244, 232, 61, 46);
    gui_obj_show((gui_obj_t *)img_78, true);

    // Create img_79 (hg_image)
    img_79 = gui_img_create_from_fs((gui_obj_t *)view, "img_79", "/home_14.bin", 131, 357, 50, 50);
    gui_obj_show((gui_obj_t *)img_79, true);

    // Create lbl_6 (hg_label)
    lbl_6 = gui_text_create((gui_obj_t *)view, "lbl_6", 192, 167, 150, 30);
    gui_text_set((gui_text_t *)lbl_6, "Label", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 5, 16);
    gui_text_type_set((gui_text_t *)lbl_6, "//Baloo2_Regular_size16_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)lbl_6, LEFT);
}
GUI_VIEW_INSTANCE("SubTabMain2View", false, SubTabMain2View_switch_in, SubTabMain2View_switch_out);
