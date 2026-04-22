#include "RotaryMain_user.h"

/**
 * User-defined implementation
 * This file is generated once only, feel free to modify
 */

// Add custom implementations here

/***
 * Template function
 * Distinguish development environments
 */
// void user_defined_func_called_by_event(void *obj, gui_event_t *e)
// {
//     GUI_UNUSED(obj);
//     GUI_UNUSED(e);
// #ifdef _HONEYGUI_SIMULATOR_
//     // TODO
// #else
//     // TODO
// #endif
// }

// void user_defined_func_called_by_msg(gui_obj_t *obj, const char *topic, void *data, uint16_t len)
// {
//     GUI_UNUSED(obj);
//     GUI_UNUSED(topic);
//     GUI_UNUSED(data);
//     GUI_UNUSED(len);
// #ifdef _HONEYGUI_SIMULATOR_
//     // TODO
// #else
//     // TODO
// #endif
// }

void empty_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("empty_cb\n");
}

typedef enum {
    AC_STATUS_OFF    = 0,
    AC_STATUS_HEAT,
    AC_STATUS_COLD,
    AC_STATUS_FRESH
}AC_STATUS;




static uint8_t ac_mod_box_show = false;
static uint8_t ac_tab_temp_fan = false;  // 0: temp, 1: fan
static uint8_t ac_status = AC_STATUS_HEAT;
static uint8_t ac_mod = AC_STATUS_HEAT;
static uint8_t ac_mod_selecting = AC_STATUS_HEAT;
static uint8_t ac_temp = 19;
static uint8_t ac_speed = 3;


static void ac_set_bg_src(const char *path)
{
    gui_img_set_src(img_ac_bg_up,  path, IMG_SRC_FILESYS);
    gui_img_set_src(img_ac_bg_mid, path, IMG_SRC_FILESYS);
    gui_img_set_src(img_ac_bg_dn,  path, IMG_SRC_FILESYS);
}
static void ac_set_bg_opa(uint8_t opa)
{
    gui_img_set_opacity((gui_img_t *)img_ac_bg_up,  opa);
    gui_img_set_opacity((gui_img_t *)img_ac_bg_mid, opa);
    gui_img_set_opacity((gui_img_t *)img_ac_bg_dn,  opa);
}

static void ac_get_temp_index(uint8_t *ten_index, uint8_t *lst_index)
{
    *lst_index = (ac_temp % 10) + 1;
    *ten_index = (ac_temp / 10) - 1;
}

void ac_show_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("ac_show_cb\n");
    switch(ac_mod)
    {
        case AC_STATUS_HEAT:
        {
            ac_set_bg_src("/ac/ac_heat.bin");
            break;
        }
        case AC_STATUS_COLD:
        {
            ac_set_bg_src("/ac/ac_cold.bin");
            break;
        }
        case AC_STATUS_FRESH:
        {
            ac_set_bg_src("/ac/ac_fresh.bin");
            break;
        }
    }
    uint8_t ten_index = 0, lst_index = 0;
    ac_get_temp_index(&ten_index, &lst_index);
    gui_list_jump_to_note(lst_unit, lst_index);
    gui_list_jump_to_note(lst_ten, ten_index);
    gui_list_jump_to_note(lst_fan, ac_speed - 1);
    btn_ac_set_state(true);

    ac_set_bg_opa((ac_status == AC_STATUS_OFF)? 0:255);    
}



