#include QMK_KEYBOARD_H
#include "muse.h"

enum custom_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// mod-tap keys
#define MT_ENT  RSFT_T(KC_ENT)

// macros keys
#define SC_FLW              LALT(KC_SPC)
#define SC_CUT              LCTL(KC_X)
#define SC_COPY             LCTL(KC_C)
#define SC_PSTE             LCTL(KC_V)
#define SC_SAVE             LCTL(KC_S)
#define SC_RFH              LCTL(KC_R)
#define SC_AC               LCTL(KC_0)
#define SC_UNDO             LCTL(KC_Z)
#define SC_OUT              LCTL(KC_MINS)
#define SC_IN               LCTL(KC_PPLS)
#define SC_V                LGUI(KC_V)
#define WIN_TAB             LGUI(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_F1,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_ENT,
    KC_F2,   KC_LCTL, KC_LALT, KC_F3,   LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, SC_FLW
),

[_LOWER] = LAYOUT_preonic_grid(
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NUBS, KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, _______,
    _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_PIPE, KC_LPRN, KC_RPRN, KC_BSLS, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, SC_AC,   SC_OUT,  SC_IN,   _______, _______,
    _______, _______, _______, _______, _______, _______, KC_UP,   KC_LEFT, KC_DOWN, KC_RGHT, _______, SC_RFH,
    _______, _______, _______, _______, _______, _______, SC_UNDO, SC_CUT,  SC_COPY, SC_PSTE, _______, SC_SAVE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
  _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
          case QWERTY:
            if (record->event.pressed) {
              set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
          case LOWER:
            if (record->event.pressed) {
              layer_on(_LOWER);
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
              layer_off(_LOWER);
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
          case RAISE:
            if (record->event.pressed) {
              layer_on(_RAISE);
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
              layer_off(_RAISE);
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        }
      return true;
  };
