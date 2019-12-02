#include QMK_KEYBOARD_H

#define KC______ KC_TRNS
#define KC_FN1_Q LT(1, KC_Q)
#define KC_RST   RESET

#define LAYOUT_kc( \
  K00, K01, K02, K03, K04, K05, K10, K11, K12, K13, \
  K14, K15, K20, K21, K22, K23, K24, K25, K30, K31, \
  K32, K33, K34, K35, K40, K41, K42, K43, K44, K45  \
  ) \
  LAYOUT_ortho_3x10( \
    KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K10, KC_##K11, KC_##K12, KC_##K13, \
    KC_##K14, KC_##K15, KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K30, KC_##K31, \
    KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45  \
  )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_kc(
  //,---------------------------------------------------------------------.
      FN1_Q,     W,     E,     R,     T,     Y,     U,     I,     O,     P,\
  //|------+------+------+------+------+------+------+------+------+------|
          A,     S,     D,     F,     G,     H,     J,     K,     L,  BSPC,\
  //|------+------+------+------+------+------+------+------+------+------|
          Z,     X,     C,     V,   SPC,   ENT,     B,     N,     M,  RSFT \
  //`------+------+------+------+------+------+------+------+------+------'
  ),

  [1] = LAYOUT_kc(
  //,---------------------------------------------------------------------.
      _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____,   RST, _____, _____, _____ \
  //`------+------+------+------+------+------+------+------+------+------'
  ),

};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}
