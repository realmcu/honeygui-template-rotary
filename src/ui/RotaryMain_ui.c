/**
 * RotaryMain UI Implementation (Auto-generated, do not modify manually)
 * Generated at: 2026-04-22T08:44:09.567Z
 */
#include "RotaryMain_ui.h"
#include "../callbacks/RotaryMain_callbacks.h"
#include "../user/RotaryMain_user.h"
#include <stddef.h>

// Component handle definitions
gui_img_t *hg_image_1770375807980_dxhf = NULL;
gui_img_t *hg_image_1770607273521_70ob = NULL;
gui_img_t *hg_image_1770607673557_iiv2 = NULL;
gui_img_t *hg_image_1770607676005_3nc2 = NULL;
gui_img_t *hg_image_1770607679223_o1zm = NULL;
gui_img_t *hg_image_1770607688255_n4di = NULL;
gui_img_t *hg_image_1770607691358_qraa = NULL;
gui_img_t *hg_image_1770607798406_9ndb = NULL;
gui_img_t *img_md_home_r = NULL;
gui_img_t *img_md_home_m = NULL;
gui_img_t *img_txt_home = NULL;
gui_list_t *lst_mode = NULL;
gui_img_t *img_md_home = NULL;
gui_img_t *img_md_out = NULL;
gui_img_t *img_md_movie = NULL;
gui_img_t *img_md_game = NULL;
gui_img_t *hg_image_1772693453806_vik8 = NULL;
gui_win_t *win_ac_bg_mid = NULL;
gui_img_t *img_ac_bg_mid = NULL;
gui_win_t *win_ac_temp = NULL;
gui_list_t *lst_unit = NULL;
gui_img_t *img_unit_9 = NULL;
gui_img_t *img_unit_0 = NULL;
gui_img_t *img_unit_1 = NULL;
gui_img_t *img_unit_2 = NULL;
gui_img_t *img_unit_3 = NULL;
gui_img_t *img_unit_4 = NULL;
gui_img_t *img_unit_5 = NULL;
gui_img_t *img_unit_6 = NULL;
gui_img_t *img_unit_7 = NULL;
gui_img_t *img_unit_8 = NULL;
gui_list_t *lst_ten = NULL;
gui_img_t *img_ten_1 = NULL;
gui_img_t *img_ten_2 = NULL;
gui_img_t *img_ten_3 = NULL;
gui_img_t *img_ac_degree = NULL;
gui_win_t *win_ac_fan = NULL;
gui_list_t *lst_fan = NULL;
gui_img_t *img_29 = NULL;
gui_img_t *img_30 = NULL;
gui_img_t *img_31 = NULL;
gui_img_t *img_32 = NULL;
gui_img_t *img_33 = NULL;
gui_img_t *img_28 = NULL;
gui_win_t *win_ac_bg_up = NULL;
gui_img_t *img_ac_bg_up = NULL;
gui_win_t *win_ac_bg_dn = NULL;
gui_img_t *img_ac_bg_dn = NULL;
gui_win_t *win_mode = NULL;
gui_img_t *img_mode_bg = NULL;
gui_img_t *img_hot_df = NULL;
gui_img_t *img_hot = NULL;
gui_img_t *img_cold_df = NULL;
gui_img_t *img_cold = NULL;
gui_img_t *img_fresh_df = NULL;
gui_img_t *img_fresh = NULL;
gui_img_t *img_mode_select = NULL;
gui_obj_t *btn_ac = NULL;
gui_img_t *img_white = NULL;
gui_img_t *img_yellow = NULL;
gui_win_t *win_temp = NULL;
gui_img_t *img_lt_bar_tmp = NULL;
gui_list_t *list_bar_temp = NULL;
gui_img_t *img_temp_knob = NULL;
gui_win_t *win_lgtn = NULL;
gui_img_t *img_lt_bar_0 = NULL;
gui_list_t *lst_lt_bar_0 = NULL;
gui_img_t *img_55 = NULL;
gui_img_t *img_light = NULL;
gui_img_t *img_56 = NULL;
gui_img_t *img_clr_white = NULL;
gui_img_t *img_clr_0 = NULL;
gui_img_t *img_clr_1 = NULL;
gui_img_t *img_clr_2 = NULL;
gui_img_t *img_clr_3 = NULL;
gui_img_t *img_clr_4 = NULL;
gui_img_t *img_clr_5 = NULL;
gui_win_t *win_clr = NULL;
gui_img_t *img_lt_bar_clr = NULL;
gui_list_t *list_bar_clr = NULL;
gui_img_t *img_clr_knob = NULL;
gui_win_t *win_lgtnn = NULL;
gui_img_t *img_lt_bar_1 = NULL;
gui_list_t *lst_lt_bar_1 = NULL;
gui_img_t *img_59 = NULL;
gui_img_t *img_57 = NULL;
gui_img_t *img_light_clr = NULL;
gui_img_t *img_cur = NULL;
gui_img_t *img_cur_bg = NULL;
gui_obj_t *btn_open = NULL;
gui_obj_t *btn_close = NULL;
gui_obj_t *btn_stop = NULL;
gui_particle_widget_t *ptcl_1 = NULL;
gui_text_t *lbl_1 = NULL;
gui_text_t *lbl_3 = NULL;
gui_text_t *lbl_4 = NULL;
gui_text_t *lbl_5 = NULL;
gui_text_t *lbl_7 = NULL;
gui_img_t *img_81 = NULL;
gui_img_t *img_82 = NULL;
gui_img_t *hg_image_1772785447547_wk17 = NULL;
gui_img_t *hg_image_1772785452162_tcmn = NULL;
gui_img_t *hg_image_1772785456571_pymf = NULL;
gui_img_t *hg_image_1772785463497_fy3r = NULL;
gui_img_t *hg_image_1772785479452_2ui7 = NULL;
gui_img_t *hg_image_1772785490027_q67d = NULL;
gui_img_t *hg_image_1772785504892_6b9q = NULL;
gui_text_t *lbl_2 = NULL;

// Toggle button callback functions

// btn_ac dual-state button callback
static bool btn_ac_state = true;

void btn_ac_toggle_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    
    // Toggle state
    btn_ac_state = !btn_ac_state;
    
    // Switch image based on state and call corresponding callback
    if (btn_ac_state) {
        gui_img_set_src((gui_img_t *)btn_ac, "/ac/ac_temp_b.bin", IMG_SRC_FILESYS);
        extern void ac_btn_sw_fan_cb(void *obj, gui_event_t *e);
        ac_btn_sw_fan_cb(obj, e);
    } else {
        gui_img_set_src((gui_img_t *)btn_ac, "/ac/ac_speed_b.bin", IMG_SRC_FILESYS);
        extern void ac_btn_sw_fan_cb(void *obj, gui_event_t *e);
        ac_btn_sw_fan_cb(obj, e);
    }
    gui_fb_change();
}

// Get current state
bool btn_ac_get_state(void)
{
    return btn_ac_state;
}

// Set state (external call)
void btn_ac_set_state(bool state)
{
    if (btn_ac_state != state) {
        btn_ac_state = state;
        
        if (state) {
            gui_img_set_src((gui_img_t *)btn_ac, "/ac/ac_temp_b.bin", IMG_SRC_FILESYS);
        extern void ac_btn_sw_fan_cb(void *obj, gui_event_t *e);
        ac_btn_sw_fan_cb(NULL, NULL);
        } else {
            gui_img_set_src((gui_img_t *)btn_ac, "/ac/ac_speed_b.bin", IMG_SRC_FILESYS);
        extern void ac_btn_sw_fan_cb(void *obj, gui_event_t *e);
        ac_btn_sw_fan_cb(NULL, NULL);
        }
    }
}
// Normal button press/release callback functions

// btn_open button press callback - switch to highlight image
void btn_open_press_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_img_set_src((gui_img_t *)btn_open, "/curtain/cur_open_hl.bin", IMG_SRC_FILESYS);
    gui_fb_change();
}

// btn_open button release callback - restore default image and trigger click
void btn_open_release_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_img_set_src((gui_img_t *)btn_open, "/curtain/cur_open.bin", IMG_SRC_FILESYS);
    gui_fb_change();
    extern void curtn_click_open_cb(void *obj, gui_event_t *e);
    curtn_click_open_cb(obj, e);
}

// btn_close button press callback - switch to highlight image
void btn_close_press_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_img_set_src((gui_img_t *)btn_close, "/curtain/cur_close_hl.bin", IMG_SRC_FILESYS);
    gui_fb_change();
}

