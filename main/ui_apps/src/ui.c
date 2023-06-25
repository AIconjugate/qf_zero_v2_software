// // SquareLine LVGL GENERATED FILE
// // EDITOR VERSION: SquareLine Studio 1.2.1
// // LVGL VERSION: 8.3.4
// // PROJECT: Smartwatch

// #include "ui.h"
// #include "ui_helpers.h"
// #include "ui_comp.h"
// #include "passive_peripheral.h"

// lv_anim_t *anim_sec_dot = NULL;
// lv_anim_t *anim_sec = NULL;

// volatile ui_time_t ui_time;
// lv_timer_t *sec_anim_timer;

// extern uint8_t blk_var_t;
// extern uint32_t amituofo_t;
// extern uint8_t last_watch_page_t;

// uint8_t analog_sec_flg = 0;

// const char *week_day[] = {"周天", "周一", "周二", "周三", "周四", "周五", "周六"};

// ///////////////////// VARIABLES ////////////////////
// void sec_Animation(lv_obj_t *TargetObject, int delay);
// void min_Animation(lv_obj_t *TargetObject, int delay);
// void hour_Animation(lv_obj_t *TargetObject, int delay);
// void left_Animation(lv_obj_t *TargetObject, int delay);
// void right_Animation(lv_obj_t *TargetObject, int delay);
// void opa_on_Animation(lv_obj_t *TargetObject, int delay);
// void dots_Animation(lv_obj_t *TargetObject, int delay);
// void top_Animation(lv_obj_t *TargetObject, int delay);
// void cloud_Animation(lv_obj_t *TargetObject, int delay);
// void blood2_Animation(lv_obj_t *TargetObject, int delay);
// void blood1_Animation(lv_obj_t *TargetObject, int delay);
// void heart_Animation(lv_obj_t *TargetObject, int delay);
// void ui_event_start(lv_event_t *e);
// lv_obj_t *ui_start;
// void ui_event_watch_digital(lv_event_t *e);
// lv_obj_t *ui_watch_digital;
// lv_obj_t *ui_bg_1;
// lv_obj_t *ui_hour_group;
// lv_obj_t *ui_label_hour_1;
// lv_obj_t *ui_label_hour_2;
// lv_obj_t *ui_label_min;
// lv_obj_t *ui_battery_group;
// lv_obj_t *ui_date_group;
// lv_obj_t *ui_weather_group_1;
// lv_obj_t *ui_weather_title_group_1;
// lv_obj_t *ui_step_group;
// lv_obj_t *ui_daily_mission_group;
// void ui_event_button_top_buttontop(lv_event_t *e);
// lv_obj_t *ui_button_top;
// void ui_event_button_down_buttondown(lv_event_t *e);
// lv_obj_t *ui_button_down;
// lv_obj_t *ui_sec_dot;
// lv_obj_t *ui_weather_dots_group2;
// lv_obj_t *ui_dot14;
// lv_obj_t *ui_dot15;
// void ui_event_watch_analog(lv_event_t *e);
// lv_obj_t *ui_watch_analog;
// lv_obj_t *ui_bg_2;
// lv_obj_t *ui_clock;
// lv_obj_t *ui_dots;
// lv_obj_t *ui_battery_group1;
// lv_obj_t *ui_date_group2;
// lv_obj_t *ui_day2;
// lv_obj_t *ui_month2;
// lv_obj_t *ui_year2;
// lv_obj_t *ui_weather_title_group_2;
// lv_obj_t *ui_weather_group_5;
// lv_obj_t *ui_degree_7;
// lv_obj_t *ui_cloud_fog_3;
// lv_obj_t *ui_step_group2;
// lv_obj_t *ui_daily_mission_group1;
// void ui_event_button_top1_buttontop(lv_event_t *e);
// lv_obj_t *ui_button_top1;
// void ui_event_button_down1_buttondown(lv_event_t *e);
// lv_obj_t *ui_button_down1;
// lv_obj_t *ui_clock_group;
// lv_obj_t *ui_sec;
// lv_obj_t *ui_min;
// lv_obj_t *ui_hour;
// lv_obj_t *ui_dots_group;
// lv_obj_t *ui_dot16;
// lv_obj_t *ui_dot17;
// void ui_event_call(lv_event_t *e);
// lv_obj_t *ui_call;
// lv_obj_t *ui_bg_3;
// lv_obj_t *ui_avatar;
// lv_obj_t *ui_avatar_label;
// lv_obj_t *ui_call_time;
// lv_obj_t *ui_mute;
// void ui_event_button_down2_buttondown(lv_event_t *e);
// lv_obj_t *ui_button_down2;
// lv_obj_t *ui_volume_group;
// lv_obj_t *ui_volume_percent;
// lv_obj_t *ui_volume_image;
// lv_obj_t *ui_volume_arc;
// void ui_event_button_top2_buttontop(lv_event_t *e);
// lv_obj_t *ui_button_top2;
// void ui_event_weather_1(lv_event_t *e);
// lv_obj_t *ui_weather_1;
// lv_obj_t *ui_bg_4;
// lv_obj_t *ui_city_gruop_1;
// lv_obj_t *ui_weather_title_group_3;
// lv_obj_t *ui_label_degree;
// lv_obj_t *ui_rain_group;
// lv_obj_t *ui_rain_icon;
// lv_obj_t *ui_rain_percent;
// lv_obj_t *ui_wind_group;
// lv_obj_t *ui_wind_icon;
// lv_obj_t *ui_wind_speed;
// lv_obj_t *ui_weather_dots_group;
// lv_obj_t *ui_dot1;
// lv_obj_t *ui_dot2;
// lv_obj_t *ui_weather_image_group;
// lv_obj_t *ui_sun;
// lv_obj_t *ui_clouds;
// void ui_event_button_down3_buttondown(lv_event_t *e);
// lv_obj_t *ui_button_down3;
// void ui_event_weather_2(lv_event_t *e);
// lv_obj_t *ui_weather_2;
// lv_obj_t *ui_bg5;
// lv_obj_t *ui_weather_dots_group1;
// lv_obj_t *ui_dot3;
// lv_obj_t *ui_dot4;
// lv_obj_t *ui_content;
// lv_obj_t *ui_city_gruop_2;
// lv_obj_t *ui_todady_weather_content;
// lv_obj_t *ui_today_weather_group;
// lv_obj_t *ui_today_weather_group1;
// lv_obj_t *ui_today_weather_group2;
// lv_obj_t *ui_today_weather_group3;
// lv_obj_t *ui_today_weather_group4;
// lv_obj_t *ui_today_weather_group5;
// lv_obj_t *ui_today_weather_group6;
// lv_obj_t *ui_today_weather_group7;
// lv_obj_t *ui_today_weather_group8;
// lv_obj_t *ui_days_forecast;
// lv_obj_t *ui_week_weather_group;
// lv_obj_t *ui_forecast_group;
// lv_obj_t *ui_forecast_group1;
// lv_obj_t *ui_forecast_group2;
// lv_obj_t *ui_forecast_group3;
// lv_obj_t *ui_forecast_group4;
// lv_obj_t *ui_forecast_group5;
// lv_obj_t *ui_space;
// void ui_event_button_down4_buttondown(lv_event_t *e);
// lv_obj_t *ui_button_down4;
// void ui_event_blood_oxy(lv_event_t *e);
// lv_obj_t *ui_blood_oxy;
// lv_obj_t *ui_bg6;
// lv_obj_t *ui_title_group_1;
// void ui_event_button_down5_buttondown(lv_event_t *e);
// lv_obj_t *ui_button_down5;
// void ui_event_button_round_buttonround(lv_event_t *e);
// lv_obj_t *ui_button_round;
// lv_obj_t *ui_blood_presure_group;
// lv_obj_t *ui_blood_oxygen;
// lv_obj_t *ui_percent;
// lv_obj_t *ui_pulse_group;
// lv_obj_t *ui_arc_spo2;
// lv_obj_t *ui_precent_70;
// lv_obj_t *ui_precent_100;
// lv_obj_t *ui_health_dots_group;
// lv_obj_t *ui_dot7;
// lv_obj_t *ui_dot6;
// lv_obj_t *ui_dot5;
// lv_obj_t *ui_dots_group1;
// lv_obj_t *ui_dot18;
// lv_obj_t *ui_dot19;
// void ui_event_ecg(lv_event_t *e);
// lv_obj_t *ui_ecg;
// lv_obj_t *ui_Image1;
// lv_obj_t *ui_bg1;
// lv_obj_t *ui_title_group_2;
// void ui_event_button_down6_buttondown(lv_event_t *e);
// lv_obj_t *ui_button_down6;
// void ui_event_button_round1_buttonround(lv_event_t *e);
// lv_obj_t *ui_button_round1;
// lv_obj_t *ui_pulse_group1;
// lv_obj_t *ui_health_dots_group1;
// lv_obj_t *ui_dot9;
// lv_obj_t *ui_dot8;
// lv_obj_t *ui_dot10;
// lv_obj_t *ui_chart_group;
// lv_obj_t *ui_chart_ecg;
// void ui_event_blood_pressure(lv_event_t *e);
// lv_obj_t *ui_blood_pressure;
// lv_obj_t *ui_bg2;
// lv_obj_t *ui_Image3;
// lv_obj_t *ui_title_group_3;
// void ui_event_button_down7_buttondown(lv_event_t *e);
// lv_obj_t *ui_button_down7;
// void ui_event_button_round2_buttonround(lv_event_t *e);
// lv_obj_t *ui_button_round2;
// lv_obj_t *ui_blood_presure_group1;
// lv_obj_t *ui_sys_group;
// lv_obj_t *ui_sys;
// lv_obj_t *ui_mmhg1;
// lv_obj_t *ui_blood_oxygen1;
// lv_obj_t *ui_pulse_group2;
// lv_obj_t *ui_blood_presure_group2;
// lv_obj_t *ui_dia_group;
// lv_obj_t *ui_dia;
// lv_obj_t *ui_mmhg2;
// lv_obj_t *ui_blood_oxygen2;
// lv_obj_t *ui_health_dots_group2;
// lv_obj_t *ui_dot12;
// lv_obj_t *ui_dot13;
// lv_obj_t *ui_dot11;
// void ui_event_measuing(lv_event_t *e);
// lv_obj_t *ui_measuing;
// lv_obj_t *ui_bg7;
// lv_obj_t *ui_pulse_group3;
// lv_obj_t *ui_measuring;
// lv_obj_t *ui_Spinner2;
// lv_obj_t *ui_blood_group;
// lv_obj_t *ui_blood1;
// lv_obj_t *ui_blood_fill;
// lv_obj_t *ui_blood2;
// void ui_event_x_button(lv_event_t *e);
// lv_obj_t *ui_x_button;
// lv_obj_t *ui_x;
// void ui_event_muyu(lv_event_t *e);
// lv_obj_t *ui_muyu;
// lv_obj_t *ui_muyu_img;
// void ui_event_popcat(lv_event_t *e);
// lv_obj_t *ui_popcat;
// lv_obj_t *ui_popcat_img;

// static uint8_t init_flg = 0;
// static uint8_t time_anim_runing = 0;

// ///////////////////// TEST LVGL SETTINGS ////////////////////
// // #if LV_COLOR_DEPTH != 16
// // #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
// // #endif
// // #if LV_COLOR_16_SWAP != 0
// // #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
// // #endif

// static void anim_end_cb(lv_timer_t *e)
// {
//     time_anim_runing = 0;
// }

// void ui_time_anim_refresh(ui_time_t *time)
// {
//     if (init_flg == 0)
//         return;

//     if (time_anim_runing == 1)
//         return;

//     if (ui_time.min != time->min)
//     {
//         ui_time.min = time->min;
//         uint8_t tmp = time->hour;
//         if (tmp >= 12)
//             tmp -= 12;
//         lv_img_set_angle(ui_hour, tmp * 300 + time->min * 5);
//         lv_label_set_text_fmt(ui_label_min, "%02d", time->min);
//         lv_label_set_text_fmt(ui_clock, "%02d   %02d", ui_time.hour, ui_time.min);
//     }
//     if (ui_time.hour != time->hour)
//     {
//         ui_time.hour = time->hour;
//         lv_label_set_text_fmt(ui_label_hour_1, "%02d", time->hour);
//         lv_obj_align(ui_label_hour_1, LV_ALIGN_CENTER, -25, 10);
//         lv_label_set_text_fmt(ui_clock, "%02d   %02d", ui_time.hour, ui_time.min);
//     }
//     lv_img_set_angle(ui_min, time->min * 60 + time->sec);

//     if (ui_time.sec == time->sec)
//         return;

//     ui_time.sec = time->sec;

//     if (anim_sec_dot != NULL)
//     {
//         lv_anim_custom_del(anim_sec_dot, _ui_anim_callback_set_image_angle);
//         lv_anim_custom_del(anim_sec, _ui_anim_callback_set_image_angle);
//         anim_sec_dot = NULL;
//         anim_sec = NULL;
//     }

//     lv_img_set_angle(ui_sec, ui_time.sec * 60);
//     lv_img_set_angle(ui_sec_dot, ui_time.sec * 60);

//     sec_Animation(ui_sec_dot, 0);
//     sec_Animation(ui_sec, 0);
// }