void ac_pop_mod_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("ac_pop_mod_cb");
    ac_mod_box_show = true;
    ac_mod_selecting = ac_mod;
    gui_obj_show((gui_obj_t *)win_mode, true);

    gui_img_set_opacity((gui_img_t *)img_mode_bg, 0);
    gui_img_set_opacity((gui_img_t *)img_hot, 0);
    gui_img_set_opacity((gui_img_t *)img_cold, 0);
    gui_img_set_opacity((gui_img_t *)img_fresh, 0);
    gui_img_set_opacity((gui_img_t *)img_hot_df, 0);
    gui_img_set_opacity((gui_img_t *)img_cold_df, 0);
    gui_img_set_opacity((gui_img_t *)img_fresh_df, 0);
    switch(ac_mod){
        case AC_STATUS_HEAT:
        {
            img_hot_timer_cnt = 0; // Reset counter
            gui_obj_create_timer(GUI_BASE(img_hot), 100, true, img_hot_timer_0_cb);
            gui_obj_start_timer(GUI_BASE(img_hot));
            gui_obj_show((gui_obj_t *)img_hot, true);
            break;
        }
        case AC_STATUS_COLD:
        {
            img_cold_timer_cnt = 0; // Reset counter
            gui_obj_create_timer(GUI_BASE(img_cold), 100, true, img_cold_timer_0_cb);
            gui_obj_start_timer(GUI_BASE(img_cold));
            gui_obj_show((gui_obj_t *)img_cold, true);
            break;
        }
        case AC_STATUS_FRESH:
        {
            img_fresh_timer_cnt = 0; // Reset counter
            gui_obj_create_timer(GUI_BASE(img_fresh), 100, true, img_fresh_timer_0_cb);
            gui_obj_start_timer(GUI_BASE(img_fresh));
            gui_obj_show((gui_obj_t *)img_fresh, true);
            break;
        }
    }
}


void ac_hide_mod_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("ac_hide_mod_cb");
    ac_mod_box_show = false;
    gui_obj_show((gui_obj_t *)win_mode, false);
}



/* select mode cb */
static void ac_selecting_mod_ui(uint8_t mod)
{
    gui_obj_show((gui_obj_t *)img_hot, false);
    gui_obj_show((gui_obj_t *)img_cold, false);
    gui_obj_show((gui_obj_t *)img_fresh, false);

    switch(mod)
    {
        case AC_STATUS_HEAT:
        {
            gui_img_set_opacity((gui_img_t *)img_hot, 255);
            gui_obj_show((gui_obj_t *)img_hot, true);
            break;
        }
        case AC_STATUS_COLD:
        {
            gui_img_set_opacity((gui_img_t *)img_cold, 255);
            gui_obj_show((gui_obj_t *)img_cold, true);
            break;
        }
        case AC_STATUS_FRESH:
        {
            gui_img_set_opacity((gui_img_t *)img_fresh, 255);
            gui_obj_show((gui_obj_t *)img_fresh, true);
            break;
        }
    }
}

void ac_select_mod_heat_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("ac_select_mod_heat_cb\n");

    gui_img_set_opacity((gui_img_t *)img_hot, 255);
    gui_obj_show((gui_obj_t *)img_hot, true);
    gui_obj_show((gui_obj_t *)img_cold, false);
    gui_obj_show((gui_obj_t *)img_fresh, false);

    ac_set_bg_src("/ac/ac_heat.bin");
    ac_set_bg_opa(128);

    ac_mod = AC_STATUS_HEAT;
    ac_status = AC_STATUS_HEAT;
    ac_mod_selecting = ac_mod;
}

void ac_select_mod_cold_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("ac_select_mod_cold_cb\n");

    gui_img_set_opacity((gui_img_t *)img_cold, 255);
    gui_obj_show((gui_obj_t *)img_cold, true);
    gui_obj_show((gui_obj_t *)img_hot, false);
    gui_obj_show((gui_obj_t *)img_fresh, false);

    ac_set_bg_src("/ac/ac_cold.bin");
    ac_set_bg_opa(128);

    ac_mod = AC_STATUS_COLD;
    ac_status = AC_STATUS_COLD;
    ac_mod_selecting = ac_mod;
}

void ac_select_mod_fresh_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("ac_select_mod_cold_cb\n");

    gui_img_set_opacity((gui_img_t *)img_fresh, 255);
    gui_obj_show((gui_obj_t *) img_fresh, true);
    gui_obj_show((gui_obj_t *)img_hot, false);
    gui_obj_show((gui_obj_t *)img_cold, false);

    ac_set_bg_src("/ac/ac_fresh.bin");
    ac_set_bg_opa(128);

    ac_mod = AC_STATUS_FRESH;
    ac_status = AC_STATUS_FRESH;
    ac_mod_selecting = ac_mod;
}