// btn_close button release callback - restore default image and trigger click
void btn_close_release_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_img_set_src((gui_img_t *)btn_close, "/curtain/cur_close.bin", IMG_SRC_FILESYS);
    gui_fb_change();
    extern void curtn_click_close_cb(void *obj, gui_event_t *e);
    curtn_click_close_cb(obj, e);
}

// btn_stop button press callback - switch to highlight image
void btn_stop_press_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_img_set_src((gui_img_t *)btn_stop, "/curtain/cur_pause_hl.bin", IMG_SRC_FILESYS);
    gui_fb_change();
}

// btn_stop button release callback - restore default image and trigger click
void btn_stop_release_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_img_set_src((gui_img_t *)btn_stop, "/curtain/cur_pause.bin", IMG_SRC_FILESYS);
    gui_fb_change();
    extern void curtn_click_stop_cb(void *obj, gui_event_t *e);
    curtn_click_stop_cb(obj, e);
}
// List component note_design callback functions
// note_design callback function declaration
static void lst_mode_note_design(gui_obj_t *obj, void *param);

// note_design callback function implementation
static void lst_mode_note_design(gui_obj_t *obj, void *param)
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
        break;
    }
    case 1:
    {
        break;
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        // Create img_md_home (hg_image)
        img_md_home = gui_img_create_from_fs((gui_obj_t *)note, "img_md_home", "/mode/md_home_s.bin", 17, 0, 60, 61);
        gui_img_set_mode((gui_img_t *)img_md_home, IMG_BYPASS_MODE);
        gui_obj_show((gui_obj_t *)img_md_home, true);
        break;
    }
    case 4:
    {
        // Create img_md_out (hg_image)
        img_md_out = gui_img_create_from_fs((gui_obj_t *)note, "img_md_out", "/mode/md_out_s.bin", 17, 4, 51, 51);
        gui_img_set_mode((gui_img_t *)img_md_out, IMG_BYPASS_MODE);
        gui_obj_show((gui_obj_t *)img_md_out, true);
        break;
    }
    case 5:
    {
        // Create img_md_movie (hg_image)
        img_md_movie = gui_img_create_from_fs((gui_obj_t *)note, "img_md_movie", "/mode/md_movie_s.bin", 17, 0, 60, 60);
        gui_img_set_mode((gui_img_t *)img_md_movie, IMG_BYPASS_MODE);
        gui_obj_show((gui_obj_t *)img_md_movie, true);
        break;
    }
    case 6:
    {
        // Create img_md_game (hg_image)
        img_md_game = gui_img_create_from_fs((gui_obj_t *)note, "img_md_game", "/mode/md_game_s.bin", 17, 4, 60, 47);
        gui_img_set_mode((gui_img_t *)img_md_game, IMG_BYPASS_MODE);
        gui_obj_show((gui_obj_t *)img_md_game, true);
        break;
    }
    case 7:
    {
        break;
    }
    case 8:
    {
        break;
    }
    case 9:
    {
        break;
    }
    default:
        break;
    }
}

// note_design callback function declaration
static void lst_unit_note_design(gui_obj_t *obj, void *param);

// note_design callback function implementation
static void lst_unit_note_design(gui_obj_t *obj, void *param)
{
    GUI_UNUSED(param);
    
    // Cast obj to gui_list_note_t * type
    gui_list_note_t *note = (gui_list_note_t *)obj;
    // Loop scroll mode: handle negative index
    int16_t index = note->index;
    gui_list_t *list = (gui_list_t *)obj->parent;
    uint8_t note_num = list->note_num;
    index %= note_num;
    index += note_num;
    index %= note_num;
    
    // Create different list_item content based on index
    switch (index)
    {
    case 0:
    {
        // Create img_unit_9 (hg_image)
        img_unit_9 = gui_img_create_from_fs((gui_obj_t *)note, "img_unit_9", "/ac/num_9.bin", 15, 0, 81, 114);
        gui_img_set_quality((gui_img_t *)img_unit_9, true);
        gui_obj_show((gui_obj_t *)img_unit_9, true);
        break;
    }
    case 1:
    {
        // Create img_unit_0 (hg_image)
        img_unit_0 = gui_img_create_from_fs((gui_obj_t *)note, "img_unit_0", "/ac/num_0.bin", 12, 0, 86, 114);
        gui_obj_show((gui_obj_t *)img_unit_0, true);
        break;
    }
    case 2:
    {
        // Create img_unit_1 (hg_image)
        img_unit_1 = gui_img_create_from_fs((gui_obj_t *)note, "img_unit_1", "/ac/num_1.bin", 30, 1, 44, 113);
        gui_obj_show((gui_obj_t *)img_unit_1, true);
        break;
    }
    case 3:
    {
        // Create img_unit_2 (hg_image)
        img_unit_2 = gui_img_create_from_fs((gui_obj_t *)note, "img_unit_2", "/ac/num_2.bin", 19, 2, 73, 112);
        gui_obj_show((gui_obj_t *)img_unit_2, true);
        break;
    }
    case 4:
    {
        // Create img_unit_3 (hg_image)
        img_unit_3 = gui_img_create_from_fs((gui_obj_t *)note, "img_unit_3", "/ac/num_3.bin", 18, 0, 75, 114);
        gui_obj_show((gui_obj_t *)img_unit_3, true);
        break;
    }
    case 5:
    {
        // Create img_unit_4 (hg_image)
        img_unit_4 = gui_img_create_from_fs((gui_obj_t *)note, "img_unit_4", "/ac/num_4.bin", 10, 2, 91, 112);
        gui_obj_show((gui_obj_t *)img_unit_4, true);
        break;
    }
    case 6:
    {
        // Create img_unit_5 (hg_image)
        img_unit_5 = gui_img_create_from_fs((gui_obj_t *)note, "img_unit_5", "/ac/num_5.bin", 17, 2, 76, 112);
        gui_obj_show((gui_obj_t *)img_unit_5, true);
        break;
    }
    case 7:
    {
        // Create img_unit_6 (hg_image)
        img_unit_6 = gui_img_create_from_fs((gui_obj_t *)note, "img_unit_6", "/ac/num_6.bin", 15, 0, 81, 114);
        gui_obj_show((gui_obj_t *)img_unit_6, true);
        break;
    }
    case 8:
    {
        // Create img_unit_7 (hg_image)
        img_unit_7 = gui_img_create_from_fs((gui_obj_t *)note, "img_unit_7", "/ac/num_7.bin", 18, 3, 75, 111);
        gui_obj_show((gui_obj_t *)img_unit_7, true);
        break;
    }
    case 9:
    {
        // Create img_unit_8 (hg_image)
        img_unit_8 = gui_img_create_from_fs((gui_obj_t *)note, "img_unit_8", "/ac/num_8.bin", 14, 0, 82, 114);
        gui_obj_show((gui_obj_t *)img_unit_8, true);
        break;
    }
    default:
        break;
    }
}

// note_design callback function declaration
static void lst_ten_note_design(gui_obj_t *obj, void *param);

// note_design callback function implementation
static void lst_ten_note_design(gui_obj_t *obj, void *param)
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
        // Create img_ten_1 (hg_image)
        img_ten_1 = gui_img_create_from_fs((gui_obj_t *)note, "img_ten_1", "/ac/num_1.bin", 32, 0, 44, 113);
        gui_img_set_quality((gui_img_t *)img_ten_1, true);
        gui_obj_show((gui_obj_t *)img_ten_1, true);
        break;
    }
    case 1:
    {
        // Create img_ten_2 (hg_image)
        img_ten_2 = gui_img_create_from_fs((gui_obj_t *)note, "img_ten_2", "/ac/num_2.bin", 21, 0, 73, 112);
        gui_img_set_quality((gui_img_t *)img_ten_2, true);
        gui_obj_show((gui_obj_t *)img_ten_2, true);
        break;
    }
    case 2:
    {
        // Create img_ten_3 (hg_image)
        img_ten_3 = gui_img_create_from_fs((gui_obj_t *)note, "img_ten_3", "/ac/num_3.bin", 20, 0, 75, 114);
        gui_img_set_quality((gui_img_t *)img_ten_3, true);
        gui_obj_show((gui_obj_t *)img_ten_3, true);
        break;
    }
    default:
        break;
    }
}

// note_design callback function declaration
static void lst_fan_note_design(gui_obj_t *obj, void *param);

