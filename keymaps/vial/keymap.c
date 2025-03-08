/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,
		KC_GRV,  KC_1,    KC_2,    KC_3,
		KC_LSFT, KC_A,    KC_S,    KC_D,
		KC_LCTL, KC_Z,    KC_X,    KC_C
	),

	[1] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[2] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[3] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

};

/* name the layers */
enum layer_names {
    _BASE,
    _LAYER1,
    _LAYER2,
	_LAYER3,
};

// caps lock = white
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 0, 0, 255} // starting at 1st LED, affecting 2 LEDs in the chain, makes it a bright white
);

// layer 1 = deep ocean blue (bloo)
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 170, 255, 255}
);

// layer 2 = purply (idk its approximate)
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 200, 255, 255}
);

// layer 3 = b l o o d r e d (not really)
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 250, 255, 255}
);

// Define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

/* make the leds do something */
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(1, layer_state_cmp(state, _LAYER1));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LAYER2));
    rgblight_set_layer_state(3, layer_state_cmp(state, _LAYER3));
    return state;
}