void ac_btn_sw_fan_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("ac_btn_sw_fan_cb\n");
    ac_tab_temp_fan = !ac_tab_temp_fan;

    if(ac_tab_temp_fan)
    {
        gui_obj_show((gui_obj_t *)win_ac_temp, false);
        gui_obj_show((gui_obj_t *)win_ac_fan, true);
    }
    else
    {
        gui_obj_show((gui_obj_t *)win_ac_temp, true);
        gui_obj_show((gui_obj_t *)win_ac_fan, false);
    }
}


// void ac_btntest_cb(void *obj, gui_event_t *e)
// {
//     GUI_UNUSED(obj);
//     GUI_UNUSED(e);
//     gui_log("ac_btntest_cb");
// }

/* button cb*/
void ac_btn_0_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("ac_btn_click_cb");

    if(ac_mod_box_show == false)
    {
        img_mode_select_clicked_cb(obj, e);
    }
    else
    {
        ac_mod = ac_mod_selecting;
        // bg animation
        switch(ac_mod)
        {
            case AC_STATUS_HEAT:
            {
                img_hot_df_clicked_cb(obj, e);
                break;
            }
            case AC_STATUS_COLD:
            {
                img_cold_df_clicked_cb(obj, e);
                break;
            }
            case AC_STATUS_FRESH:
            {
                img_fresh_df_clicked_cb(obj, e);
                break;
            }
        }
        view_ac_clicked_0_cb(obj, e);
    }
}

// set 16~30
void ac_btn_1_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("ac_btn_1_click_cb");
    if(ac_mod_box_show == false)
    {
        if(ac_tab_temp_fan == false)
        {
            uint8_t lst_index = gui_list_get_current_note(lst_unit);
            uint8_t ten_index = gui_list_get_current_note(lst_ten);
            gui_log("lst_index get %d %d\n", lst_ten, lst_index);
            lst_index--;
            lst_index = (lst_index > 200)?9:lst_index;
            gui_log("lst_index %d\n", lst_index);
            if(!(ten_index == 0 && lst_index == 6))
            {
                gui_list_scroll_to_note(lst_unit, lst_index);
            }
            if(lst_index == 0)
            {
                ten_index = (ten_index == 0)?ten_index:ten_index - 1;
                gui_log("index set ten %d\n", ten_index);
                gui_list_scroll_to_note(lst_ten, ten_index);
            }
            ac_temp = (ten_index + 1) * 10 + ((lst_index + 9)%10);
        }
        else
        {
            uint8_t lst_index = gui_list_get_current_note(lst_fan);
            gui_log("lst_index get %d\n", lst_fan);
            lst_index--;
            lst_index = (lst_index > 200)?0:lst_index;
            gui_log("lst_index %d\n", lst_index);
            gui_list_scroll_to_note(lst_fan, lst_index);
            ac_speed--;
        }
    }
    else
    {
        uint8_t mod = ac_mod_selecting;
        mod--;
        mod = (mod < AC_STATUS_HEAT) ? AC_STATUS_FRESH : mod;
        ac_mod_selecting = mod;
        ac_selecting_mod_ui(mod);
    }

}

