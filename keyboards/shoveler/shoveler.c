#include "vaporwave1.qgf.h"
#include "qp.h"
#include "shoveler.h"
kb_runtime_config kb_state;
static painter_device_t display;
static painter_image_handle_t image;
void keyboard_post_init_kb(void) {
    display = qp_st7789_make_spi_device(240, 280, DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN, 8, 3);

    qp_init(display, QP_ROTATION_180);
    qp_power(display, true);

    image = qp_load_image_mem(gfx_vaporwave1);
    if (image != NULL) {
        qp_drawimage(display, (239 - image->width), (280 - image->height), image);
    }
}