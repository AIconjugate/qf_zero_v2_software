// // SquareLine LVGL GENERATED FILE
// // EDITOR VERSION: SquareLine Studio 1.2.1
// // LVGL VERSION: 8.3.4
// // PROJECT: Smartwatch

// #include "ui.h"
// #include "ui_helpers.h"
// #include "ui_comp.h"
// #include "lcd_driver.h"
// #include "passive_peripheral.h"

// extern uint8_t blk_var_t;
// extern uint32_t amituofo_t;
// extern volatile ui_time_t ui_time;

// uint32_t LV_EVENT_GET_COMP_CHILD;

// lv_obj_t *bat_label[2] = {NULL, NULL};
// lv_obj_t *label_vol[5] = {NULL, NULL, NULL, NULL, NULL};

// void ui_set_bat(uint8_t bat, uint16_t vol)
// {
//     static uint8_t last_bat = 0;
//     static uint16_t last_vol = 0;
//     if (bat_label[0] == NULL || bat_label[1] == NULL)
//         return;
//     if (last_bat != bat && bat)
//     {
//         last_bat = bat;
//         lv_label_set_text_fmt(bat_label[0], "%d%%", bat);
//         lv_label_set_text_fmt(bat_label[1], "%d%%", bat);
//     }
//     if (last_vol != vol && vol)
//     {
//         last_vol = vol;
//         for (size_t i = 0; i < 5; i++)
//         {
//             if (label_vol[i] != NULL)
//                 lv_label_set_text_fmt(label_vol[i], "%dmV", last_vol);
//         }
//     }
// }

// typedef struct
// {
//     uint32_t child_idx;
//     lv_obj_t *child;
// } ui_comp_get_child_t;

// lv_obj_t *ui_comp_get_child(lv_obj_t *comp, uint32_t child_idx)
// {
//     ui_comp_get_child_t info;
//     info.child = NULL;
//     info.child_idx = child_idx;
//     lv_event_send(comp, LV_EVENT_GET_COMP_CHILD, &info);
//     return info.child;
// }

// void get_component_child_event_cb(lv_event_t *e)
// {
//     lv_obj_t **c = lv_event_get_user_data(e);
//     ui_comp_get_child_t *info = lv_event_get_param(e);
//     info->child = c[info->child_idx];
// }

// void del_component_child_event_cb(lv_event_t *e)
// {
//     lv_obj_t **c = lv_event_get_user_data(e);
//     lv_mem_free(c);
// }

// // COMPONENT batterygroup

// lv_obj_t *ui_batterygroup_create(lv_obj_t *comp_parent)
// {
//     lv_obj_t *cui_batterygroup;
//     cui_batterygroup = lv_obj_create(comp_parent);
//     lv_obj_set_width(cui_batterygroup, 48);
//     lv_obj_set_height(cui_batterygroup, 14);
//     lv_obj_set_x(cui_batterygroup, 0);
//     lv_obj_set_y(cui_batterygroup, 20);
//     lv_obj_set_align(cui_batterygroup, LV_ALIGN_TOP_MID);
//     lv_obj_set_flex_flow(cui_batterygroup, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(cui_batterygroup, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(cui_batterygroup, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(cui_batterygroup, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_batterygroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(cui_batterygroup, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(cui_batterygroup, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_flash;
//     cui_flash = lv_img_create(cui_batterygroup);
//     lv_img_set_src(cui_flash, &ui_img_flash_png);
//     lv_obj_set_width(cui_flash, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_flash, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_flash, LV_ALIGN_CENTER);
//     lv_obj_add_flag(cui_flash, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(cui_flash, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_t *cui_battery_percent;
//     cui_battery_percent = lv_label_create(cui_batterygroup);
//     lv_obj_set_width(cui_battery_percent, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_battery_percent, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_battery_percent, LV_ALIGN_CENTER);
//     lv_label_set_text(cui_battery_percent, "86%");
//     lv_obj_set_style_text_color(cui_battery_percent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_battery_percent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_battery_percent, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);
//     if (bat_label[0] == NULL)
//         bat_label[0] = cui_battery_percent;
//     else
//         bat_label[1] = cui_battery_percent;

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_BATTERYGROUP_NUM);
//     children[UI_COMP_BATTERYGROUP_BATTERYGROUP] = cui_batterygroup;
//     children[UI_COMP_BATTERYGROUP_FLASH] = cui_flash;
//     children[UI_COMP_BATTERYGROUP_BATTERY_PERCENT] = cui_battery_percent;
//     lv_obj_add_event_cb(cui_batterygroup, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_batterygroup, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     return cui_batterygroup;
// }

