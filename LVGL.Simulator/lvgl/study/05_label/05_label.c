// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "05_label.h"
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
    case LV_EVENT_PRESSED:
        printf("LV_EVENT_PRESSED \r\n");
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

    // ui_Label1
    lv_obj_t* label = lv_label_create(ui_Screen1);
    lv_obj_t* label2 = lv_label_create(ui_Screen1);

    //lv_label_set_text(label, "LVGL Label Study");
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);//style对象放置在顶部中间
    //lv_label_set_text_fmt(label, "Name:%s Age:%d %s", "Value", 25);//用类似Printf的方式显示
    //lv_label_set_text(label2, "LVGL\nLabel\nStudy");//换行操作
    lv_obj_set_width(label2, 60);
    lv_obj_set_height(label2, 30);
    lv_label_set_text(label2, "LVGL Label Study -------------------------");
    //lv_obj_set_style_text_font(label, &lv_font_montserrat_28,0);// 设置英文文字的大小  lv_font_montserrat_18在src->font->里定义
    //lv_label_set_long_mode(label2, LV_LABEL_LONG_WRAP);//当前面已经设定了宽高后 再设置模式为自定应就不起作用
    //lv_label_set_long_mode(label2, LV_LABEL_LONG_DOT); //当文本太长是用...表示
    //lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL); //当文本太长时水平滚动（默认会自动循环且是来回滚动）
    //lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR); //当文本太长时水平滚动（默认会自动循环只有一个方向滚动）
    //lv_label_set_long_mode(label2, LV_LABEL_LONG_CLIP); //当文本太长时裁剪
    //lv_obj_set_style_text_color(label, lv_color_hex(0x2bdc70), 0);//给文本设置颜色
    //lv_obj_set_style_bg_color(label, lv_color_hex(0x861b2d), 0);//设置背景颜色
    //lv_obj_set_style_bg_opa(label, 255, 0); //透明度范围uint8_t  0是全透明 255是完全不透明

    //lv_label_set_recolor(label, true);
    //lv_label_set_text(label, "#0000ff Re-color# 123  #ff00ff words# 456 #ff0000 Test# 789");//改变Label不同部分的颜色 不在# #之间的显示绿色
    //lv_label_set_text(label, "#0000ff %s# 123 #ff00ff %s# #ff0000 %s#", "Re-color","words","Test");//改变Label不同部分的颜色 拼接似乎不起作用
    //lv_label_set_text_sel_start(label, 0);//默认情况下 文本只有在文本框里才可以被选中 但可以手动指定
    //lv_label_set_text_sel_end(label, 6);
    //lv_label_set_text(label, LV_SYMBOL_OK);//显示图标
    lv_obj_add_flag(label, LV_OBJ_FLAG_CLICKABLE);//开启CLICKABLE Event cb才可以捕获CLICKABLE事件 否则只能捕获系统刷新的post draw 和 post draw end事件
    lv_obj_add_event_cb(label, enent_cb, LV_EVENT_ALL, NULL);
    //显示中文需要先切换字体  LVGL默认只有1000余个汉字
    lv_obj_set_style_text_font(label, &lv_font_simsun_16_cjk, 0);
    lv_label_set_text(label, "你好中国");//使用lv_font_simsun_16_cjk 来显示中文


}


void ui_init_05(void)
{
    lv_disp_t* dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
    printf("ui init \r\n");

}
