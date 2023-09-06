#include "vaporwave1.qgf.h"
#include "qp.h"
#include "shoveler.h"
kb_runtime_config kb_state;
static painter_device_t display;
static painter_image_handle_t image;
void keyboard_post_init_kb(void) {
    setPinOutput(GP22); 
    writePinHigh(GP22);
    display = qp_st7789_make_spi_device(240, 280, DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN, 128, 0);

    qp_init(display, QP_ROTATION_180);

    image = qp_load_image_mem(gfx_vaporwave1);
    if (image != NULL) {
        qp_drawimage(display, (239 - image->width), (280 - image->height), image);
    }
}

void housekeeping_task_user(void) {
    setPinOutput(GP22); 
    writePinHigh(GP22);

    display = qp_st7789_make_spi_device(240, 280, DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN, 128, 0);

    qp_init(display, QP_ROTATION_180);

    image = qp_load_image_mem(gfx_vaporwave1);
    if (image != NULL) {
        qp_drawimage(display, (239 - image->width), (280 - image->height), image);
    }
    // static uint32_t last_draw = 0;
    // if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
    //     last_draw = timer_read32();
    //     // Draw 8px-wide rainbow filled rectangles down the left side of the display
    //     for (int i = 0; i < 239; i+=8) {
    //         qp_rect(display, 0, i, 7, i+7, i, 255, 255, true);
    //     }
    //     qp_flush(display);
    // }
}