// // COMPONENT buttondown

// lv_obj_t *ui_buttondown_create(lv_obj_t *comp_parent)
// {

//     lv_obj_t *cui_buttondown;
//     cui_buttondown = lv_obj_create(comp_parent);
//     lv_obj_set_width(cui_buttondown, 43);
//     lv_obj_set_height(cui_buttondown, 43);
//     lv_obj_set_x(cui_buttondown, 89);
//     lv_obj_set_y(cui_buttondown, 62);
//     lv_obj_set_align(cui_buttondown, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(cui_buttondown, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(cui_buttondown, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(cui_buttondown, lv_color_hex(0xEE1E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_buttondown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(cui_buttondown, lv_color_hex(0xEE1E1E), LV_PART_MAIN | LV_STATE_CHECKED);
//     lv_obj_set_style_bg_opa(cui_buttondown, 255, LV_PART_MAIN | LV_STATE_CHECKED);
//     lv_obj_set_style_bg_color(cui_buttondown, lv_color_hex(0xEE1E1E), LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_bg_opa(cui_buttondown, 255, LV_PART_MAIN | LV_STATE_PRESSED);

//     lv_obj_t *cui_button_down_icon;
//     cui_button_down_icon = lv_img_create(cui_buttondown);
//     lv_img_set_src(cui_button_down_icon, &ui_img_weather_png);
//     lv_obj_set_width(cui_button_down_icon, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_button_down_icon, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(cui_button_down_icon, -7);
//     lv_obj_set_y(cui_button_down_icon, -6);
//     lv_obj_set_align(cui_button_down_icon, LV_ALIGN_CENTER);
//     lv_obj_add_flag(cui_button_down_icon, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(cui_button_down_icon, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_t *cui_line;
//     cui_line = lv_img_create(cui_buttondown);
//     lv_img_set_src(cui_line, &ui_img_btn_bg_3_png);
//     lv_obj_set_width(cui_line, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_line, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(cui_line, 5);
//     lv_obj_set_y(cui_line, 4);
//     lv_obj_set_align(cui_line, LV_ALIGN_CENTER);
//     lv_obj_add_flag(cui_line, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(cui_line, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_BUTTONDOWN_NUM);
//     children[UI_COMP_BUTTONDOWN_BUTTONDOWN] = cui_buttondown;
//     children[UI_COMP_BUTTONDOWN_BUTTON_DOWN_ICON] = cui_button_down_icon;
//     children[UI_COMP_BUTTONDOWN_LINE] = cui_line;
//     lv_obj_add_event_cb(cui_buttondown, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_buttondown, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     return cui_buttondown;
// }

// // COMPONENT buttonround

// lv_obj_t *ui_buttonround_create(lv_obj_t *comp_parent)
// {

//     lv_obj_t *cui_buttonround;
//     cui_buttonround = lv_btn_create(comp_parent);
//     lv_obj_set_width(cui_buttonround, 40);
//     lv_obj_set_height(cui_buttonround, 40);
//     lv_obj_set_x(cui_buttonround, 0);
//     lv_obj_set_y(cui_buttonround, -28);
//     lv_obj_set_align(cui_buttonround, LV_ALIGN_BOTTOM_MID);
//     lv_obj_add_flag(cui_buttonround, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
//     lv_obj_clear_flag(cui_buttonround, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
//     lv_obj_set_style_radius(cui_buttonround, 61, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(cui_buttonround, lv_color_hex(0xEE1C18), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_buttonround, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_img_src(cui_buttonround, &ui_img_measure_png, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_color(cui_buttonround, lv_color_hex(0xEE1C18), LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_outline_opa(cui_buttonround, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_outline_width(cui_buttonround, 3, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_outline_pad(cui_buttonround, 0, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_shadow_color(cui_buttonround, lv_color_hex(0xEE1C18), LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_shadow_opa(cui_buttonround, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_shadow_width(cui_buttonround, 31, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_shadow_spread(cui_buttonround, 2, LV_PART_MAIN | LV_STATE_PRESSED);

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_BUTTONROUND_NUM);
//     children[UI_COMP_BUTTONROUND_BUTTONROUND] = cui_buttonround;
//     lv_obj_add_event_cb(cui_buttonround, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_buttonround, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     return cui_buttonround;
// }

