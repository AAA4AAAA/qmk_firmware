#include QMK_KEYBOARD_H

#define KC_WM(n) LGUI(KC_##n)

#define KC_TN LGUI(KC_UP)
#define KC_TS LGUI(KC_DOWN)
#define KC_TW LGUI(KC_LEFT)
#define KC_TE LGUI(KC_RIGHT)

#define KC_T(k) LGUI(LSFT(k))

#define KC_NW LGUI(LSFT(KC_LEFT))
#define KC_NE LGUI(LSFT(KC_RIGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_3x10(
  //,-----------------------------------------------------------------------------------------.
     KC_WM(1),KC_WM(2),KC_WM(3),KC_WM(4),KC_WM(5),KC_WM(6),KC_WM(7),KC_WM(8),KC_WM(9),KC_WM(0),\
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        TO(1), _______, _______, _______, _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  //`----------------------------------------------------------------------------------------'-
  ),

  [1] = LAYOUT_ortho_3x10(
  //,-----------------------------------------------------------------------------------------.
        RESET, _______, _______, _______, _______, _______, _______, _______,   KC_TN, _______, \
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,   KC_TW, _______,   KC_TE, \
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______, _______,   KC_TS, _______ \
  //`-----------------------------------------------------------------------------------------'
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
