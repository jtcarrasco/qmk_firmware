#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

// mod-tap keys
#define MT_ENT  RSFT_T(KC_ENT)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

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

[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_ENT,
    KC_F1,   KC_LCTL, KC_LALT, KC_F2, LOWER,      KC_SPC,        RAISE,     KC_RGUI, KC_RALT, KC_RCTL, SC_FLW
),

[_LOWER] = LAYOUT_planck_mit(
    KC_ESC,  _______, KC_1,    KC_2, KC_3,    _______, KC_NUBS, KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, _______,
    KC_CAPS, _______, KC_4,    KC_5, KC_6,    _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, KC_7,    KC_8, KC_9,    _______, KC_PIPE, KC_LPRN, KC_RPRN, KC_BSLS, _______, _______,
    _______, _______, _______, KC_0, _______,    _______,       _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_mit(
    _______, _______, KC_F1,   KC_F2, KC_F3,    _______, _______, SC_AC,   SC_OUT,  SC_IN,   _______, KC_DEL,
    _______, _______, KC_F4,   KC_F5, KC_F6,    _______, KC_UP,   KC_LEFT, KC_DOWN, KC_RGHT, _______, SC_RFH,
    _______, _______, KC_F7,   KC_F8, KC_F9,    _______, SC_UNDO, SC_CUT,  SC_COPY, SC_PSTE, _______, SC_SAVE,
    _______, _______, _______, KC_F10, _______,     _______,      _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_mit(
    _______, QK_BOOT, DB_TOGG, RM_TOGG, RM_NEXT, RM_HUEU, RM_HUED, RM_SATU, RM_SATD,  RM_VALU, RM_VALD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______,  _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