// // COMPONENT buttontop

// lv_obj_t *ui_buttontop_create(lv_obj_t *comp_parent)
// {

//     lv_obj_t *cui_buttontop;
//     cui_buttontop = lv_obj_create(comp_parent);
//     lv_obj_set_width(cui_buttontop, 43);
//     lv_obj_set_height(cui_buttontop, 43);
//     lv_obj_set_x(cui_buttontop, 89);
//     lv_obj_set_y(cui_buttontop, -64);
//     lv_obj_set_align(cui_buttontop, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(cui_buttontop, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(cui_buttontop, 122, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(cui_buttontop, lv_color_hex(0xEE1E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_buttontop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(cui_buttontop, lv_color_hex(0xEE1E1E), LV_PART_MAIN | LV_STATE_CHECKED);
//     lv_obj_set_style_bg_opa(cui_buttontop, 255, LV_PART_MAIN | LV_STATE_CHECKED);
//     lv_obj_set_style_bg_color(cui_buttontop, lv_color_hex(0xEE1E1E), LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_bg_opa(cui_buttontop, 255, LV_PART_MAIN | LV_STATE_PRESSED);

//     lv_obj_t *cui_button_top_icon;
//     cui_button_top_icon = lv_img_create(cui_buttontop);
//     lv_img_set_src(cui_button_top_icon, &ui_img_call1_png);
//     lv_obj_set_width(cui_button_top_icon, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_button_top_icon, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(cui_button_top_icon, -6);
//     lv_obj_set_y(cui_button_top_icon, 4);
//     lv_obj_set_align(cui_button_top_icon, LV_ALIGN_CENTER);
//     lv_obj_add_flag(cui_button_top_icon, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(cui_button_top_icon, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_t *cui_line;
//     cui_line = lv_img_create(cui_buttontop);
//     lv_img_set_src(cui_line, &ui_img_btn_bg_1_png);
//     lv_obj_set_width(cui_line, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_line, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(cui_line, 6);
//     lv_obj_set_y(cui_line, -2);
//     lv_obj_set_align(cui_line, LV_ALIGN_CENTER);
//     lv_obj_add_flag(cui_line, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(cui_line, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_BUTTONTOP_NUM);
//     children[UI_COMP_BUTTONTOP_BUTTONTOP] = cui_buttontop;
//     children[UI_COMP_BUTTONTOP_BUTTON_TOP_ICON] = cui_button_top_icon;
//     children[UI_COMP_BUTTONTOP_LINE] = cui_line;
//     lv_obj_add_event_cb(cui_buttontop, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_buttontop, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     return cui_buttontop;
// }

// void ui_event_comp_dailymissiongroup_daily_mission_arc(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t *target = lv_event_get_target(e);
//     lv_obj_t **comp_dailymissiongroup = lv_event_get_user_data(e);
//     if (event_code == LV_EVENT_VALUE_CHANGED)
//     {
//         blk_var_t = lv_arc_get_value(target);
//         if (blk_var_t == 0)
//             blk_var_t = 0;
//         // if (lv_obj_has_flag(target, LV_OBJ_FLAG_USER_1))
//         lcd_set_blk(blk_var_t);

//         // else
//         //     per_motor_set(lv_arc_get_value(target));
//         _ui_arc_set_text_value(comp_dailymissiongroup[UI_COMP_DAILYMISSIONGROUP_MISSION_PERCENT], target, "", "%");
//     }
// }

// // COMPONENT dailymissiongroup