// note_design callback function implementation
static void lst_fan_note_design(gui_obj_t *obj, void *param)
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
        // Create img_29 (hg_image)
        img_29 = gui_img_create_from_fs((gui_obj_t *)note, "img_29", "/ac/num_1.bin", 14, 0, 44, 113);
        gui_img_set_quality((gui_img_t *)img_29, true);
        gui_img_translate((gui_img_t *)img_29, 22.0f, 56.0f);
        gui_img_set_focus((gui_img_t *)img_29, 22.0f, 56.0f);
        gui_obj_show((gui_obj_t *)img_29, true);
        break;
    }
    case 1:
    {
        // Create img_30 (hg_image)
        img_30 = gui_img_create_from_fs((gui_obj_t *)note, "img_30", "/ac/num_2.bin", 3, 0, 73, 112);
        gui_obj_show((gui_obj_t *)img_30, true);
        break;
    }
    case 2:
    {
        // Create img_31 (hg_image)
        img_31 = gui_img_create_from_fs((gui_obj_t *)note, "img_31", "/ac/num_3.bin", 0, 0, 75, 114);
        gui_obj_show((gui_obj_t *)img_31, true);
        break;
    }
    case 3:
    {
        // Create img_32 (hg_image)
        img_32 = gui_img_create_from_fs((gui_obj_t *)note, "img_32", "/ac/num_4.bin", -2, 0, 91, 112);
        gui_obj_show((gui_obj_t *)img_32, true);
        break;
    }
    case 4:
    {
        // Create img_33 (hg_image)
        img_33 = gui_img_create_from_fs((gui_obj_t *)note, "img_33", "/ac/num_5.bin", 0, 0, 76, 112);
        gui_obj_show((gui_obj_t *)img_33, true);
        break;
    }
    default:
        break;
    }
}

// note_design callback function declaration
static void list_bar_temp_note_design(gui_obj_t *obj, void *param);

// note_design callback function implementation
static void list_bar_temp_note_design(gui_obj_t *obj, void *param)
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
        break;
    }
    case 1:
    {
        break;
    }
    case 2:
    {
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
    case 5:
    {
        break;
    }
    case 6:
    {
        break;
    }
    case 7:
    {
        break;
    }
    case 8:
    {
        break;
    }
    case 9:
    {
        break;
    }
    case 10:
    {
        break;
    }
    case 11:
    {
        break;
    }
    case 12:
    {
        break;
    }
    case 13:
    {
        break;
    }
    case 14:
    {
        break;
    }
    case 15:
    {
        break;
    }
    case 16:
    {
        break;
    }
    case 17:
    {
        break;
    }
    case 18:
    {
        break;
    }
    case 19:
    {
        break;
    }
    case 20:
    {
        break;
    }
    case 21:
    {
        break;
    }
    case 22:
    {
        // Create img_temp_knob (hg_image)
        img_temp_knob = gui_img_create_from_fs((gui_obj_t *)note, "img_temp_knob", "/light/knob.bin", 4, 0, 20, 20);
        gui_img_translate((gui_img_t *)img_temp_knob, 10.0f, 20.0f);
        gui_img_set_focus((gui_img_t *)img_temp_knob, 10.0f, 20.0f);
        gui_obj_show((gui_obj_t *)img_temp_knob, true);
        break;
    }
    case 23:
    {
        break;
    }
    case 24:
    {
        break;
    }
    case 25:
    {
        break;
    }
    case 26:
    {
        break;
    }
    case 27:
    {
        break;
    }
    case 28:
    {
        break;
    }
    case 29:
    {
        break;
    }
    case 30:
    {
        break;
    }
    case 31:
    {
        break;
    }
    case 32:
    {
        break;
    }
    case 33:
    {
        break;
    }
    case 34:
    {
        break;
    }
    case 35:
    {
        break;
    }
    case 36:
    {
        break;
    }
    case 37:
    {
        break;
    }
    case 38:
    {
        break;
    }
    case 39:
    {
        break;
    }
    case 40:
    {
        break;
    }
    case 41:
    {
        break;
    }
    case 42:
    {
        break;
    }
    case 43:
    {
        break;
    }
    case 44:
    {
        break;
    }
    case 45:
    {
        break;
    }
    case 46:
    {
        break;
    }
    default:
        break;
    }
}

// note_design callback function declaration
static void lst_lt_bar_0_note_design(gui_obj_t *obj, void *param);

// note_design callback function implementation
static void lst_lt_bar_0_note_design(gui_obj_t *obj, void *param)
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
        break;
    }
    case 1:
    {
        break;
    }
    case 2:
    {
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
    case 5:
    {
        break;
    }
    case 6:
    {
        break;
    }
    case 7:
    {
        break;
    }
    case 8:
    {
        break;
    }
    case 9:
    {
        break;
    }
    case 10:
    {
        break;
    }
    case 11:
    {
        break;
    }
    case 12:
    {
        break;
    }
    case 13:
    {
        break;
    }
    case 14:
    {
        break;
    }
    case 15:
    {
        break;
    }
    case 16:
    {
        break;
    }
    case 17:
    {
        break;
    }
    case 18:
    {
        break;
    }
    case 19:
    {
        break;
    }
    case 20:
    {
        break;
    }
    case 21:
    {
        break;
    }
    case 22:
    {
        break;
    }
    case 23:
    {
        break;
    }
    case 24:
    {
        // Create img_55 (hg_image)
        img_55 = gui_img_create_from_fs((gui_obj_t *)note, "img_55", "/light/knob.bin", -20, 0, 20, 20);
        gui_obj_show((gui_obj_t *)img_55, false);
        break;
    }
    case 25:
    {
        break;
    }
    case 26:
    {
        break;
    }
    case 27:
    {
        break;
    }
    case 28:
    {
        break;
    }
    case 29:
    {
        break;
    }
    case 30:
    {
        break;
    }
    case 31:
    {
        break;
    }
    case 32:
    {
        break;
    }
    case 33:
    {
        break;
    }
    case 34:
    {
        break;
    }
    case 35:
    {
        break;
    }
    case 36:
    {
        break;
    }
    case 37:
    {
        break;
    }
    case 38:
    {
        break;
    }
    case 39:
    {
        break;
    }
    case 40:
    {
        break;
    }
    case 41:
    {
        break;
    }
    case 42:
    {
        break;
    }
    case 43:
    {
        break;
    }
    case 44:
    {
        break;
    }
    case 45:
    {
        break;
    }
    case 46:
    {
        break;
    }
    default:
        break;
    }
}

// note_design callback function declaration
static void list_bar_clr_note_design(gui_obj_t *obj, void *param);

// note_design callback function implementation
static void list_bar_clr_note_design(gui_obj_t *obj, void *param)
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
        break;
    }
    case 1:
    {
        break;
    }
    case 2:
    {
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
    case 5:
    {
        break;
    }
    case 6:
    {
        break;
    }
    case 7:
    {
        break;
    }
    case 8:
    {
        break;
    }
    case 9:
    {
        break;
    }
    case 10:
    {
        break;
    }
    case 11:
    {
        break;
    }
    case 12:
    {
        break;
    }
    case 13:
    {
        break;
    }
    case 14:
    {
        break;
    }
    case 15:
    {
        break;
    }
    case 16:
    {
        break;
    }
    case 17:
    {
        break;
    }
    case 18:
    {
        break;
    }
    case 19:
    {
        break;
    }
    case 20:
    {
        break;
    }
    case 21:
    {
        break;
    }
    case 22:
    {
        // Create img_clr_knob (hg_image)
        img_clr_knob = gui_img_create_from_fs((gui_obj_t *)note, "img_clr_knob", "/light/knob.bin", 4, 0, 20, 20);
        gui_img_translate((gui_img_t *)img_clr_knob, 10.0f, 20.0f);
        gui_img_set_focus((gui_img_t *)img_clr_knob, 10.0f, 20.0f);
        gui_obj_show((gui_obj_t *)img_clr_knob, true);
        break;
    }
    case 23:
    {
        break;
    }
    case 24:
    {
        break;
    }
    case 25:
    {
        break;
    }
    case 26:
    {
        break;
    }
    case 27:
    {
        break;
    }
    case 28:
    {
        break;
    }
    case 29:
    {
        break;
    }
    case 30:
    {
        break;
    }
    case 31:
    {
        break;
    }
    case 32:
    {
        break;
    }
    case 33:
    {
        break;
    }
    case 34:
    {
        break;
    }
    case 35:
    {
        break;
    }
    case 36:
    {
        break;
    }
    case 37:
    {
        break;
    }
    case 38:
    {
        break;
    }
    case 39:
    {
        break;
    }
    case 40:
    {
        break;
    }
    case 41:
    {
        break;
    }
    case 42:
    {
        break;
    }
    case 43:
    {
        break;
    }
    case 44:
    {
        break;
    }
    case 45:
    {
        break;
    }
    case 46:
    {
        break;
    }
    default:
        break;
    }
}

