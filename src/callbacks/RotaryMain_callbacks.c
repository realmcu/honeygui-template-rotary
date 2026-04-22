#include "RotaryMain_callbacks.h"
#include "../ui/RotaryMain_ui.h"
#include "../user/RotaryMain_user.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// Timer animation counters
uint16_t img_ac_bg_mid_timer_cnt = 0;
uint16_t img_ac_bg_up_timer_cnt = 0;
uint16_t img_ac_bg_dn_timer_cnt = 0;
uint16_t img_mode_bg_timer_cnt = 0;
uint16_t img_hot_df_timer_cnt = 0;
uint16_t img_hot_timer_cnt = 0;
uint16_t img_cold_df_timer_cnt = 0;
uint16_t img_cold_timer_cnt = 0;
uint16_t img_fresh_df_timer_cnt = 0;
uint16_t img_fresh_timer_cnt = 0;
uint16_t img_mode_select_timer_cnt = 0;
uint16_t win_temp_timer_cnt = 0;
uint16_t img_lt_bar_tmp_timer_cnt = 0;
uint16_t img_temp_knob_timer_cnt = 0;
uint16_t win_lgtn_timer_cnt = 0;
uint16_t img_lt_bar_0_timer_cnt = 0;
uint16_t win_clr_timer_cnt = 0;
uint16_t img_lt_bar_clr_timer_cnt = 0;
uint16_t img_clr_knob_timer_cnt = 0;
uint16_t win_lgtnn_timer_cnt = 0;
uint16_t img_lt_bar_1_timer_cnt = 0;
uint16_t img_cur_timer_cnt = 0;

// Event callback function implementations

void hg_image_1770607273521_70ob_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_mode", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_ANIMATION_FADE);
}

void hg_image_1770607673557_iiv2_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_ac", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_ANIMATION_FADE);
    ac_show_cb(obj, e);
}

void hg_image_1770607676005_3nc2_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_light", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_ANIMATION_FADE);
    light_tmp_show_cb(obj, e);
}

void hg_image_1770607679223_o1zm_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_curtain", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_ANIMATION_FADE);
    curtn_show_cb(obj, e);
}

void hg_image_1770607688255_n4di_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_wash", SWITCH_INIT_STATE, SWITCH_IN_ANIMATION_FADE);
}

void hg_image_1770607691358_qraa_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_setting", SWITCH_OUT_NONE_ANIMATION, SWITCH_IN_ANIMATION_FADE);
}

void view_ac_clicked_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    ac_hide_mod_cb(obj, e);
    img_mode_select_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_mode_select), 20, true, img_mode_select_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(img_mode_select));
}

void view_ac_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        ac_btn_long_press_cb(obj, e);
    }
}

void view_ac_key_1_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        ac_btn_0_click_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Back") == 0)
    {
        ac_btn_1_click_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Menu") == 0)
    {
        ac_btn_2_click_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Power") == 0)
    {
    }
}

void win_mode_clicked_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    empty_cb(obj, e);
}

void img_mode_bg_released_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    empty_cb(obj, e);
}

void img_hot_df_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    ac_select_mod_heat_cb(obj, e);
    img_ac_bg_mid_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_ac_bg_mid), 50, true, img_ac_bg_mid_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(img_ac_bg_mid));
    img_ac_bg_up_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_ac_bg_up), 50, true, img_ac_bg_up_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(img_ac_bg_up));
    img_ac_bg_dn_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_ac_bg_dn), 50, true, img_ac_bg_dn_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(img_ac_bg_dn));
}

void img_cold_df_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    ac_select_mod_cold_cb(obj, e);
    img_ac_bg_mid_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_ac_bg_mid), 50, true, img_ac_bg_mid_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(img_ac_bg_mid));
    img_ac_bg_up_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_ac_bg_up), 50, true, img_ac_bg_up_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(img_ac_bg_up));
    img_ac_bg_dn_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_ac_bg_dn), 50, true, img_ac_bg_dn_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(img_ac_bg_dn));
}

void img_fresh_df_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    ac_select_mod_fresh_cb(obj, e);
    img_ac_bg_mid_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_ac_bg_mid), 50, true, img_ac_bg_mid_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(img_ac_bg_mid));
    img_ac_bg_up_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_ac_bg_up), 50, true, img_ac_bg_up_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(img_ac_bg_up));
    img_ac_bg_dn_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_ac_bg_dn), 50, true, img_ac_bg_dn_timer_2_cb);
    gui_obj_start_timer(GUI_BASE(img_ac_bg_dn));
}