// ///////////////////// ANIMATIONS ////////////////////
// void sec_Animation(lv_obj_t *TargetObject, int delay)
// {
//     static uint8_t count = 0;
//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 60 * 1000); // 60000
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
//     lv_anim_set_values(&PropertyAnimation_0, 0, 3600);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
//     // lv_anim_set_early_apply(&PropertyAnimation_0, false);
//     lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
//     if (count == 0)
//         anim_sec_dot = lv_anim_start(&PropertyAnimation_0);
//     else
//         anim_sec = lv_anim_start(&PropertyAnimation_0);
//     count++;
//     count &= 1;
// }
// void min_Animation(lv_obj_t *TargetObject, int delay)
// {
//     int16_t tmp = (ui_time.min * 60 + ui_time.sec) - 1400;

//     if (tmp < 0)
//         tmp += 3600;
//     lv_img_set_angle(ui_min, tmp);

//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 1000);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
//     lv_anim_set_values(&PropertyAnimation_0, 0, 1400);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
//     // lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_0, false);
//     lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
//     lv_anim_start(&PropertyAnimation_0);
// }
// void hour_Animation(lv_obj_t *TargetObject, int delay)
// {
//     uint8_t tmp = ui_time.hour;
//     if (tmp >= 12)
//         tmp -= 12;

//     int16_t angle_tmp = (tmp * 300 + ui_time.min * 5) - 300;
//     if (angle_tmp < 0)
//         angle_tmp += 3600;
//     lv_img_set_angle(ui_hour, angle_tmp);

//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 1000);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);

//     lv_anim_set_values(&PropertyAnimation_0, 0, 300);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
//     lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_0, false);
//     lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
//     lv_anim_start(&PropertyAnimation_0);
// }
// void left_Animation(lv_obj_t *TargetObject, int delay)
// {
//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 500);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
//     lv_anim_set_values(&PropertyAnimation_0, -61, 0);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
//     lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_0, 0);
//     lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_0, true);
//     lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
//     lv_anim_start(&PropertyAnimation_0);
//     lv_anim_t PropertyAnimation_1;
//     lv_anim_init(&PropertyAnimation_1);
//     lv_anim_set_time(&PropertyAnimation_1, 300);
//     lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
//     lv_anim_set_values(&PropertyAnimation_1, 0, 255);
//     lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
//     lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_1, 0);
//     lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
//     lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_1, true);
//     lv_anim_start(&PropertyAnimation_1);
// }
// void right_Animation(lv_obj_t *TargetObject, int delay)
// {
//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 500);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
//     lv_anim_set_values(&PropertyAnimation_0, 92, 0);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
//     lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_0, 0);
//     lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_0, false);
//     lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
//     lv_anim_start(&PropertyAnimation_0);
//     lv_anim_t PropertyAnimation_1;
//     lv_anim_init(&PropertyAnimation_1);
//     lv_anim_set_time(&PropertyAnimation_1, 300);
//     lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
//     lv_anim_set_values(&PropertyAnimation_1, 0, 255);
//     lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
//     lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_1, 0);
//     lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
//     lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_1, true);
//     lv_anim_start(&PropertyAnimation_1);
// }
// void opa_on_Animation(lv_obj_t *TargetObject, int delay)
// {
//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 500);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
//     lv_anim_set_values(&PropertyAnimation_0, 0, 255);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
//     lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_0, 0);
//     lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_0, true);
//     lv_anim_start(&PropertyAnimation_0);
// }
// void dots_Animation(lv_obj_t *TargetObject, int delay)
// {
//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 250);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
//     lv_anim_set_values(&PropertyAnimation_0, 0, 255);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
//     lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_0, 250);
//     lv_anim_set_playback_delay(&PropertyAnimation_0, 250);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
//     lv_anim_set_repeat_delay(&PropertyAnimation_0, 500);
//     lv_anim_set_early_apply(&PropertyAnimation_0, true);
//     lv_anim_start(&PropertyAnimation_0);
// }
// void top_Animation(lv_obj_t *TargetObject, int delay)
// {
//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 400);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
//     lv_anim_set_values(&PropertyAnimation_0, -61, 0);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
//     lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_0, 0);
//     lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_0, false);
//     lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
//     lv_anim_start(&PropertyAnimation_0);
// }
// void cloud_Animation(lv_obj_t *TargetObject, int delay)
// {
//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 1000);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
//     lv_anim_set_values(&PropertyAnimation_0, 0, 6);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
//     lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_0, 1000);
//     lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
//     lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_0, false);
//     lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
//     lv_anim_start(&PropertyAnimation_0);
// }
// void blood2_Animation(lv_obj_t *TargetObject, int delay)
// {
//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 3000);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
//     lv_anim_set_values(&PropertyAnimation_0, 0, 102);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
//     lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_0, 0);
//     lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
//     lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_0, false);
//     lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
//     lv_anim_start(&PropertyAnimation_0);
// }
// void blood1_Animation(lv_obj_t *TargetObject, int delay)
// {
//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 2000);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
//     lv_anim_set_values(&PropertyAnimation_0, 102, 0);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
//     lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_0, 0);
//     lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
//     lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_0, false);
//     lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
//     lv_anim_start(&PropertyAnimation_0);
// }
// void heart_Animation(lv_obj_t *TargetObject, int delay)
// {
//     lv_anim_t PropertyAnimation_0;
//     lv_anim_init(&PropertyAnimation_0);
//     lv_anim_set_time(&PropertyAnimation_0, 900);
//     lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
//     lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom);
//     lv_anim_set_values(&PropertyAnimation_0, 73, 37);
//     lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
//     lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
//     lv_anim_set_playback_time(&PropertyAnimation_0, 0);
//     lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
//     lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
//     lv_anim_set_early_apply(&PropertyAnimation_0, false);
//     lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_zoom);
//     lv_anim_start(&PropertyAnimation_0);
// }

// ///////////////////// FUNCTIONS ////////////////////
// void ui_event_start(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_SCREEN_LOADED)
//     {
//         //_ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_NONE, 0, 0);
//         // sec_Animation(ui_sec_dot, 0);
//         // sec_Animation(ui_sec, 0);
//         dots_Animation(ui_dots, 0);
//         cloud_Animation(ui_clouds, 0);
//         blood1_Animation(ui_blood1, 0);
//         blood2_Animation(ui_blood2, 0);

//         heart_Animation(ui_comp_get_child(ui_pulse_group3, UI_COMP_PULSEGROUP_HEART), 0);

//         if (last_watch_page_t)
//         {
//             analog_sec_flg = 1;
//             _ui_screen_change(ui_watch_analog, LV_SCR_LOAD_ANIM_NONE, 0, 0);
//         }
//         else
//         {
//             _ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_NONE, 0, 0);
//         }
//     }
// }
// void ui_event_watch_digital(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
//     {
//         _ui_screen_change(ui_watch_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//         last_watch_page_t = 1;
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
//     {
//         _ui_screen_change(ui_muyu, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
//     if (event_code == LV_EVENT_SCREEN_LOAD_START)
//     {
//         left_Animation(ui_hour_group, 0);
//         right_Animation(ui_label_min, 0);
//         opa_on_Animation(ui_weather_group_1, 300);
//         opa_on_Animation(ui_date_group, 500);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP)
//     {
//         _ui_screen_change(ui_blood_oxy, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM)
//     {
//         _ui_screen_change(ui_blood_oxy, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_top_buttontop(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     ;
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_call, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_down_buttondown(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_weather_1, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_watch_analog(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_SCREEN_LOAD_START)
//     {
//         if (analog_sec_flg)
//         {
//             analog_sec_flg = 0;
//             lv_img_set_angle(ui_sec, ui_time.sec * 60);
//             lv_img_set_angle(ui_sec_dot, ui_time.sec * 60);
//             sec_Animation(ui_sec_dot, 0);
//             sec_Animation(ui_sec, 0);
//         }
//         time_anim_runing = 1;
//         min_Animation(ui_min, 0);
//         hour_Animation(ui_hour, 0);
//         lv_timer_set_repeat_count(lv_timer_create(anim_end_cb, 1000, NULL), 1);
//         opa_on_Animation(ui_weather_group_5, 300);
//         opa_on_Animation(ui_date_group2, 500);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
//     {
//         _ui_screen_change(ui_popcat, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
//     {
//         _ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//         last_watch_page_t = 0;
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP)
//     {
//         _ui_screen_change(ui_blood_oxy, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM)
//     {
//         _ui_screen_change(ui_blood_oxy, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_top1_buttontop(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_call, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_down1_buttondown(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_weather_1, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_call(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_SCREEN_LOAD_START)
//     {
//         top_Animation(ui_avatar, 0);
//         opa_on_Animation(ui_avatar_label, 300);
//         opa_on_Animation(ui_call_time, 400);
//         opa_on_Animation(ui_mute, 500);
//     }
// }
// void ui_event_button_down2_buttondown(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_top2_buttontop(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_watch_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_weather_1(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_SCREEN_LOAD_START)
//     {
//         left_Animation(ui_label_degree, 0);
//         right_Animation(ui_sun, 100);
//         right_Animation(ui_clouds, 200);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
//     {
//         _ui_screen_change(ui_weather_2, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
//     {
//         _ui_screen_change(ui_weather_2, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_down3_buttondown(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_weather_2(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
//     {
//         _ui_screen_change(ui_weather_1, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
//     {
//         _ui_screen_change(ui_weather_1, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_down4_buttondown(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_blood_oxy(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_SCREEN_LOAD_START)
//     {
//         top_Animation(ui_blood_presure_group, 0);
//         opa_on_Animation(ui_arc_spo2, 100);
//         opa_on_Animation(ui_pulse_group, 200);
//         opa_on_Animation(ui_button_round, 300);
//         opa_on_Animation(ui_blood_presure_group, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP)
//     {
//         _ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM)
//     {
//         _ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
//     {
//         _ui_screen_change(ui_ecg, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
//     {
//         _ui_screen_change(ui_blood_pressure, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_down5_buttondown(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_round_buttonround(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_measuing, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_ecg(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_SCREEN_LOAD_START)
//     {
//         top_Animation(ui_chart_group, 0);
//         opa_on_Animation(ui_pulse_group1, 100);
//         opa_on_Animation(ui_button_round1, 200);
//         opa_on_Animation(ui_chart_ecg, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
//     {
//         _ui_screen_change(ui_blood_oxy, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
//     {
//         _ui_screen_change(ui_blood_pressure, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_down6_buttondown(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_round1_buttonround(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_measuing, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_blood_pressure(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_SCREEN_LOAD_START)
//     {
//         top_Animation(ui_blood_presure_group1, 0);
//         opa_on_Animation(ui_blood_presure_group1, 0);
//         top_Animation(ui_blood_presure_group2, 100);
//         opa_on_Animation(ui_blood_presure_group2, 100);
//         opa_on_Animation(ui_button_round2, 200);
//         top_Animation(ui_pulse_group2, 100);
//         opa_on_Animation(ui_pulse_group2, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
//     {
//         _ui_screen_change(ui_blood_oxy, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
//     if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
//     {
//         _ui_screen_change(ui_ecg, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_down7_buttondown(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_button_round2_buttonround(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_measuing, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }
// void ui_event_measuing(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_SCREEN_LOAD_START)
//     {
//         top_Animation(ui_blood_group, 0);
//         opa_on_Animation(ui_blood_group, 0);
//         opa_on_Animation(ui_Spinner2, 300);
//         opa_on_Animation(ui_pulse_group3, 200);
//         opa_on_Animation(ui_measuring, 300);
//         opa_on_Animation(ui_x_button, 300);
//     }
// }
// void ui_event_x_button(lv_event_t *e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     if (event_code == LV_EVENT_CLICKED)
//     {
//         _ui_screen_change(ui_blood_oxy, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }

// ///////////////////// SCREENS ////////////////////
// void ui_start_screen_init(void)
// {
//     ui_start = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_start, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_start, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_start, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_add_event_cb(ui_start, ui_event_start, LV_EVENT_ALL, NULL);
// }

// void ui_watch_digital_screen_init(void)
// {
//     ui_watch_digital = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_watch_digital, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_watch_digital, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_watch_digital, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_bg_1 = lv_img_create(ui_watch_digital);
//     lv_img_set_src(ui_bg_1, &ui_img_bg1_png);
//     // lv_obj_set_width(ui_bg_1, 240);  /// 1
//     // lv_obj_set_height(ui_bg_1, 240); /// 1
//     lv_obj_set_align(ui_bg_1, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_bg_1, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_bg_1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_hour_group = lv_obj_create(ui_watch_digital);
//     lv_obj_set_width(ui_hour_group, 177);
//     lv_obj_set_height(ui_hour_group, 136);
//     lv_obj_clear_flag(ui_hour_group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_hour_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_hour_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_label_hour_1 = lv_label_create(ui_hour_group);
//     lv_obj_set_width(ui_label_hour_1, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_label_hour_1, LV_SIZE_CONTENT); /// 1
//     // lv_obj_set_x(ui_label_hour_1, 5);
//     // lv_obj_set_y(ui_label_hour_1, 37);
//     lv_label_set_text_fmt(ui_label_hour_1, "%02d", ui_time.hour);
//     lv_obj_set_style_text_color(ui_label_hour_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_label_hour_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_label_hour_1, &canger_02w03_150, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_align(ui_label_hour_1, LV_ALIGN_CENTER, -25, 10);