// note_design callback function declaration
static void lst_lt_bar_1_note_design(gui_obj_t *obj, void *param);

// note_design callback function implementation
static void lst_lt_bar_1_note_design(gui_obj_t *obj, void *param)
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
        break;
    }
    case 1:
    {
        break;
    }
    case 2:
    {
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
    case 5:
    {
        break;
    }
    case 6:
    {
        break;
    }
    case 7:
    {
        break;
    }
    case 8:
    {
        break;
    }
    case 9:
    {
        break;
    }
    case 10:
    {
        break;
    }
    case 11:
    {
        break;
    }
    case 12:
    {
        break;
    }
    case 13:
    {
        break;
    }
    case 14:
    {
        break;
    }
    case 15:
    {
        break;
    }
    case 16:
    {
        break;
    }
    case 17:
    {
        break;
    }
    case 18:
    {
        break;
    }
    case 19:
    {
        break;
    }
    case 20:
    {
        break;
    }
    case 21:
    {
        break;
    }
    case 22:
    {
        break;
    }
    case 23:
    {
        break;
    }
    case 24:
    {
        // Create img_59 (hg_image)
        img_59 = gui_img_create_from_fs((gui_obj_t *)note, "img_59", "/light/knob.bin", -20, 0, 20, 20);
        gui_obj_show((gui_obj_t *)img_59, false);
        break;
    }
    case 25:
    {
        break;
    }
    case 26:
    {
        break;
    }
    case 27:
    {
        break;
    }
    case 28:
    {
        break;
    }
    case 29:
    {
        break;
    }
    case 30:
    {
        break;
    }
    case 31:
    {
        break;
    }
    case 32:
    {
        break;
    }
    case 33:
    {
        break;
    }
    case 34:
    {
        break;
    }
    case 35:
    {
        break;
    }
    case 36:
    {
        break;
    }
    case 37:
    {
        break;
    }
    case 38:
    {
        break;
    }
    case 39:
    {
        break;
    }
    case 40:
    {
        break;
    }
    case 41:
    {
        break;
    }
    case 42:
    {
        break;
    }
    case 43:
    {
        break;
    }
    case 44:
    {
        break;
    }
    case 45:
    {
        break;
    }
    case 46:
    {
        break;
    }
    default:
        break;
    }
}


// Create RotaryTemplateMainView (hg_view)
static void RotaryTemplateMainView_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void RotaryTemplateMainView_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    GUI_UNUSED(view);


    // Create hg_image_1770375807980_dxhf (hg_image)
    hg_image_1770375807980_dxhf = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1770375807980_dxhf", "/home_21.bin", 0, 0, 480, 480);
    gui_img_set_mode((gui_img_t *)hg_image_1770375807980_dxhf, IMG_BYPASS_MODE);
    gui_obj_show((gui_obj_t *)hg_image_1770375807980_dxhf, true);

    // Create hg_image_1770607273521_70ob (hg_image)
    hg_image_1770607273521_70ob = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1770607273521_70ob", "/home_5.bin", 217, 379, 50, 50);
    gui_img_set_mode((gui_img_t *)hg_image_1770607273521_70ob, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)hg_image_1770607273521_70ob, true);
    gui_obj_add_event_cb(hg_image_1770607273521_70ob, (gui_event_cb_t)hg_image_1770607273521_70ob_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create hg_image_1770607673557_iiv2 (hg_image)
    hg_image_1770607673557_iiv2 = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1770607673557_iiv2", "/home_6.bin", 142, 300, 61, 46);
    gui_img_set_mode((gui_img_t *)hg_image_1770607673557_iiv2, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)hg_image_1770607673557_iiv2, true);
    gui_obj_add_event_cb(hg_image_1770607673557_iiv2, (gui_event_cb_t)hg_image_1770607673557_iiv2_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create hg_image_1770607676005_3nc2 (hg_image)
    hg_image_1770607676005_3nc2 = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1770607676005_3nc2", "/home_7.bin", 264, 298, 50, 50);
    gui_img_set_mode((gui_img_t *)hg_image_1770607676005_3nc2, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)hg_image_1770607676005_3nc2, true);
    gui_obj_add_event_cb(hg_image_1770607676005_3nc2, (gui_event_cb_t)hg_image_1770607676005_3nc2_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create hg_image_1770607679223_o1zm (hg_image)
    hg_image_1770607679223_o1zm = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1770607679223_o1zm", "/home_8.bin", 373, 293, 60, 60);
    gui_obj_show((gui_obj_t *)hg_image_1770607679223_o1zm, true);
    gui_obj_add_event_cb(hg_image_1770607679223_o1zm, (gui_event_cb_t)hg_image_1770607679223_o1zm_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create hg_image_1770607688255_n4di (hg_image)
    hg_image_1770607688255_n4di = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1770607688255_n4di", "/home_9.bin", 105, 379, 50, 50);
    gui_obj_show((gui_obj_t *)hg_image_1770607688255_n4di, true);
    gui_obj_add_event_cb(hg_image_1770607688255_n4di, (gui_event_cb_t)hg_image_1770607688255_n4di_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create hg_image_1770607691358_qraa (hg_image)
    hg_image_1770607691358_qraa = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1770607691358_qraa", "/home_10.bin", 327, 379, 50, 50);
    gui_obj_show((gui_obj_t *)hg_image_1770607691358_qraa, true);
    gui_obj_add_event_cb(hg_image_1770607691358_qraa, (gui_event_cb_t)hg_image_1770607691358_qraa_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create hg_image_1770607798406_9ndb (hg_image)
    hg_image_1770607798406_9ndb = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1770607798406_9ndb", "/home_4.bin", 225, 450, 30, 30);
    gui_img_set_mode((gui_img_t *)hg_image_1770607798406_9ndb, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)hg_image_1770607798406_9ndb, true);
}
GUI_VIEW_INSTANCE("RotaryTemplateMainView", false, RotaryTemplateMainView_switch_in, RotaryTemplateMainView_switch_out);

// Create view_mode (hg_view)
static void view_mode_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void view_mode_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    gui_view_switch_on_event(view, "RotaryTemplateMainView", SWITCH_INIT_STATE, SWITCH_IN_ANIMATION_FADE, GUI_EVENT_TOUCH_MOVE_RIGHT);


    // Create img_md_home_r (hg_image)
    img_md_home_r = gui_img_create_from_fs((gui_obj_t *)view, "img_md_home_r", "/mode/md_home_r.bin", 123, 67, 306, 306);
    gui_img_set_mode((gui_img_t *)img_md_home_r, IMG_BYPASS_MODE);
    gui_obj_show((gui_obj_t *)img_md_home_r, true);

    // Create img_md_home_m (hg_image)
    img_md_home_m = gui_img_create_from_fs((gui_obj_t *)view, "img_md_home_m", "/mode/md_home_b.bin", 226, 161, 100, 100);
    gui_img_set_mode((gui_img_t *)img_md_home_m, IMG_BYPASS_MODE);
    gui_obj_show((gui_obj_t *)img_md_home_m, true);

    // Create img_txt_home (hg_image)
    img_txt_home = gui_img_create_from_fs((gui_obj_t *)view, "img_txt_home", "/mode/md_home_txt.bin", 198, 274, 156, 38);
    gui_img_set_mode((gui_img_t *)img_txt_home, IMG_BYPASS_MODE);
    gui_obj_show((gui_obj_t *)img_txt_home, true);

    // Create lst_mode (hg_list)
    lst_mode = gui_list_create((gui_obj_t *)view, "lst_mode", 20, 0, 300, 480, 66, 0, VERTICAL, lst_mode_note_design, NULL, false);
    gui_list_set_style(lst_mode, LIST_CIRCLE);
    gui_list_set_note_num(lst_mode, 10);
    gui_list_set_auto_align(lst_mode, true);
    gui_list_set_circle_radius(lst_mode, 240);
    gui_obj_show((gui_obj_t *)lst_mode, true);

    // Create hg_image_1772693453806_vik8 (hg_image)
    hg_image_1772693453806_vik8 = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1772693453806_vik8", "/mode/md_select.bin", -46, 138, 246, 187);
    gui_img_set_mode((gui_img_t *)hg_image_1772693453806_vik8, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)hg_image_1772693453806_vik8, true);
}
GUI_VIEW_INSTANCE("view_mode", false, view_mode_switch_in, view_mode_switch_out);

