// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "02_layout.h"
#include "stdio.h"
///////////////////// VARIABLES ////////////////////
lv_obj_t* ui_Screen1;

lv_obj_t* obj_pos;
lv_obj_t* obj_size;
lv_obj_t* obj_center;
lv_obj_t* obj_top;
lv_obj_t* obj_bottom;
lv_obj_t* obj_left;
lv_obj_t* obj_right;
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

    // ui_Screen1

    ui_Screen1 = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Label1
    obj_pos = lv_obj_create(ui_Screen1);

    obj_size = lv_obj_create(ui_Screen1);

    obj_center = lv_obj_create(ui_Screen1);
    obj_top = lv_obj_create(ui_Screen1);
    obj_bottom = lv_obj_create(ui_Screen1);
    obj_left = lv_obj_create(ui_Screen1);
    obj_right = lv_obj_create(ui_Screen1);


    lv_obj_set_pos(obj_pos, 70, 70);//pos对象放置在(70，70)的位置

    lv_obj_align(obj_size, LV_ALIGN_TOP_LEFT, 0, 0);//size对象放置在左上角
    lv_obj_set_size(obj_size, 60, 60);//size对象设置宽高为60 60
    lv_obj_set_style_border_width(obj_size, 10, 0);//设置border
    lv_obj_set_style_outline_width(obj_size, 10, 0);//设置outline

    lv_obj_align(obj_center, LV_ALIGN_CENTER, 0, 0);//center对象放置在中心屏幕  其他4个对象以center为中心放置
    lv_obj_align_to(obj_top, obj_center, LV_ALIGN_OUT_TOP_MID, 0, 0);
    lv_obj_align_to(obj_bottom, obj_center, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_align_to(obj_left, obj_center, LV_ALIGN_OUT_LEFT_MID, 0, 0);
    lv_obj_align_to(obj_right, obj_center, LV_ALIGN_OUT_RIGHT_MID, 0, 0);


}

void ui_init_02(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
        false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
    printf("ui init");

}