//     // ui_label_hour_2 = lv_label_create(ui_hour_group);
//     // lv_obj_set_width(ui_label_hour_2, LV_SIZE_CONTENT);  /// 1
//     // lv_obj_set_height(ui_label_hour_2, LV_SIZE_CONTENT); /// 1
//     // lv_obj_set_x(ui_label_hour_2, 57);
//     // lv_obj_set_y(ui_label_hour_2, 37);
//     // lv_label_set_text_fmt(ui_label_hour_2, "%d", ui_time.hour % 10);
//     // lv_obj_set_style_text_color(ui_label_hour_2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     // lv_obj_set_style_text_opa(ui_label_hour_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     // lv_obj_set_style_text_font(ui_label_hour_2, &canger_02w03_150, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_label_min = lv_label_create(ui_watch_digital);
//     lv_obj_set_width(ui_label_min, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_label_min, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_label_min, 125);
//     lv_obj_set_y(ui_label_min, 96);
//     lv_label_set_text_fmt(ui_label_min, "%02d", ui_time.min);
//     lv_obj_set_style_text_color(ui_label_min, lv_color_hex(0xEE1E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_label_min, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_label_min, &canger_02w03_92, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_battery_group = ui_batterygroup_create(ui_watch_digital);
//     lv_obj_set_x(ui_battery_group, 0);
//     lv_obj_set_y(ui_battery_group, 16);

//     ui_date_group = ui_dategroup_create(ui_watch_digital);
//     lv_obj_set_x(ui_date_group, 36);
//     lv_obj_set_y(ui_date_group, 40);

//     ui_weather_group_1 = ui_weathergroup1_create(ui_watch_digital);
//     lv_obj_set_x(ui_weather_group_1, -34);
//     lv_obj_set_y(ui_weather_group_1, 20);

//     lv_img_set_src(ui_comp_get_child(ui_weather_group_1, UI_COMP_WEATHERGROUP1_CLOUD_FOG_1), &ui_img_weather_sun_cloud_png);

//     ui_weather_title_group_1 = ui_titlegroup_create(ui_watch_digital);
//     lv_obj_set_x(ui_weather_title_group_1, 8);
//     lv_obj_set_y(ui_weather_title_group_1, -51);
//     lv_obj_set_align(ui_weather_title_group_1, LV_ALIGN_BOTTOM_MID);

//     lv_label_set_text(ui_comp_get_child(ui_weather_title_group_1, UI_COMP_TITLEGROUP_TITLE), "晴转多云");

//     lv_label_set_text(ui_comp_get_child(ui_weather_title_group_1, UI_COMP_TITLEGROUP_SUBTITLE), "23°-34°");

//     ui_step_group = ui_stepgroup_create(ui_watch_digital);
//     lv_obj_set_x(ui_step_group, 0);
//     lv_obj_set_y(ui_step_group, -27);

//     ui_daily_mission_group = ui_dailymissiongroup_create(ui_watch_digital);
//     lv_obj_set_x(ui_daily_mission_group, 0);
//     lv_obj_set_y(ui_daily_mission_group, 0);

//     ui_button_top = ui_buttontop_create(ui_watch_digital);
//     lv_obj_set_x(ui_button_top, 89);
//     lv_obj_set_y(ui_button_top, -64);

//     ui_button_down = ui_buttondown_create(ui_watch_digital);
//     lv_obj_set_x(ui_button_down, 89);
//     lv_obj_set_y(ui_button_down, 62);

//     ui_sec_dot = lv_img_create(ui_watch_digital);
//     lv_img_set_src(ui_sec_dot, &ui_img_sec_dot_png);
//     lv_obj_set_y(ui_sec_dot, -117 + 3);
//     lv_obj_set_align(ui_sec_dot, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_sec_dot, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_img_set_pivot(ui_sec_dot, 3, 117);

//     ui_weather_dots_group2 = lv_obj_create(ui_watch_digital);
//     lv_obj_set_width(ui_weather_dots_group2, 12);
//     lv_obj_set_height(ui_weather_dots_group2, 31);
//     lv_obj_set_x(ui_weather_dots_group2, -6);
//     lv_obj_set_y(ui_weather_dots_group2, 0);
//     lv_obj_set_align(ui_weather_dots_group2, LV_ALIGN_RIGHT_MID);
//     lv_obj_set_flex_flow(ui_weather_dots_group2, LV_FLEX_FLOW_COLUMN);
//     lv_obj_set_flex_align(ui_weather_dots_group2, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_weather_dots_group2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_weather_dots_group2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_weather_dots_group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_weather_dots_group2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_weather_dots_group2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot14 = lv_obj_create(ui_weather_dots_group2);
//     lv_obj_set_width(ui_dot14, 6);
//     lv_obj_set_height(ui_dot14, 6);
//     lv_obj_set_align(ui_dot14, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot14, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot14, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot15 = lv_obj_create(ui_weather_dots_group2);
//     lv_obj_set_width(ui_dot15, 4);
//     lv_obj_set_height(ui_dot15, 4);
//     lv_obj_set_align(ui_dot15, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot15, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot15, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_dot15, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dot15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_add_event_cb(ui_button_top, ui_event_button_top_buttontop, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_button_down, ui_event_button_down_buttondown, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_watch_digital, ui_event_watch_digital, LV_EVENT_ALL, NULL);
// }
// void ui_watch_analog_screen_init(void)
// {
//     ui_watch_analog = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_watch_analog, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_watch_analog, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_watch_analog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_bg_2 = lv_img_create(ui_watch_analog);
//     lv_img_set_src(ui_bg_2, &ui_img_bg1_png);
//     lv_obj_set_width(ui_bg_2, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_bg_2, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_bg_2, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_bg_2, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_bg_2, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_clock = lv_label_create(ui_watch_analog);
//     lv_obj_set_width(ui_clock, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_clock, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_clock, 2);
//     lv_obj_set_y(ui_clock, 46);
//     lv_obj_set_align(ui_clock, LV_ALIGN_TOP_MID);
//     lv_label_set_text_fmt(ui_clock, "%02d   %02d", ui_time.hour, ui_time.min);
//     lv_obj_set_style_text_color(ui_clock, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_clock, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_clock, &CangEr_Kai_22, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dots = lv_label_create(ui_watch_analog);
//     lv_obj_set_width(ui_dots, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_dots, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_dots, 2);
//     lv_obj_set_y(ui_dots, 46);
//     lv_obj_set_align(ui_dots, LV_ALIGN_TOP_MID);
//     lv_label_set_text(ui_dots, ":");
//     lv_obj_set_style_text_color(ui_dots, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_dots, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_dots, &CangEr_Kai_22, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_battery_group1 = ui_batterygroup_create(ui_watch_analog);
//     lv_obj_set_x(ui_battery_group1, 0);
//     lv_obj_set_y(ui_battery_group1, 16);

//     ui_date_group2 = lv_obj_create(ui_watch_analog);
//     lv_obj_set_width(ui_date_group2, 62);
//     lv_obj_set_height(ui_date_group2, 51);
//     lv_obj_set_x(ui_date_group2, 64);
//     lv_obj_set_y(ui_date_group2, 98);
//     lv_obj_set_align(ui_date_group2, LV_ALIGN_TOP_MID);
//     lv_obj_set_flex_flow(ui_date_group2, LV_FLEX_FLOW_COLUMN);
//     lv_obj_set_flex_align(ui_date_group2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_date_group2, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_date_group2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_date_group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_day2 = lv_label_create(ui_date_group2);
//     lv_obj_set_width(ui_day2, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_day2, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_day2, LV_ALIGN_CENTER);
//     lv_label_set_text_fmt(ui_day2, "%s", week_day[ui_time.week]);
//     lv_obj_set_style_text_color(ui_day2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_day2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_day2, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_month2 = lv_label_create(ui_date_group2);
//     lv_obj_set_width(ui_month2, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_month2, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_month2, LV_ALIGN_CENTER);
//     lv_label_set_text_fmt(ui_month2, "%02d月%02d日", ui_time.month, ui_time.day);
//     lv_obj_set_style_text_color(ui_month2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_month2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_month2, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_year2 = lv_label_create(ui_date_group2);
//     lv_obj_set_width(ui_year2, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_year2, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_year2, LV_ALIGN_CENTER);
//     lv_label_set_text_fmt(ui_year2, "20%d年", ui_time.year);
//     lv_obj_set_style_text_color(ui_year2, lv_color_hex(0x6B6B6B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_year2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_year2, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_weather_title_group_2 = ui_titlegroup_create(ui_watch_analog);
//     lv_obj_set_x(ui_weather_title_group_2, 8);
//     lv_obj_set_y(ui_weather_title_group_2, -51);
//     lv_obj_set_align(ui_weather_title_group_2, LV_ALIGN_BOTTOM_MID);

//     lv_label_set_text(ui_comp_get_child(ui_weather_title_group_2, UI_COMP_TITLEGROUP_TITLE), "晴转多云");

//     lv_label_set_text(ui_comp_get_child(ui_weather_title_group_2, UI_COMP_TITLEGROUP_SUBTITLE), "23°-34°");

//     ui_weather_group_5 = lv_obj_create(ui_watch_analog);
//     lv_obj_set_width(ui_weather_group_5, 51);
//     lv_obj_set_height(ui_weather_group_5, 47);
//     lv_obj_set_x(ui_weather_group_5, -55);
//     lv_obj_set_y(ui_weather_group_5, 1);
//     lv_obj_set_align(ui_weather_group_5, LV_ALIGN_CENTER);
//     lv_obj_set_flex_flow(ui_weather_group_5, LV_FLEX_FLOW_COLUMN_REVERSE);
//     lv_obj_set_flex_align(ui_weather_group_5, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_weather_group_5, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_weather_group_5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_weather_group_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_weather_group_5, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_weather_group_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_degree_7 = lv_label_create(ui_weather_group_5);
//     lv_obj_set_width(ui_degree_7, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_degree_7, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_degree_7, 8);
//     lv_obj_set_y(ui_degree_7, 0);
//     lv_obj_set_align(ui_degree_7, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_degree_7, "25°");
//     lv_obj_set_style_text_color(ui_degree_7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_degree_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_degree_7, &CangEr_Kai_22, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_cloud_fog_3 = lv_img_create(ui_weather_group_5);
//     lv_img_set_src(ui_cloud_fog_3, &ui_img_weather_sun_cloud_png);
//     lv_obj_set_width(ui_cloud_fog_3, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_cloud_fog_3, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_cloud_fog_3, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_cloud_fog_3, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_cloud_fog_3, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_step_group2 = ui_stepgroup_create(ui_watch_analog);
//     lv_obj_set_x(ui_step_group2, 0);
//     lv_obj_set_y(ui_step_group2, -27);

//     ui_daily_mission_group1 = ui_dailymissiongroup_create(ui_watch_analog);
//     lv_obj_set_x(ui_daily_mission_group1, 0);
//     lv_obj_set_y(ui_daily_mission_group1, 0);

//     ui_button_top1 = ui_buttontop_create(ui_watch_analog);
//     lv_obj_set_x(ui_button_top1, 89);
//     lv_obj_set_y(ui_button_top1, -64);

//     ui_button_down1 = ui_buttondown_create(ui_watch_analog);
//     lv_obj_set_x(ui_button_down1, 89);
//     lv_obj_set_y(ui_button_down1, 62);

//     ui_clock_group = lv_obj_create(ui_watch_analog);
//     lv_obj_set_width(ui_clock_group, 214);
//     lv_obj_set_height(ui_clock_group, 214);
//     lv_obj_set_align(ui_clock_group, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_clock_group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_clock_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_clock_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_sec = lv_img_create(ui_clock_group);
//     lv_img_set_src(ui_sec, &ui_img_clockwise_sec_png);
//     lv_obj_set_y(ui_sec, -55 + 15);
//     lv_obj_set_align(ui_sec, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_sec, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_img_set_pivot(ui_sec, 10, 95);
//     // lv_img_set_angle(ui_sec, 0);

//     ui_min = lv_img_create(ui_clock_group);
//     lv_img_set_src(ui_min, &ui_img_clockwise_min_png);
//     lv_obj_set_y(ui_min, -52);
//     lv_obj_set_align(ui_min, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_min, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_img_set_pivot(ui_min, 6, 104);

//     ui_hour = lv_img_create(ui_clock_group);
//     lv_img_set_src(ui_hour, &ui_img_clockwise_hour_png);
//     lv_obj_set_y(ui_hour, -32);
//     lv_obj_set_align(ui_hour, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_hour, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_img_set_pivot(ui_hour, 6, 64);

//     ui_dots_group = lv_obj_create(ui_watch_analog);
//     lv_obj_set_width(ui_dots_group, 12);
//     lv_obj_set_height(ui_dots_group, 31);
//     lv_obj_set_x(ui_dots_group, -6);
//     lv_obj_set_y(ui_dots_group, 0);
//     lv_obj_set_align(ui_dots_group, LV_ALIGN_RIGHT_MID);
//     lv_obj_set_flex_flow(ui_dots_group, LV_FLEX_FLOW_COLUMN);
//     lv_obj_set_flex_align(ui_dots_group, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dots_group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_dots_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dots_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_dots_group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_dots_group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot16 = lv_obj_create(ui_dots_group);
//     lv_obj_set_width(ui_dot16, 6);
//     lv_obj_set_height(ui_dot16, 6);
//     lv_obj_set_align(ui_dot16, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot16, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot16, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot17 = lv_obj_create(ui_dots_group);
//     lv_obj_set_width(ui_dot17, 4);
//     lv_obj_set_height(ui_dot17, 4);
//     lv_obj_set_align(ui_dot17, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot17, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot17, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_dot17, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dot17, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_add_event_cb(ui_button_top1, ui_event_button_top1_buttontop, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_button_down1, ui_event_button_down1_buttondown, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_watch_analog, ui_event_watch_analog, LV_EVENT_ALL, NULL);
// }
// void ui_call_screen_init(void)
// {
//     ui_call = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_call, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_call, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     // lv_obj_set_style_bg_opa(ui_call, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_bg_3 = lv_img_create(ui_call);
//     lv_img_set_src(ui_bg_3, &ui_img_bg3_png);
//     lv_obj_set_width(ui_bg_3, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_bg_3, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_bg_3, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_bg_3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST); /// Flags
//     lv_obj_clear_flag(ui_bg_3, LV_OBJ_FLAG_SCROLLABLE);                        /// Flags

