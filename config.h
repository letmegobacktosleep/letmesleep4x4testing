#pragma once

/* Enable support for printing floats (debugging purposes) */
#undef PRINTF_SUPPORT_DECIMAL_SPECIFIERS
#define PRINTF_SUPPORT_DECIMAL_SPECIFIERS 1

/* Add RGB Lighting for onboard WS2812 led on RP2040 zero */
#define RGBLIGHT_MAX_LAYERS 4

/* Set size of EECONFIG for analog_config (per key) */
#define EECONFIG_USER_DATA_SIZE (5 * MATRIX_ROWS * MATRIX_COLS)
/* Set size of EECONFIG for calibration (global) */
#define EECONFIG_KB_DATA_SIZE (36 * 3)