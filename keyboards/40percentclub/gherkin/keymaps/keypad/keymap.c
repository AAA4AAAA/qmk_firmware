#include QMK_KEYBOARD_H

#define _DM 0
#define _FN1 1
#define _FN2 2

enum custom_keycodes {
  DM = SAFE_RANGE,
  FN1,
  FN2,
  RGBRST
};

#define KC______  KC_TRNS
#define KC_RST    RESET
#define KC_FN1    _FN1
#define KC_FN2    _FN2

#define KC_VIEW1  LGUI(KC_1)
#define KC_VIEW2  LGUI(KC_2)
#define KC_VIEW3  LGUI(KC_3)
#define KC_VIEW4  LGUI(KC_4)
#define KC_VIEW5  LGUI(KC_5)
#define KC_VIEW6  LGUI(KC_6)
#define KC_VIEW7  LGUI(KC_7)
#define KC_VIEW8  LGUI(KC_8)
#define KC_VIEW9  LGUI(KC_9)
#define KC_VIEW0  LGUI(KC_0)

#define KC_TAG1   LGUI(LSFT(KC_1))
#define KC_TAG2   LGUI(LSFT(KC_2))
#define KC_TAG3   LGUI(LSFT(KC_3))
#define KC_TAG4   LGUI(LSFT(KC_4))
#define KC_TAG5   LGUI(LSFT(KC_5))
#define KC_TAG6   LGUI(LSFT(KC_6))
#define KC_TAG7   LGUI(LSFT(KC_7))
#define KC_TAG8   LGUI(LSFT(KC_8))
#define KC_TAG9   LGUI(LSFT(KC_9))
#define KC_TAG0   LGUI(LSFT(KC_0))

#define KC_LTILE  LGUI(KC_T)
#define KC_LMONO  LGUI(KC_M)
#define KC_LFLT   LGUI(KC_F)

#define KC_DFSTK  LGUI(KC_J)
#define KC_UFSTK  LGUI(KC_K)

#define KC_TFLT   LGUI(LSFT(KC_SPC))

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
  [_DM] = LAYOUT_kc(
  //,---------------------------------------------------------------------.
      VIEW1, VIEW2, VIEW3, VIEW4, VIEW5, VIEW6, VIEW7, VIEW8, VIEW9, VIEW0,\
  //|------+------+------+------+------+------+------+------+------+------|
       TAG1,  TAG2,  TAG3,  TAG4,  TAG5,  TAG6,  TAG7,  TAG8,  TAG9,  TAG0,\
  //|------+------+------+------+------+------+------+------+------+------|
        FN1,   FN2, _____, _____, LTILE, LMONO,  LFLT,  TFLT, DFSTK, UFSTK \
  //`------+------+------+------+------+------+------+------+------+------'
  ),

  [_FN1] = LAYOUT_kc(
  //,---------------------------------------------------------------------.
      _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------+------+------+------+------|
        FN1,   FN2, _____, _____, _____, _____, _____, _____, _____, _____ \
  //`------+------+------+------+------+------+------+------+------+------'
  ),

  [_FN2] = LAYOUT_kc(
  //,---------------------------------------------------------------------.
        RST, _____, _____, _____, _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------+------+------+------+------|
      _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,\
  //|------+------+------+------+------+------+------+------+------+------|
        FN1,   FN2, _____, _____, _____, _____, _____, _____, _____, _____ \
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
