// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "11_roller.h"
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
    if (code == LV_EVENT_VALUE_CHANGED)
    {
        uint16_t selectedID;
        char tmp_buf[32];
        selectedID = lv_roller_get_selected(obj);
        lv_roller_get_selected_str(obj, tmp_buf, sizeof(tmp_buf));
        printf("Current Selected :%d   item:%s\r\n", selectedID, tmp_buf);//事件与dropdown类似 但是函数名称不一样 
       // lv_obj_t* dd_list = lv_dropdown_get_list(obj);
        
    }
}
///////////////////// SCREENS ////////////////////
static void ui_Screen1_screen_init(void)
{
    // ui_Screen1
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t* roller = lv_roller_create(ui_Screen1);
    lv_roller_set_options(roller, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9",LV_ROLLER_MODE_INFINITE);//设置条目 最后一个条目结尾不应加\n否则会出现空条目 NORMAL 普通模式INFINITE无限循环(占用更多内存）
    lv_roller_set_visible_row_count(roller, 4);//设置选择范围
    lv_obj_center(roller);
    lv_roller_set_selected(roller, 3, LV_ANIM_ON);//设置默认选中项
    lv_obj_add_event_cb(roller, enent_cb, LV_EVENT_ALL, NULL);
    //lv_obj_set_height(roller, 400);//设置整体高度
    //lv_obj_set_style_bg_color(roller, lv_color_hex(0xdd0031), 0);
    lv_obj_set_style_text_line_space(roller, 50, 0);
}


void ui_init_11(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
    printf("ui init \r\n");
}