// lv_obj_t *ui_dailymissiongroup_create(lv_obj_t *comp_parent)
// {
//     static uint8_t user_flg = 0;
//     lv_obj_t *cui_dailymissiongroup;
//     cui_dailymissiongroup = lv_obj_create(comp_parent);
//     lv_obj_set_width(cui_dailymissiongroup, 173);
//     lv_obj_set_height(cui_dailymissiongroup, 113);
//     lv_obj_set_align(cui_dailymissiongroup, LV_ALIGN_BOTTOM_LEFT);
//     lv_obj_clear_flag(cui_dailymissiongroup, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(cui_dailymissiongroup, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_dailymissiongroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_mission_percent;
//     cui_mission_percent = lv_label_create(cui_dailymissiongroup);
//     lv_obj_set_width(cui_mission_percent, LV_SIZE_CONTENT);  /// 90
//     lv_obj_set_height(cui_mission_percent, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(cui_mission_percent, 127);
//     lv_obj_set_y(cui_mission_percent, -10);
//     lv_obj_set_align(cui_mission_percent, LV_ALIGN_BOTTOM_LEFT);
//     lv_label_set_text_fmt(cui_mission_percent, "%d%%", blk_var_t);
//     lv_obj_set_style_text_color(cui_mission_percent, lv_color_hex(0xEE1E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_mission_percent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_mission_percent, &canger_02w03_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_daily_mission_image;
//     cui_daily_mission_image = lv_img_create(cui_dailymissiongroup);
//     lv_img_set_src(cui_daily_mission_image, &ui_img_daily_mission_png);
//     lv_obj_set_width(cui_daily_mission_image, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_daily_mission_image, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(cui_daily_mission_image, -36);
//     lv_obj_set_y(cui_daily_mission_image, -14);
//     lv_obj_set_align(cui_daily_mission_image, LV_ALIGN_CENTER);
//     lv_obj_add_flag(cui_daily_mission_image, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(cui_daily_mission_image, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_t *cui_daily_mission_arc;
//     cui_daily_mission_arc = lv_arc_create(cui_dailymissiongroup);
//     lv_obj_set_width(cui_daily_mission_arc, 202);
//     lv_obj_set_height(cui_daily_mission_arc, 202);
//     lv_obj_set_x(cui_daily_mission_arc, 31);
//     lv_obj_set_y(cui_daily_mission_arc, -60);
//     lv_obj_set_align(cui_daily_mission_arc, LV_ALIGN_CENTER);
//     lv_obj_add_flag(cui_daily_mission_arc, LV_OBJ_FLAG_ADV_HITTEST); /// Flags
//     lv_arc_set_value(cui_daily_mission_arc, blk_var_t);
//     lv_arc_set_bg_angles(cui_daily_mission_arc, 88, 170);
//     lv_obj_set_style_arc_color(cui_daily_mission_arc, lv_color_hex(0x303030), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_opa(cui_daily_mission_arc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_rounded(cui_daily_mission_arc, true, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_set_style_arc_color(cui_daily_mission_arc, lv_color_hex(0xB0E14A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_opa(cui_daily_mission_arc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_rounded(cui_daily_mission_arc, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);

//     lv_obj_set_style_bg_color(cui_daily_mission_arc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_daily_mission_arc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

//     if (user_flg == 0)
//         lv_obj_add_flag(cui_daily_mission_arc, LV_OBJ_FLAG_USER_1);
//     else
//         lv_obj_add_flag(cui_daily_mission_arc, LV_OBJ_FLAG_USER_2);

//     user_flg++;

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_DAILYMISSIONGROUP_NUM);
//     children[UI_COMP_DAILYMISSIONGROUP_DAILYMISSIONGROUP] = cui_dailymissiongroup;
//     children[UI_COMP_DAILYMISSIONGROUP_MISSION_PERCENT] = cui_mission_percent;
//     children[UI_COMP_DAILYMISSIONGROUP_DAILY_MISSION_IMAGE] = cui_daily_mission_image;
//     children[UI_COMP_DAILYMISSIONGROUP_DAILY_MISSION_ARC] = cui_daily_mission_arc;
//     lv_obj_add_event_cb(cui_dailymissiongroup, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_dailymissiongroup, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     lv_obj_add_event_cb(cui_daily_mission_arc, ui_event_comp_dailymissiongroup_daily_mission_arc, LV_EVENT_ALL, children);
//     return cui_dailymissiongroup;
// }

// // COMPONENT dategroup

