// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "08_switch.h"
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
    lv_obj_t* sw = lv_event_get_target(event);//获取触发事件的对象
    /*
    * SWITCH Event 方法一
        lv_obj_t* obj = lv_event_get_target(event);//获取触发事件的对象
        lv_event_code_t code = lv_event_get_code(event);

        if (code == LV_EVENT_VALUE_CHANGED)
        {
            if (lv_obj_has_state(obj, LV_STATE_CHECKED))
                printf("ON\n");
            else
                printf("OFF\n");
        }
    */

    if(lv_obj_get_state(sw)&LV_STATE_CHECKED) //只能用&不能用==
        printf("ON\n");
    else
        printf("OFF\n");
}
///////////////////// SCREENS ////////////////////
static void ui_Screen1_screen_init(void)
{
    // ui_Screen1
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t* sw = lv_switch_create(ui_Screen1);
    lv_obj_center(sw);//让sw对象居中

    lv_obj_set_style_bg_color(sw, lv_color_hex(0x861b2d), LV_PART_MAIN);//默认整体背景色 
    lv_obj_set_style_bg_opa(sw, 255, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(sw, lv_color_hex(0xe07e4b), LV_PART_INDICATOR);//关闭时指示器的颜色
    lv_obj_set_style_bg_color(sw, lv_color_hex(0xffd96a), LV_PART_INDICATOR|LV_STATE_CHECKED);//打开时指示器的颜色
    //lv_obj_set_style_pad_right(sw, 10, LV_PART_MAIN);//向右偏移
    //lv_obj_add_state(sw, LV_STATE_CHECKED);//设置默认状态为开
    //lv_obj_add_state(sw, LV_STATE_CHECKED|LV_STATE_DISABLED);//设置默认状态为开且不可修改
    lv_obj_add_event_cb(sw, enent_cb, 0, NULL, LV_EVENT_VALUE_CHANGED, NULL);
}


void ui_init_08(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
    printf("ui init \r\n");

}
