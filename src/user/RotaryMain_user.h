#ifndef ROTARYMAIN_USER_H
#define ROTARYMAIN_USER_H

#include "../callbacks/RotaryMain_callbacks.h"
#include "../ui/RotaryMain_ui.h"

/**
 * User-defined header file
 * This file is generated once only, feel free to modify
 */

// Add custom declarations here
void empty_cb(void *obj, gui_event_t *e);

void ac_show_cb(void *obj, gui_event_t *e);

void ac_pop_mod_cb(void *obj, gui_event_t *e);
void ac_hide_mod_cb(void *obj, gui_event_t *e);


void ac_select_mod_heat_cb(void *obj, gui_event_t *e);
void ac_select_mod_cold_cb(void *obj, gui_event_t *e);
void ac_select_mod_fresh_cb(void *obj, gui_event_t *e);
// void ac_btntest_cb(void *obj, gui_event_t *e);
void ac_btn_sw_fan_cb(void *obj, gui_event_t *e);



void ac_btn_0_click_cb(void *obj, gui_event_t *e);
void ac_btn_1_click_cb(void *obj, gui_event_t *e);
void ac_btn_2_click_cb(void *obj, gui_event_t *e);

void ac_btn_long_press_cb(void *obj, gui_event_t *e);



// light
void light_tmp_show_cb(void *obj, gui_event_t *e);
void light_tmp_click_tmp_cb(void *obj, gui_event_t *e);
void light_tmp_click_lgt_cb(void *obj, gui_event_t *e);

void light_tmp_btn_0_click_cb(void *obj, gui_event_t *e);
void light_tmp_btn_1_click_cb(void *obj, gui_event_t *e);
void light_tmp_btn_2_click_cb(void *obj, gui_event_t *e);
void light_tmp_btn_long_press_cb(void *obj, gui_event_t *e);
// color light 
void light_clr_show_cb(void *obj, gui_event_t *e);
void light_clr_click_clr_cb(void *obj, gui_event_t *e);
void light_clr_click_lgt_cb(void *obj, gui_event_t *e);

void light_clr_btn_0_click_cb(void *obj, gui_event_t *e);
void light_clr_btn_1_click_cb(void *obj, gui_event_t *e);
void light_clr_btn_2_click_cb(void *obj, gui_event_t *e);
void light_clr_btn_long_press_cb(void *obj, gui_event_t *e);

// curtain
void curtn_show_cb(void *obj, gui_event_t *e);
void curtn_click_open_cb(void *obj, gui_event_t *e);
void curtn_click_close_cb(void *obj, gui_event_t *e);
void curtn_click_stop_cb(void *obj, gui_event_t *e);

void curtn_btn_0_click_cb(void *obj, gui_event_t *e);
void curtn_btn_1_click_cb(void *obj, gui_event_t *e);
void curtn_btn_2_click_cb(void *obj, gui_event_t *e);
#endif // ROTARYMAIN_USER_H
