#include QMK_KEYBOARD_H

// Initial keymap for daemoncat's Keyboardio Atreus

enum layer_names {
    _QWTY,
    _NUM,
    _FUN
};

// mod-tap keys
#define MT_Z        LSFT_T(KC_Z)
#define MT_X        LCTL_T(KC_X)
#define MT_RP       RCTL_T(KC_DOT)
#define MT_RS       RSFT_T(KC_SLSH)
#define MT_ESC      LGUI_T(KC_ESC)
#define MT_ENT      LGUI_T(KC_ENT)

// macros
#define SC_CUT      LCTL(KC_X)
#define SC_COPY     LCTL(KC_C)
#define SC_PSTE     LCTL(KC_V)
#define SC_SAVE     LCTL(KC_S)
#define SC_RFH      LCTL(KC_R)
#define SC_AC       LCTL(KC_0)
#define SC_OUT      LCTL(KC_MINS)
#define SC_IN       LCTL(KC_PPLS)
#define SC_ESC      LALT(KC_ESC)
#define SC_FLW      LALT(KC_SPC)
//#define SC_UNDO   LCTL(KC_Z)
//#define SC_V      LGUI(KC_V)
//#define WIN_TAB   LGUI(KC_TAB)

// lt_layer keys
#define LT_FUN      LT(_FUN, KC_TAB)
#define LT_NUM      LT(_NUM, KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWTY] = LAYOUT(
    KC_Q,     KC_W,      KC_E,    KC_R,      KC_T,                         KC_Y,    KC_U,      KC_I,     KC_O,     KC_P,
    KC_A,     KC_S,      KC_D,    KC_F,      KC_G,                         KC_H,    KC_J,      KC_K,     KC_L,     KC_SCLN,
    MT_Z,     MT_X,      KC_C,    KC_V,      KC_B,     XXXXXXX,  XXXXXXX,  KC_N,    KC_M,      KC_COMM,  MT_RP,    MT_RS,
    XXXXXXX,  XXXXXXX,   ______,  SC_ESC,    LT_FUN,   XXXXXXX,  XXXXXXX,  LT_NUM,  MT_ENT,    SC_FLW,  XXXXXXX,  XXXXXXX
  ),
  [_NUM] = LAYOUT(
    _______,  KC_1,     KC_2,     KC_3,     _______,                      KC_DEL,   KC_PGUP,  KC_PGDN,  _______,   KC_BSPC,
    _______,  KC_4,     KC_5,     KC_6,     _______,                      KC_UP,    KC_LEFT,  KC_DOWN,  KC_RIGHT,  SC_RFH,
    KC_LSFT,  KC_7,     KC_8,     KC_9,     KC_0,     XXXXXXX,  XXXXXXX,  SC_SAVE,  SC_CUT,   SC_COPY,  SC_PSTE,   KC_RSFT,
    XXXXXXX,  XXXXXXX,  KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX,  XXXXXXX,  KC_TAB,   KC_TRNS,  KC_TRNS,  XXXXXXX,   XXXXXXX
  ),
  [_FUN] = LAYOUT(
    KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F10,                       KC_NUBS,  KC_MINS,  KC_EQL,   KC_UNDS,  KC_PLUS,
    _______,  KC_F4,    KC_F5,    KC_F6,    KC_F11,                       KC_LCBR,  KC_RCBR,  KC_LBRC,  KC_RBRC,  KC_QUOT,
    KC_LSFT,  KC_F7,    KC_F8,    KC_F9,    KC_F12,   XXXXXXX,  XXXXXXX,  KC_PIPE,  KC_LPRN,  KC_RPRN,  KC_BSLS,  KC_RSFT,
    XXXXXXX,  XXXXXXX,  KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX,  XXXXXXX,  KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX,  XXXXXXX
  )
};