void img_mode_select_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    img_mode_bg_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_mode_bg), 50, true, img_mode_bg_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(img_mode_bg));
    img_fresh_df_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_fresh_df), 50, true, img_fresh_df_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(img_fresh_df));
    img_cold_df_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_cold_df), 50, true, img_cold_df_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(img_cold_df));
    img_hot_df_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_hot_df), 50, true, img_hot_df_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(img_hot_df));
    img_mode_select_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_mode_select), 20, true, img_mode_select_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(img_mode_select));
    ac_pop_mod_cb(obj, e);
}

void view_light_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        light_tmp_btn_0_click_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Back") == 0)
    {
        light_tmp_btn_1_click_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Menu") == 0)
    {
        light_tmp_btn_2_click_cb(obj, e);
    }
}

void view_light_key_1_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        light_tmp_btn_long_press_cb(obj, e);
    }
}

void img_lt_bar_tmp_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    light_tmp_click_tmp_cb(obj, e);
}

void img_lt_bar_0_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    light_tmp_click_lgt_cb(obj, e);
}

void img_56_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_light_color", SWITCH_INIT_STATE, SWITCH_IN_ANIMATION_FADE);
    light_clr_show_cb(obj, e);
}

void view_light_color_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        light_clr_btn_0_click_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Back") == 0)
    {
        light_clr_btn_1_click_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Menu") == 0)
    {
        light_clr_btn_2_click_cb(obj, e);
    }
}

void view_light_color_key_1_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        light_clr_btn_long_press_cb(obj, e);
    }
}

void img_lt_bar_clr_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    light_clr_click_clr_cb(obj, e);
}

void img_lt_bar_1_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    light_clr_click_lgt_cb(obj, e);
}

void img_57_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_light", SWITCH_INIT_STATE, SWITCH_IN_ANIMATION_FADE);
    light_tmp_show_cb(obj, e);
}

void view_curtain_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        curtn_btn_0_click_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Back") == 0)
    {
        curtn_btn_1_click_cb(obj, e);
    }
    else if (strcmp(e->indev_name, "Menu") == 0)
    {
        curtn_btn_2_click_cb(obj, e);
    }
}

// Preset timer callback functions

/**
 * ani_ac_on
 * Component: img_ac_bg_mid
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_ac_bg_mid_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 8;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 8;
    
    img_ac_bg_mid_timer_cnt++;
    
    // Segment 1: 800ms, 1 action(s)
    if (img_ac_bg_mid_timer_cnt > seg0_start && img_ac_bg_mid_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_ac_bg_mid_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 0 -> 255
            const uint8_t opacity_origin = 0;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_ac_bg_mid_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_ac_bg_mid_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_ac_off
 * Component: img_ac_bg_mid
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_ac_bg_mid_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 8;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 8;
    
    img_ac_bg_mid_timer_cnt++;
    
    // Segment 1: 800ms, 1 action(s)
    if (img_ac_bg_mid_timer_cnt > seg0_start && img_ac_bg_mid_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_ac_bg_mid_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 255 -> 0
            const uint8_t opacity_origin = 255;
            const uint8_t opacity_target = 0;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_ac_bg_mid_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_ac_bg_mid_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_ac_sw
 * Component: img_ac_bg_mid
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_ac_bg_mid_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 8;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 8;
    
    img_ac_bg_mid_timer_cnt++;
    
    // Segment 1: 400ms, 1 action(s)
    if (img_ac_bg_mid_timer_cnt > seg0_start && img_ac_bg_mid_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_ac_bg_mid_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 128 -> 255
            const uint8_t opacity_origin = 128;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_ac_bg_mid_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_ac_bg_mid_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_ac_on
 * Component: img_ac_bg_up
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_ac_bg_up_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 8;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 8;
    
    img_ac_bg_up_timer_cnt++;
    
    // Segment 1: 800ms, 1 action(s)
    if (img_ac_bg_up_timer_cnt > seg0_start && img_ac_bg_up_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_ac_bg_up_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 0 -> 255
            const uint8_t opacity_origin = 0;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_ac_bg_up_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_ac_bg_up_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_ac_off
 * Component: img_ac_bg_up
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_ac_bg_up_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 8;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 8;
    
    img_ac_bg_up_timer_cnt++;
    
    // Segment 1: 800ms, 1 action(s)
    if (img_ac_bg_up_timer_cnt > seg0_start && img_ac_bg_up_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_ac_bg_up_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 255 -> 0
            const uint8_t opacity_origin = 255;
            const uint8_t opacity_target = 0;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_ac_bg_up_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_ac_bg_up_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_ac_sw
 * Component: img_ac_bg_up
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_ac_bg_up_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 8;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 8;
    
    img_ac_bg_up_timer_cnt++;
    
    // Segment 1: 400ms, 1 action(s)
    if (img_ac_bg_up_timer_cnt > seg0_start && img_ac_bg_up_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_ac_bg_up_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 128 -> 255
            const uint8_t opacity_origin = 128;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_ac_bg_up_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_ac_bg_up_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_ac_on
 * Component: img_ac_bg_dn
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_ac_bg_dn_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 8;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 8;
    
    img_ac_bg_dn_timer_cnt++;
    
    // Segment 1: 800ms, 1 action(s)
    if (img_ac_bg_dn_timer_cnt > seg0_start && img_ac_bg_dn_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_ac_bg_dn_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 0 -> 255
            const uint8_t opacity_origin = 0;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_ac_bg_dn_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_ac_bg_dn_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_ac_off
 * Component: img_ac_bg_dn
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_ac_bg_dn_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 8;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 8;
    
    img_ac_bg_dn_timer_cnt++;
    
    // Segment 1: 800ms, 1 action(s)
    if (img_ac_bg_dn_timer_cnt > seg0_start && img_ac_bg_dn_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_ac_bg_dn_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 255 -> 0
            const uint8_t opacity_origin = 255;
            const uint8_t opacity_target = 0;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_ac_bg_dn_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_ac_bg_dn_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_ac_sw
 * Component: img_ac_bg_dn
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_ac_bg_dn_timer_2_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 8;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 8;
    
    img_ac_bg_dn_timer_cnt++;
    
    // Segment 1: 400ms, 1 action(s)
    if (img_ac_bg_dn_timer_cnt > seg0_start && img_ac_bg_dn_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_ac_bg_dn_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 128 -> 255
            const uint8_t opacity_origin = 128;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_ac_bg_dn_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_ac_bg_dn_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_box
 * Component: img_mode_bg
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_mode_bg_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 6;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 6;
    
    img_mode_bg_timer_cnt++;
    
    // Segment 1: 300ms, 3 action(s)
    if (img_mode_bg_timer_cnt > seg0_start && img_mode_bg_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_mode_bg_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 1 -> 255
            const uint8_t opacity_origin = 1;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust scale: (0.7, 0.7) -> (1, 1)
            const float zoom_x_origin = 0.7;
            const float zoom_x_target = 1;
            const float zoom_y_origin = 0.7;
            const float zoom_y_target = 1;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust position: (0, 140) -> (0, 0)
            const int16_t x_origin = 0;
            const int16_t y_origin = 140;
            const int16_t x_target = 0;
            const int16_t y_target = 0;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_mode_bg_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_mode_bg_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_hot_df
 * Component: img_hot_df
 * Mode: Preset actions (multi-segment animation)
 * Segments: 2
 */