//     ui_avatar = lv_img_create(ui_call);
//     lv_img_set_src(ui_avatar, &ui_img_samatha_png);
//     lv_obj_set_width(ui_avatar, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_avatar, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_avatar, LV_ALIGN_TOP_MID);
//     lv_obj_add_flag(ui_avatar, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_avatar, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_avatar_label = lv_label_create(ui_call);
//     lv_obj_set_width(ui_avatar_label, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_avatar_label, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_avatar_label, 0);
//     lv_obj_set_y(ui_avatar_label, 6);
//     lv_obj_set_align(ui_avatar_label, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_avatar_label, "QF MAKER");
//     lv_obj_set_style_text_color(ui_avatar_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_avatar_label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_avatar_label, &CangEr_Kai_22, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_call_time = lv_label_create(ui_call);
//     lv_obj_set_width(ui_call_time, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_call_time, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_call_time, 0);
//     lv_obj_set_y(ui_call_time, 30);
//     lv_obj_set_align(ui_call_time, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_call_time, "01:25.18");
//     lv_obj_set_style_text_color(ui_call_time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_call_time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_call_time, &canger_02w03_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_mute = lv_obj_create(ui_call);
//     lv_obj_set_width(ui_mute, 42);
//     lv_obj_set_height(ui_mute, 31);
//     lv_obj_set_x(ui_mute, 0);
//     lv_obj_set_y(ui_mute, 61);
//     lv_obj_set_align(ui_mute, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_mute, LV_OBJ_FLAG_CHECKABLE);    /// Flags
//     lv_obj_clear_flag(ui_mute, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_mute, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_mute, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_img_src(ui_mute, &ui_img_mute_png, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_img_src(ui_mute, &ui_img_unmute_png, LV_PART_MAIN | LV_STATE_CHECKED);

//     ui_button_down2 = ui_buttondown_create(ui_call);
//     lv_obj_set_x(ui_button_down2, 89);
//     lv_obj_set_y(ui_button_down2, 62);

//     lv_img_set_src(ui_comp_get_child(ui_button_down2, UI_COMP_BUTTONDOWN_BUTTON_DOWN_ICON), &ui_img_house_png);

//     ui_volume_group = lv_obj_create(ui_call);
//     lv_obj_set_width(ui_volume_group, 173);
//     lv_obj_set_height(ui_volume_group, 113);
//     lv_obj_set_align(ui_volume_group, LV_ALIGN_BOTTOM_LEFT);
//     lv_obj_clear_flag(ui_volume_group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_volume_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_volume_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_volume_percent = lv_label_create(ui_volume_group);
//     lv_obj_set_width(ui_volume_percent, LV_SIZE_CONTENT);  /// 90
//     lv_obj_set_height(ui_volume_percent, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_volume_percent, 127);
//     lv_obj_set_y(ui_volume_percent, -10);
//     lv_obj_set_align(ui_volume_percent, LV_ALIGN_BOTTOM_LEFT);
//     lv_label_set_text(ui_volume_percent, "87%");
//     lv_obj_set_style_text_color(ui_volume_percent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_volume_percent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_volume_percent, &canger_02w03_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_volume_image = lv_img_create(ui_volume_group);
//     lv_img_set_src(ui_volume_image, &ui_img_volume_png);
//     lv_obj_set_width(ui_volume_image, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_volume_image, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_volume_image, 12);
//     lv_obj_set_y(ui_volume_image, 24);
//     lv_obj_set_align(ui_volume_image, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_volume_image, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_volume_image, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_volume_arc = lv_arc_create(ui_volume_group);
//     lv_obj_set_width(ui_volume_arc, 202);
//     lv_obj_set_height(ui_volume_arc, 202);
//     lv_obj_set_x(ui_volume_arc, 31);
//     lv_obj_set_y(ui_volume_arc, -60);
//     lv_obj_set_align(ui_volume_arc, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_volume_arc, LV_OBJ_FLAG_ADV_HITTEST); /// Flags
//     lv_arc_set_value(ui_volume_arc, 87);
//     lv_arc_set_bg_angles(ui_volume_arc, 88, 170);
//     lv_obj_set_style_arc_color(ui_volume_arc, lv_color_hex(0x303030), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_opa(ui_volume_arc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_rounded(ui_volume_arc, true, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_set_style_arc_color(ui_volume_arc, lv_color_hex(0xEF1E1E), LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_opa(ui_volume_arc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_rounded(ui_volume_arc, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);

//     lv_obj_set_style_bg_color(ui_volume_arc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_volume_arc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

//     ui_button_top2 = ui_buttontop_create(ui_call);
//     lv_obj_set_x(ui_button_top2, 89);
//     lv_obj_set_y(ui_button_top2, -64);
//     lv_obj_add_state(ui_button_top2, LV_STATE_CHECKED); /// States

//     lv_img_set_src(ui_comp_get_child(ui_button_top2, UI_COMP_BUTTONTOP_BUTTON_TOP_ICON), &ui_img_call2_png);

//     lv_obj_add_flag(ui_comp_get_child(ui_button_top2, UI_COMP_BUTTONTOP_LINE), LV_OBJ_FLAG_HIDDEN); /// Flags

//     lv_obj_add_event_cb(ui_button_down2, ui_event_button_down2_buttondown, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_button_top2, ui_event_button_top2_buttontop, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_call, ui_event_call, LV_EVENT_ALL, NULL);
// }
// void ui_weather_1_screen_init(void)
// {
//     ui_weather_1 = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_weather_1, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_weather_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_bg_4 = lv_img_create(ui_weather_1);
//     lv_img_set_src(ui_bg_4, &ui_img_bg3_png);
//     lv_obj_set_width(ui_bg_4, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_bg_4, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_bg_4, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_bg_4, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_bg_4, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_city_gruop_1 = ui_titlegroup_create(ui_weather_1);
//     lv_obj_set_x(ui_city_gruop_1, -26);
//     lv_obj_set_y(ui_city_gruop_1, -186);
//     lv_obj_set_align(ui_city_gruop_1, LV_ALIGN_BOTTOM_MID);

//     lv_obj_set_x(ui_comp_get_child(ui_city_gruop_1, UI_COMP_TITLEGROUP_TITLE), -18);
//     lv_obj_set_y(ui_comp_get_child(ui_city_gruop_1, UI_COMP_TITLEGROUP_TITLE), 0);
//     lv_obj_set_align(ui_comp_get_child(ui_city_gruop_1, UI_COMP_TITLEGROUP_TITLE), LV_ALIGN_TOP_RIGHT);
//     lv_label_set_text(ui_comp_get_child(ui_city_gruop_1, UI_COMP_TITLEGROUP_TITLE), "沙坪坝区");
//     lv_obj_set_style_text_font(ui_comp_get_child(ui_city_gruop_1, UI_COMP_TITLEGROUP_TITLE), &CangEr_Kai_14,
//                                LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_label_set_text(ui_comp_get_child(ui_city_gruop_1, UI_COMP_TITLEGROUP_SUBTITLE), "4-16 星期天");

//     ui_weather_title_group_3 = ui_titlegroup_create(ui_weather_1);
//     lv_obj_set_x(ui_weather_title_group_3, -25);
//     lv_obj_set_y(ui_weather_title_group_3, -69);
//     lv_obj_set_align(ui_weather_title_group_3, LV_ALIGN_BOTTOM_MID);

//     lv_obj_set_x(ui_comp_get_child(ui_weather_title_group_3, UI_COMP_TITLEGROUP_TITLE), -18);
//     lv_obj_set_y(ui_comp_get_child(ui_weather_title_group_3, UI_COMP_TITLEGROUP_TITLE), 0);
//     lv_label_set_text(ui_comp_get_child(ui_weather_title_group_3, UI_COMP_TITLEGROUP_TITLE), "晴转多云");

//     lv_obj_set_x(ui_comp_get_child(ui_weather_title_group_3, UI_COMP_TITLEGROUP_SUBTITLE), 5);
//     lv_label_set_text(ui_comp_get_child(ui_weather_title_group_3, UI_COMP_TITLEGROUP_SUBTITLE), "23°-34°");

//     ui_label_degree = lv_label_create(ui_weather_1);
//     lv_obj_set_width(ui_label_degree, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_label_degree, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_label_degree, -39);
//     lv_obj_set_y(ui_label_degree, -22);
//     lv_obj_set_align(ui_label_degree, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_label_degree, "25°");
//     lv_obj_set_style_text_color(ui_label_degree, lv_color_hex(0xEE1E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_label_degree, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_label_degree, &canger_02w03_92, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_rain_group = lv_obj_create(ui_weather_1);
//     lv_obj_set_width(ui_rain_group, 43);
//     lv_obj_set_height(ui_rain_group, 20);
//     lv_obj_set_x(ui_rain_group, 58);
//     lv_obj_set_y(ui_rain_group, -31);
//     lv_obj_set_align(ui_rain_group, LV_ALIGN_BOTTOM_LEFT);
//     lv_obj_set_flex_flow(ui_rain_group, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_rain_group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_rain_group, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_rain_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_rain_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_rain_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_rain_group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_rain_icon = lv_img_create(ui_rain_group);
//     lv_img_set_src(ui_rain_icon, &ui_img_rain_png);
//     lv_obj_set_width(ui_rain_icon, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_rain_icon, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_rain_icon, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_rain_icon, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_rain_icon, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_rain_percent = lv_label_create(ui_rain_group);
//     lv_obj_set_width(ui_rain_percent, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_rain_percent, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_rain_percent, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_rain_percent, "18%");
//     lv_obj_set_style_text_color(ui_rain_percent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_rain_percent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_rain_percent, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_wind_group = lv_obj_create(ui_weather_1);
//     lv_obj_set_width(ui_wind_group, 75);
//     lv_obj_set_height(ui_wind_group, 20);
//     lv_obj_set_x(ui_wind_group, 112);
//     lv_obj_set_y(ui_wind_group, -31);
//     lv_obj_set_align(ui_wind_group, LV_ALIGN_BOTTOM_LEFT);
//     lv_obj_set_flex_flow(ui_wind_group, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_wind_group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_wind_group, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_wind_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_wind_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_wind_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_wind_group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_wind_icon = lv_img_create(ui_wind_group);
//     lv_img_set_src(ui_wind_icon, &ui_img_wind_png);
//     lv_obj_set_width(ui_wind_icon, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_wind_icon, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_wind_icon, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_wind_icon, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_wind_icon, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_wind_speed = lv_label_create(ui_wind_group);
//     lv_obj_set_width(ui_wind_speed, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_wind_speed, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_wind_speed, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_wind_speed, "54 km/h");
//     lv_obj_set_style_text_color(ui_wind_speed, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_wind_speed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_wind_speed, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_weather_dots_group = lv_obj_create(ui_weather_1);
//     lv_obj_set_width(ui_weather_dots_group, 30);
//     lv_obj_set_height(ui_weather_dots_group, 11);
//     lv_obj_set_x(ui_weather_dots_group, 0);
//     lv_obj_set_y(ui_weather_dots_group, -9);
//     lv_obj_set_align(ui_weather_dots_group, LV_ALIGN_BOTTOM_MID);
//     lv_obj_set_flex_flow(ui_weather_dots_group, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_weather_dots_group, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_weather_dots_group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_weather_dots_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_weather_dots_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_weather_dots_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_weather_dots_group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot1 = lv_obj_create(ui_weather_dots_group);
//     lv_obj_set_width(ui_dot1, 6);
//     lv_obj_set_height(ui_dot1, 6);
//     lv_obj_set_align(ui_dot1, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot1, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot2 = lv_obj_create(ui_weather_dots_group);
//     lv_obj_set_width(ui_dot2, 4);
//     lv_obj_set_height(ui_dot2, 4);
//     lv_obj_set_align(ui_dot2, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot2, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_dot2, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dot2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_weather_image_group = lv_obj_create(ui_weather_1);
//     lv_obj_set_width(ui_weather_image_group, 147);
//     lv_obj_set_height(ui_weather_image_group, 187);
//     lv_obj_set_x(ui_weather_image_group, 9);
//     lv_obj_set_y(ui_weather_image_group, 0);
//     lv_obj_set_align(ui_weather_image_group, LV_ALIGN_TOP_RIGHT);
//     lv_obj_clear_flag(ui_weather_image_group, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_weather_image_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_weather_image_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_sun = lv_img_create(ui_weather_image_group);
//     lv_img_set_src(ui_sun, &ui_img_sun_png);
//     lv_obj_set_width(ui_sun, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_sun, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_sun, LV_ALIGN_TOP_RIGHT);
//     lv_obj_add_flag(ui_sun, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_sun, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_clouds = lv_img_create(ui_weather_image_group);
//     lv_img_set_src(ui_clouds, &ui_img_clouds_png);
//     lv_obj_set_width(ui_clouds, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_clouds, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_clouds, 23);
//     lv_obj_set_y(ui_clouds, -8);
//     lv_obj_set_align(ui_clouds, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_clouds, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_clouds, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_button_down3 = ui_buttondown_create(ui_weather_1);
//     lv_obj_set_x(ui_button_down3, 89);
//     lv_obj_set_y(ui_button_down3, 62);

//     lv_img_set_src(ui_comp_get_child(ui_button_down3, UI_COMP_BUTTONDOWN_BUTTON_DOWN_ICON), &ui_img_house_png);

