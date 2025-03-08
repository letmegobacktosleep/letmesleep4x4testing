#pragma once

/* Enable support for printing floats (debugging purposes) */
#undef PRINTF_SUPPORT_DECIMAL_SPECIFIERS
#define PRINTF_SUPPORT_DECIMAL_SPECIFIERS 1

/* Add RGB Lighting for onboard WS2812 led on RP2040 zero */
#define RGBLIGHT_MAX_LAYERS 4