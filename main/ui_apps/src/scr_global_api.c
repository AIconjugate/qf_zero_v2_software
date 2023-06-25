
// #include "scr_global_api.h"

// #include "device_interfaces.h"
// #include "scr_scheduler.h"
// #include "system_data.h"
// #include "scr_global_data.h"

// void scr_global_load_init()
// {
//     // system_paras_t *_sys = system_get_paras();
//     //scr_global_paras_t *_global = scr_global_get_paras();

// }

// void scr_obj_set_border_focus_color(lv_obj_t *obj, uint8_t width, uint8_t opa)
// {
//     lv_obj_set_style_border_width(obj, width, LV_STATE_FOCUSED);
//     lv_obj_set_style_border_opa(obj, opa, LV_STATE_FOCUSED);
//     scr_global_paras_t *tmp = scr_global_get_paras();
//     lv_obj_set_style_border_color(obj, lv_color_hex(tmp->eeprom.focus_color), LV_STATE_FOCUSED);
// }

// void scr_obj_set_border_edit_color(lv_obj_t *obj, uint8_t width, uint8_t opa)
// {
//     lv_obj_set_style_border_width(obj, width, LV_STATE_EDITED);
//     lv_obj_set_style_border_opa(obj, opa, LV_STATE_EDITED);
//     scr_global_paras_t *tmp = scr_global_get_paras();
//     lv_obj_set_style_border_color(obj, lv_color_hex(tmp->eeprom.edit_color), LV_STATE_EDITED);
// }

// void scr_obj_set_outline_focus_color(lv_obj_t *obj, uint8_t width, uint8_t opa)
// {
//     scr_global_paras_t *tmp = scr_global_get_paras();
//     lv_obj_set_style_outline_color(obj, lv_color_hex(tmp->eeprom.focus_color), LV_STATE_FOCUSED);
//     lv_obj_set_style_outline_width(obj, width, LV_STATE_FOCUSED);
//     lv_obj_set_style_outline_opa(obj, opa, LV_STATE_FOCUSED);
// }

// void scr_obj_set_outline_edit_color(lv_obj_t *obj, uint8_t width, uint8_t opa)
// {
//     lv_obj_set_style_outline_width(obj, width, LV_STATE_EDITED);
//     lv_obj_set_style_outline_opa(obj, opa, LV_STATE_EDITED);
//     scr_global_paras_t *tmp = scr_global_get_paras();
//     lv_obj_set_style_outline_color(obj, lv_color_hex(tmp->eeprom.edit_color), LV_STATE_EDITED);
// }

// lv_obj_t *scr_obj_creat(lv_obj_t *para, int32_t weight, int32_t height, uint8_t radius, lv_color_t color, uint8_t opa)
// {
//     lv_obj_t *obj = lv_obj_create(para);
//     lv_obj_remove_style_all(obj);
//     lv_obj_set_size(obj, weight, height);
//     lv_obj_set_style_radius(obj, radius, 0);
//     lv_obj_set_style_bg_color(obj, color, 0);
//     lv_obj_set_style_bg_opa(obj, opa, 0);
//     return obj;
// }

// lv_obj_t *scr_lable_create(lv_obj_t *pararent, int32_t width, int32_t height, const char *text, const lv_font_t *font, lv_color_t color)
// {
//     lv_obj_t *label = lv_label_create(pararent);
//     if (width != 0)
//         lv_obj_set_width(label, width);
//     if (height != 0)
//         lv_obj_set_width(label, height);
//     if (font != NULL)
//         lv_obj_set_style_text_font(label, font, 0);
//     if (text != NULL)
//         lv_label_set_text_static(label, text);
//     lv_obj_set_style_text_color(label, color, 0);
//     return label;
// }

// lv_obj_t *scr_slider_create(lv_obj_t *para, int32_t min, int32_t max, int32_t var, int32_t weight, int32_t height, uint8_t radius, lv_group_t *group)
// {
//     lv_obj_t *slider = lv_slider_create(para);
//     lv_obj_remove_style_all(slider);
//     lv_obj_set_size(slider, weight, height);
//     lv_slider_set_range(slider, min, max);
//     lv_slider_set_value(slider, var, LV_ANIM_OFF);
//     lv_obj_set_style_radius(slider, radius, 0);
//     if (group != NULL)
//         lv_group_add_obj(group, slider);
//     return slider;
// }

// void scr_slider_set_style(lv_obj_t *obj, lv_color_t bg, lv_color_t in_bg, bool grad_en, lv_color_t grad_color)
// {

//     lv_obj_set_style_bg_opa(obj, 255, 0);
//     lv_obj_set_style_bg_color(obj, bg, 0);

//     lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR);
//     lv_obj_set_style_bg_color(obj, in_bg, LV_PART_INDICATOR);
//     if (grad_en == 1)
//     {
//         lv_obj_set_style_bg_grad_color(obj, grad_color, LV_PART_INDICATOR);
//         lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_INDICATOR);
//     }

//     lv_obj_set_style_outline_color(obj, lv_color_hex(0x3C3E49), LV_PART_MAIN);
//     scr_global_paras_t *tmp = scr_global_get_paras();
//     lv_obj_set_style_outline_color(obj, lv_color_hex(tmp->eeprom.focus_color), LV_PART_MAIN | LV_STATE_FOCUSED);
//     lv_obj_set_style_outline_color(obj, lv_color_hex(tmp->eeprom.edit_color), LV_PART_MAIN | LV_STATE_EDITED);

//     lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN);
// }

// void slider_value_changed_cb(lv_event_t *e)
// {
//     lv_label_set_text_fmt((lv_obj_t *)e->user_data, "%d", lv_slider_get_value(e->target));
// }

// lv_obj_t *scr_btn_create(lv_obj_t *para, int32_t weight, int32_t height, uint8_t radius, lv_color_t color, lv_group_t *group)
// {
//     lv_obj_t *btn = lv_btn_create(para);
//     lv_obj_remove_style_all(btn);
//     lv_obj_set_size(btn, weight, height);
//     lv_obj_set_style_radius(btn, radius, 0);
//     lv_obj_set_style_bg_color(btn, color, 0);
//     lv_obj_set_style_bg_opa(btn, 255, 0);
//     if (group != NULL)
//         lv_group_add_obj(group, btn);
//     return btn;
// }