//     lv_obj_add_event_cb(ui_button_down3, ui_event_button_down3_buttondown, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_weather_1, ui_event_weather_1, LV_EVENT_ALL, NULL);
// }
// void ui_weather_2_screen_init(void)
// {
//     ui_weather_2 = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_weather_2, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_weather_2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_bg5 = lv_img_create(ui_weather_2);
//     lv_img_set_src(ui_bg5, &ui_img_bg3_png);
//     lv_obj_set_width(ui_bg5, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_bg5, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_bg5, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_bg5, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_bg5, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_weather_dots_group1 = lv_obj_create(ui_weather_2);
//     lv_obj_set_width(ui_weather_dots_group1, 30);
//     lv_obj_set_height(ui_weather_dots_group1, 11);
//     lv_obj_set_x(ui_weather_dots_group1, 0);
//     lv_obj_set_y(ui_weather_dots_group1, -9);
//     lv_obj_set_align(ui_weather_dots_group1, LV_ALIGN_BOTTOM_MID);
//     lv_obj_set_flex_flow(ui_weather_dots_group1, LV_FLEX_FLOW_ROW_REVERSE);
//     lv_obj_set_flex_align(ui_weather_dots_group1, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_weather_dots_group1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_weather_dots_group1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_weather_dots_group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_weather_dots_group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_weather_dots_group1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot3 = lv_obj_create(ui_weather_dots_group1);
//     lv_obj_set_width(ui_dot3, 6);
//     lv_obj_set_height(ui_dot3, 6);
//     lv_obj_set_align(ui_dot3, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot3, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot4 = lv_obj_create(ui_weather_dots_group1);
//     lv_obj_set_width(ui_dot4, 4);
//     lv_obj_set_height(ui_dot4, 4);
//     lv_obj_set_align(ui_dot4, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot4, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot4, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_dot4, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dot4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_content = lv_obj_create(ui_weather_2);
//     lv_obj_set_width(ui_content, lv_pct(100));
//     lv_obj_set_height(ui_content, lv_pct(100));
//     lv_obj_set_align(ui_content, LV_ALIGN_CENTER);
//     lv_obj_set_flex_flow(ui_content, LV_FLEX_FLOW_COLUMN);
//     lv_obj_set_flex_align(ui_content, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_set_scrollbar_mode(ui_content, LV_SCROLLBAR_MODE_OFF);
//     lv_obj_set_style_bg_color(ui_content, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_content, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_left(ui_content, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_right(ui_content, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_top(ui_content, 24, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_bottom(ui_content, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_content, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_content, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_city_gruop_2 = ui_titlegroup_create(ui_content);
//     lv_obj_set_x(ui_city_gruop_2, -26);
//     lv_obj_set_y(ui_city_gruop_2, -186);
//     lv_obj_set_align(ui_city_gruop_2, LV_ALIGN_BOTTOM_MID);

//     lv_obj_set_x(ui_comp_get_child(ui_city_gruop_2, UI_COMP_TITLEGROUP_TITLE), 0);
//     lv_obj_set_y(ui_comp_get_child(ui_city_gruop_2, UI_COMP_TITLEGROUP_TITLE), 0);
//     lv_obj_set_align(ui_comp_get_child(ui_city_gruop_2, UI_COMP_TITLEGROUP_TITLE), LV_ALIGN_TOP_MID);
//     lv_label_set_text(ui_comp_get_child(ui_city_gruop_2, UI_COMP_TITLEGROUP_TITLE), "沙坪坝区");
//     lv_obj_set_style_text_font(ui_comp_get_child(ui_city_gruop_2, UI_COMP_TITLEGROUP_TITLE), &CangEr_Kai_14,
//                                LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_label_set_text(ui_comp_get_child(ui_city_gruop_2, UI_COMP_TITLEGROUP_SUBTITLE), "4-16 星期天");

//     ui_todady_weather_content = lv_obj_create(ui_content);
//     lv_obj_set_height(ui_todady_weather_content, 84);
//     lv_obj_set_width(ui_todady_weather_content, lv_pct(100));
//     lv_obj_set_x(ui_todady_weather_content, 0);
//     lv_obj_set_y(ui_todady_weather_content, -7);
//     lv_obj_set_align(ui_todady_weather_content, LV_ALIGN_CENTER);
//     lv_obj_set_flex_flow(ui_todady_weather_content, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_todady_weather_content, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_set_style_bg_color(ui_todady_weather_content, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_todady_weather_content, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_left(ui_todady_weather_content, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_right(ui_todady_weather_content, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_top(ui_todady_weather_content, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_bottom(ui_todady_weather_content, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_todady_weather_content, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_todady_weather_content, 18, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_set_style_bg_color(ui_todady_weather_content, lv_color_hex(0xFFFFFF), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_todady_weather_content, 30, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_left(ui_todady_weather_content, 18, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_right(ui_todady_weather_content, 18, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_top(ui_todady_weather_content, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_bottom(ui_todady_weather_content, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

//     ui_today_weather_group = ui_todayweathergroup_create(ui_todady_weather_content);
//     lv_obj_set_x(ui_today_weather_group, 0);
//     lv_obj_set_y(ui_today_weather_group, 0);

//     lv_img_set_src(ui_comp_get_child(ui_today_weather_group, UI_COMP_TODAYWEATHERGROUP_CLOUD_SUN),
//                    &ui_img_weather_sun_cloud_png);

//     lv_obj_set_style_text_color(ui_comp_get_child(ui_today_weather_group, UI_COMP_TODAYWEATHERGROUP_DEGREE_8),
//                                 lv_color_hex(0xED1E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_comp_get_child(ui_today_weather_group, UI_COMP_TODAYWEATHERGROUP_DEGREE_8), 255,
//                               LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_today_weather_group1 = ui_todayweathergroup_create(ui_todady_weather_content);
//     lv_obj_set_x(ui_today_weather_group1, 0);
//     lv_obj_set_y(ui_today_weather_group1, 0);

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group1, UI_COMP_TODAYWEATHERGROUP_DEGREE_6), "26°");

//     lv_img_set_src(ui_comp_get_child(ui_today_weather_group1, UI_COMP_TODAYWEATHERGROUP_CLOUD_SUN),
//                    &ui_img_weather_cloud_png);

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group1, UI_COMP_TODAYWEATHERGROUP_DEGREE_8), "16:00");

//     ui_today_weather_group2 = ui_todayweathergroup_create(ui_todady_weather_content);
//     lv_obj_set_x(ui_today_weather_group2, 0);
//     lv_obj_set_y(ui_today_weather_group2, 0);

//     lv_img_set_src(ui_comp_get_child(ui_today_weather_group2, UI_COMP_TODAYWEATHERGROUP_CLOUD_SUN),
//                    &ui_img_weather_sun_cloud_png);

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group2, UI_COMP_TODAYWEATHERGROUP_DEGREE_8), "17:00");

//     ui_today_weather_group3 = ui_todayweathergroup_create(ui_todady_weather_content);
//     lv_obj_set_x(ui_today_weather_group3, 0);
//     lv_obj_set_y(ui_today_weather_group3, 0);

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group3, UI_COMP_TODAYWEATHERGROUP_DEGREE_6), "22°");

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group3, UI_COMP_TODAYWEATHERGROUP_DEGREE_8), "18:00");

//     ui_today_weather_group4 = ui_todayweathergroup_create(ui_todady_weather_content);
//     lv_obj_set_x(ui_today_weather_group4, 0);
//     lv_obj_set_y(ui_today_weather_group4, 0);

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group4, UI_COMP_TODAYWEATHERGROUP_DEGREE_6), "21°");

//     lv_img_set_src(ui_comp_get_child(ui_today_weather_group4, UI_COMP_TODAYWEATHERGROUP_CLOUD_SUN),
//                    &ui_img_weather_cloud_fog_png);

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group4, UI_COMP_TODAYWEATHERGROUP_DEGREE_8), "19:00");

//     ui_today_weather_group5 = ui_todayweathergroup_create(ui_todady_weather_content);
//     lv_obj_set_x(ui_today_weather_group5, 0);
//     lv_obj_set_y(ui_today_weather_group5, 0);

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group5, UI_COMP_TODAYWEATHERGROUP_DEGREE_6), "20°");

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group5, UI_COMP_TODAYWEATHERGROUP_DEGREE_8), "20:00");

//     ui_today_weather_group6 = ui_todayweathergroup_create(ui_todady_weather_content);
//     lv_obj_set_x(ui_today_weather_group6, 0);
//     lv_obj_set_y(ui_today_weather_group6, 0);

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group6, UI_COMP_TODAYWEATHERGROUP_DEGREE_6), "20°");

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group6, UI_COMP_TODAYWEATHERGROUP_DEGREE_8), "21:00");

//     ui_today_weather_group7 = ui_todayweathergroup_create(ui_todady_weather_content);
//     lv_obj_set_x(ui_today_weather_group7, 0);
//     lv_obj_set_y(ui_today_weather_group7, 0);

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group7, UI_COMP_TODAYWEATHERGROUP_DEGREE_6), "19°");

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group7, UI_COMP_TODAYWEATHERGROUP_DEGREE_8), "22:00");

//     ui_today_weather_group8 = ui_todayweathergroup_create(ui_todady_weather_content);
//     lv_obj_set_x(ui_today_weather_group8, 0);
//     lv_obj_set_y(ui_today_weather_group8, 0);

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group8, UI_COMP_TODAYWEATHERGROUP_DEGREE_6), "17°");

//     lv_label_set_text(ui_comp_get_child(ui_today_weather_group8, UI_COMP_TODAYWEATHERGROUP_DEGREE_8), "23:00");

//     ui_days_forecast = lv_label_create(ui_content);
//     lv_obj_set_width(ui_days_forecast, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_days_forecast, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_days_forecast, -53);
//     lv_obj_set_y(ui_days_forecast, 38);
//     lv_obj_set_align(ui_days_forecast, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_days_forecast, "未来十天");
//     lv_obj_add_flag(ui_days_forecast, LV_OBJ_FLAG_IGNORE_LAYOUT); /// Flags
//     lv_obj_set_style_text_font(ui_days_forecast, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_week_weather_group = lv_obj_create(ui_content);
//     lv_obj_set_width(ui_week_weather_group, 190);
//     lv_obj_set_height(ui_week_weather_group, LV_SIZE_CONTENT); /// 205
//     lv_obj_set_x(ui_week_weather_group, 0);
//     lv_obj_set_y(ui_week_weather_group, 10);
//     lv_obj_set_align(ui_week_weather_group, LV_ALIGN_CENTER);
//     lv_obj_set_flex_flow(ui_week_weather_group, LV_FLEX_FLOW_COLUMN);
//     lv_obj_set_flex_align(ui_week_weather_group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_week_weather_group, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_week_weather_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_week_weather_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_left(ui_week_weather_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_right(ui_week_weather_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_top(ui_week_weather_group, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_bottom(ui_week_weather_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_forecast_group = ui_forecastgroup_create(ui_week_weather_group);
//     lv_obj_set_x(ui_forecast_group, 6);
//     lv_obj_set_y(ui_forecast_group, 48);

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group, UI_COMP_FORECASTGROUP_DAY1), "周一");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group, UI_COMP_FORECASTGROUP_DEGREE_GROUP_DAYTIME), "24°");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group, UI_COMP_FORECASTGROUP_DEGREE_GROUP_NIGHTTIME), "17°");

//     lv_img_set_src(ui_comp_get_child(ui_forecast_group, UI_COMP_FORECASTGROUP_CLOUD_SUN), &ui_img_weather_cloud_fog_png);

//     ui_forecast_group1 = ui_forecastgroup_create(ui_week_weather_group);
//     lv_obj_set_x(ui_forecast_group1, 6);
//     lv_obj_set_y(ui_forecast_group1, 48);

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group1, UI_COMP_FORECASTGROUP_DAY1), "周二");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group1, UI_COMP_FORECASTGROUP_DEGREE_GROUP_NIGHTTIME), "19°");

//     ui_forecast_group2 = ui_forecastgroup_create(ui_week_weather_group);
//     lv_obj_set_x(ui_forecast_group2, 6);
//     lv_obj_set_y(ui_forecast_group2, 48);

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group2, UI_COMP_FORECASTGROUP_DAY1), "周三");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group2, UI_COMP_FORECASTGROUP_DEGREE_GROUP_DAYTIME), "26°");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group2, UI_COMP_FORECASTGROUP_DEGREE_GROUP_NIGHTTIME), "19°");

//     lv_img_set_src(ui_comp_get_child(ui_forecast_group2, UI_COMP_FORECASTGROUP_CLOUD_SUN), &ui_img_weather_cloud_png);

//     ui_forecast_group3 = ui_forecastgroup_create(ui_week_weather_group);
//     lv_obj_set_x(ui_forecast_group3, 6);
//     lv_obj_set_y(ui_forecast_group3, 48);

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group3, UI_COMP_FORECASTGROUP_DAY1), "周四");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group3, UI_COMP_FORECASTGROUP_DEGREE_GROUP_NIGHTTIME), "16°");

//     lv_img_set_src(ui_comp_get_child(ui_forecast_group3, UI_COMP_FORECASTGROUP_CLOUD_SUN), &ui_img_weather_cloud_fog_png);

//     ui_forecast_group4 = ui_forecastgroup_create(ui_week_weather_group);
//     lv_obj_set_x(ui_forecast_group4, 6);
//     lv_obj_set_y(ui_forecast_group4, 48);

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group4, UI_COMP_FORECASTGROUP_DAY1), "周五");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group4, UI_COMP_FORECASTGROUP_DEGREE_GROUP_DAYTIME), "27°");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group4, UI_COMP_FORECASTGROUP_DEGREE_GROUP_NIGHTTIME), "20°");

