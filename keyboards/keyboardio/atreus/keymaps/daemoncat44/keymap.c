#include QMK_KEYBOARD_H

// Initial keymap for daemoncat's Keyboardio Atreus

enum layer_names {
  _QWTY,
  _LOWER,
  _RAISE
};

// Adding macros to make the keymaps below much easier to read.

// LAYER TOGGLES
#define ADJUST MO(_ADJ)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// mod-tap keys
#define MT_Z    LSFT_T(KC_Z)
#define MT_ESC  LGUI_T(KC_ESC)
#define MT_ENT  RSFT_T(KC_ENTER)
#define MT_TAB  RSFT_T(KC_TAB)

// macros keys
#define SC_CUT              LCTL(KC_X)
#define SC_COPY             LCTL(KC_C)
#define SC_PSTE             LCTL(KC_V)
#define SC_SAVE             LCTL(KC_S)
#define SC_RFH              LCTL(KC_R)
#define SC_AC               LCTL(KC_0)
#define SC_OUT              LCTL(KC_MINS)
#define SC_IN               LCTL(KC_PPLS)
#define SC_NEW              LCTL(KC_N)
#define SC_V                LGUI(KC_V)
#define WIN_TAB             LGUI(KC_TAB)
#define SFT_TAB             LSFT(KC_TAB)
#define SC_LCH              LALT(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWTY] = LAYOUT(
    KC_Q,      KC_W,      KC_E,      KC_R,    KC_T,                         KC_Y,     KC_U,    KC_I,      KC_O,      KC_P,
    KC_A,      KC_S,      KC_D,      KC_F,    KC_G,                         KC_H,     KC_J,    KC_K,      KC_L,      KC_SCLN,
    KC_Z,      KC_X,      KC_C,      KC_V,    KC_B,   KC_GRAVE,  MT_ESC,    KC_N,     KC_M,    KC_COMM,   KC_DOT,    KC_ENT,
    KC_LSFT,   KC_LCTL,   KC_LALT,   LOWER,   SC_V,   KC_PGUP,   KC_PGDN,   KC_SPC,   RAISE,   KC_RALT,   KC_RCTL,   MT_TAB
  ),
  [_RAISE] = LAYOUT(
    _______, KC_1,    KC_2, KC_3,     KC_GRAVE,                  _______, SC_AC,   SC_OUT,  SC_IN,    KC_BSPC,
    _______, KC_4,    KC_5, KC_6,     _______,                   KC_UP,   KC_LEFT, KC_DOWN, KC_RIGHT, SC_RFH,
    _______, KC_7,    KC_8, KC_9,     _______, _______, _______, _______, SC_CUT,  SC_COPY, SC_PSTE,  SC_SAVE,
    _______, _______, KC_0, _______,  _______, _______, _______, _______, _______, SC_LCH,  WIN_TAB,  KC_DEL
  ),
  [_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2, KC_F3,   _______,                   KC_NUBS, KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS,
    _______, KC_F4,   KC_F5, KC_F6,   _______,                   KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_QUOT,
    _______, KC_F7,   KC_F8, KC_F9,   _______, _______, _______, KC_PIPE, KC_LPRN, KC_RPRN, KC_SLSH, KC_RSFT,
    _______, KC_CAPS, KC_0,  _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};