void ac_btn_2_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("ac_btn_2_click_cb");
    if(ac_mod_box_show == false)
    {
        if(ac_tab_temp_fan == false)
        {
            uint8_t lst_index =  gui_list_get_current_note(lst_unit);
            uint8_t ten_index = gui_list_get_current_note(lst_ten);
            gui_log("lst_index get %d\n", lst_index);
            lst_index++;
            lst_index = (lst_index >= 10)?0:lst_index;
            gui_log("lst_index %d\n", lst_index);
            if(!(ten_index == 2 && lst_index == 2))
            {
                gui_list_scroll_to_note(lst_unit, lst_index);
            }
            if(lst_index == 1)
            {
                gui_log("lst_index get ten %d\n", ten_index);
                ten_index = (ten_index >= 2)?ten_index:ten_index + 1;
                gui_log("index set ten %d\n", ten_index);
                gui_list_scroll_to_note(lst_ten, ten_index);
            }       
            ac_temp = (ten_index + 1) * 10 + ((lst_index + 9)%10);
        }
        else
        {
            uint8_t lst_index = gui_list_get_current_note(lst_fan);
            gui_log("lst_index get %d\n", lst_fan);
            lst_index++;
            lst_index = (lst_index > 4)?4:lst_index;
            gui_log("lst_index %d\n", lst_index);
            gui_list_scroll_to_note(lst_fan, lst_index);
            ac_speed++;
        }

    }
    else
    {
        uint8_t mod = ac_mod_selecting;
        mod++;
        mod = (mod > AC_STATUS_FRESH) ? AC_STATUS_HEAT : mod;
        ac_mod_selecting = mod;
        ac_selecting_mod_ui(mod);
    }

}

void ac_btn_long_press_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("ac_btn_long_press_cb");
    ac_status = (ac_status == AC_STATUS_OFF)? ac_mod:AC_STATUS_OFF;
    if(ac_status)
    {
        gui_log("ac turn ON");
        ani_ac_turnon_cb(obj, e);
    }
    else
    {
        gui_log("ac turn OFF");
        ani_ac_turnoff_cb(obj, e);
    }
}


/***************************  Light Control  ******************************/
typedef enum {
    LIGHT_STATUS_OFF    = 0,
    LIGHT_STATUS_TEMP,
    LIGHT_STATUS_LIGHTNING,
    LIGHT_STATUS_COLOR
}LIGHT_STATUS;


static uint8_t light_mod = LIGHT_STATUS_TEMP;
static uint8_t light_tmp_sw = true;
uint8_t light_tmp_idx = 20;
uint8_t light_ltn_idx_0 = 0;
uint32_t light_ltn_0 = 100;


static void light_ani_tmp_pop_temp_bar(void)
{
    img_lt_bar_0_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_lt_bar_0), 50, true, img_lt_bar_0_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(img_lt_bar_0));
    img_lt_bar_tmp_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_lt_bar_tmp), 50, true, img_lt_bar_tmp_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(img_lt_bar_tmp));
    img_temp_knob_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_temp_knob), 50, true, img_temp_knob_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(img_temp_knob));
}
static void light_ani_tmp_pop_light_bar(void)
{
    img_lt_bar_0_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_lt_bar_0), 50, true, img_lt_bar_0_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(img_lt_bar_0));
    img_lt_bar_tmp_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_lt_bar_tmp), 50, true, img_lt_bar_tmp_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(img_lt_bar_tmp));
    img_temp_knob_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_temp_knob), 50, true, img_temp_knob_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(img_temp_knob));
}

void light_tmp_update_light(void)
{
    uint8_t opa_w =  light_ltn_0 * 255 *  (23 - light_tmp_idx) / 2300.f ;
    uint8_t opa_y =  light_ltn_0 * 255 / 100 -  opa_w;

    // gui_log("opa w %d, opa y %d\n", opa_w, opa_y);
    gui_img_set_opacity(img_white, opa_w); 
    gui_img_set_opacity(img_yellow, opa_y); 

}

void light_set_ltn_bar(void *obj, uint8_t val)
{
    GUI_UNUSED(obj);
    char filepath[32];
    memset(filepath, 0, sizeof(filepath));
    sprintf(filepath, "/light/led_ani/loading_%d.bin", val);
    gui_log("obj 0x%x %s 0x%x filepath %s \n", obj, ((gui_obj_t *)obj)->name, ((gui_obj_t *)obj)->type, filepath);
    gui_img_set_src((gui_img_t *)obj, filepath, IMG_SRC_FILESYS);
    gui_log("light_set_ltn_bar done \n");
}



