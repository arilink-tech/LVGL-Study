// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "04_event.h"
#include "stdio.h"
///////////////////// VARIABLES ////////////////////
lv_obj_t* ui_Screen1;
lv_obj_t* obj_event;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
#error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
#error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
static void enent_cb()
{
    printf("Clicked \r\n");
}

static void enent_cb_filter(lv_event_t* event)
{
    lv_obj_t * obj = lv_event_get_target(event);//获取触发事件的对象
    lv_event_code_t code = lv_event_get_code(event);
    if (code == LV_EVENT_CLICKED)
    {
        lv_obj_set_style_bg_color(obj, lv_color_hex(0xc4331c), 0);
        //uint8_t data = event->user_data;
        printf("LV_EVENT_CLICKED \r\n");
    }
    else
    {
        //printf("Other Event \r\n");
    }
}
static void enent_cb_with_data(lv_event_t *event)
{
    lv_obj_t* obj = lv_event_get_target(event);//获取触发事件的对象
    lv_obj_t *label = lv_event_get_user_data(event);//获取触发事件的对象
    lv_event_code_t code = lv_event_get_code(event);
    if (code == LV_EVENT_PRESSED)
    {
        lv_label_set_text(label, "PRESSED!!!\r\b");
        lv_obj_set_style_bg_color(obj, lv_color_hex(0xc4331c), 0);
    }
    else if(code == LV_EVENT_RELEASED)
    {
        lv_obj_set_style_bg_color(obj, lv_color_hex(0x429c43), 0);
        lv_label_set_text(label, "RELEASED!!!\r\b");
    }
    else
    {

    }
}

static void enent_cb_with_bubble(lv_event_t* event)
{
    lv_obj_t* obj = lv_event_get_target(event);//获取触发事件的对象
    lv_obj_t* obj_parent = lv_event_get_current_target(event);//获取触发事件的父对象
    lv_obj_t* label = lv_event_get_user_data(event);//获取触发事件的对象
    lv_event_code_t code = lv_event_get_code(event);
    if (code == LV_EVENT_PRESSED)
    {
        lv_label_set_text(label, "PRESSED!!!\r\b");
        lv_obj_set_style_bg_color(obj_parent, lv_color_hex(0x7c2fa0), 0);
        lv_obj_set_style_bg_color(obj, lv_color_hex(0xc4331c), 0);
    }
    else if (code == LV_EVENT_RELEASED)
    {
        lv_obj_set_style_bg_color(obj_parent, lv_color_hex(0xffd662), 0);
        lv_obj_set_style_bg_color(obj, lv_color_hex(0x16d46b), 0);
        lv_label_set_text(label, "RELEASED!!!\r\b");
    }
    else
    {

    }
}

///////////////////// SCREENS ////////////////////
static void ui_Screen1_screen_init(void)
{
    // ui_Screen1
    ui_Screen1 = lv_obj_create(NULL);
    /**
     * @brief
     * @param
    */
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Label1
    obj_event = lv_obj_create(ui_Screen1);
    lv_obj_t* label = lv_label_create(ui_Screen1);
    lv_label_set_text(label, "Hello");
    lv_obj_center(label);
    lv_obj_add_event_cb(obj_event, enent_cb, LV_EVENT_CLICKED,NULL);//给对象增加Click事件回调
    //lv_obj_add_event_cb(obj_event, enent_cb_filter, LV_EVENT_ALL, NULL);//给对象增加所有事件回调
    lv_obj_add_event_cb(obj_event, enent_cb_with_data, LV_EVENT_ALL, label);
}
//EVENT BUBBLE
static void ui_Screen2_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_t* obj1 = lv_obj_create(ui_Screen1);
    lv_obj_t* obj2 = lv_obj_create(obj1);
    lv_obj_t* label = lv_label_create(ui_Screen1);
    lv_label_set_text(label, "Hello");
    lv_obj_center(label);
    lv_obj_add_flag(obj2, LV_OBJ_FLAG_EVENT_BUBBLE);//增加EVENT BUBBLE属性后 子对象会把事件传递给父对象
    lv_obj_add_event_cb(obj1, enent_cb_with_bubble, LV_EVENT_ALL, label);//此时尽管没有给子对象绑定事件回调 也会触发事件
}


void ui_init_04(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
        false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen2_screen_init();
    lv_disp_load_scr(ui_Screen1);
    printf("ui init");

}