// Create view_ac (hg_view)
static void view_ac_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void view_ac_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    gui_view_switch_on_event(view, "RotaryTemplateMainView", SWITCH_INIT_STATE, SWITCH_IN_ANIMATION_FADE, GUI_EVENT_TOUCH_MOVE_RIGHT);


    // Create win_ac_bg_mid (hg_window)
    win_ac_bg_mid = gui_win_create((gui_obj_t *)view, "win_ac_bg_mid", -103, 175, 583, 137);
    gui_obj_show((gui_obj_t *)win_ac_bg_mid, true);


    // Create img_ac_bg_mid (hg_image)
    img_ac_bg_mid = gui_img_create_from_fs(win_ac_bg_mid, "img_ac_bg_mid", "/ac/ac_heat.bin", 0, -276, 686, 686);
    gui_img_set_mode((gui_img_t *)img_ac_bg_mid, IMG_BYPASS_MODE);
    ((gui_img_t *)img_ac_bg_mid)->need_clip = true;
    gui_obj_show((gui_obj_t *)img_ac_bg_mid, true);

    // Create win_ac_temp (hg_window)
    win_ac_temp = gui_win_create((gui_obj_t *)view, "win_ac_temp", 117, 188, 313, 120);
    gui_obj_show((gui_obj_t *)win_ac_temp, true);


    // Create lst_unit (hg_list)
    lst_unit = gui_list_create(win_ac_temp, "lst_unit", 97, 0, 110, 114, 114, 70, VERTICAL, lst_unit_note_design, NULL, false);
    gui_list_set_style(lst_unit, LIST_CLASSIC);
    gui_list_set_note_num(lst_unit, 10);
    gui_list_set_auto_align(lst_unit, true);
    gui_list_enable_loop(lst_unit, true);
    gui_list_enable_area_display(lst_unit, true);
    gui_obj_show((gui_obj_t *)lst_unit, true);

    // Create lst_ten (hg_list)
    lst_ten = gui_list_create(win_ac_temp, "lst_ten", 0, 0, 110, 114, 114, 70, VERTICAL, lst_ten_note_design, NULL, false);
    gui_list_set_style(lst_ten, LIST_CLASSIC);
    gui_list_set_note_num(lst_ten, 3);
    gui_list_set_auto_align(lst_ten, true);
    gui_list_enable_area_display(lst_ten, true);
    gui_obj_show((gui_obj_t *)lst_ten, true);

    // Create img_ac_degree (hg_image)
    img_ac_degree = gui_img_create_from_fs(win_ac_temp, "img_ac_degree", "/ac/degree.bin", 200, -2, 33, 28);
    gui_obj_show((gui_obj_t *)img_ac_degree, true);

    // Create win_ac_fan (hg_window)
    win_ac_fan = gui_win_create((gui_obj_t *)view, "win_ac_fan", 198, 188, 100, 120);
    gui_obj_show((gui_obj_t *)win_ac_fan, false);


    // Create lst_fan (hg_list)
    lst_fan = gui_list_create(win_ac_fan, "lst_fan", 0, 0, 84, 114, 114, 70, VERTICAL, lst_fan_note_design, NULL, false);
    gui_list_set_style(lst_fan, LIST_CLASSIC);
    gui_list_set_note_num(lst_fan, 5);
    gui_list_set_auto_align(lst_fan, true);
    gui_list_enable_area_display(lst_fan, true);
    gui_obj_show((gui_obj_t *)lst_fan, true);

    // Create img_28 (hg_image)
    img_28 = gui_img_create_from_fs(win_ac_fan, "img_28", "/ac/fan.bin", 88, -2, 40, 40);
    gui_obj_show((gui_obj_t *)img_28, true);

    // Create win_ac_bg_up (hg_window)
    win_ac_bg_up = gui_win_create((gui_obj_t *)view, "win_ac_bg_up", -103, -101, 580, 276);
    gui_obj_show((gui_obj_t *)win_ac_bg_up, true);


    // Create img_ac_bg_up (hg_image)
    img_ac_bg_up = gui_img_create_from_fs(win_ac_bg_up, "img_ac_bg_up", "/ac/ac_heat.bin", 0, 0, 686, 686);
    gui_img_set_mode((gui_img_t *)img_ac_bg_up, IMG_BYPASS_MODE);
    ((gui_img_t *)img_ac_bg_up)->need_clip = true;
    gui_obj_show((gui_obj_t *)img_ac_bg_up, true);

    // Create win_ac_bg_dn (hg_window)
    win_ac_bg_dn = gui_win_create((gui_obj_t *)view, "win_ac_bg_dn", -103, 312, 580, 172);
    gui_obj_show((gui_obj_t *)win_ac_bg_dn, true);


    // Create img_ac_bg_dn (hg_image)
    img_ac_bg_dn = gui_img_create_from_fs(win_ac_bg_dn, "img_ac_bg_dn", "/ac/ac_heat.bin", 0, -413, 686, 686);
    gui_img_set_mode((gui_img_t *)img_ac_bg_dn, IMG_BYPASS_MODE);
    ((gui_img_t *)img_ac_bg_dn)->need_clip = true;
    gui_obj_show((gui_obj_t *)img_ac_bg_dn, true);

    // Create win_mode (hg_window)
    win_mode = gui_win_create((gui_obj_t *)view, "win_mode", 85, 181, 312, 122);
    gui_obj_show((gui_obj_t *)win_mode, false);


    // Create img_mode_bg (hg_image)
    img_mode_bg = gui_img_create_from_fs(win_mode, "img_mode_bg", "/ac/ac_mode_mix.bin", 0, 0, 311, 122);
    gui_img_set_mode((gui_img_t *)img_mode_bg, IMG_SRC_OVER_MODE);
    gui_img_translate((gui_img_t *)img_mode_bg, 155.0f, 61.0f);
    gui_img_set_focus((gui_img_t *)img_mode_bg, 155.0f, 61.0f);
    gui_obj_show((gui_obj_t *)img_mode_bg, true);
    gui_obj_add_event_cb(img_mode_bg, (gui_event_cb_t)img_mode_bg_released_cb, GUI_EVENT_TOUCH_RELEASED, NULL);

    // Create img_hot_df (hg_image)
    img_hot_df = gui_img_create_from_fs(win_mode, "img_hot_df", "/ac/ac_mod_heat.bin", 42, 43, 45, 45);
    gui_img_set_mode((gui_img_t *)img_hot_df, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_hot_df, true);
    gui_obj_add_event_cb(img_hot_df, (gui_event_cb_t)img_hot_df_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create img_hot (hg_image)
    img_hot = gui_img_create_from_fs(win_mode, "img_hot", "/ac/ac_mod_heat_hl_r.bin", 24, 29, 81, 81);
    gui_img_set_mode((gui_img_t *)img_hot, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_hot, true);

    // Create img_cold_df (hg_image)
    img_cold_df = gui_img_create_from_fs(win_mode, "img_cold_df", "/ac/ac_mod_cold.bin", 133, 41, 45, 45);
    gui_img_set_mode((gui_img_t *)img_cold_df, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_cold_df, true);
    gui_obj_add_event_cb(img_cold_df, (gui_event_cb_t)img_cold_df_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create img_cold (hg_image)
    img_cold = gui_img_create_from_fs(win_mode, "img_cold", "/ac/ac_mod_cold_hl.bin", 115, 27, 81, 81);
    gui_img_set_mode((gui_img_t *)img_cold, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_cold, true);

    // Create img_fresh_df (hg_image)
    img_fresh_df = gui_img_create_from_fs(win_mode, "img_fresh_df", "/ac/ac_mod_fan.bin", 225, 43, 45, 45);
    gui_img_set_mode((gui_img_t *)img_fresh_df, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_fresh_df, true);
    gui_obj_add_event_cb(img_fresh_df, (gui_event_cb_t)img_fresh_df_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create img_fresh (hg_image)
    img_fresh = gui_img_create_from_fs(win_mode, "img_fresh", "/ac/ac_mod_fan_hl_g.bin", 207, 29, 81, 81);
    gui_img_set_mode((gui_img_t *)img_fresh, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_fresh, true);

    gui_obj_add_event_cb(GUI_BASE(win_mode), empty_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create img_mode_select (hg_image)
    img_mode_select = gui_img_create_from_fs((gui_obj_t *)view, "img_mode_select", "/ac/ac_mod.bin", 220, 431, 40, 40);
    gui_img_set_mode((gui_img_t *)img_mode_select, IMG_SRC_OVER_MODE);
    gui_img_translate((gui_img_t *)img_mode_select, 20.0f, 20.0f);
    gui_img_set_focus((gui_img_t *)img_mode_select, 20.0f, 20.0f);
    gui_obj_show((gui_obj_t *)img_mode_select, true);
    gui_obj_add_event_cb(img_mode_select, (gui_event_cb_t)img_mode_select_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create btn_ac (hg_button)
    btn_ac = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "btn_ac", "/ac/ac_speed_b.bin", 441, 209, 33, 67);
    if (btn_ac_state) {
        gui_img_set_src((gui_img_t *)btn_ac, "/ac/ac_temp_b.bin", IMG_SRC_FILESYS);
    }
    gui_obj_show((gui_obj_t *)btn_ac, true);
    gui_obj_add_event_cb((gui_obj_t *)btn_ac, btn_ac_toggle_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    gui_obj_add_event_cb((gui_obj_t *)view, (gui_event_cb_t)view_ac_key_0_cb, GUI_EVENT_KB_LONG_PRESSED, NULL);
    gui_obj_add_event_cb((gui_obj_t *)view, (gui_event_cb_t)view_ac_clicked_0_cb, GUI_EVENT_TOUCH_CLICKED, NULL);
    gui_obj_add_event_cb((gui_obj_t *)view, (gui_event_cb_t)view_ac_key_1_cb, GUI_EVENT_KB_SHORT_PRESSED, NULL);
    gui_obj_focus_set((gui_obj_t *)view);
}
GUI_VIEW_INSTANCE("view_ac", false, view_ac_switch_in, view_ac_switch_out);

// Create view_light (hg_view)
static void view_light_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void view_light_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    gui_view_switch_on_event(view, "view_light_color", SWITCH_INIT_STATE, SWITCH_IN_ANIMATION_FADE, GUI_EVENT_TOUCH_MOVE_UP);
    gui_view_switch_on_event(view, "RotaryTemplateMainView", SWITCH_INIT_STATE, SWITCH_IN_ANIMATION_FADE, GUI_EVENT_TOUCH_MOVE_RIGHT);


    // Create img_white (hg_image)
    img_white = gui_img_create_from_fs((gui_obj_t *)view, "img_white", "/light/light_color.bin", -63, -61, 606, 606);
    gui_img_set_mode((gui_img_t *)img_white, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_white, true);

    // Create img_yellow (hg_image)
    img_yellow = gui_img_create_from_fs((gui_obj_t *)view, "img_yellow", "/light/light_temp_1.bin", -63, -61, 606, 606);
    gui_img_set_mode((gui_img_t *)img_yellow, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_yellow, true);

    // Create win_temp (hg_window)
    win_temp = gui_win_create((gui_obj_t *)view, "win_temp", 129, 345, 261, 26);
    gui_obj_show((gui_obj_t *)win_temp, true);
    // Bind timer: ani_tmr
    gui_obj_create_timer((gui_obj_t *)win_temp, 100, true, win_temp_timer_0_cb);


    // Create img_lt_bar_tmp (hg_image)
    img_lt_bar_tmp = gui_img_create_from_fs(win_temp, "img_lt_bar_tmp", "/light/bar_temp.bin", 0, 4, 236, 14);
    gui_img_translate((gui_img_t *)img_lt_bar_tmp, 118.0f, 14.0f);
    gui_img_set_focus((gui_img_t *)img_lt_bar_tmp, 118.0f, 14.0f);
    gui_obj_show((gui_obj_t *)img_lt_bar_tmp, true);
    gui_obj_add_event_cb(img_lt_bar_tmp, (gui_event_cb_t)img_lt_bar_tmp_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create list_bar_temp (hg_list)
    list_bar_temp = gui_list_create(win_temp, "list_bar_temp", 0, 0, 242, 20, 10, 0, HORIZONTAL, list_bar_temp_note_design, NULL, false);
    gui_list_set_style(list_bar_temp, LIST_CLASSIC);
    gui_list_set_note_num(list_bar_temp, 47);
    gui_list_set_inertia(list_bar_temp, false);
    gui_list_enable_area_display(list_bar_temp, true);
    gui_obj_show((gui_obj_t *)list_bar_temp, true);

    // Create win_lgtn (hg_window)
    win_lgtn = gui_win_create((gui_obj_t *)view, "win_lgtn", 112, 364, 300, 40);
    gui_obj_show((gui_obj_t *)win_lgtn, true);
    // Bind timer: ani_tmr
    gui_obj_create_timer((gui_obj_t *)win_lgtn, 100, true, win_lgtn_timer_0_cb);


    // Create img_lt_bar_0 (hg_image)
    img_lt_bar_0 = gui_img_create_from_fs(win_lgtn, "img_lt_bar_0", "/light/led_ani/loading_100.bin", 50, 5, 236, 37);
    gui_img_set_mode((gui_img_t *)img_lt_bar_0, IMG_SRC_OVER_MODE);
    gui_img_translate((gui_img_t *)img_lt_bar_0, 118.0f * 0.700000f, 0.0f * 0.700000f);
    gui_img_set_focus((gui_img_t *)img_lt_bar_0, 118.0f, 0.0f);
    gui_img_scale((gui_img_t *)img_lt_bar_0, 0.700000f, 0.700000f);
    gui_img_set_opacity((gui_img_t *)img_lt_bar_0, 91);
    gui_obj_show((gui_obj_t *)img_lt_bar_0, true);
    gui_obj_add_event_cb(img_lt_bar_0, (gui_event_cb_t)img_lt_bar_0_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create lst_lt_bar_0 (hg_list)
    lst_lt_bar_0 = gui_list_create(win_lgtn, "lst_lt_bar_0", 18, 7, 242, 37, 10, 0, HORIZONTAL, lst_lt_bar_0_note_design, NULL, false);
    gui_list_set_style(lst_lt_bar_0, LIST_CLASSIC);
    gui_list_set_note_num(lst_lt_bar_0, 47);
    gui_list_set_inertia(lst_lt_bar_0, false);
    gui_list_enable_area_display(lst_lt_bar_0, true);
    gui_obj_show((gui_obj_t *)lst_lt_bar_0, true);

    // Create img_light (hg_image)
    img_light = gui_img_create_from_fs((gui_obj_t *)view, "img_light", "/light/led_temp.bin", 168, 83, 144, 157);
    gui_img_set_mode((gui_img_t *)img_light, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_light, true);

    // Create img_56 (hg_image)
    img_56 = gui_img_create_from_fs((gui_obj_t *)view, "img_56", "/ac/ac_temp_b.bin", 432, 208, 33, 67);
    gui_obj_show((gui_obj_t *)img_56, true);
    gui_obj_add_event_cb(img_56, (gui_event_cb_t)img_56_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    gui_obj_add_event_cb((gui_obj_t *)view, (gui_event_cb_t)view_light_key_0_cb, GUI_EVENT_KB_SHORT_PRESSED, NULL);
    gui_obj_add_event_cb((gui_obj_t *)view, (gui_event_cb_t)view_light_key_1_cb, GUI_EVENT_KB_LONG_PRESSED, NULL);
    gui_obj_focus_set((gui_obj_t *)view);
}
GUI_VIEW_INSTANCE("view_light", false, view_light_switch_in, view_light_switch_out);

// Create view_light_color (hg_view)
static void view_light_color_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void view_light_color_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    gui_view_switch_on_event(view, "RotaryTemplateMainView", SWITCH_INIT_STATE, SWITCH_IN_ANIMATION_FADE, GUI_EVENT_TOUCH_MOVE_RIGHT);


    // Create img_clr_white (hg_image)
    img_clr_white = gui_img_create_from_fs((gui_obj_t *)view, "img_clr_white", "/light/light_color.bin", -63, -61, 606, 606);
    gui_img_set_mode((gui_img_t *)img_clr_white, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_clr_white, true);

    // Create img_clr_0 (hg_image)
    img_clr_0 = gui_img_create_from_fs((gui_obj_t *)view, "img_clr_0", "/light/color_0.bin", -63, -61, 606, 606);
    gui_img_set_mode((gui_img_t *)img_clr_0, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_clr_0, true);

    // Create img_clr_1 (hg_image)
    img_clr_1 = gui_img_create_from_fs((gui_obj_t *)view, "img_clr_1", "/light/color_1.bin", -63, -61, 606, 606);
    gui_img_set_mode((gui_img_t *)img_clr_1, IMG_SRC_OVER_MODE);
    gui_img_set_opacity((gui_img_t *)img_clr_1, 107);
    gui_obj_show((gui_obj_t *)img_clr_1, true);

    // Create img_clr_2 (hg_image)
    img_clr_2 = gui_img_create_from_fs((gui_obj_t *)view, "img_clr_2", "/light/color_2.bin", -63, -61, 606, 606);
    gui_img_set_mode((gui_img_t *)img_clr_2, IMG_SRC_OVER_MODE);
    gui_img_set_opacity((gui_img_t *)img_clr_2, 62);
    gui_obj_show((gui_obj_t *)img_clr_2, false);

    // Create img_clr_3 (hg_image)
    img_clr_3 = gui_img_create_from_fs((gui_obj_t *)view, "img_clr_3", "/light/color_3.bin", -63, -61, 606, 606);
    gui_img_set_mode((gui_img_t *)img_clr_3, IMG_SRC_OVER_MODE);
    gui_img_set_opacity((gui_img_t *)img_clr_3, 0);
    gui_obj_show((gui_obj_t *)img_clr_3, false);

    // Create img_clr_4 (hg_image)
    img_clr_4 = gui_img_create_from_fs((gui_obj_t *)view, "img_clr_4", "/light/color_4.bin", -63, -61, 606, 606);
    gui_img_set_mode((gui_img_t *)img_clr_4, IMG_SRC_OVER_MODE);
    gui_img_set_opacity((gui_img_t *)img_clr_4, 0);
    gui_obj_show((gui_obj_t *)img_clr_4, false);

    // Create img_clr_5 (hg_image)
    img_clr_5 = gui_img_create_from_fs((gui_obj_t *)view, "img_clr_5", "/light/color_5.bin", -63, -61, 606, 606);
    gui_img_set_mode((gui_img_t *)img_clr_5, IMG_SRC_OVER_MODE);
    gui_img_set_opacity((gui_img_t *)img_clr_5, 0);
    gui_obj_show((gui_obj_t *)img_clr_5, false);

    // Create win_clr (hg_window)
    win_clr = gui_win_create((gui_obj_t *)view, "win_clr", 129, 345, 261, 26);
    gui_obj_show((gui_obj_t *)win_clr, true);
    // Bind timer: ani_tmr
    gui_obj_create_timer((gui_obj_t *)win_clr, 100, true, win_clr_timer_0_cb);


    // Create img_lt_bar_clr (hg_image)
    img_lt_bar_clr = gui_img_create_from_fs(win_clr, "img_lt_bar_clr", "/light/bar_color.bin", 0, 4, 236, 14);
    gui_img_translate((gui_img_t *)img_lt_bar_clr, 118.0f, 14.0f);
    gui_img_set_focus((gui_img_t *)img_lt_bar_clr, 118.0f, 14.0f);
    gui_obj_show((gui_obj_t *)img_lt_bar_clr, true);
    gui_obj_add_event_cb(img_lt_bar_clr, (gui_event_cb_t)img_lt_bar_clr_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create list_bar_clr (hg_list)
    list_bar_clr = gui_list_create(win_clr, "list_bar_clr", 0, 0, 242, 20, 10, 0, HORIZONTAL, list_bar_clr_note_design, NULL, false);
    gui_list_set_style(list_bar_clr, LIST_CLASSIC);
    gui_list_set_note_num(list_bar_clr, 47);
    gui_list_set_inertia(list_bar_clr, false);
    gui_list_enable_area_display(list_bar_clr, true);
    gui_obj_show((gui_obj_t *)list_bar_clr, true);

    // Create win_lgtnn (hg_window)
    win_lgtnn = gui_win_create((gui_obj_t *)view, "win_lgtnn", 112, 364, 300, 40);
    gui_obj_show((gui_obj_t *)win_lgtnn, true);
    // Bind timer: ani_tmr
    gui_obj_create_timer((gui_obj_t *)win_lgtnn, 100, true, win_clr_lgtn_timer_0_cb);


    // Create img_lt_bar_1 (hg_image)
    img_lt_bar_1 = gui_img_create_from_fs(win_lgtnn, "img_lt_bar_1", "/light/led_ani/loading_100.bin", 50, 5, 236, 37);
    gui_img_set_mode((gui_img_t *)img_lt_bar_1, IMG_SRC_OVER_MODE);
    gui_img_translate((gui_img_t *)img_lt_bar_1, 118.0f * 0.700000f, 0.0f * 0.700000f);
    gui_img_set_focus((gui_img_t *)img_lt_bar_1, 118.0f, 0.0f);
    gui_img_scale((gui_img_t *)img_lt_bar_1, 0.700000f, 0.700000f);
    gui_img_set_opacity((gui_img_t *)img_lt_bar_1, 91);
    gui_obj_show((gui_obj_t *)img_lt_bar_1, true);
    gui_obj_add_event_cb(img_lt_bar_1, (gui_event_cb_t)img_lt_bar_1_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create lst_lt_bar_1 (hg_list)
    lst_lt_bar_1 = gui_list_create(win_lgtnn, "lst_lt_bar_1", 18, 7, 242, 37, 10, 0, HORIZONTAL, lst_lt_bar_1_note_design, NULL, false);
    gui_list_set_style(lst_lt_bar_1, LIST_CLASSIC);
    gui_list_set_note_num(lst_lt_bar_1, 47);
    gui_list_set_inertia(lst_lt_bar_1, false);
    gui_list_enable_area_display(lst_lt_bar_1, true);
    gui_obj_show((gui_obj_t *)lst_lt_bar_1, true);

    // Create img_57 (hg_image)
    img_57 = gui_img_create_from_fs((gui_obj_t *)view, "img_57", "/ac/ac_speed_b.bin", 432, 208, 33, 67);
    gui_obj_show((gui_obj_t *)img_57, true);
    gui_obj_add_event_cb(img_57, (gui_event_cb_t)img_57_clicked_cb, GUI_EVENT_TOUCH_CLICKED, NULL);

    // Create img_light_clr (hg_image)
    img_light_clr = gui_img_create_from_fs((gui_obj_t *)view, "img_light_clr", "/light/led_color.bin", 168, 83, 144, 158);
    gui_img_set_mode((gui_img_t *)img_light_clr, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_light_clr, true);

    gui_obj_add_event_cb((gui_obj_t *)view, (gui_event_cb_t)view_light_color_key_0_cb, GUI_EVENT_KB_SHORT_PRESSED, NULL);
    gui_obj_add_event_cb((gui_obj_t *)view, (gui_event_cb_t)view_light_color_key_1_cb, GUI_EVENT_KB_LONG_PRESSED, NULL);
    gui_obj_focus_set((gui_obj_t *)view);
}
GUI_VIEW_INSTANCE("view_light_color", false, view_light_color_switch_in, view_light_color_switch_out);

// Create view_curtain (hg_view)
static void view_curtain_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void view_curtain_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    gui_view_switch_on_event(view, "RotaryTemplateMainView", SWITCH_INIT_STATE, SWITCH_IN_ANIMATION_FADE, GUI_EVENT_TOUCH_MOVE_RIGHT);


    // Create img_cur (hg_image)
    img_cur = gui_img_create_from_fs((gui_obj_t *)view, "img_cur", "/curtain/cur_ani/cur_10.bin", 0, 0, 480, 350);
    gui_obj_show((gui_obj_t *)img_cur, true);
    // Bind timer: ani_curtain
    gui_obj_create_timer((gui_obj_t *)img_cur, 100, true, img_cur_timer_0_cb);

    // Create img_cur_bg (hg_image)
    img_cur_bg = gui_img_create_from_fs((gui_obj_t *)view, "img_cur_bg", "/curtain/cur_bg.bin", -196, 182, 875, 449);
    gui_img_set_mode((gui_img_t *)img_cur_bg, IMG_SRC_OVER_MODE);
    gui_obj_show((gui_obj_t *)img_cur_bg, true);

    // Create btn_open (hg_button)
    btn_open = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "btn_open", "/curtain/cur_open.bin", 155, 381, 50, 50);
    gui_obj_show((gui_obj_t *)btn_open, true);
    gui_obj_add_event_cb((gui_obj_t *)btn_open, btn_open_press_cb, GUI_EVENT_TOUCH_PRESSED, NULL);
    gui_obj_add_event_cb((gui_obj_t *)btn_open, btn_open_release_cb, GUI_EVENT_TOUCH_RELEASED, NULL);

    // Create btn_close (hg_button)
    btn_close = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "btn_close", "/curtain/cur_close.bin", 276, 381, 50, 50);
    gui_obj_show((gui_obj_t *)btn_close, true);
    gui_obj_add_event_cb((gui_obj_t *)btn_close, btn_close_press_cb, GUI_EVENT_TOUCH_PRESSED, NULL);
    gui_obj_add_event_cb((gui_obj_t *)btn_close, btn_close_release_cb, GUI_EVENT_TOUCH_RELEASED, NULL);

    // Create btn_stop (hg_button)
    btn_stop = (gui_obj_t *)gui_img_create_from_fs((gui_obj_t *)view, "btn_stop", "/curtain/cur_pause.bin", 216, 381, 50, 50);
    gui_obj_show((gui_obj_t *)btn_stop, true);
    gui_obj_add_event_cb((gui_obj_t *)btn_stop, btn_stop_press_cb, GUI_EVENT_TOUCH_PRESSED, NULL);
    gui_obj_add_event_cb((gui_obj_t *)btn_stop, btn_stop_release_cb, GUI_EVENT_TOUCH_RELEASED, NULL);

    gui_obj_add_event_cb((gui_obj_t *)view, (gui_event_cb_t)view_curtain_key_0_cb, GUI_EVENT_KB_SHORT_PRESSED, NULL);
    gui_obj_focus_set((gui_obj_t *)view);
}
GUI_VIEW_INSTANCE("view_curtain", false, view_curtain_switch_in, view_curtain_switch_out);

// Create view_wash (hg_view)
static void view_wash_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void view_wash_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    gui_view_switch_on_event(view, "RotaryTemplateMainView", SWITCH_INIT_STATE, SWITCH_IN_ANIMATION_FADE, GUI_EVENT_TOUCH_MOVE_RIGHT);


    // Create ptcl_1 (hg_particle)
    ptcl_1 = effect_bubble_create((gui_obj_t *)view, "ptcl_1", 0, 0, 480, 480);
    gui_obj_show((gui_obj_t *)ptcl_1, false);

    // Create lbl_1 (hg_label)
    lbl_1 = gui_text_create((gui_obj_t *)view, "lbl_1", 165, 57, 117, 39);
    gui_text_set((gui_text_t *)lbl_1, "Washer", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 6, 42);
    gui_text_type_set((gui_text_t *)lbl_1, "//Baloo2_Regular_size42_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)lbl_1, LEFT);
    gui_text_extra_letter_spacing_set((gui_text_t *)lbl_1, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)lbl_1, 0);

    // Create lbl_4 (hg_label)
    lbl_4 = gui_text_create((gui_obj_t *)view, "lbl_4", 197, 110, 146, 82);
    gui_text_set((gui_text_t *)lbl_4, "Label", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 5, 34);
    gui_text_type_set((gui_text_t *)lbl_4, "//Baloo2_Regular_size34_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)lbl_4, LEFT);
    gui_text_extra_letter_spacing_set((gui_text_t *)lbl_4, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)lbl_4, 0);

    // Create lbl_3 (hg_label)
    lbl_3 = gui_text_create((gui_obj_t *)view, "lbl_3", 165, 205, 210, 78);
    gui_text_set((gui_text_t *)lbl_3, "Label", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 5, 34);
    gui_text_type_set((gui_text_t *)lbl_3, "//Baloo2_Regular_size34_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)lbl_3, LEFT);

    // Create lbl_5 (hg_label)
    lbl_5 = gui_text_create((gui_obj_t *)view, "lbl_5", 204, 301, 150, 30);
    gui_text_set((gui_text_t *)lbl_5, "Label", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 5, 28);
    gui_text_type_set((gui_text_t *)lbl_5, "//Baloo2_Regular_size28_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)lbl_5, LEFT);

    // Create lbl_7 (hg_label)
    lbl_7 = gui_text_create((gui_obj_t *)view, "lbl_7", 77, 253, 150, 30);
    gui_text_set((gui_text_t *)lbl_7, "Label", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 5, 16);
    gui_text_type_set((gui_text_t *)lbl_7, "//Baloo2_Regular_size16_bits4_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)lbl_7, LEFT);

    // Create img_81 (hg_image)
    img_81 = gui_img_create_from_fs((gui_obj_t *)view, "img_81", "/home_16.bin", 314, 221, 50, 50);
    gui_obj_show((gui_obj_t *)img_81, true);

    // Create img_82 (hg_image)
    img_82 = gui_img_create_from_fs((gui_obj_t *)view, "img_82", "/home_6.bin", 150, 365, 61, 46);
    gui_obj_show((gui_obj_t *)img_82, true);
}
GUI_VIEW_INSTANCE("view_wash", false, view_wash_switch_in, view_wash_switch_out);

// Create view_setting (hg_view)
static void view_setting_switch_out(gui_view_t *view)
{
    GUI_UNUSED(view);
}

static void view_setting_switch_in(gui_view_t *view)
{
    // Set animation step
    gui_view_set_animate_step(view, 48);

    // Set opacity
    gui_view_set_opacity(view, 255);

    // Set background color
    gui_set_bg_color(gui_rgb(0, 0, 0));

    gui_view_switch_on_event(view, "RotaryTemplateMainView", SWITCH_INIT_STATE, SWITCH_IN_ANIMATION_FADE, GUI_EVENT_TOUCH_MOVE_RIGHT);


    // Create hg_image_1772785447547_wk17 (hg_image)
    hg_image_1772785447547_wk17 = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1772785447547_wk17", "/setting/WLAN.bin", 104, 77, 98, 25);
    gui_obj_show((gui_obj_t *)hg_image_1772785447547_wk17, true);

    // Create hg_image_1772785452162_tcmn (hg_image)
    hg_image_1772785452162_tcmn = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1772785452162_tcmn", "/setting/wf_on.bin", 243, 60, 60, 60);
    gui_obj_show((gui_obj_t *)hg_image_1772785452162_tcmn, true);

    // Create lbl_2 (hg_label)
    lbl_2 = gui_text_create((gui_obj_t *)view, "lbl_2", 187, 16, 106, 28);
    gui_text_set((gui_text_t *)lbl_2, "Setting", GUI_FONT_SRC_BMP, gui_rgb(255, 255, 255), 7, 43);
    gui_text_type_set((gui_text_t *)lbl_2, "//Baloo2_Regular_size43_bits2_bitmap.bin", FONT_SRC_FILESYS);
    gui_text_mode_set((gui_text_t *)lbl_2, CENTER);
    gui_text_extra_letter_spacing_set((gui_text_t *)lbl_2, 0);
    gui_text_extra_line_spacing_set((gui_text_t *)lbl_2, 0);

    // Create hg_image_1772785456571_pymf (hg_image)
    hg_image_1772785456571_pymf = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1772785456571_pymf", "/setting/wf_refresh.bin", 338, 70, 40, 40);
    gui_obj_show((gui_obj_t *)hg_image_1772785456571_pymf, true);

    // Create hg_image_1772785463497_fy3r (hg_image)
    hg_image_1772785463497_fy3r = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1772785463497_fy3r", "/setting/wf00.bin", 25, 152, 430, 64);
    gui_obj_show((gui_obj_t *)hg_image_1772785463497_fy3r, true);

    // Create hg_image_1772785479452_2ui7 (hg_image)
    hg_image_1772785479452_2ui7 = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1772785479452_2ui7", "/setting/wf01.bin", 25, 227, 430, 64);
    gui_obj_show((gui_obj_t *)hg_image_1772785479452_2ui7, true);

    // Create hg_image_1772785490027_q67d (hg_image)
    hg_image_1772785490027_q67d = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1772785490027_q67d", "/setting/wf02.bin", 61, 304, 358, 64);
    gui_obj_show((gui_obj_t *)hg_image_1772785490027_q67d, true);

    // Create hg_image_1772785504892_6b9q (hg_image)
    hg_image_1772785504892_6b9q = gui_img_create_from_fs((gui_obj_t *)view, "hg_image_1772785504892_6b9q", "/setting/wf04.bin", 107, 378, 266, 66);
    gui_obj_show((gui_obj_t *)hg_image_1772785504892_6b9q, true);
}
GUI_VIEW_INSTANCE("view_setting", false, view_setting_switch_in, view_setting_switch_out);
