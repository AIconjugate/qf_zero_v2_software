
// #include "scr_scheduler.h"


// typedef struct
// {
//     lv_obj_t *msgbox;
//     lv_obj_t *btn;
// } lv_timer_user_t;

// typedef struct scr_list
// {
//     scr_load_cb_t scr_load;
//     scr_del_cb_t scr_del;
//     const char *scr_str;
//     struct scr_list *next;
// } scr_list_t;

// static scr_list_t *list_head = NULL;
// static scr_list_t *list_move = NULL;
// static scr_list_t *list_tail = NULL;
// static scr_list_t *list_act = NULL;
// static lv_scr_load_anim_t _anim_type = scr_load_anim_defaule;
// static uint32_t _load_time = scr_load_time_defaule;
// static uint32_t _load_delay = scr_load_delay_defaule;

// void scr_attach(scr_load_cb_t scr_load, scr_del_cb_t scr_del, const char *name_str)
// {
//     if (list_head == NULL)
//     {
//         list_head = lv_mem_alloc(sizeof(scr_list_t));
//         list_head->next = NULL;
//         list_head->scr_load = scr_load;
//         list_head->scr_del = scr_del;
//         list_head->scr_str = name_str;
//         list_tail = list_head;
//         return;
//     }
//     // list_move = list_tail;
//     list_move = (scr_list_t *)lv_mem_alloc(sizeof(scr_list_t));

//     list_tail->next = list_move;

//     list_move->next = NULL;
//     list_move->scr_load = scr_load;
//     list_move->scr_del = scr_del;
//     list_move->scr_str = name_str;
//     list_tail = list_move;
// }

// void scr_load(const char *name_str)
// {
//     if (list_head == NULL)
//         return;
//     list_move = list_head;
//     for (;;)
//     {
//         if (strcmp(list_move->scr_str, name_str) == 0) // 找到界面
//         {
//             lv_obj_t *new_scr = list_move->scr_load(); // 获取界面对象
//             if (new_scr == NULL)                       // 界面为空
//             {
//                 scr_create_msg_box_str(lv_scr_act(), "No this page~");
//                 break;
//             }
//             lv_scr_load_anim(new_scr, _anim_type, _load_time, _load_delay, scr_delete_old_screen); // 加载界面
//             if (list_act != NULL)                                                                  // 当前有激活的界面
//                 list_act->scr_del();                                                               // 通知界面转至后台
//             list_act = list_move;
//             _anim_type = scr_load_anim_defaule;
//             _load_time = scr_load_time_defaule;
//             _load_delay = scr_load_delay_defaule;
//             break;
//         }
//         if (list_move->next == NULL)
//         {
//             scr_create_msg_box_str(lv_scr_act(), "No this page~");
//             break;
//         }
//         list_move = list_move->next;
//     }
// }

// void scr_load_anim(const char *name_str, lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay)
// {
//     _anim_type = anim_type;
//     _load_time = time;
//     _load_delay = delay;
//     scr_load(name_str);
// }

// static void msg_box_timer(lv_timer_t *e)
// {
//     lv_timer_user_t *user_t = (lv_timer_user_t *)e->user_data;
//     lv_obj_clear_flag(user_t->btn, LV_OBJ_FLAG_USER_4);
//     lv_msgbox_close(user_t->msgbox);
//     lv_mem_free(user_t);
// }

// void scr_create_msg_box_str(lv_obj_t *trig_obj, const char *str)
// {
//     if (lv_obj_has_flag(trig_obj, LV_OBJ_FLAG_USER_4))
//         return;
//     lv_obj_add_flag(trig_obj, LV_OBJ_FLAG_USER_4);

//     lv_obj_t *obj = lv_msgbox_create(NULL, "Tip", str, NULL, 0);
//     lv_obj_set_style_text_font(obj, &msgbox_text_font_default, 0);
//     lv_obj_set_style_text_color(obj, lv_color_hex(0xFFFBB3), 0);
//     lv_obj_center(obj);
//     lv_obj_set_style_bg_opa(obj, 200, 0);
//     lv_obj_set_style_bg_color(obj, lv_color_hex(0x4F4C4D), 0);
//     lv_obj_set_width(obj, scr_width_defaule - 50);

//     lv_timer_user_t *user_t = lv_mem_alloc(sizeof(lv_timer_user_t));
//     user_t->btn = trig_obj;
//     user_t->msgbox = obj;
//     lv_timer_t *timer = lv_timer_create(msg_box_timer, 2000, user_t);
//     lv_timer_set_repeat_count(timer, 1);
// }

// void scr_create_msg_box(lv_event_t *e)
// {
//     scr_create_msg_box_str(e->target, (const char *)e->user_data);
// }