//     ui_forecast_group5 = ui_forecastgroup_create(ui_week_weather_group);
//     lv_obj_set_x(ui_forecast_group5, 6);
//     lv_obj_set_y(ui_forecast_group5, 48);

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group5, UI_COMP_FORECASTGROUP_DAY1), "周六");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group5, UI_COMP_FORECASTGROUP_DEGREE_GROUP_DAYTIME), "29°");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group5, UI_COMP_FORECASTGROUP_DEGREE_GROUP_NIGHTTIME), "21°");

//     ui_forecast_group1 = ui_forecastgroup_create(ui_week_weather_group);
//     lv_obj_set_x(ui_forecast_group1, 6);
//     lv_obj_set_y(ui_forecast_group1, 48);

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group1, UI_COMP_FORECASTGROUP_DAY1), "周天");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group1, UI_COMP_FORECASTGROUP_DEGREE_GROUP_NIGHTTIME), "19°");

//     ui_forecast_group2 = ui_forecastgroup_create(ui_week_weather_group);
//     lv_obj_set_x(ui_forecast_group2, 6);
//     lv_obj_set_y(ui_forecast_group2, 48);

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group2, UI_COMP_FORECASTGROUP_DAY1), "周一");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group2, UI_COMP_FORECASTGROUP_DEGREE_GROUP_DAYTIME), "26°");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group2, UI_COMP_FORECASTGROUP_DEGREE_GROUP_NIGHTTIME), "19°");

//     lv_img_set_src(ui_comp_get_child(ui_forecast_group2, UI_COMP_FORECASTGROUP_CLOUD_SUN), &ui_img_weather_cloud_png);

//     ui_forecast_group3 = ui_forecastgroup_create(ui_week_weather_group);
//     lv_obj_set_x(ui_forecast_group3, 6);
//     lv_obj_set_y(ui_forecast_group3, 48);

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group3, UI_COMP_FORECASTGROUP_DAY1), "周二");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group3, UI_COMP_FORECASTGROUP_DEGREE_GROUP_NIGHTTIME), "16°");

//     lv_img_set_src(ui_comp_get_child(ui_forecast_group3, UI_COMP_FORECASTGROUP_CLOUD_SUN), &ui_img_weather_cloud_fog_png);

//     ui_forecast_group4 = ui_forecastgroup_create(ui_week_weather_group);
//     lv_obj_set_x(ui_forecast_group4, 6);
//     lv_obj_set_y(ui_forecast_group4, 48);

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group4, UI_COMP_FORECASTGROUP_DAY1), "周三");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group4, UI_COMP_FORECASTGROUP_DEGREE_GROUP_DAYTIME), "27°");

//     lv_label_set_text(ui_comp_get_child(ui_forecast_group4, UI_COMP_FORECASTGROUP_DEGREE_GROUP_NIGHTTIME), "20°");

//     ui_space = lv_obj_create(ui_week_weather_group);
//     lv_obj_set_height(ui_space, 31);
//     lv_obj_set_width(ui_space, lv_pct(100));
//     lv_obj_set_align(ui_space, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_space, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_space, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_space, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_button_down4 = ui_buttondown_create(ui_weather_2);
//     lv_obj_set_x(ui_button_down4, 89);
//     lv_obj_set_y(ui_button_down4, 62);

//     lv_img_set_src(ui_comp_get_child(ui_button_down4, UI_COMP_BUTTONDOWN_BUTTON_DOWN_ICON), &ui_img_house_png);

//     lv_obj_add_event_cb(ui_button_down4, ui_event_button_down4_buttondown, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_weather_2, ui_event_weather_2, LV_EVENT_ALL, NULL);
// }
// void ui_blood_oxy_screen_init(void)
// {
//     ui_blood_oxy = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_blood_oxy, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_blood_oxy, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_bg6 = lv_img_create(ui_blood_oxy);
//     lv_img_set_src(ui_bg6, &ui_img_bg3_png);
//     lv_obj_set_width(ui_bg6, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_bg6, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_bg6, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_bg6, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_bg6, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_title_group_1 = ui_titlegroup_create(ui_blood_oxy);
//     lv_obj_set_x(ui_title_group_1, 0);
//     lv_obj_set_y(ui_title_group_1, -180);
//     lv_obj_set_align(ui_title_group_1, LV_ALIGN_BOTTOM_MID);

//     lv_obj_set_x(ui_comp_get_child(ui_title_group_1, UI_COMP_TITLEGROUP_TITLE), 0);
//     lv_obj_set_y(ui_comp_get_child(ui_title_group_1, UI_COMP_TITLEGROUP_TITLE), 0);
//     lv_obj_set_align(ui_comp_get_child(ui_title_group_1, UI_COMP_TITLEGROUP_TITLE), LV_ALIGN_TOP_MID);
//     lv_label_set_text(ui_comp_get_child(ui_title_group_1, UI_COMP_TITLEGROUP_TITLE), "SpO2");
//     lv_obj_set_style_text_font(ui_comp_get_child(ui_title_group_1, UI_COMP_TITLEGROUP_TITLE), &canger_02w03_14,
//                                LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_label_set_text(ui_comp_get_child(ui_title_group_1, UI_COMP_TITLEGROUP_SUBTITLE), "血氧");

//     ui_button_down5 = ui_buttondown_create(ui_blood_oxy);
//     lv_obj_set_x(ui_button_down5, 89);
//     lv_obj_set_y(ui_button_down5, 62);

//     lv_img_set_src(ui_comp_get_child(ui_button_down5, UI_COMP_BUTTONDOWN_BUTTON_DOWN_ICON), &ui_img_house_png);

//     ui_button_round = ui_buttonround_create(ui_blood_oxy);
//     lv_obj_set_x(ui_button_round, 0);
//     lv_obj_set_y(ui_button_round, -37);

//     ui_blood_presure_group = lv_obj_create(ui_blood_oxy);
//     lv_obj_set_height(ui_blood_presure_group, 65);
//     lv_obj_set_width(ui_blood_presure_group, LV_SIZE_CONTENT); /// 186
//     lv_obj_set_x(ui_blood_presure_group, 0);
//     lv_obj_set_y(ui_blood_presure_group, -19);
//     lv_obj_set_align(ui_blood_presure_group, LV_ALIGN_CENTER);
//     lv_obj_set_flex_flow(ui_blood_presure_group, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_blood_presure_group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_START);
//     lv_obj_clear_flag(ui_blood_presure_group, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_blood_presure_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_blood_presure_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_blood_oxygen = lv_label_create(ui_blood_presure_group);
//     lv_obj_set_height(ui_blood_oxygen, lv_pct(80));
//     lv_obj_set_width(ui_blood_oxygen, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_blood_oxygen, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_blood_oxygen, "91");
//     lv_obj_set_style_text_color(ui_blood_oxygen, lv_color_hex(0xEE1E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_blood_oxygen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_blood_oxygen, &canger_02w03_92, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_percent = lv_label_create(ui_blood_presure_group);
//     lv_obj_set_width(ui_percent, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_percent, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_percent, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_percent, "%");
//     lv_obj_set_style_text_color(ui_percent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_percent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_percent, &CangEr_Kai_22, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_pulse_group = ui_pulsegroup_create(ui_blood_oxy);
//     lv_obj_set_x(ui_pulse_group, 0);
//     lv_obj_set_y(ui_pulse_group, 25);
//     lv_obj_set_style_border_color(ui_pulse_group, lv_color_hex(0x545454), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_opa(ui_pulse_group, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_width(ui_pulse_group, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_pulse_group, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_arc_spo2 = lv_arc_create(ui_blood_oxy);
//     lv_obj_set_width(ui_arc_spo2, 227);
//     lv_obj_set_height(ui_arc_spo2, 227);
//     lv_obj_set_align(ui_arc_spo2, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_arc_spo2, LV_OBJ_FLAG_CLICKABLE); /// Flags
//     lv_arc_set_value(ui_arc_spo2, 91);
//     lv_arc_set_bg_angles(ui_arc_spo2, 145, 335);
//     lv_obj_set_style_arc_color(ui_arc_spo2, lv_color_hex(0x414141), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_opa(ui_arc_spo2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_rounded(ui_arc_spo2, true, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_set_style_arc_color(ui_arc_spo2, lv_color_hex(0x41A1E6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_opa(ui_arc_spo2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_rounded(ui_arc_spo2, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);

//     lv_obj_set_style_bg_color(ui_arc_spo2, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_arc_spo2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

//     ui_precent_70 = lv_label_create(ui_blood_oxy);
//     lv_obj_set_width(ui_precent_70, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_precent_70, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_precent_70, 32);
//     lv_obj_set_y(ui_precent_70, -37);
//     lv_obj_set_align(ui_precent_70, LV_ALIGN_BOTTOM_LEFT);
//     lv_label_set_text(ui_precent_70, "70%");
//     lv_obj_set_style_text_color(ui_precent_70, lv_color_hex(0x6A6D6A), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_precent_70, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_precent_70, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_precent_100 = lv_label_create(ui_blood_oxy);
//     lv_obj_set_width(ui_precent_100, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_precent_100, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_precent_100, -12);
//     lv_obj_set_y(ui_precent_100, -39);
//     lv_obj_set_align(ui_precent_100, LV_ALIGN_RIGHT_MID);
//     lv_label_set_text(ui_precent_100, "100%");
//     lv_obj_set_style_text_color(ui_precent_100, lv_color_hex(0x6A6D6A), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_precent_100, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_precent_100, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_health_dots_group = lv_obj_create(ui_blood_oxy);
//     lv_obj_set_width(ui_health_dots_group, 62);
//     lv_obj_set_height(ui_health_dots_group, 11);
//     lv_obj_set_x(ui_health_dots_group, 0);
//     lv_obj_set_y(ui_health_dots_group, -9);
//     lv_obj_set_align(ui_health_dots_group, LV_ALIGN_BOTTOM_MID);
//     lv_obj_set_flex_flow(ui_health_dots_group, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_health_dots_group, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_health_dots_group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_health_dots_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_health_dots_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_health_dots_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_health_dots_group, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot7 = lv_obj_create(ui_health_dots_group);
//     lv_obj_set_width(ui_dot7, 6);
//     lv_obj_set_height(ui_dot7, 6);
//     lv_obj_set_align(ui_dot7, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot7, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot7, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot6 = lv_obj_create(ui_health_dots_group);
//     lv_obj_set_width(ui_dot6, 4);
//     lv_obj_set_height(ui_dot6, 4);
//     lv_obj_set_align(ui_dot6, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot6, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot6, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_dot6, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dot6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot5 = lv_obj_create(ui_health_dots_group);
//     lv_obj_set_width(ui_dot5, 4);
//     lv_obj_set_height(ui_dot5, 4);
//     lv_obj_set_align(ui_dot5, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot5, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot5, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_dot5, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dot5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dots_group1 = lv_obj_create(ui_blood_oxy);
//     lv_obj_set_width(ui_dots_group1, 12);
//     lv_obj_set_height(ui_dots_group1, 31);
//     lv_obj_set_x(ui_dots_group1, -6);
//     lv_obj_set_y(ui_dots_group1, 0);
//     lv_obj_set_align(ui_dots_group1, LV_ALIGN_RIGHT_MID);
//     lv_obj_set_flex_flow(ui_dots_group1, LV_FLEX_FLOW_COLUMN_REVERSE);
//     lv_obj_set_flex_align(ui_dots_group1, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dots_group1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_dots_group1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dots_group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_dots_group1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_dots_group1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot18 = lv_obj_create(ui_dots_group1);
//     lv_obj_set_width(ui_dot18, 6);
//     lv_obj_set_height(ui_dot18, 6);
//     lv_obj_set_align(ui_dot18, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot18, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot18, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot19 = lv_obj_create(ui_dots_group1);
//     lv_obj_set_width(ui_dot19, 4);
//     lv_obj_set_height(ui_dot19, 4);
//     lv_obj_set_align(ui_dot19, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot19, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot19, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_dot19, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dot19, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_add_event_cb(ui_button_down5, ui_event_button_down5_buttondown, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_button_round, ui_event_button_round_buttonround, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_blood_oxy, ui_event_blood_oxy, LV_EVENT_ALL, NULL);
// }
// void ui_ecg_screen_init(void)
// {
//     ui_ecg = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_ecg, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_ecg, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_Image1 = lv_img_create(ui_ecg);
//     lv_img_set_src(ui_Image1, &ui_img_s8_png);
//     lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);  /// 397
//     lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT); /// 397
//     lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_bg1 = lv_img_create(ui_ecg);
//     lv_img_set_src(ui_bg1, &ui_img_bg3_png);
//     lv_obj_set_width(ui_bg1, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_bg1, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_bg1, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_bg1, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_bg1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_title_group_2 = ui_titlegroup_create(ui_ecg);
//     lv_obj_set_x(ui_title_group_2, 0);
//     lv_obj_set_y(ui_title_group_2, -186);
//     lv_obj_set_align(ui_title_group_2, LV_ALIGN_BOTTOM_MID);