void light_tmp_show_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // gui_log("light_show_cb\n");

    light_mod = LIGHT_STATUS_TEMP;
    gui_list_jump_to_note(list_bar_temp, light_tmp_idx);
    light_set_ltn_bar(img_lt_bar_0, light_ltn_0);
    gui_list_jump_to_note(lst_lt_bar_0, light_ltn_idx_0);
    light_tmp_update_light();
    gui_obj_show((gui_obj_t *)img_white, light_tmp_sw);
    gui_obj_show((gui_obj_t *)img_yellow, light_tmp_sw);
}


void light_tmp_click_tmp_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if(light_mod == LIGHT_STATUS_LIGHTNING)
    {
        light_mod = LIGHT_STATUS_TEMP;
        light_ani_tmp_pop_light_bar();
    }
}

void light_tmp_click_lgt_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if(light_mod == LIGHT_STATUS_TEMP)
    {
        light_mod = LIGHT_STATUS_LIGHTNING;
        light_ani_tmp_pop_temp_bar();
    }

}



/* button cb*/
void light_tmp_btn_0_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("light_btn_0_click_cb\n");

    if(light_mod == LIGHT_STATUS_TEMP)
    {
        light_mod = LIGHT_STATUS_LIGHTNING;
        light_ani_tmp_pop_temp_bar();
    }
    else if(light_mod == LIGHT_STATUS_LIGHTNING)
    {
        light_mod = LIGHT_STATUS_TEMP;
        light_ani_tmp_pop_light_bar();
    }
}

void light_tmp_btn_1_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("light_tmp_btn_1_click_cb\n");

    if(light_mod == LIGHT_STATUS_TEMP)
    {
        uint8_t index =  gui_list_get_current_note(list_bar_temp);
        index++;
        index = (index >= 23)? 23 : index;
        gui_list_scroll_to_note(list_bar_temp, index);
    }
    else if(light_mod == LIGHT_STATUS_LIGHTNING)
    {
        uint8_t index =  gui_list_get_current_note(lst_lt_bar_0);
        index++;
        index = (index >= 23)? 23 : index;
        gui_list_scroll_to_note(lst_lt_bar_0, index);
    }
}

void light_tmp_btn_2_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("light_tmp_btn_2_click_cb\n");

    if(light_mod == LIGHT_STATUS_TEMP)
    {
        uint8_t index =  gui_list_get_current_note(list_bar_temp);
        index--;
        index = (index >= 200)? 0 : index;
        gui_list_scroll_to_note(list_bar_temp, index);
    }
    else if(light_mod == LIGHT_STATUS_LIGHTNING)
    {
        uint8_t index =  gui_list_get_current_note(lst_lt_bar_0);
        index--;
        index = (index >= 200)? 0 : index;
        gui_list_scroll_to_note(lst_lt_bar_0, index);
    }
}

void light_tmp_btn_long_press_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("light_tmp_btn_long_press_cb");
    light_tmp_sw = (light_tmp_sw == true)? false:true;
    if(light_tmp_sw)
    {
        gui_log("light turn ON");
        gui_obj_show((gui_obj_t *)img_white, true);
        gui_obj_show((gui_obj_t *)img_yellow, true);
    }
    else
    {
        gui_log("light turn OFF");
        gui_obj_show((gui_obj_t *)img_white, false);
        gui_obj_show((gui_obj_t *)img_yellow, false);
    }
}
/***************************  Light Color Control  ******************************/


static uint8_t light_clr_mod = LIGHT_STATUS_COLOR;
static uint8_t light_clr_sw = true;
uint8_t light_clr_idx = 20;
uint8_t light_ltn_idx_1 = 0;
uint32_t light_ltn_1 = 100;


static void light_ani_clr_pop_clr_bar(void)
{
    img_lt_bar_1_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_lt_bar_1), 50, true, img_lt_bar_1_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(img_lt_bar_1));
    img_lt_bar_clr_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_lt_bar_clr), 50, true, img_lt_bar_clr_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(img_lt_bar_clr));
    img_clr_knob_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_clr_knob), 50, true, img_clr_knob_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(img_clr_knob));
}
static void light_ani_clr_pop_light_bar(void)
{
    img_lt_bar_1_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_lt_bar_1), 50, true, img_lt_bar_1_timer_0_cb);
    gui_obj_start_timer(GUI_BASE(img_lt_bar_1));
    img_lt_bar_clr_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_lt_bar_clr), 50, true, img_lt_bar_clr_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(img_lt_bar_clr));
    img_clr_knob_timer_cnt = 0; // Reset counter
    gui_obj_create_timer(GUI_BASE(img_clr_knob), 50, true, img_clr_knob_timer_1_cb);
    gui_obj_start_timer(GUI_BASE(img_clr_knob));
}


