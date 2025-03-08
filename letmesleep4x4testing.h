#include <stdint.h>
#include <stdbool.h>

enum custom_keycodes {
    PRINT_CONFIG = QK_KB_0,
};

typedef struct PACKED { 

    // All the settings
    uint8_t mode;   // actuation mode // 0 = normal // 2 = rapid trigger // 5,6,7,8 = DKS
    uint8_t lower;  // actuation point
    uint8_t upper;  // deadzone
    uint8_t down;   // rapid trigger sensitivity
    uint8_t up;     // rapid trigger sensitivity

} analog_config_t; // 5 bytes
extern analog_config_t analog_config[MATRIX_ROWS][MATRIX_COLS];

typedef struct PACKED {

    // Get displacement from gauss
    double lut_a;        // 8 bytes
    double lut_b;        // 8 bytes
    double lut_c;        // 8 bytes
    double lut_d;        // 8 bytes
    // Define the maximum values
    uint16_t max_input;  // 1 byte
    uint16_t max_output; // 1 byte

} lookup_table_t; // 36 bytes

typedef struct PACKED {

    lookup_table_t multiplier;   // 36 bytes
    lookup_table_t displacement; // 36 bytes
    lookup_table_t joystick;     // 36 bytes

} calibration_parameters_t; // 108 bytes
extern calibration_parameters_t calibration_parameters;