//     lv_obj_set_x(ui_comp_get_child(ui_title_group_2, UI_COMP_TITLEGROUP_TITLE), 0);
//     lv_obj_set_y(ui_comp_get_child(ui_title_group_2, UI_COMP_TITLEGROUP_TITLE), 0);
//     lv_obj_set_align(ui_comp_get_child(ui_title_group_2, UI_COMP_TITLEGROUP_TITLE), LV_ALIGN_TOP_MID);
//     lv_label_set_text(ui_comp_get_child(ui_title_group_2, UI_COMP_TITLEGROUP_TITLE), "心电图");
//     lv_obj_set_style_text_font(ui_comp_get_child(ui_title_group_2, UI_COMP_TITLEGROUP_TITLE), &CangEr_Kai_14,
//                                LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_label_set_text(ui_comp_get_child(ui_title_group_2, UI_COMP_TITLEGROUP_SUBTITLE), "7小时之前");

//     ui_button_down6 = ui_buttondown_create(ui_ecg);
//     lv_obj_set_x(ui_button_down6, 89);
//     lv_obj_set_y(ui_button_down6, 62);

//     lv_img_set_src(ui_comp_get_child(ui_button_down6, UI_COMP_BUTTONDOWN_BUTTON_DOWN_ICON), &ui_img_house_png);

//     ui_button_round1 = ui_buttonround_create(ui_ecg);
//     lv_obj_set_x(ui_button_round1, 0);
//     lv_obj_set_y(ui_button_round1, -28);

//     ui_pulse_group1 = ui_pulsegroup_create(ui_ecg);
//     lv_obj_set_x(ui_pulse_group1, 0);
//     lv_obj_set_y(ui_pulse_group1, 32);

//     ui_health_dots_group1 = lv_obj_create(ui_ecg);
//     lv_obj_set_width(ui_health_dots_group1, 62);
//     lv_obj_set_height(ui_health_dots_group1, 11);
//     lv_obj_set_x(ui_health_dots_group1, 0);
//     lv_obj_set_y(ui_health_dots_group1, -9);
//     lv_obj_set_align(ui_health_dots_group1, LV_ALIGN_BOTTOM_MID);
//     lv_obj_set_flex_flow(ui_health_dots_group1, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_health_dots_group1, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_health_dots_group1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_health_dots_group1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_health_dots_group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_health_dots_group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_health_dots_group1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot9 = lv_obj_create(ui_health_dots_group1);
//     lv_obj_set_width(ui_dot9, 4);
//     lv_obj_set_height(ui_dot9, 4);
//     lv_obj_set_align(ui_dot9, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot9, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot9, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_dot9, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dot9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot8 = lv_obj_create(ui_health_dots_group1);
//     lv_obj_set_width(ui_dot8, 6);
//     lv_obj_set_height(ui_dot8, 6);
//     lv_obj_set_align(ui_dot8, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot8, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot8, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot10 = lv_obj_create(ui_health_dots_group1);
//     lv_obj_set_width(ui_dot10, 4);
//     lv_obj_set_height(ui_dot10, 4);
//     lv_obj_set_align(ui_dot10, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot10, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot10, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_dot10, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dot10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_chart_group = lv_obj_create(ui_ecg);
//     lv_obj_set_height(ui_chart_group, 72);
//     lv_obj_set_width(ui_chart_group, lv_pct(100));
//     lv_obj_set_x(ui_chart_group, 0);
//     lv_obj_set_y(ui_chart_group, -21);
//     lv_obj_set_align(ui_chart_group, LV_ALIGN_CENTER);
//     lv_obj_set_style_bg_color(ui_chart_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_chart_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_set_style_bg_color(ui_chart_group, lv_color_hex(0x494949), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_chart_group, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

//     ui_chart_ecg = lv_chart_create(ui_chart_group);
//     lv_obj_set_width(ui_chart_ecg, 308);
//     lv_obj_set_height(ui_chart_ecg, 61);
//     lv_obj_set_align(ui_chart_ecg, LV_ALIGN_LEFT_MID);
//     lv_chart_set_type(ui_chart_ecg, LV_CHART_TYPE_LINE);
//     lv_chart_set_point_count(ui_chart_ecg, 90);
//     lv_chart_set_div_line_count(ui_chart_ecg, 6, 24);
//     lv_chart_set_axis_tick(ui_chart_ecg, LV_CHART_AXIS_PRIMARY_X, 1, 10, 0, 10, false, 50);
//     lv_chart_set_axis_tick(ui_chart_ecg, LV_CHART_AXIS_PRIMARY_Y, 1, 5, 0, 2, false, 50);
//     lv_chart_series_t *ui_chart_ecg_series_1 = lv_chart_add_series(ui_chart_ecg, lv_color_hex(0xEE1C18),
//                                                                    LV_CHART_AXIS_PRIMARY_Y);
//     static lv_coord_t ui_chart_ecg_series_1_array[] = {20, 20, 21, 24, 25, 24, 22, 25, 18, 90, 10, 24, 25, 28, 38, 39, 28, 24, 23, 25, 27, 27, 25, 22, 20, 20, 20, 21, 24, 25, 24, 22, 25, 18, 90, 10, 24, 25, 28, 38, 39, 28, 24, 23, 25, 27, 27, 25, 22, 20, 20, 20, 21, 24, 25, 24, 22, 25, 18, 90, 10, 24, 25, 28, 38, 39, 28, 24, 23, 25, 27, 27, 25, 22, 20, 20, 21, 24, 25, 24, 22, 25, 18, 90, 10, 24, 25, 28, 38, 39, 28, 24, 23, 25, 27, 27, 25, 22, 20, 20, 21, 24, 25, 24, 22, 25, 18, 90, 10, 24, 25, 28, 38, 39, 28, 24, 23, 25, 27, 27, 25, 22, 20, 20, 21, 24, 25, 24, 22, 25, 18, 90, 10, 24, 25, 28, 38, 39, 28, 24, 23, 25, 27, 27, 25, 22, 20};
//     lv_chart_set_ext_y_array(ui_chart_ecg, ui_chart_ecg_series_1, ui_chart_ecg_series_1_array);
//     lv_obj_set_style_bg_color(ui_chart_ecg, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_chart_ecg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_line_color(ui_chart_ecg, lv_color_hex(0x2C2C2C), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_line_opa(ui_chart_ecg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_set_style_line_width(ui_chart_ecg, 2, LV_PART_ITEMS | LV_STATE_DEFAULT);

//     lv_obj_add_event_cb(ui_button_down6, ui_event_button_down6_buttondown, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_button_round1, ui_event_button_round1_buttonround, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ecg, ui_event_ecg, LV_EVENT_ALL, NULL);
// }
// void ui_blood_pressure_screen_init(void)
// {
//     ui_blood_pressure = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_blood_pressure, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_blood_pressure, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_bg2 = lv_img_create(ui_blood_pressure);
//     lv_img_set_src(ui_bg2, &ui_img_bg3_png);
//     lv_obj_set_width(ui_bg2, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_bg2, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_bg2, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_bg2, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_bg2, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_Image3 = lv_img_create(ui_blood_pressure);
//     lv_img_set_src(ui_Image3, &ui_img_s9_png);
//     lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST); /// Flags
//     lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);                     /// Flags

//     ui_title_group_3 = ui_titlegroup_create(ui_blood_pressure);
//     lv_obj_set_x(ui_title_group_3, 0);
//     lv_obj_set_y(ui_title_group_3, -186);
//     lv_obj_set_align(ui_title_group_3, LV_ALIGN_BOTTOM_MID);

//     lv_obj_set_x(ui_comp_get_child(ui_title_group_3, UI_COMP_TITLEGROUP_TITLE), 0);
//     lv_obj_set_y(ui_comp_get_child(ui_title_group_3, UI_COMP_TITLEGROUP_TITLE), 0);
//     lv_obj_set_align(ui_comp_get_child(ui_title_group_3, UI_COMP_TITLEGROUP_TITLE), LV_ALIGN_TOP_MID);
//     lv_label_set_text(ui_comp_get_child(ui_title_group_3, UI_COMP_TITLEGROUP_TITLE), "血压");
//     lv_obj_set_style_text_font(ui_comp_get_child(ui_title_group_3, UI_COMP_TITLEGROUP_TITLE), &CangEr_Kai_14,
//                                LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_label_set_text(ui_comp_get_child(ui_title_group_3, UI_COMP_TITLEGROUP_SUBTITLE), "7小时之前");
//     lv_obj_add_flag(ui_comp_get_child(ui_title_group_3, UI_COMP_TITLEGROUP_SUBTITLE), LV_OBJ_FLAG_HIDDEN); /// Flags

//     ui_button_down7 = ui_buttondown_create(ui_blood_pressure);
//     lv_obj_set_x(ui_button_down7, 89);
//     lv_obj_set_y(ui_button_down7, 62);

//     lv_img_set_src(ui_comp_get_child(ui_button_down7, UI_COMP_BUTTONDOWN_BUTTON_DOWN_ICON), &ui_img_house_png);

//     ui_button_round2 = ui_buttonround_create(ui_blood_pressure);
//     lv_obj_set_x(ui_button_round2, 0);
//     lv_obj_set_y(ui_button_round2, -28);

//     ui_blood_presure_group1 = lv_obj_create(ui_blood_pressure);
//     lv_obj_set_width(ui_blood_presure_group1, 114);
//     lv_obj_set_height(ui_blood_presure_group1, 86);
//     lv_obj_set_x(ui_blood_presure_group1, -51);
//     lv_obj_set_y(ui_blood_presure_group1, -1);
//     lv_obj_set_align(ui_blood_presure_group1, LV_ALIGN_CENTER);
//     lv_obj_set_flex_flow(ui_blood_presure_group1, LV_FLEX_FLOW_COLUMN);
//     lv_obj_set_flex_align(ui_blood_presure_group1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
//     lv_obj_clear_flag(ui_blood_presure_group1, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_blood_presure_group1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_blood_presure_group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_blood_presure_group1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_blood_presure_group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_sys_group = lv_obj_create(ui_blood_presure_group1);
//     lv_obj_set_width(ui_sys_group, 89);
//     lv_obj_set_height(ui_sys_group, 26);
//     lv_obj_set_x(ui_sys_group, 22);
//     lv_obj_set_y(ui_sys_group, -24);
//     lv_obj_set_align(ui_sys_group, LV_ALIGN_RIGHT_MID);
//     lv_obj_set_flex_flow(ui_sys_group, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_sys_group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_sys_group, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_sys_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_sys_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_sys_group, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_sys_group, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_sys = lv_label_create(ui_sys_group);
//     lv_obj_set_width(ui_sys, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_sys, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_sys, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_sys, "最高");
//     lv_obj_set_style_text_color(ui_sys, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_sys, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_sys, &CangEr_Kai_22, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_mmhg1 = lv_label_create(ui_sys_group);
//     lv_obj_set_height(ui_mmhg1, 18);
//     lv_obj_set_width(ui_mmhg1, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_mmhg1, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_mmhg1, "mmhg");
//     lv_obj_set_style_text_color(ui_mmhg1, lv_color_hex(0x7B7D7B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_mmhg1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_mmhg1, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_blood_oxygen1 = lv_label_create(ui_blood_presure_group1);
//     lv_obj_set_width(ui_blood_oxygen1, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_blood_oxygen1, LV_SIZE_CONTENT); /// 80
//     lv_obj_set_align(ui_blood_oxygen1, LV_ALIGN_CENTER);
//     lv_obj_set_y(ui_blood_oxygen1, -12);
//     lv_label_set_text(ui_blood_oxygen1, "136");
//     lv_obj_set_style_text_color(ui_blood_oxygen1, lv_color_hex(0xEE1E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_blood_oxygen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_blood_oxygen1, &canger_02w03_92, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_pulse_group2 = ui_pulsegroup_create(ui_blood_pressure);
//     lv_obj_set_x(ui_pulse_group2, 0);
//     lv_obj_set_y(ui_pulse_group2, 41);
//     lv_obj_set_align(ui_pulse_group2, LV_ALIGN_TOP_MID);

