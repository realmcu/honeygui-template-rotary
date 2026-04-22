#ifndef ROTARYMAIN_CALLBACKS_H
#define ROTARYMAIN_CALLBACKS_H

#include "gui_api.h"
#include "gui_text.h"
#include "gui_obj_focus.h"

// Timer animation counters (defined in callbacks.c)
extern uint16_t img_ac_bg_mid_timer_cnt;
extern uint16_t img_ac_bg_up_timer_cnt;
extern uint16_t img_ac_bg_dn_timer_cnt;
extern uint16_t img_mode_bg_timer_cnt;
extern uint16_t img_hot_df_timer_cnt;
extern uint16_t img_hot_timer_cnt;
extern uint16_t img_cold_df_timer_cnt;
extern uint16_t img_cold_timer_cnt;
extern uint16_t img_fresh_df_timer_cnt;
extern uint16_t img_fresh_timer_cnt;
extern uint16_t img_mode_select_timer_cnt;
extern uint16_t win_temp_timer_cnt;
extern uint16_t img_lt_bar_tmp_timer_cnt;
extern uint16_t img_temp_knob_timer_cnt;
extern uint16_t win_lgtn_timer_cnt;
extern uint16_t img_lt_bar_0_timer_cnt;
extern uint16_t win_clr_timer_cnt;
extern uint16_t img_lt_bar_clr_timer_cnt;
extern uint16_t img_clr_knob_timer_cnt;
extern uint16_t win_lgtnn_timer_cnt;
extern uint16_t img_lt_bar_1_timer_cnt;
extern uint16_t img_cur_timer_cnt;

// Event callback function declarations
void ac_btn_0_click_cb(void *obj, gui_event_t *e);
void ac_btn_1_click_cb(void *obj, gui_event_t *e);
void ac_btn_2_click_cb(void *obj, gui_event_t *e);
void ac_btn_long_press_cb(void *obj, gui_event_t *e);
void curtn_btn_0_click_cb(void *obj, gui_event_t *e);
void curtn_btn_1_click_cb(void *obj, gui_event_t *e);
void curtn_btn_2_click_cb(void *obj, gui_event_t *e);
void empty_cb(void *obj, gui_event_t *e);
void hg_image_1770607273521_70ob_clicked_cb(void *obj, gui_event_t *e);
void hg_image_1770607673557_iiv2_clicked_cb(void *obj, gui_event_t *e);
void hg_image_1770607676005_3nc2_clicked_cb(void *obj, gui_event_t *e);
void hg_image_1770607679223_o1zm_clicked_cb(void *obj, gui_event_t *e);
void hg_image_1770607688255_n4di_clicked_cb(void *obj, gui_event_t *e);
void hg_image_1770607691358_qraa_clicked_cb(void *obj, gui_event_t *e);
void img_56_clicked_cb(void *obj, gui_event_t *e);
void img_57_clicked_cb(void *obj, gui_event_t *e);
void img_cold_df_clicked_cb(void *obj, gui_event_t *e);
void img_fresh_df_clicked_cb(void *obj, gui_event_t *e);
void img_hot_df_clicked_cb(void *obj, gui_event_t *e);
void img_lt_bar_0_clicked_cb(void *obj, gui_event_t *e);
void img_lt_bar_1_clicked_cb(void *obj, gui_event_t *e);
void img_lt_bar_clr_clicked_cb(void *obj, gui_event_t *e);
void img_lt_bar_tmp_clicked_cb(void *obj, gui_event_t *e);
void img_mode_bg_released_cb(void *obj, gui_event_t *e);
void img_mode_select_clicked_cb(void *obj, gui_event_t *e);
void light_clr_btn_0_click_cb(void *obj, gui_event_t *e);
void light_clr_btn_1_click_cb(void *obj, gui_event_t *e);
void light_clr_btn_2_click_cb(void *obj, gui_event_t *e);
void light_clr_btn_long_press_cb(void *obj, gui_event_t *e);
void light_tmp_btn_0_click_cb(void *obj, gui_event_t *e);
void light_tmp_btn_1_click_cb(void *obj, gui_event_t *e);
void light_tmp_btn_2_click_cb(void *obj, gui_event_t *e);
void light_tmp_btn_long_press_cb(void *obj, gui_event_t *e);
void view_ac_clicked_0_cb(void *obj, gui_event_t *e);
void view_ac_key_0_cb(void *obj, gui_event_t *e);
void view_ac_key_1_cb(void *obj, gui_event_t *e);
void view_curtain_key_0_cb(void *obj, gui_event_t *e);
void view_light_color_key_0_cb(void *obj, gui_event_t *e);
void view_light_color_key_1_cb(void *obj, gui_event_t *e);
void view_light_key_0_cb(void *obj, gui_event_t *e);
void view_light_key_1_cb(void *obj, gui_event_t *e);

