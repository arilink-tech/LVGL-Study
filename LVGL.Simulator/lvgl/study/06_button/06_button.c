// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "06_button.h"
#include "stdio.h"
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

    lv_obj_t* btn = lv_btn_create(ui_Screen1);
    //修改button样式
    //lv_obj_set_style_bg_color(btn, lv_color_hex(0xdd0031), LV_PART_MAIN|LV_STATE_PRESSED);//按下时修改背景颜色（选择器+状态组合使用）
    lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);//状态改变 类似SWITCH

}


void ui_init_06(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
    printf("ui init \r\n");

}