void light_clr_update_light(void)
{
    if(!light_clr_sw) return;
    gui_img_t *img_clr_group[7] = {img_clr_0,
                                   img_clr_1,
                                   img_clr_2,
                                   img_clr_3,
                                   img_clr_4,
                                   img_clr_5,
                                   img_clr_0};

    uint8_t clr_int = (23 - light_clr_idx)  / 4;
    float clr_f = (23 - light_clr_idx)  / 4.f - clr_int;

    uint8_t opa_w =  light_ltn_1 * light_ltn_1 * 255 / 10000;
    uint8_t opa_0 = (1 - clr_f) * light_ltn_1 * 255 / 100;
    uint8_t opa_1 = clr_f * light_ltn_1 * 255 / 100;

    for(uint8_t i=0; i<6; i++)
    {
        gui_obj_show((gui_obj_t *)img_clr_group[i], false);
    }

    gui_img_set_opacity(img_clr_group[clr_int], opa_0); 
    gui_img_set_opacity(img_clr_group[clr_int + 1], opa_1); 
    gui_obj_show((gui_obj_t *)img_clr_group[clr_int], true);
    gui_obj_show((gui_obj_t *)img_clr_group[clr_int + 1], true);



    gui_log("light_clr_idx %d clr_int %d opa 0 %d, opa 1 %d opaw %d\n", light_clr_idx, clr_int, opa_0, opa_1, opa_w);
    gui_img_set_opacity(img_clr_white, opa_w); 
    gui_obj_show((gui_obj_t *)img_clr_white, true);
    

}


void light_clr_switch(void)
{
    gui_img_t *img_clr_group[7] = {img_clr_0,
                                   img_clr_1,
                                   img_clr_2,
                                   img_clr_3,
                                   img_clr_4,
                                   img_clr_5,
                                   img_clr_0};

    if(!light_clr_sw)
    {
        for(uint8_t i=0; i<6; i++)
        {
            gui_obj_show((gui_obj_t *)img_clr_group[i], false);
        }
        gui_obj_show((gui_obj_t *)img_clr_white, false);
    }
    else
    {
        light_clr_update_light();
    }
}


void light_clr_show_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("light_clr_show_cb\n");

    light_clr_mod = LIGHT_STATUS_COLOR;
    gui_log("%s %d   0x%x\n", __FUNCTION__, __LINE__, list_bar_clr);
    gui_list_jump_to_note(list_bar_clr, light_clr_idx);
    gui_log("%s %d\n", __FUNCTION__, __LINE__);
    light_set_ltn_bar(img_lt_bar_1, light_ltn_1);
    gui_log("%s %d\n", __FUNCTION__, __LINE__);
    gui_list_jump_to_note(lst_lt_bar_1, light_ltn_idx_1);
    gui_log("%s %d\n", __FUNCTION__, __LINE__);
    // light_clr_update_light();

    light_clr_switch();

    gui_log("%s %d\n", __FUNCTION__, __LINE__);
}


void light_clr_click_clr_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if(light_clr_mod == LIGHT_STATUS_LIGHTNING)
    {
        light_clr_mod = LIGHT_STATUS_COLOR;
        light_ani_clr_pop_light_bar();
    }
}

void light_clr_click_lgt_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    if(light_clr_mod == LIGHT_STATUS_COLOR)
    {
        light_clr_mod = LIGHT_STATUS_LIGHTNING;
        light_ani_clr_pop_clr_bar();
    }

}



