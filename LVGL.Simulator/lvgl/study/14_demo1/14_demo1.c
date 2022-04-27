// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "14_demo1.h"
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

    lv_obj_t* lum = lv_slider_create(ui_Screen1);
    lv_obj_t* vol = lv_slider_create(ui_Screen1);
    lv_obj_t* vol_icon = lv_label_create(lum);
    //竖直摆放
    lv_obj_align(lum, LV_ALIGN_CENTER, -40, 0);//竖直摆放
    lv_obj_align(vol, LV_ALIGN_CENTER, 40, 0);
    //调整大小
    lv_obj_set_size(lum, 60, 120);
    lv_obj_set_size(vol, 60, 120);
    //设置四个角圆角（PARTMAIN）
    static lv_style_t style_part_main;
    static lv_style_t style_part_indc;
    static lv_style_t style_part_knob;
    lv_style_init(&style_part_main);
    lv_style_init(&style_part_indc);
    lv_style_init(&style_part_knob);
    lv_style_set_radius(&style_part_main, 12);
    //设置背景颜色、透明度
    lv_style_set_bg_color(&style_part_main, lv_color_hex(0x1f1f1f));
    lv_style_set_pad_top(&style_part_main, -1);//消除指示器边角露出slider背景的问题
    lv_style_set_pad_bottom(&style_part_main, -1);
    //设置指示器颜色矩形 #e0eaf9
    lv_style_set_radius(&style_part_indc, 0);
    lv_style_set_bg_color(&style_part_indc, lv_color_hex(0xf5f5f5));
    //去除旋钮
    lv_style_set_opa(&style_part_knob, LV_OPA_0);//使旋钮透明
    //内部图标展示设置（图标 位置 大小 颜色 ）
    lv_label_set_text(vol_icon, LV_SYMBOL_VOLUME_MAX);
    lv_obj_align(vol_icon, LV_ALIGN_BOTTOM_MID, 0, -10);
    lv_obj_set_style_text_font(vol_icon, &lv_font_montserrat_20, 0);//改变图标大小
    lv_obj_set_style_text_color(vol_icon, lv_color_hex(0x1e1e1e),0);//改变图标颜色


    lv_obj_add_style(lum, &style_part_main,LV_PART_MAIN);
    lv_obj_add_style(lum, &style_part_indc, LV_PART_INDICATOR);
    lv_obj_add_style(lum, &style_part_knob, LV_PART_KNOB);
}


void ui_init_14(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
    printf("ui init \r\n");
}