// User-configured timer callback function declarations
void img_ac_bg_mid_timer_0_cb(void *obj);
void img_ac_bg_mid_timer_1_cb(void *obj);
void img_ac_bg_mid_timer_2_cb(void *obj);
void img_ac_bg_up_timer_0_cb(void *obj);
void img_ac_bg_up_timer_1_cb(void *obj);
void img_ac_bg_up_timer_2_cb(void *obj);
void img_ac_bg_dn_timer_0_cb(void *obj);
void img_ac_bg_dn_timer_1_cb(void *obj);
void img_ac_bg_dn_timer_2_cb(void *obj);
void img_mode_bg_timer_0_cb(void *obj);
void img_hot_df_timer_0_cb(void *obj);
void img_hot_timer_0_cb(void *obj);
void img_cold_df_timer_0_cb(void *obj);
void img_cold_timer_0_cb(void *obj);
void img_fresh_df_timer_0_cb(void *obj);
void img_fresh_timer_0_cb(void *obj);
void img_mode_select_timer_0_cb(void *obj);
void img_mode_select_timer_1_cb(void *obj);
void win_temp_timer_0_cb(void *obj);
void img_lt_bar_tmp_timer_0_cb(void *obj);
void img_lt_bar_tmp_timer_1_cb(void *obj);
void img_temp_knob_timer_0_cb(void *obj);
void img_temp_knob_timer_1_cb(void *obj);
void win_lgtn_timer_0_cb(void *obj);
void img_lt_bar_0_timer_0_cb(void *obj);
void img_lt_bar_0_timer_1_cb(void *obj);
void win_clr_timer_0_cb(void *obj);
void img_lt_bar_clr_timer_0_cb(void *obj);
void img_lt_bar_clr_timer_1_cb(void *obj);
void img_clr_knob_timer_0_cb(void *obj);
void img_clr_knob_timer_1_cb(void *obj);
void win_clr_lgtn_timer_0_cb(void *obj);
void img_lt_bar_1_timer_0_cb(void *obj);
void img_lt_bar_1_timer_1_cb(void *obj);
void img_cur_timer_0_cb(void *obj);

// Toggle button state callback function declarations
void btn_ac_on_callback(void);
void btn_ac_off_callback(void);

// Custom function declarations (auto-extracted from callbacks.c protected area)
void ani_ac_turnon_cb(void *obj, gui_event_t *e);
void ani_ac_turnoff_cb(void *obj, gui_event_t *e);
void light_tmp_update_light(void);
void light_set_ltn_bar(void *obj, uint8_t val);
void light_clr_update_light(void);
void win_temp_timer_0_cb_impl(void);
void win_lgtn_timer_0_cb_impl(void);
void win_clr_timer_0_cb_impl(void);
void win_clr_lgtn_timer_0_cb_impl(void);
void curtn_update_img(void);
void img_cur_timer_0_cb_impl(void);

#endif // ROTARYMAIN_CALLBACKS_H
