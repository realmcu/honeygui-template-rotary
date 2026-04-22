/**
 * SubTab UI Implementation (Auto-generated, do not modify manually)
 * Generated at: 2026-04-22T08:44:09.631Z
 */
#include "SubTab_ui.h"
#include "../callbacks/SubTab_callbacks.h"
#include "../user/SubTab_user.h"
#include <stddef.h>

// Component handle definitions
gui_list_t *list_1 = NULL;
gui_win_t *win_4 = NULL;
gui_img_t *img_5 = NULL;
gui_win_t *win_5 = NULL;
gui_img_t *img_4 = NULL;
gui_img_t *img_35 = NULL;
gui_obj_t *btn_5 = NULL;
gui_img_t *img_72 = NULL;
gui_img_t *img_73 = NULL;
gui_img_t *img_74 = NULL;

// Toggle button callback functions

// btn_5 dual-state button callback
static bool btn_5_state = true;

void btn_5_toggle_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    
    // Toggle state
    btn_5_state = !btn_5_state;
    
    // Switch image based on state and call corresponding callback
    if (btn_5_state) {
        gui_img_set_src((gui_img_t *)btn_5, "/ac/ac_temp_b.bin", IMG_SRC_FILESYS);
    } else {
        gui_img_set_src((gui_img_t *)btn_5, "/ac/ac_speed_b.bin", IMG_SRC_FILESYS);
    }
    gui_fb_change();
}

// Get current state
bool btn_5_get_state(void)
{
    return btn_5_state;
}

// Set state (external call)
void btn_5_set_state(bool state)
{
    if (btn_5_state != state) {
        btn_5_state = state;
        
        if (state) {
            gui_img_set_src((gui_img_t *)btn_5, "/ac/ac_temp_b.bin", IMG_SRC_FILESYS);
        } else {
            gui_img_set_src((gui_img_t *)btn_5, "/ac/ac_speed_b.bin", IMG_SRC_FILESYS);
        }
    }
}
// List component note_design callback functions
// note_design callback function declaration
static void list_1_note_design(gui_obj_t *obj, void *param);

// note_design callback function implementation
static void list_1_note_design(gui_obj_t *obj, void *param)
{
    GUI_UNUSED(param);
    
    // Cast obj to gui_list_note_t * type
    gui_list_note_t *note = (gui_list_note_t *)obj;
    uint16_t index = note->index;
    
    // Create different list_item content based on index
    switch (index)
    {
    case 0:
    {
        // Create win_4 (hg_window)
        win_4 = gui_win_create((gui_obj_t *)note, "win_4", 81, 64, 251, 164);
        gui_obj_show((gui_obj_t *)win_4, true);
        // Create img_5 (hg_image)
        img_5 = gui_img_create_from_fs((gui_obj_t *)note, "img_5", "/home_14.bin", 200, 23, 50, 50);
        gui_obj_show((gui_obj_t *)img_5, true);
        break;
    }
    case 1:
    {
        // Create win_5 (hg_window)
        win_5 = gui_win_create((gui_obj_t *)note, "win_5", 26, -2, 100, 100);
        gui_obj_show((gui_obj_t *)win_5, true);
        // Create img_4 (hg_image)
        img_4 = gui_img_create_from_fs((gui_obj_t *)note, "img_4", "/home_14.bin", 342, 23, 50, 50);
        gui_obj_show((gui_obj_t *)img_4, true);
        // Create img_35 (hg_image)
        img_35 = gui_img_create_from_fs((gui_obj_t *)note, "img_35", "/home_14.bin", 81, 20, 50, 50);
        gui_obj_show((gui_obj_t *)img_35, true);
        break;
    }
    case 2:
    {
        // Create btn_5 (hg_button)
        btn_5 = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)note, "btn_5", "/ac/ac_speed_b.bin", 95, 0, 33, 67);
        if (btn_5_state) {
            gui_img_set_src((gui_img_t *)btn_5, "/ac/ac_temp_b.bin", IMG_SRC_FILESYS);
        }
        gui_obj_show((gui_obj_t *)btn_5, true);
        gui_obj_add_event_cb((gui_obj_t *)btn_5, btn_5_toggle_cb, GUI_EVENT_TOUCH_CLICKED, NULL);
        break;
    }
    case 3:
    {
        break;
    }
    case 4:
    {
        break;
    }
    default:
        break;
    }
}


// Create SubTabMainView (hg_view)
static void SubTabMainView_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void SubTabMainView_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    gui_view_switch_on_event(view, "RotaryTemplateMainView", SWITCH_OUT_TO_LEFT_USE_TRANSLATION, SWITCH_IN_FROM_RIGHT_USE_TRANSLATION, GUI_EVENT_TOUCH_CLICKED);


    // Create list_1 (hg_list)
    list_1 = gui_list_create((gui_obj_t *)view, "list_1", 0, 0, 480, 480, 96, 5, VERTICAL, list_1_note_design, NULL, false);
    gui_list_set_style(list_1, LIST_CLASSIC);
    gui_list_set_note_num(list_1, 5);
    gui_list_set_auto_align(list_1, true);
    gui_obj_show((gui_obj_t *)list_1, true);
}
GUI_VIEW_INSTANCE("SubTabMainView", false, SubTabMainView_switch_in, SubTabMainView_switch_out);

// Create view_1 (hg_view)
static void view_1_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void view_1_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    GUI_UNUSED(view);


    // Create img_72 (hg_image)
    img_72 = gui_img_create_from_fs((gui_obj_t *)view, "img_72", "/ac/num_9.bin", 189, 175, 81, 114);
    gui_img_set_quality((gui_img_t *)img_72, true);
    gui_obj_show((gui_obj_t *)img_72, true);

    // Create img_73 (hg_image)
    img_73 = gui_img_create_from_fs((gui_obj_t *)view, "img_73", "/ac/num_9.bin", 62, 210, 81, 114);
    gui_img_set_quality((gui_img_t *)img_73, true);
    gui_obj_show((gui_obj_t *)img_73, true);

    // Create img_74 (hg_image)
    img_74 = gui_img_create_from_fs((gui_obj_t *)view, "img_74", "/home_1222.bin", 243, 89, 60, 60);
    gui_obj_show((gui_obj_t *)img_74, true);
}
GUI_VIEW_INSTANCE("view_1", false, view_1_switch_in, view_1_switch_out);

// Create view_2 (hg_view)
static void view_2_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void view_2_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    GUI_UNUSED(view);
}
GUI_VIEW_INSTANCE("view_2", false, view_2_switch_in, view_2_switch_out);