/* button cb*/
void light_clr_btn_0_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("light_clr_btn_0_click_cb\n");

    if(light_clr_mod == LIGHT_STATUS_COLOR)
    {
        light_clr_mod = LIGHT_STATUS_LIGHTNING;
        light_ani_clr_pop_clr_bar();
    }
    else if(light_clr_mod == LIGHT_STATUS_LIGHTNING)
    {
        light_clr_mod = LIGHT_STATUS_COLOR;
        light_ani_clr_pop_light_bar();
    }
}

void light_clr_btn_1_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("light_clr_btn_1_click_cb\n");

    if(light_clr_mod == LIGHT_STATUS_COLOR)
    {
        uint8_t index =  gui_list_get_current_note(list_bar_clr);
        index++;
        index = (index >= 23)? 23 : index;
        gui_list_scroll_to_note(list_bar_clr, index);
    }
    else if(light_clr_mod == LIGHT_STATUS_LIGHTNING)
    {
        uint8_t index =  gui_list_get_current_note(lst_lt_bar_1);
        index++;
        index = (index >= 23)? 23 : index;
        gui_list_scroll_to_note(lst_lt_bar_1, index);
    }
}

void light_clr_btn_2_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("light_clr_btn_2_click_cb\n");

    if(light_clr_mod == LIGHT_STATUS_COLOR)
    {
        uint8_t index =  gui_list_get_current_note(list_bar_clr);
        index--;
        index = (index >= 200)? 0 : index;
        gui_list_scroll_to_note(list_bar_clr, index);
    }
    else if(light_clr_mod == LIGHT_STATUS_LIGHTNING)
    {
        uint8_t index =  gui_list_get_current_note(lst_lt_bar_1);
        index--;
        index = (index >= 200)? 0 : index;
        gui_list_scroll_to_note(lst_lt_bar_1, index);
    }
}
void light_clr_btn_long_press_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("light_clr_btn_long_press_cb");
    light_clr_sw = (light_clr_sw == true)? false:true;
    light_clr_switch();
}


/***************************  Curtain Control  ******************************/

typedef enum{
    CURTN_STOP = 0,
    CURTN_OPENING,
    CURTN_CLOSING,


}CURTN_STATUS;

// 0~24
uint8_t curtn_ani_idx = 10;
uint8_t curtn_status = CURTN_STOP;
uint8_t curtn_status_cache = CURTN_STOP;


void curtn_update_img(void)
{
    char filepath[32];
    memset(filepath, 0, sizeof(filepath));
    sprintf(filepath, "/curtain/cur_ani/cur_%02d.bin", curtn_ani_idx);
    gui_log("filepath %s \n", filepath);
    gui_img_set_src((gui_img_t *)img_cur, filepath, IMG_SRC_FILESYS);
    gui_log("curtn_update_img done \n");
    gui_fb_change();
}



void curtn_show_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // curtn_ani_idx = 10;
    curtn_update_img();
    curtn_status = CURTN_STOP;
    curtn_status_cache = CURTN_STOP;
}

void curtn_click_open_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    curtn_status = CURTN_OPENING;

}

void curtn_click_close_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    curtn_status = CURTN_CLOSING;

}

void curtn_click_stop_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    curtn_status = CURTN_STOP;

}



void curtn_btn_0_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("curtn_btn_1_click_cb\n");

    if(curtn_status != CURTN_STOP)
    {
        curtn_status_cache = curtn_status;
        curtn_status = CURTN_STOP;
    }
    else if(curtn_status_cache != CURTN_STOP)
    {
        curtn_status = curtn_status_cache;
        curtn_status_cache = CURTN_STOP;
    }

}

void curtn_btn_1_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("curtn_btn_1_click_cb\n");

    if(curtn_status == CURTN_STOP)
    {
        curtn_ani_idx = (curtn_ani_idx == 0)? 0:curtn_ani_idx - 1;
    }
}

void curtn_btn_2_click_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_log("curtn_btn_2_click_cb\n");

    if(curtn_status == CURTN_STOP)
    {
        curtn_ani_idx = (curtn_ani_idx == 24)? 24:curtn_ani_idx + 1;
    }
}