//     ui_blood_presure_group2 = lv_obj_create(ui_blood_pressure);
//     lv_obj_set_width(ui_blood_presure_group2, 114);
//     lv_obj_set_height(ui_blood_presure_group2, 86);
//     lv_obj_set_x(ui_blood_presure_group2, 75);
//     lv_obj_set_y(ui_blood_presure_group2, 0);
//     lv_obj_set_align(ui_blood_presure_group2, LV_ALIGN_CENTER);
//     lv_obj_set_flex_flow(ui_blood_presure_group2, LV_FLEX_FLOW_COLUMN);
//     lv_obj_set_flex_align(ui_blood_presure_group2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
//     lv_obj_clear_flag(ui_blood_presure_group2, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_blood_presure_group2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_blood_presure_group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_blood_presure_group2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_blood_presure_group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dia_group = lv_obj_create(ui_blood_presure_group2);
//     lv_obj_set_width(ui_dia_group, 89);
//     lv_obj_set_height(ui_dia_group, 26);
//     lv_obj_set_x(ui_dia_group, 22);
//     lv_obj_set_y(ui_dia_group, -24);
//     lv_obj_set_align(ui_dia_group, LV_ALIGN_RIGHT_MID);
//     lv_obj_set_flex_flow(ui_dia_group, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_dia_group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dia_group, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_dia_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dia_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_dia_group, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_dia_group, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dia = lv_label_create(ui_dia_group);
//     lv_obj_set_width(ui_dia, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_dia, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_dia, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_dia, "平均");
//     lv_obj_set_style_text_color(ui_dia, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_dia, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_dia, &CangEr_Kai_22, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_mmhg2 = lv_label_create(ui_dia_group);
//     lv_obj_set_height(ui_mmhg2, 18);
//     lv_obj_set_width(ui_mmhg2, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_mmhg2, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_mmhg2, "mmhg");
//     lv_obj_set_style_text_color(ui_mmhg2, lv_color_hex(0x7B7D7B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_mmhg2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_mmhg2, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_blood_oxygen2 = lv_label_create(ui_blood_presure_group2);
//     lv_obj_set_width(ui_blood_oxygen2, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_blood_oxygen2, LV_SIZE_CONTENT); /// 80
//     lv_obj_set_align(ui_blood_oxygen2, LV_ALIGN_CENTER);
//     lv_obj_set_y(ui_blood_oxygen2, -12);
//     lv_label_set_text(ui_blood_oxygen2, "85");
//     lv_obj_set_style_text_color(ui_blood_oxygen2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_blood_oxygen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_blood_oxygen2, &canger_02w03_92, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_health_dots_group2 = lv_obj_create(ui_blood_pressure);
//     lv_obj_set_width(ui_health_dots_group2, 62);
//     lv_obj_set_height(ui_health_dots_group2, 11);
//     lv_obj_set_x(ui_health_dots_group2, 0);
//     lv_obj_set_y(ui_health_dots_group2, -9);
//     lv_obj_set_align(ui_health_dots_group2, LV_ALIGN_BOTTOM_MID);
//     lv_obj_set_flex_flow(ui_health_dots_group2, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_health_dots_group2, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_health_dots_group2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_health_dots_group2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_health_dots_group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_health_dots_group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_health_dots_group2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot12 = lv_obj_create(ui_health_dots_group2);
//     lv_obj_set_width(ui_dot12, 4);
//     lv_obj_set_height(ui_dot12, 4);
//     lv_obj_set_align(ui_dot12, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot12, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot12, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_dot12, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dot12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot13 = lv_obj_create(ui_health_dots_group2);
//     lv_obj_set_width(ui_dot13, 4);
//     lv_obj_set_height(ui_dot13, 4);
//     lv_obj_set_align(ui_dot13, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot13, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot13, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_dot13, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_dot13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_dot11 = lv_obj_create(ui_health_dots_group2);
//     lv_obj_set_width(ui_dot11, 6);
//     lv_obj_set_height(ui_dot11, 6);
//     lv_obj_set_align(ui_dot11, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_dot11, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_dot11, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_add_event_cb(ui_button_down7, ui_event_button_down7_buttondown, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_button_round2, ui_event_button_round2_buttonround, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_blood_pressure, ui_event_blood_pressure, LV_EVENT_ALL, NULL);
// }
// void ui_measuing_screen_init(void)
// {
//     ui_measuing = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_measuing, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_measuing, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_bg7 = lv_img_create(ui_measuing);
//     lv_img_set_src(ui_bg7, &ui_img_bg3_png);
//     lv_obj_set_width(ui_bg7, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_bg7, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_bg7, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_bg7, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_bg7, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_pulse_group3 = ui_pulsegroup_create(ui_measuing);
//     lv_obj_set_x(ui_pulse_group3, 0);
//     lv_obj_set_y(ui_pulse_group3, 43);
//     lv_obj_set_style_border_color(ui_pulse_group3, lv_color_hex(0x545454), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_opa(ui_pulse_group3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_width(ui_pulse_group3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_pulse_group3, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_measuring = lv_label_create(ui_measuing);
//     lv_obj_set_width(ui_measuring, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_measuring, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_measuring, 0);
//     lv_obj_set_y(ui_measuring, 73);
//     lv_obj_set_align(ui_measuring, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_measuring, "测量中...");
//     lv_obj_set_style_text_color(ui_measuring, lv_color_hex(0x6A6D6A), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_measuring, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_measuring, &CangEr_Kai_14, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_Spinner2 = lv_spinner_create(ui_measuing, 1000, 90);
//     lv_obj_set_width(ui_Spinner2, 122);
//     lv_obj_set_height(ui_Spinner2, 122);
//     lv_obj_set_x(ui_Spinner2, 0);
//     lv_obj_set_y(ui_Spinner2, -43);
//     lv_obj_set_align(ui_Spinner2, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_Spinner2, LV_OBJ_FLAG_CLICKABLE); /// Flags
//     lv_obj_set_style_arc_color(ui_Spinner2, lv_color_hex(0x3E413E), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_opa(ui_Spinner2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_width(ui_Spinner2, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_set_style_arc_color(ui_Spinner2, lv_color_hex(0xEE1C18), LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_opa(ui_Spinner2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_arc_rounded(ui_Spinner2, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);

//     ui_blood_group = lv_obj_create(ui_measuing);
//     lv_obj_set_width(ui_blood_group, 98);
//     lv_obj_set_height(ui_blood_group, 98);
//     lv_obj_set_x(ui_blood_group, 0);
//     lv_obj_set_y(ui_blood_group, -43);
//     lv_obj_set_align(ui_blood_group, LV_ALIGN_CENTER);
//     lv_obj_clear_flag(ui_blood_group, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_radius(ui_blood_group, 98, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_blood_group, lv_color_hex(0x390800), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_blood_group, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_clip_corner(ui_blood_group, true, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_color(ui_blood_group, lv_color_hex(0x4E2725), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_opa(ui_blood_group, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_width(ui_blood_group, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_outline_pad(ui_blood_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_blood1 = lv_img_create(ui_blood_group);
//     lv_img_set_src(ui_blood1, &ui_img_wave2_png);
//     lv_obj_set_width(ui_blood1, 245);
//     lv_obj_set_height(ui_blood1, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_blood1, -59);
//     lv_obj_set_y(ui_blood1, -4);
//     lv_obj_set_align(ui_blood1, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_blood1, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_blood1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_blood_fill = lv_obj_create(ui_blood_group);
//     lv_obj_set_height(ui_blood_fill, 44);
//     lv_obj_set_width(ui_blood_fill, lv_pct(100));
//     lv_obj_set_align(ui_blood_fill, LV_ALIGN_BOTTOM_MID);
//     lv_obj_clear_flag(ui_blood_fill, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_blood_fill, lv_color_hex(0xDE615A), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_blood_fill, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_grad_color(ui_blood_fill, lv_color_hex(0xDE1810), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_grad_dir(ui_blood_fill, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_blood2 = lv_img_create(ui_blood_group);
//     lv_img_set_src(ui_blood2, &ui_img_wave1_png);
//     lv_obj_set_width(ui_blood2, 246);
//     lv_obj_set_height(ui_blood2, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_x(ui_blood2, -31);
//     lv_obj_set_y(ui_blood2, -2);
//     lv_obj_set_align(ui_blood2, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_blood2, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_blood2, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     ui_x_button = lv_btn_create(ui_measuing);
//     lv_obj_set_width(ui_x_button, 31);
//     lv_obj_set_height(ui_x_button, 40);
//     lv_obj_set_align(ui_x_button, LV_ALIGN_BOTTOM_MID);
//     lv_obj_add_flag(ui_x_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
//     lv_obj_clear_flag(ui_x_button, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
//     lv_obj_set_style_radius(ui_x_button, 31, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_x_button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_x_button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_x = lv_img_create(ui_x_button);
//     lv_img_set_src(ui_x, &ui_img_x_png);
//     lv_obj_set_width(ui_x, LV_SIZE_CONTENT);  /// 1
//     lv_obj_set_height(ui_x, LV_SIZE_CONTENT); /// 1
//     lv_obj_set_align(ui_x, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_x, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
//     lv_obj_clear_flag(ui_x, LV_OBJ_FLAG_SCROLLABLE); /// Flags

//     lv_obj_add_event_cb(ui_x_button, ui_event_x_button, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_measuing, ui_event_measuing, LV_EVENT_ALL, NULL);
// }

// void ui_muyu_timer_img(lv_timer_t *e)
// {
//     lv_img_set_zoom(ui_muyu_img, 256);
//     per_motor_set(0);
// }

// void ui_event_muyu(lv_event_t *e)
// {
//     if (e->code == LV_EVENT_PRESSED)
//     {
//         per_motor_set(40);
//         lv_obj_t *label = lv_label_create(ui_muyu);
//         lv_label_set_text(label, "功德+1");
//         lv_obj_align(label, LV_ALIGN_CENTER, 0, -70);
//         lv_obj_set_style_text_font(label, &CangEr_Kai_22, 0);
//         lv_obj_set_style_text_color(label, lv_color_hex(0x9A7E5D), 0);
//         lv_obj_add_flag(label, LV_OBJ_FLAG_USER_3);

//         lv_anim_t _muyu_anim;
//         lv_anim_init(&_muyu_anim);
//         lv_anim_set_time(&_muyu_anim, 500);
//         lv_anim_set_user_data(&_muyu_anim, label);
//         lv_anim_set_custom_exec_cb(&_muyu_anim, _ui_anim_callback_set_y);
//         lv_anim_set_values(&_muyu_anim, 0, -50);
//         lv_anim_set_path_cb(&_muyu_anim, lv_anim_path_ease_in);
//         lv_anim_set_delay(&_muyu_anim, 100);
//         lv_anim_set_repeat_count(&_muyu_anim, 0);
//         // lv_anim_set_early_apply(&_muyu_anim, true);
//         lv_anim_set_get_value_cb(&_muyu_anim, &_ui_anim_callback_get_y);
//         lv_anim_start(&_muyu_anim);

//         lv_timer_t *muyu_timer = lv_timer_create(ui_muyu_timer_img, 30, NULL);
//         lv_timer_set_repeat_count(muyu_timer, 1);
//         lv_timer_enable(1);
//         lv_img_set_zoom(ui_muyu_img, 256 + 15);
//         amituofo_t++;
//         lv_label_set_text_fmt((lv_obj_t *)e->user_data, "功德:%d", amituofo_t);
//         lv_obj_align((lv_obj_t *)e->user_data, LV_ALIGN_BOTTOM_MID, 0, -5);

//     }
//     else if (e->code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
//     {
//         _ui_screen_change(ui_watch_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }

// void ui_muyu_event_btn(lv_event_t *e)
// {
//     amituofo_t = 0;
//     lv_label_set_text_fmt((lv_obj_t *)e->user_data, "功德:%d", amituofo_t);
//     lv_obj_align((lv_obj_t *)e->user_data, LV_ALIGN_BOTTOM_MID, 0, -5);
// }

// void ui_muyu_screen_init()
// {
//     ui_muyu = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_muyu, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_muyu, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_muyu_img = lv_img_create(ui_muyu);
//     lv_img_set_src(ui_muyu_img, &img_muyu);
//     lv_obj_clear_flag(ui_muyu_img, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_align(ui_muyu_img, LV_ALIGN_CENTER, 0, 0);

//     lv_obj_t *btn = lv_btn_create(ui_muyu);
//     lv_obj_remove_style_all(btn);
//     lv_obj_set_size(btn, 30, 20);
//     lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, -5);

//     lv_obj_t *label = lv_label_create(ui_muyu);
//     lv_obj_set_style_text_font(label, &CangEr_Kai_18, 0);
//     lv_obj_set_style_text_color(label, lv_color_hex(0xd9b38c), 0);
//     lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, -5);
//     lv_label_set_text_fmt(label, "功德:%d", amituofo_t);

//     lv_obj_add_event_cb(btn, ui_muyu_event_btn, LV_EVENT_CLICKED, label);
//     lv_obj_add_event_cb(ui_muyu, ui_event_muyu, LV_EVENT_ALL, label);
// }

// void ui_event_popcat(lv_event_t *e)
// {
//     if (e->code == LV_EVENT_PRESSED)
//     {
//         lv_img_set_src(ui_popcat_img, &img_popcat_open);
//         per_motor_set(30);
//     }
//     else if (e->code == LV_EVENT_RELEASED)
//     {
//         lv_img_set_src(ui_popcat_img, &img_popcat_close);
//         per_motor_set(0);
//     }
//     if (e->code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
//     {
//         lv_img_set_src(ui_popcat_img, &img_popcat_close);
//         per_motor_set(0);
//         _ui_screen_change(ui_watch_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
//     }
// }

// void ui_popcat_screen_init()
// {
//     ui_popcat = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_popcat, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_set_style_bg_color(ui_popcat, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_popcat_img = lv_img_create(ui_popcat);
//     lv_img_set_src(ui_popcat_img, &img_popcat_close);
//     lv_obj_clear_flag(ui_popcat_img, LV_OBJ_FLAG_SCROLLABLE); /// Flags
//     lv_obj_align(ui_popcat_img, LV_ALIGN_CENTER, 0, 0);

//     lv_obj_add_event_cb(ui_popcat, ui_event_popcat, LV_EVENT_ALL, NULL);
// }

// void time_sec_cb(lv_timer_t *e)
// {
//     ui_time.sec++;
// }

// void ui_init(ui_time_t *time)
// {

//     ui_time = *time;
//     ui_time.sec++;
//     LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

//     lv_disp_t *dispp = lv_disp_get_default();
//     lv_theme_t *theme = lv_theme_basic_init(dispp);
//     lv_disp_set_theme(dispp, theme);
//     ui_start_screen_init();
//     ui_watch_digital_screen_init();
//     ui_watch_analog_screen_init();
//     ui_call_screen_init();
//     ui_weather_1_screen_init();
//     ui_weather_2_screen_init();
//     ui_blood_oxy_screen_init();
//     ui_ecg_screen_init();
//     ui_blood_pressure_screen_init();
//     ui_measuing_screen_init();
//     ui_muyu_screen_init();
//     ui_popcat_screen_init();

//     lv_disp_load_scr(ui_start);

//     sec_anim_timer = lv_timer_create(time_sec_cb, 1000, NULL);
//     lv_timer_set_repeat_count(sec_anim_timer, -1);

//     init_flg = 1;
//     ui_time_anim_refresh(time);
// }

// uint8_t ui_get_init_flg()
// {
//     return init_flg;
// }