// lv_obj_t *ui_dategroup_create(lv_obj_t *comp_parent)
// {
//     lv_obj_t *cui_dategroup;
//     cui_dategroup = lv_obj_create(comp_parent);
//     lv_obj_set_width(cui_dategroup, 61);
//     lv_obj_set_height(cui_dategroup, 50);
//     lv_obj_set_align(cui_dategroup, LV_ALIGN_TOP_MID);
//     lv_obj_set_flex_flow(cui_dategroup, LV_FLEX_FLOW_COLUMN);
//     lv_obj_set_flex_align(cui_dategroup, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
//     lv_obj_clear_flag(cui_dategroup, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(cui_dategroup, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_dategroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_day;
//     cui_day = lv_label_create(cui_dategroup);
//     lv_obj_set_width(cui_day, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_day, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_day, LV_ALIGN_CENTER);
//     lv_label_set_text_fmt(cui_day, "%s", week_day[ui_time.week]);
//     lv_obj_set_style_text_color(cui_day, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_day, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_day, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_month;
//     cui_month = lv_label_create(cui_dategroup);
//     lv_obj_set_width(cui_month, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_month, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_month, LV_ALIGN_CENTER);
//     lv_label_set_text_fmt(cui_month, "%02d月%02d日", ui_time.month, ui_time.day);
//     lv_obj_set_style_text_color(cui_month, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_month, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_month, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_year;
//     cui_year = lv_label_create(cui_dategroup);
//     lv_obj_set_width(cui_year, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_year, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_year, LV_ALIGN_CENTER);
//     lv_label_set_text_fmt(cui_year, "20%d年", ui_time.year);
//     lv_obj_set_style_text_color(cui_year, lv_color_hex(0x6B6B6B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_year, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_year, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_DATEGROUP_NUM);
//     children[UI_COMP_DATEGROUP_DATEGROUP] = cui_dategroup;
//     children[UI_COMP_DATEGROUP_DAY] = cui_day;
//     children[UI_COMP_DATEGROUP_MONTH] = cui_month;
//     children[UI_COMP_DATEGROUP_YEAR] = cui_year;
//     lv_obj_add_event_cb(cui_dategroup, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_dategroup, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     return cui_dategroup;
// }

// // COMPONENT forecastgroup

// lv_obj_t *ui_forecastgroup_create(lv_obj_t *comp_parent)
// {

//     lv_obj_t *cui_forecastgroup;
//     cui_forecastgroup = lv_obj_create(comp_parent);
//     lv_obj_set_width(cui_forecastgroup, 159);
//     lv_obj_set_height(cui_forecastgroup, 31);
//     lv_obj_set_x(cui_forecastgroup, 6);
//     lv_obj_set_y(cui_forecastgroup, 48);
//     lv_obj_set_align(cui_forecastgroup, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(cui_forecastgroup, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(cui_forecastgroup, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_forecastgroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_left(cui_forecastgroup, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_right(cui_forecastgroup, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_top(cui_forecastgroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_bottom(cui_forecastgroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_day1;
//     cui_day1 = lv_label_create(cui_forecastgroup);
//     lv_obj_set_width(cui_day1, 32);
//     lv_obj_set_height(cui_day1, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_day1, LV_ALIGN_LEFT_MID);
//     lv_obj_set_style_text_color(cui_day1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_day1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_day1, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_degree_group;
//     cui_degree_group = lv_obj_create(cui_forecastgroup);
//     lv_obj_set_width(cui_degree_group, 61);
//     lv_obj_set_height(cui_degree_group, 84);
//     lv_obj_set_align(cui_degree_group, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(cui_degree_group, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(cui_degree_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_degree_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_daytime;
//     cui_daytime = lv_label_create(cui_degree_group);
//     lv_obj_set_width(cui_daytime, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_daytime, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_daytime, LV_ALIGN_LEFT_MID);
//     lv_label_set_text(cui_daytime, "25°");
//     lv_obj_set_style_text_color(cui_daytime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_daytime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_daytime, &CangEr_Kai_22, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_nighttime;
//     cui_nighttime = lv_label_create(cui_degree_group);
//     lv_obj_set_width(cui_nighttime, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_nighttime, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_nighttime, LV_ALIGN_RIGHT_MID);
//     lv_label_set_text(cui_nighttime, "25°");
//     lv_obj_set_style_text_color(cui_nighttime, lv_color_hex(0x737373), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_nighttime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_nighttime, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_cloud_sun;
//     cui_cloud_sun = lv_img_create(cui_forecastgroup);
//     lv_img_set_src(cui_cloud_sun, &ui_img_weather_sun_png);
//     lv_obj_set_width(cui_cloud_sun, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_cloud_sun, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_cloud_sun, LV_ALIGN_RIGHT_MID);
//     lv_obj_add_flag(cui_cloud_sun, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(cui_cloud_sun, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_FORECASTGROUP_NUM);
//     children[UI_COMP_FORECASTGROUP_FORECASTGROUP] = cui_forecastgroup;
//     children[UI_COMP_FORECASTGROUP_DAY1] = cui_day1;
//     children[UI_COMP_FORECASTGROUP_DEGREE_GROUP] = cui_degree_group;
//     children[UI_COMP_FORECASTGROUP_DEGREE_GROUP_DAYTIME] = cui_daytime;
//     children[UI_COMP_FORECASTGROUP_DEGREE_GROUP_NIGHTTIME] = cui_nighttime;
//     children[UI_COMP_FORECASTGROUP_CLOUD_SUN] = cui_cloud_sun;
//     lv_obj_add_event_cb(cui_forecastgroup, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_forecastgroup, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     return cui_forecastgroup;
// }

