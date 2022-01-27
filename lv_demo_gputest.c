/**
 * @file lv_demo_gputest.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "../../lv_demo.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void on_press_event_cb(lv_event_t* e);
/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_demo_gputest(void)
{
  lv_obj_t* root = lv_obj_create(lv_scr_act());
  lv_obj_set_size(root, 400, 400);
  lv_obj_set_style_bg_color(root, lv_color_black(), 0);
  lv_obj_center(root);

  for (int i = 0; i < 9; i++) {
    lv_obj_t* img = lv_img_create(root);
    lv_img_set_src(img, "/resource/app/control_center/icon/flashlight.bin");

    lv_obj_set_style_img_recolor(img, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_style_img_recolor_opa(img, LV_OPA_50, 0);
  }

  lv_obj_set_flex_flow(root, LV_FLEX_FLOW_COLUMN_WRAP);
  lv_obj_set_flex_align(root, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

  lv_obj_t* obj = lv_obj_create(lv_layer_sys());
  lv_obj_set_size(obj, 480, 480);
  lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_set_style_bg_color(obj, lv_palette_main(LV_PALETTE_GREY), 0);
  lv_obj_add_event_cb(obj, on_press_event_cb, LV_EVENT_PRESSING, NULL);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void on_press_event_cb(lv_event_t* e)
{
  lv_point_t vect;
  lv_indev_get_vect(lv_indev_get_act(), &vect);

  lv_obj_t* obj = lv_event_get_current_target(e);
  lv_coord_t y = lv_obj_get_y(obj);
  lv_obj_set_y(obj, y + vect.y);
}