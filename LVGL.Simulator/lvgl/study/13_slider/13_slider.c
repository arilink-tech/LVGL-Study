// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "13_slider.h"
#include "stdio.h"
#include "lv_drivers/win32drv/win32drv.h"
///////////////////// VARIABLES ////////////////////
lv_obj_t* ui_Screen1;
lv_obj_t* label;
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
    lv_obj_t* bar = lv_event_get_user_data(event);
    lv_event_code_t code = lv_event_get_code(event);
    
    if (code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(obj);
        printf("Slider Value Changed :%d \r\n", value);
        lv_bar_set_value(bar, value, LV_ANIM_ON);
        lv_label_set_text_fmt(label, "%d%%", lv_bar_get_value(bar));
    }
}
///////////////////// SCREENS ////////////////////
static void ui_Screen1_screen_init(void)
{
    // ui_Screen1
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t* bar = lv_bar_create(ui_Screen1);
    lv_obj_t* slider = lv_slider_create(ui_Screen1);
    label = lv_label_create(ui_Screen1);

    lv_obj_center(bar);
    lv_obj_align(slider, LV_ALIGN_CENTER, 0, 40);
    lv_obj_set_size(bar, 200, 20);//Width < Heigh时为垂直进度条
    lv_bar_set_range(bar, 0, 100);//设置进度条范围（应先给出取值范围 再给出设置值）
    lv_bar_set_value(bar, 10, LV_ANIM_ON);//不设置value时只显示默认背景 value>最大值时只显示最大值
    

    lv_slider_set_range(slider, 0, 100);
    lv_slider_set_value(slider, 10, LV_ANIM_ON);
    lv_obj_set_style_anim_time(slider, 500, LV_PART_MAIN);

    //lv_label_set_text_fmt(label, "%d%%", lv_bar_get_value(bar));
    lv_obj_align_to(label, slider, LV_ALIGN_BOTTOM_MID,0,0);
    lv_obj_add_event_cb(slider, enent_cb, LV_EVENT_VALUE_CHANGED, bar);//设置slider滑动事件回调 并传入bar 以实现滑动条控制进度条

}


void ui_init_13(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
    printf("ui init \r\n");
}

