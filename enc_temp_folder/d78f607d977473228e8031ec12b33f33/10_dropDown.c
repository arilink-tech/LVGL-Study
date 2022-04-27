// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "10_dropDown.h"
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
        selectedID = lv_dropdown_get_selected(obj);
        lv_dropdown_get_selected_str(obj, tmp_buf, sizeof(tmp_buf));
        printf("Current Selected :%d  Item Info:%s \r\n", selectedID,tmp_buf);
        lv_obj_t* dd_list = lv_dropdown_get_list(obj);
        
    }
}
///////////////////// SCREENS ////////////////////
static void ui_Screen1_screen_init(void)
{
    // ui_Screen1
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t* dd = lv_dropdown_create(ui_Screen1);
    lv_dropdown_set_options(dd, "你\n"
                                "好\n"
                                "中\n"
                                "国");
    lv_obj_align(dd, LV_ALIGN_CENTER, 0, 20);
    lv_obj_add_event_cb(dd, enent_cb, LV_EVENT_ALL, NULL);
    lv_dropdown_set_dir(dd, LV_DIR_TOP);//设置列表的显示位置 上下左右
    lv_dropdown_set_symbol(dd, LV_SYMBOL_DOWN);//设置按钮图标的显示方向
    LV_FONT_DECLARE(lv_font_opposans_medium_20);//改变字体
    lv_obj_set_style_text_font(dd, &lv_font_opposans_medium_20, 0);
}


void ui_init_10(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
    printf("ui init \r\n");
}