// // COMPONENT pulsegroup

// lv_obj_t *ui_pulsegroup_create(lv_obj_t *comp_parent)
// {

//     lv_obj_t *cui_pulsegroup;
//     cui_pulsegroup = lv_obj_create(comp_parent);
//     lv_obj_set_width(cui_pulsegroup, 111);
//     lv_obj_set_height(cui_pulsegroup, 31);
//     lv_obj_set_x(cui_pulsegroup, 0);
//     lv_obj_set_y(cui_pulsegroup, 43);
//     lv_obj_set_align(cui_pulsegroup, LV_ALIGN_CENTER);
//     lv_obj_set_flex_flow(cui_pulsegroup, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(cui_pulsegroup, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(cui_pulsegroup, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(cui_pulsegroup, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_pulsegroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(cui_pulsegroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(cui_pulsegroup, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_heart;
//     cui_heart = lv_img_create(cui_pulsegroup);
//     lv_img_set_src(cui_heart, &ui_img_heart_png);
//     lv_obj_set_width(cui_heart, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_heart, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_heart, LV_ALIGN_CENTER);
//     lv_obj_add_flag(cui_heart, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(cui_heart, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_t *cui_pulse_number;
//     cui_pulse_number = lv_label_create(cui_pulsegroup);
//     lv_obj_set_width(cui_pulse_number, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_pulse_number, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_pulse_number, LV_ALIGN_CENTER);
//     lv_label_set_text(cui_pulse_number, "63");
//     lv_obj_set_style_text_color(cui_pulse_number, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_pulse_number, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_pulse_number, &CangEr_Kai_22, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_bpm;
//     cui_bpm = lv_label_create(cui_pulsegroup);
//     lv_obj_set_width(cui_bpm, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_bpm, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_bpm, LV_ALIGN_CENTER);
//     lv_label_set_text(cui_bpm, "次/分");
//     lv_obj_set_style_text_color(cui_bpm, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_bpm, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_bpm, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_PULSEGROUP_NUM);
//     children[UI_COMP_PULSEGROUP_PULSEGROUP] = cui_pulsegroup;
//     children[UI_COMP_PULSEGROUP_HEART] = cui_heart;
//     children[UI_COMP_PULSEGROUP_PULSE_NUMBER] = cui_pulse_number;
//     children[UI_COMP_PULSEGROUP_BPM] = cui_bpm;
//     lv_obj_add_event_cb(cui_pulsegroup, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_pulsegroup, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     return cui_pulsegroup;
// }

// // COMPONENT stepgroup