void img_hot_df_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 6;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    const uint16_t seg1_start = 4;
    const uint16_t seg1_end = 6;
    
    img_hot_df_timer_cnt++;
    
    // Segment 1: 200ms, 1 action(s)
    if (img_hot_df_timer_cnt > seg0_start && img_hot_df_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_hot_df_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 0 -> 0
            const uint8_t opacity_origin = 0;
            const uint8_t opacity_target = 0;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    // Segment 2: 100ms, 1 action(s)
    else if (img_hot_df_timer_cnt > seg1_start && img_hot_df_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = img_hot_df_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // Adjust opacity: 128 -> 255
            const uint8_t opacity_origin = 128;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_hot_df_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_hot_df_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_hot
 * Component: img_hot
 * Mode: Preset actions (multi-segment animation)
 * Segments: 2
 */
void img_hot_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 6;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    const uint16_t seg1_start = 4;
    const uint16_t seg1_end = 6;
    
    img_hot_timer_cnt++;
    
    // Segment 1: 200ms, 1 action(s)
    if (img_hot_timer_cnt > seg0_start && img_hot_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_hot_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 0 -> 0
            const uint8_t opacity_origin = 0;
            const uint8_t opacity_target = 0;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    // Segment 2: 100ms, 1 action(s)
    else if (img_hot_timer_cnt > seg1_start && img_hot_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = img_hot_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // Adjust opacity: 128 -> 255
            const uint8_t opacity_origin = 128;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_hot_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_hot_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_cold_df
 * Component: img_cold_df
 * Mode: Preset actions (multi-segment animation)
 * Segments: 2
 */
void img_cold_df_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 6;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    const uint16_t seg1_start = 4;
    const uint16_t seg1_end = 6;
    
    img_cold_df_timer_cnt++;
    
    // Segment 1: 200ms, 1 action(s)
    if (img_cold_df_timer_cnt > seg0_start && img_cold_df_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_cold_df_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 0 -> 0
            const uint8_t opacity_origin = 0;
            const uint8_t opacity_target = 0;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    // Segment 2: 100ms, 1 action(s)
    else if (img_cold_df_timer_cnt > seg1_start && img_cold_df_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = img_cold_df_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // Adjust opacity: 128 -> 255
            const uint8_t opacity_origin = 128;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_cold_df_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_cold_df_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_cold
 * Component: img_cold
 * Mode: Preset actions (multi-segment animation)
 * Segments: 2
 */
void img_cold_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 6;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    const uint16_t seg1_start = 4;
    const uint16_t seg1_end = 6;
    
    img_cold_timer_cnt++;
    
    // Segment 1: 200ms, 1 action(s)
    if (img_cold_timer_cnt > seg0_start && img_cold_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_cold_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 0 -> 0
            const uint8_t opacity_origin = 0;
            const uint8_t opacity_target = 0;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    // Segment 2: 100ms, 1 action(s)
    else if (img_cold_timer_cnt > seg1_start && img_cold_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = img_cold_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // Adjust opacity: 128 -> 255
            const uint8_t opacity_origin = 128;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_cold_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_cold_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_fresh_df
 * Component: img_fresh_df
 * Mode: Preset actions (multi-segment animation)
 * Segments: 2
 */
void img_fresh_df_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 6;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    const uint16_t seg1_start = 4;
    const uint16_t seg1_end = 6;
    
    img_fresh_df_timer_cnt++;
    
    // Segment 1: 200ms, 1 action(s)
    if (img_fresh_df_timer_cnt > seg0_start && img_fresh_df_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_fresh_df_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 0 -> 0
            const uint8_t opacity_origin = 0;
            const uint8_t opacity_target = 0;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    // Segment 2: 100ms, 1 action(s)
    else if (img_fresh_df_timer_cnt > seg1_start && img_fresh_df_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = img_fresh_df_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // Adjust opacity: 128 -> 255
            const uint8_t opacity_origin = 128;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_fresh_df_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_fresh_df_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_fresh
 * Component: img_fresh
 * Mode: Preset actions (multi-segment animation)
 * Segments: 2
 */
void img_fresh_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 6;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    const uint16_t seg1_start = 4;
    const uint16_t seg1_end = 6;
    
    img_fresh_timer_cnt++;
    
    // Segment 1: 200ms, 1 action(s)
    if (img_fresh_timer_cnt > seg0_start && img_fresh_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_fresh_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 0 -> 0
            const uint8_t opacity_origin = 0;
            const uint8_t opacity_target = 0;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    // Segment 2: 100ms, 1 action(s)
    else if (img_fresh_timer_cnt > seg1_start && img_fresh_timer_cnt <= seg1_end) {
        uint16_t seg_cnt = img_fresh_timer_cnt - seg1_start;
        const uint16_t seg_cnt_max = seg1_end - seg1_start;
        
            // Adjust opacity: 128 -> 255
            const uint8_t opacity_origin = 128;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
    }
    
    if (img_fresh_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_fresh_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_hid
 * Component: img_mode_select
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_mode_select_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 5;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 5;
    
    img_mode_select_timer_cnt++;
    gui_log("img_mode_select_timer_0_cb: cnt=%d\n", img_mode_select_timer_cnt);
    
    // Segment 1: 100ms, 2 action(s)
    if (img_mode_select_timer_cnt > seg0_start && img_mode_select_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_mode_select_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 255 -> 1
            const uint8_t opacity_origin = 255;
            const uint8_t opacity_target = 1;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust scale: (1, 1) -> (0.7, 0.7)
            const float zoom_x_origin = 1;
            const float zoom_x_target = 0.7;
            const float zoom_y_origin = 1;
            const float zoom_y_target = 0.7;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
    }
    
    if (img_mode_select_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_mode_select_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_pop
 * Component: img_mode_select
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_mode_select_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 5;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 5;
    
    img_mode_select_timer_cnt++;
    gui_log("img_mode_select_timer_1_cb: cnt=%d\n", img_mode_select_timer_cnt);
    
    // Segment 1: 100ms, 2 action(s)
    if (img_mode_select_timer_cnt > seg0_start && img_mode_select_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_mode_select_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust opacity: 1 -> 255
            const uint8_t opacity_origin = 1;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust scale: (0.7, 0.7) -> (1, 1)
            const float zoom_x_origin = 0.7;
            const float zoom_x_target = 1;
            const float zoom_y_origin = 0.7;
            const float zoom_y_target = 1;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
    }
    
    if (img_mode_select_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_mode_select_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_tmr
 * Component: win_temp
 */
void win_temp_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    // Call the implementation function in protected area (if exists)
    // Define win_temp_timer_0_cb_impl() in custom_functions protected area for custom logic
#ifdef __cplusplus
    extern "C" {
#endif
    extern void win_temp_timer_0_cb_impl(void) __attribute__((weak));
#ifdef __cplusplus
    }
#endif
    
    if (win_temp_timer_0_cb_impl) {
        win_temp_timer_0_cb_impl();
    } else {
        // TODO: Implement timer callback logic
        // Or define win_temp_timer_0_cb_impl() in custom_functions protected area
    }
}

/**
 * ani_hide
 * Component: img_lt_bar_tmp
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_lt_bar_tmp_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_lt_bar_tmp_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_lt_bar_tmp_timer_cnt > seg0_start && img_lt_bar_tmp_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_lt_bar_tmp_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (1, 1) -> (0.7, 0.7)
            const float zoom_x_origin = 1;
            const float zoom_x_target = 0.7;
            const float zoom_y_origin = 1;
            const float zoom_y_target = 0.7;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 255 -> 90
            const uint8_t opacity_origin = 255;
            const uint8_t opacity_target = 90;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (0, 4) -> (0, 4)
            const int16_t x_origin = 0;
            const int16_t y_origin = 4;
            const int16_t x_target = 0;
            const int16_t y_target = 4;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_lt_bar_tmp_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_lt_bar_tmp_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_pop
 * Component: img_lt_bar_tmp
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_lt_bar_tmp_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_lt_bar_tmp_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_lt_bar_tmp_timer_cnt > seg0_start && img_lt_bar_tmp_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_lt_bar_tmp_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (0.7, 0.7) -> (1, 1)
            const float zoom_x_origin = 0.7;
            const float zoom_x_target = 1;
            const float zoom_y_origin = 0.7;
            const float zoom_y_target = 1;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 90 -> 255
            const uint8_t opacity_origin = 90;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (0, 4) -> (0, 4)
            const int16_t x_origin = 0;
            const int16_t y_origin = 4;
            const int16_t x_target = 0;
            const int16_t y_target = 4;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_lt_bar_tmp_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_lt_bar_tmp_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_hide
 * Component: img_temp_knob
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_temp_knob_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_temp_knob_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_temp_knob_timer_cnt > seg0_start && img_temp_knob_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_temp_knob_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (1, 1) -> (0.7, 0.7)
            const float zoom_x_origin = 1;
            const float zoom_x_target = 0.7;
            const float zoom_y_origin = 1;
            const float zoom_y_target = 0.7;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 255 -> 100
            const uint8_t opacity_origin = 255;
            const uint8_t opacity_target = 100;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (4, 0) -> (-35, 0)
            const int16_t x_origin = 4;
            const int16_t y_origin = 0;
            const int16_t x_target = -35;
            const int16_t y_target = 0;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_temp_knob_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_temp_knob_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_pop
 * Component: img_temp_knob
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_temp_knob_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_temp_knob_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_temp_knob_timer_cnt > seg0_start && img_temp_knob_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_temp_knob_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (0.7, 0.7) -> (1, 1)
            const float zoom_x_origin = 0.7;
            const float zoom_x_target = 1;
            const float zoom_y_origin = 0.7;
            const float zoom_y_target = 1;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 90 -> 255
            const uint8_t opacity_origin = 90;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (4, 0) -> (4, 0)
            const int16_t x_origin = 4;
            const int16_t y_origin = 0;
            const int16_t x_target = 4;
            const int16_t y_target = 0;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_temp_knob_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_temp_knob_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_tmr
 * Component: win_lgtn
 */
void win_lgtn_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    // Call the implementation function in protected area (if exists)
    // Define win_lgtn_timer_0_cb_impl() in custom_functions protected area for custom logic
#ifdef __cplusplus
    extern "C" {
#endif
    extern void win_lgtn_timer_0_cb_impl(void) __attribute__((weak));
#ifdef __cplusplus
    }
#endif
    
    if (win_lgtn_timer_0_cb_impl) {
        win_lgtn_timer_0_cb_impl();
    } else {
        // TODO: Implement timer callback logic
        // Or define win_lgtn_timer_0_cb_impl() in custom_functions protected area
    }
}

/**
 * ani_hide
 * Component: img_lt_bar_0
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_lt_bar_0_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_lt_bar_0_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_lt_bar_0_timer_cnt > seg0_start && img_lt_bar_0_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_lt_bar_0_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (1, 1) -> (0.7, 0.7)
            const float zoom_x_origin = 1;
            const float zoom_x_target = 0.7;
            const float zoom_y_origin = 1;
            const float zoom_y_target = 0.7;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 255 -> 90
            const uint8_t opacity_origin = 255;
            const uint8_t opacity_target = 90;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (50, 5) -> (50, 5)
            const int16_t x_origin = 50;
            const int16_t y_origin = 5;
            const int16_t x_target = 50;
            const int16_t y_target = 5;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_lt_bar_0_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_lt_bar_0_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_pop
 * Component: img_lt_bar_0
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_lt_bar_0_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_lt_bar_0_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_lt_bar_0_timer_cnt > seg0_start && img_lt_bar_0_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_lt_bar_0_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (0.7, 0.7) -> (1, 1)
            const float zoom_x_origin = 0.7;
            const float zoom_x_target = 1;
            const float zoom_y_origin = 0.7;
            const float zoom_y_target = 1;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 90 -> 255
            const uint8_t opacity_origin = 90;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (50, 5) -> (50, 5)
            const int16_t x_origin = 50;
            const int16_t y_origin = 5;
            const int16_t x_target = 50;
            const int16_t y_target = 5;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_lt_bar_0_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_lt_bar_0_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_tmr
 * Component: win_clr
 */
void win_clr_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    // Call the implementation function in protected area (if exists)
    // Define win_clr_timer_0_cb_impl() in custom_functions protected area for custom logic
#ifdef __cplusplus
    extern "C" {
#endif
    extern void win_clr_timer_0_cb_impl(void) __attribute__((weak));
#ifdef __cplusplus
    }
#endif
    
    if (win_clr_timer_0_cb_impl) {
        win_clr_timer_0_cb_impl();
    } else {
        // TODO: Implement timer callback logic
        // Or define win_clr_timer_0_cb_impl() in custom_functions protected area
    }
}

/**
 * ani_hide
 * Component: img_lt_bar_clr
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_lt_bar_clr_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_lt_bar_clr_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_lt_bar_clr_timer_cnt > seg0_start && img_lt_bar_clr_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_lt_bar_clr_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (1, 1) -> (0.7, 0.7)
            const float zoom_x_origin = 1;
            const float zoom_x_target = 0.7;
            const float zoom_y_origin = 1;
            const float zoom_y_target = 0.7;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 255 -> 90
            const uint8_t opacity_origin = 255;
            const uint8_t opacity_target = 90;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (0, 4) -> (0, 4)
            const int16_t x_origin = 0;
            const int16_t y_origin = 4;
            const int16_t x_target = 0;
            const int16_t y_target = 4;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_lt_bar_clr_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_lt_bar_clr_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_pop
 * Component: img_lt_bar_clr
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_lt_bar_clr_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_lt_bar_clr_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_lt_bar_clr_timer_cnt > seg0_start && img_lt_bar_clr_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_lt_bar_clr_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (0.7, 0.7) -> (1, 1)
            const float zoom_x_origin = 0.7;
            const float zoom_x_target = 1;
            const float zoom_y_origin = 0.7;
            const float zoom_y_target = 1;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 90 -> 255
            const uint8_t opacity_origin = 90;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (0, 4) -> (0, 4)
            const int16_t x_origin = 0;
            const int16_t y_origin = 4;
            const int16_t x_target = 0;
            const int16_t y_target = 4;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_lt_bar_clr_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_lt_bar_clr_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_hide
 * Component: img_clr_knob
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_clr_knob_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_clr_knob_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_clr_knob_timer_cnt > seg0_start && img_clr_knob_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_clr_knob_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (1, 1) -> (0.7, 0.7)
            const float zoom_x_origin = 1;
            const float zoom_x_target = 0.7;
            const float zoom_y_origin = 1;
            const float zoom_y_target = 0.7;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 255 -> 100
            const uint8_t opacity_origin = 255;
            const uint8_t opacity_target = 100;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (4, 0) -> (-35, 0)
            const int16_t x_origin = 4;
            const int16_t y_origin = 0;
            const int16_t x_target = -35;
            const int16_t y_target = 0;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_clr_knob_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_clr_knob_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_pop
 * Component: img_clr_knob
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_clr_knob_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_clr_knob_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_clr_knob_timer_cnt > seg0_start && img_clr_knob_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_clr_knob_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (0.7, 0.7) -> (1, 1)
            const float zoom_x_origin = 0.7;
            const float zoom_x_target = 1;
            const float zoom_y_origin = 0.7;
            const float zoom_y_target = 1;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 90 -> 255
            const uint8_t opacity_origin = 90;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (4, 0) -> (4, 0)
            const int16_t x_origin = 4;
            const int16_t y_origin = 0;
            const int16_t x_target = 4;
            const int16_t y_target = 0;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_clr_knob_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_clr_knob_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_tmr
 * Component: win_lgtnn
 */
void win_clr_lgtn_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    // Call the implementation function in protected area (if exists)
    // Define win_clr_lgtn_timer_0_cb_impl() in custom_functions protected area for custom logic
#ifdef __cplusplus
    extern "C" {
#endif
    extern void win_clr_lgtn_timer_0_cb_impl(void) __attribute__((weak));
#ifdef __cplusplus
    }
#endif
    
    if (win_clr_lgtn_timer_0_cb_impl) {
        win_clr_lgtn_timer_0_cb_impl();
    } else {
        // TODO: Implement timer callback logic
        // Or define win_clr_lgtn_timer_0_cb_impl() in custom_functions protected area
    }
}

/**
 * ani_hide
 * Component: img_lt_bar_1
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_lt_bar_1_timer_0_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_lt_bar_1_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_lt_bar_1_timer_cnt > seg0_start && img_lt_bar_1_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_lt_bar_1_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (1, 1) -> (0.7, 0.7)
            const float zoom_x_origin = 1;
            const float zoom_x_target = 0.7;
            const float zoom_y_origin = 1;
            const float zoom_y_target = 0.7;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 255 -> 90
            const uint8_t opacity_origin = 255;
            const uint8_t opacity_target = 90;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (50, 5) -> (50, 5)
            const int16_t x_origin = 50;
            const int16_t y_origin = 5;
            const int16_t x_target = 50;
            const int16_t y_target = 5;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_lt_bar_1_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_lt_bar_1_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_pop
 * Component: img_lt_bar_1
 * Mode: Preset actions (multi-segment animation)
 * Segments: 1
 */
void img_lt_bar_1_timer_1_cb(void *obj)
{
    gui_obj_t *target = (gui_obj_t *)obj;
    const uint16_t total_cnt_max = 4;
    
    const uint16_t seg0_start = 0;
    const uint16_t seg0_end = 4;
    
    img_lt_bar_1_timer_cnt++;
    
    // Segment 1: 200ms, 3 action(s)
    if (img_lt_bar_1_timer_cnt > seg0_start && img_lt_bar_1_timer_cnt <= seg0_end) {
        uint16_t seg_cnt = img_lt_bar_1_timer_cnt - seg0_start;
        const uint16_t seg_cnt_max = seg0_end - seg0_start;
        
            // Adjust scale: (0.7, 0.7) -> (1, 1)
            const float zoom_x_origin = 0.7;
            const float zoom_x_target = 1;
            const float zoom_y_origin = 0.7;
            const float zoom_y_target = 1;
            float zoom_x_cur = zoom_x_origin + (zoom_x_target - zoom_x_origin) * seg_cnt / seg_cnt_max;
            float zoom_y_cur = zoom_y_origin + (zoom_y_target - zoom_y_origin) * seg_cnt / seg_cnt_max;
            gui_img_scale((gui_img_t *)target, zoom_x_cur, zoom_y_cur);
            
            // Adjust opacity: 90 -> 255
            const uint8_t opacity_origin = 90;
            const uint8_t opacity_target = 255;
            int16_t opacity_cur = opacity_origin + (opacity_target - opacity_origin) * seg_cnt / seg_cnt_max;
            gui_img_set_opacity((gui_img_t *)target, opacity_cur);
            
            // Adjust position: (50, 5) -> (50, 5)
            const int16_t x_origin = 50;
            const int16_t y_origin = 5;
            const int16_t x_target = 50;
            const int16_t y_target = 5;
            int16_t x_cur = x_origin + (x_target - x_origin) * seg_cnt / seg_cnt_max;
            int16_t y_cur = y_origin + (y_target - y_origin) * seg_cnt / seg_cnt_max;
            gui_obj_move(target, x_cur, y_cur);
            
    }
    
    if (img_lt_bar_1_timer_cnt >= total_cnt_max) {
        gui_obj_stop_timer(target);
        img_lt_bar_1_timer_cnt = 0; // Reset counter
    }
}


/**
 * ani_curtain
 * Component: img_cur
 */
void img_cur_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    // Call the implementation function in protected area (if exists)
    // Define img_cur_timer_0_cb_impl() in custom_functions protected area for custom logic
#ifdef __cplusplus
    extern "C" {
#endif
    extern void img_cur_timer_0_cb_impl(void) __attribute__((weak));
#ifdef __cplusplus
    }
#endif
    
    if (img_cur_timer_0_cb_impl) {
        img_cur_timer_0_cb_impl();
    } else {
        // TODO: Implement timer callback logic
        // Or define img_cur_timer_0_cb_impl() in custom_functions protected area
    }
}

// Toggle button state callback functions

/* USER CODE BEGIN btn_ac_on_callback */
/**
 * btn_ac ON state callback
 * Called when button switches to ON state
 */
void btn_ac_on_callback(void)
{
    // TODO: Implement ON state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_play();
}
/* USER CODE END btn_ac_on_callback */

/* USER CODE BEGIN btn_ac_off_callback */
/**
 * btn_ac OFF state callback
 * Called when button switches to OFF state
 */
void btn_ac_off_callback(void)
{
    // TODO: Implement OFF state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_pause();
}
/* USER CODE END btn_ac_off_callback */

/* @protected start custom_functions */
// Custom functions

/* AC */

void ani_ac_turnon_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        img_ac_bg_up_timer_cnt = 0; // Reset counter
        gui_obj_create_timer(GUI_BASE(img_ac_bg_up), 100, true, img_ac_bg_up_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(img_ac_bg_up));

        img_ac_bg_mid_timer_cnt = 0; // Reset counter
        gui_obj_create_timer(GUI_BASE(img_ac_bg_mid), 100, true, img_ac_bg_mid_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(img_ac_bg_mid));

        img_ac_bg_dn_timer_cnt = 0; // Reset counter
        gui_obj_create_timer(GUI_BASE(img_ac_bg_dn), 100, true, img_ac_bg_dn_timer_0_cb);
        gui_obj_start_timer(GUI_BASE(img_ac_bg_dn));
    }
}

void ani_ac_turnoff_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        img_ac_bg_up_timer_cnt = 0; // Reset counter
        gui_obj_create_timer(GUI_BASE(img_ac_bg_up), 100, true, img_ac_bg_up_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(img_ac_bg_up));

        img_ac_bg_mid_timer_cnt = 0; // Reset counter
        gui_obj_create_timer(GUI_BASE(img_ac_bg_mid), 100, true, img_ac_bg_mid_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(img_ac_bg_mid));

        img_ac_bg_dn_timer_cnt = 0; // Reset counter
        gui_obj_create_timer(GUI_BASE(img_ac_bg_dn), 100, true, img_ac_bg_dn_timer_1_cb);
        gui_obj_start_timer(GUI_BASE(img_ac_bg_dn));
    }
}


// function declare
extern void light_tmp_update_light(void);
extern void light_set_ltn_bar(void *obj, uint8_t val);
extern void light_clr_update_light(void);


void win_temp_timer_0_cb_impl(void)
{
    extern uint8_t light_tmp_idx;
    uint8_t index =  gui_list_get_current_note(list_bar_temp);
    if(light_tmp_idx != index)
    {
        // gui_log("win_temp_timer_0_cb_impl %d\n", index);
        light_tmp_idx = index;

        light_tmp_update_light();
    }
}

void win_lgtn_timer_0_cb_impl(void)
{
    extern uint8_t light_ltn_idx_0;
    uint8_t index =  gui_list_get_current_note(lst_lt_bar_0);

    // gui_log("win_lgtn_timer_0_cb_impl");
    if(light_ltn_idx_0 != index)
    {
        extern uint8_t light_ltn_0;
        // gui_log("win_lgtn_timer_0_cb_impl %d\n", index);
        light_ltn_idx_0 = index;
        uint8_t val = (23 - index) * 4.34f;
        uint8_t val_5 =  val + 5 * ((val % 5 > 2)? 1:0) - (val % 5);
        // gui_log("val  %d   val_5  %d \n", val, val_5);
        
        if(light_ltn_0 != val_5)
        {
            light_set_ltn_bar(img_lt_bar_0, val_5);
            light_ltn_0 = val_5;

            light_tmp_update_light();
        }
        
    }

}


void win_clr_timer_0_cb_impl(void)
{
    extern uint8_t light_clr_idx;
    uint8_t index =  gui_list_get_current_note(list_bar_clr);
    if(light_clr_idx != index)
    {
        // gui_log("win_temp_timer_0_cb_impl %d\n", index);
        light_clr_idx = index;

        light_clr_update_light();
    }
}

void win_clr_lgtn_timer_0_cb_impl(void)
{
    extern uint8_t light_ltn_idx_1;
    uint8_t index =  gui_list_get_current_note(lst_lt_bar_1);

    // gui_log("win_lgtn_timer_0_cb_impl");
    if(light_ltn_idx_1 != index)
    {
        extern uint8_t light_ltn_1;
        // gui_log("win_lgtn_timer_0_cb_impl %d\n", index);
        light_ltn_idx_1 = index;
        uint8_t val = (23 - index) * 4.34f;
        uint8_t val_5 =  val + 5 * ((val % 5 > 2)? 1:0) - (val % 5);
        // gui_log("val  %d   val_5  %d \n", val, val_5);
        
        if(light_ltn_1 != val_5)
        {
            light_set_ltn_bar(img_lt_bar_1, val_5);
            light_ltn_1 = val_5;

            light_clr_update_light();
        }
        
    }

}

// function declare
extern uint8_t curtn_ani_idx;
extern uint8_t curtn_status;
extern uint8_t curtn_status_cache;

extern void curtn_update_img(void);



void img_cur_timer_0_cb_impl(void)
{
    static uint8_t lst_cur_idx = 10;

    if(curtn_status == 1) // CURTN_OPENING
    {
        curtn_ani_idx = (curtn_ani_idx == 24)? 24:curtn_ani_idx + 1;
    }
    else if(curtn_status == 2) // CURTN_OPENING
    {
        curtn_ani_idx = (curtn_ani_idx == 0)? 0:curtn_ani_idx - 1;
    }


    if(lst_cur_idx != curtn_ani_idx)
    {
        lst_cur_idx = curtn_ani_idx;
        curtn_update_img();
    }
    

    if((curtn_ani_idx == 24) || (curtn_ani_idx == 0))
    {
        curtn_status = 0; // STOP
        curtn_status_cache = 0;
    }
}
/* @protected end custom_functions */
