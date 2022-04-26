// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "07_group.h"
#include "stdio.h"
#include "lv_drivers/win32drv/win32drv.h"
///////////////////// VARIABLES ////////////////////
lv_obj_t* ui_Screen1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
#error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
#error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
static void enent_cb(lv_event_t* event)
{
    lv_obj_t* obj = lv_event_get_target(event);//获取触发事件的对象
    lv_event_code_t code = lv_event_get_code(event);
    switch (code)
    {
    case LV_EVENT_VALUE_CHANGED:
        printf("LV_EVENT_VALUE_CHANGED \r\n");
        break;
    case LV_EVENT_PREPROCESS:
        printf("LV_EVENT_PREPROCESS \r\n");
    default:
        //printf("code :%d \r\n",code);
        break;
    }
}
///////////////////// SCREENS ////////////////////
static void ui_Screen1_screen_init(void)
{
    // ui_Screen1
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    lv_group_t* group = lv_group_create();
    lv_obj_t* btn1 = lv_btn_create(ui_Screen1);
    lv_obj_t* btn2 = lv_btn_create(ui_Screen1);
    lv_obj_t* btn3 = lv_btn_create(ui_Screen1);
    lv_obj_t* btn4 = lv_btn_create(ui_Screen1);
    lv_obj_t* slider = lv_slider_create(ui_Screen1);
    lv_obj_set_size(btn1, 100, 50);
    lv_obj_set_size(btn2, 100, 50);
    lv_obj_set_size(btn3, 100, 50);
    lv_obj_set_size(btn4, 100, 50);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -100);
    lv_obj_align_to(btn2, btn1,  LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_obj_align_to(btn3, btn2, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_obj_align_to(btn4, btn3, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_obj_align_to(slider, btn4, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_group_add_obj(group, btn1);
    lv_group_add_obj(group, btn2);
    lv_group_add_obj(group, btn3);
    lv_group_add_obj(group, btn4);
    lv_group_add_obj(group, slider);
    // lv_indev_set_group(lv_win32_keypad_device_object, group);//键盘模式
    lv_indev_set_group(lv_win32_encoder_device_object, group);
}


void ui_init_07(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
    printf("ui init \r\n");

}