// lv_obj_t *ui_stepgroup_create(lv_obj_t *comp_parent)
// {
//     static  uint8_t s_cout = 0;
//     lv_obj_t *cui_stepgroup;
//     cui_stepgroup = lv_obj_create(comp_parent);
//     lv_obj_set_width(cui_stepgroup, 61);
//     lv_obj_set_height(cui_stepgroup, 16);
//     lv_obj_set_x(cui_stepgroup, 0);
//     lv_obj_set_y(cui_stepgroup, -24);
//     lv_obj_set_align(cui_stepgroup, LV_ALIGN_BOTTOM_MID);
//     lv_obj_set_flex_flow(cui_stepgroup, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(cui_stepgroup, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(cui_stepgroup, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(cui_stepgroup, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_stepgroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(cui_stepgroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(cui_stepgroup, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_step;
//     cui_step = lv_img_create(cui_stepgroup);
//     // lv_img_set_src(cui_step, &ui_img_step_png);
//     // lv_obj_set_width(cui_step, LV_SIZE_CONTENT);  /// 1
//     // lv_obj_set_height(cui_step, LV_SIZE_CONTENT); /// 1
//     // lv_obj_set_align(cui_step, LV_ALIGN_CENTER);
//     // lv_obj_add_flag(cui_step, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     // lv_obj_clear_flag(cui_step, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_t *cui_step_label;
//     cui_step_label = lv_label_create(cui_stepgroup);
//     lv_obj_set_width(cui_step_label, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_step_label, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(cui_step_label, 1);
//     lv_obj_set_y(cui_step_label, -2);
//     lv_obj_set_align(cui_step_label, LV_ALIGN_CENTER);
//     lv_label_set_text(cui_step_label, "1526");
//     lv_obj_set_style_text_color(cui_step_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_step_label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_step_label, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);
//     label_vol[s_cout++] = cui_step_label;

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_STEPGROUP_NUM);
//     children[UI_COMP_STEPGROUP_STEPGROUP] = cui_stepgroup;
//     children[UI_COMP_STEPGROUP_STEP] = cui_step;
//     children[UI_COMP_STEPGROUP_STEP_LABEL] = cui_step_label;
//     lv_obj_add_event_cb(cui_stepgroup, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_stepgroup, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     return cui_stepgroup;
// }

// // COMPONENT titlegroup

// lv_obj_t *ui_titlegroup_create(lv_obj_t *comp_parent)
// {

//     lv_obj_t *cui_titlegroup;
//     cui_titlegroup = lv_obj_create(comp_parent);
//     lv_obj_set_width(cui_titlegroup, 123);
//     lv_obj_set_height(cui_titlegroup, 36);
//     lv_obj_set_x(cui_titlegroup, 8);
//     lv_obj_set_y(cui_titlegroup, -49);
//     lv_obj_set_align(cui_titlegroup, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(cui_titlegroup, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(cui_titlegroup, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_titlegroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_title;
//     cui_title = lv_label_create(cui_titlegroup);
//     lv_obj_set_width(cui_title, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_title, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_title, LV_ALIGN_TOP_MID);
//     lv_label_set_text(cui_title, "title");
//     lv_obj_set_style_text_color(cui_title, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_title, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_subtitle;
//     cui_subtitle = lv_label_create(cui_titlegroup);
//     lv_obj_set_width(cui_subtitle, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_subtitle, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_subtitle, LV_ALIGN_BOTTOM_MID);
//     lv_label_set_text(cui_subtitle, "subtitle");
//     lv_obj_set_style_text_color(cui_subtitle, lv_color_hex(0x6D6D6D), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_subtitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_subtitle, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_TITLEGROUP_NUM);
//     children[UI_COMP_TITLEGROUP_TITLEGROUP] = cui_titlegroup;
//     children[UI_COMP_TITLEGROUP_TITLE] = cui_title;
//     children[UI_COMP_TITLEGROUP_SUBTITLE] = cui_subtitle;
//     lv_obj_add_event_cb(cui_titlegroup, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_titlegroup, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     return cui_titlegroup;
// }

// // COMPONENT todayweathergroup

// lv_obj_t *ui_todayweathergroup_create(lv_obj_t *comp_parent)
// {

