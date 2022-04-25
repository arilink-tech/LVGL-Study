// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "03_style.h"
#include "stdio.h"
///////////////////// VARIABLES ////////////////////
lv_obj_t* ui_Screen1;

lv_obj_t* obj_style;
lv_obj_t* obj_style2;
lv_obj_t* obj_label;
///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
#error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
#error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
static void ui_Screen1_screen_init(void)
{
    static lv_style_t style_obj;
    // ui_Screen1

    ui_Screen1 = lv_obj_create(NULL);
    /**
     * @brief 
     * @param  
    */
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Label1
    obj_style = lv_obj_create(ui_Screen1);
    obj_style2 = lv_obj_create(ui_Screen1);
    obj_label = lv_label_create(obj_style);
    lv_obj_align(obj_style, LV_ALIGN_CENTER, 0, 0);//style对象放置在左上角
     // 普通样式 可以被多个对象使用
    lv_style_init(&style_obj);
    lv_style_set_bg_color(&style_obj, lv_color_hex(0x000000));
    lv_style_set_text_color(&style_obj, lv_color_hex(0xc4331c));
    lv_obj_add_style(obj_style, &style_obj, LV_STATE_PRESSED);
    // 本地样式 与对象绑定 且能覆盖普通样式
    lv_obj_set_style_bg_color(obj_style2, lv_color_hex(0xc4331c), LV_STATE_PRESSED);
    // 普通样式尽管定义在后 仍被本地样式覆盖
    lv_obj_add_style(obj_style2, &style_obj, LV_STATE_PRESSED);
    
}

void ui_init_03(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
        false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
    printf("ui init");

}