//     lv_obj_t *cui_todayweathergroup;
//     cui_todayweathergroup = lv_obj_create(comp_parent);
//     lv_obj_set_height(cui_todayweathergroup, 66);
//     lv_obj_set_width(cui_todayweathergroup, LV_SIZE_CONTENT); /// 82
//     lv_obj_set_align(cui_todayweathergroup, LV_ALIGN_CENTER);
//     lv_obj_set_flex_flow(cui_todayweathergroup, LV_FLEX_FLOW_COLUMN_REVERSE);
//     lv_obj_set_flex_align(cui_todayweathergroup, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(cui_todayweathergroup, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(cui_todayweathergroup, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_todayweathergroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(cui_todayweathergroup, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(cui_todayweathergroup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_degree_6;
//     cui_degree_6 = lv_label_create(cui_todayweathergroup);
//     lv_obj_set_width(cui_degree_6, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_degree_6, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(cui_degree_6, 5);
//     lv_obj_set_y(cui_degree_6, 0);
//     lv_obj_set_align(cui_degree_6, LV_ALIGN_CENTER);
//     lv_label_set_text(cui_degree_6, "25°");
//     lv_obj_set_style_text_color(cui_degree_6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_degree_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_degree_6, &CangEr_Kai_22, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_cloud_sun;
//     cui_cloud_sun = lv_img_create(cui_todayweathergroup);
//     lv_img_set_src(cui_cloud_sun, &ui_img_weather_sun_png);
//     lv_obj_set_width(cui_cloud_sun, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_cloud_sun, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_cloud_sun, LV_ALIGN_CENTER);
//     lv_obj_add_flag(cui_cloud_sun, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(cui_cloud_sun, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_t *cui_degree_8;
//     cui_degree_8 = lv_label_create(cui_todayweathergroup);
//     lv_obj_set_width(cui_degree_8, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_degree_8, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(cui_degree_8, 5);
//     lv_obj_set_y(cui_degree_8, 0);
//     lv_obj_set_align(cui_degree_8, LV_ALIGN_CENTER);
//     lv_label_set_text(cui_degree_8, "当前");
//     lv_obj_set_style_text_color(cui_degree_8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_degree_8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_degree_8, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_TODAYWEATHERGROUP_NUM);
//     children[UI_COMP_TODAYWEATHERGROUP_TODAYWEATHERGROUP] = cui_todayweathergroup;
//     children[UI_COMP_TODAYWEATHERGROUP_DEGREE_6] = cui_degree_6;
//     children[UI_COMP_TODAYWEATHERGROUP_CLOUD_SUN] = cui_cloud_sun;
//     children[UI_COMP_TODAYWEATHERGROUP_DEGREE_8] = cui_degree_8;
//     lv_obj_add_event_cb(cui_todayweathergroup, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_todayweathergroup, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     return cui_todayweathergroup;
// }

// // COMPONENT weathergroup1

// lv_obj_t *ui_weathergroup1_create(lv_obj_t *comp_parent)
// {

//     lv_obj_t *cui_weathergroup1;
//     cui_weathergroup1 = lv_obj_create(comp_parent);
//     lv_obj_set_width(cui_weathergroup1, 65);
//     lv_obj_set_height(cui_weathergroup1, 27);
//     lv_obj_set_x(cui_weathergroup1, -34);
//     lv_obj_set_y(cui_weathergroup1, 20);
//     lv_obj_set_align(cui_weathergroup1, LV_ALIGN_CENTER);
//     lv_obj_set_flex_flow(cui_weathergroup1, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(cui_weathergroup1, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(cui_weathergroup1, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(cui_weathergroup1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(cui_weathergroup1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_degree_1;
//     cui_degree_1 = lv_label_create(cui_weathergroup1);
//     lv_obj_set_width(cui_degree_1, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_degree_1, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_degree_1, LV_ALIGN_CENTER);
//     lv_label_set_text(cui_degree_1, "25°");
//     lv_obj_set_style_text_color(cui_degree_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(cui_degree_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(cui_degree_1, &CangEr_Kai_22, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_t *cui_cloud_fog_1;
//     cui_cloud_fog_1 = lv_img_create(cui_weathergroup1);
//     lv_img_set_src(cui_cloud_fog_1, &ui_img_weather_sun_cloud_png);
//     lv_obj_set_width(cui_cloud_fog_1, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(cui_cloud_fog_1, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(cui_cloud_fog_1, LV_ALIGN_CENTER);
//     lv_obj_add_flag(cui_cloud_fog_1, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(cui_cloud_fog_1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_t **children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_WEATHERGROUP1_NUM);
//     children[UI_COMP_WEATHERGROUP1_WEATHERGROUP1] = cui_weathergroup1;
//     children[UI_COMP_WEATHERGROUP1_DEGREE_1] = cui_degree_1;
//     children[UI_COMP_WEATHERGROUP1_CLOUD_FOG_1] = cui_cloud_fog_1;
//     lv_obj_add_event_cb(cui_weathergroup1, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
//     lv_obj_add_event_cb(cui_weathergroup1, del_component_child_event_cb, LV_EVENT_DELETE, children);
//     return cui_weathergroup1;
// }
