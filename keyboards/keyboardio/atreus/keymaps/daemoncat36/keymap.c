#include QMK_KEYBOARD_H

// Initial keymap for daemoncat's Keyboardio Atreus

enum layer_names {
    _QWTY,
    _NUM,
    _FUN,
    _MOU
};

// mod-tap keys
#define MT_Z    LSFT_T(KC_Z)
#define MT_X    LCTL_T(KC_X)
#define MT_RP   RCTL_T(KC_DOT)
#define MT_RS   RSFT_T(KC_SLSH)
#define MT_ESC  LALT_T(KC_ESC)
#define MT_ENT  LT(_MOU, KC_ENT)
#define MT_FUN  LT(_FUN, KC_GRV)
#define MT_NUM  LT(_NUM, KC_GRV)

// macros keys
#define SC_CUT              LGUI(KC_X)
#define SC_COPY             LGUI(KC_C)
#define SC_PSTE             LGUI(KC_V)
#define SC_SAVE             LGUI(KC_S)
#define SC_RFH              LGUI(KC_R)
#define SC_AC               LGUI(KC_0)
#define SC_OUT              LGUI(KC_MINS)
#define SC_IN               LGUI(KC_PPLS)
#define SC_RC               LGUI(KC_SPC)
//#define SC_UNDO             LCTL(KC_Z)
//#define SC_V                LGUI(KC_V)
//#define WIN_TAB             LGUI(KC_TAB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWTY] = LAYOUT(
    KC_Q,     KC_W,      KC_E,    KC_R,      KC_T,                         KC_Y,    KC_U,      KC_I,     KC_O,     KC_P,
    KC_A,     KC_S,      KC_D,    KC_F,      KC_G,                         KC_H,    KC_J,      KC_K,     KC_L,     KC_SCLN,
    MT_Z,     MT_X,      KC_C,    KC_V,      KC_B,     XXXXXXX,  XXXXXXX,  KC_N,    KC_M,      KC_COMM,  MT_RP,    MT_RS,
    XXXXXXX,  XXXXXXX,   MT_ESC,  MT_FUN,    KC_TAB,   XXXXXXX,  SC_RC,    KC_SPC,  MT_NUM,    MT_ENT,   XXXXXXX,  XXXXXXX
  ),
  [_NUM] = LAYOUT(
    KC_TILD,  KC_1,     KC_2,  KC_3,     KC_MINS,                      KC_DEL,   SC_AC,    SC_OUT,   SC_IN,     KC_BSPC,
    KC_CAPS,  KC_4,     KC_5,  KC_6,     KC_PLUS,                      KC_UP,    KC_LEFT,  KC_DOWN,  KC_RIGHT,  SC_RFH,
    KC_LSFT,  KC_7,     KC_8,  KC_9,     KC_EQL,   XXXXXXX,  XXXXXXX,  SC_SAVE,  SC_CUT,   SC_COPY,  SC_PSTE,   KC_RSFT,
    XXXXXXX,  XXXXXXX,  KC_0,  _______,  _______,  XXXXXXX,  XXXXXXX,  KC_TAB,   _______,  _______,  XXXXXXX,   XXXXXXX
  ),
  [_FUN] = LAYOUT(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F10,                       _______,  _______,  _______,  _______,  _______,
    KC_CAPS,  KC_F4,    KC_F5,    KC_F6,    KC_F11,                       _______,  _______,  _______,  _______,  _______,
    KC_LSFT,  KC_F7,    KC_F8,    KC_F9,    KC_F12,   XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,  _______,
    XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX
  ),
  [_MOU] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,                        KC_BTN1,  KC_PGDN,  KC_PGUP,  KC_BTN2,  KC_HOME,
    _______,  _______,  _______,  _______,  _______,                        KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_END,
    _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,    KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  _______,
    XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,    _______,  _______,  _______,  XXXXXXX,  XXXXXXX
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_FUN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_TILD);
                return false;
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM dl_combo[]   = {KC_D,    KC_L,    COMBO_END};
const uint16_t PROGMEM scsl_combo[] = {KC_SCLN, MT_RS,   COMBO_END};
const uint16_t PROGMEM psc_combo[]  = {KC_P,    KC_SCLN, COMBO_END};
const uint16_t PROGMEM ol_combo[]   = {KC_O,    KC_L,    COMBO_END};
const uint16_t PROGMEM ldt_combo[]  = {KC_L,    MT_RP,   COMBO_END};
const uint16_t PROGMEM ik_combo[]   = {KC_I,    KC_K,    COMBO_END};
const uint16_t PROGMEM kc_combo[]   = {KC_K,    KC_COMM, COMBO_END};
const uint16_t PROGMEM uj_combo[]   = {KC_U,    KC_J,    COMBO_END};
const uint16_t PROGMEM jm_combo[]   = {KC_J,    KC_M,    COMBO_END};
const uint16_t PROGMEM yh_combo[]   = {KC_Y,    KC_H,    COMBO_END};
const uint16_t PROGMEM hn_combo[]   = {KC_H,    KC_N,    COMBO_END};
const uint16_t PROGMEM tg_combo[]   = {KC_T,    KC_G,    COMBO_END};
const uint16_t PROGMEM gb_combo[]   = {KC_G,    KC_B,    COMBO_END};
const uint16_t PROGMEM rf_combo[]   = {KC_R,    KC_F,    COMBO_END};
const uint16_t PROGMEM fv_combo[]   = {KC_F,    KC_V,    COMBO_END};
const uint16_t PROGMEM ed_combo[]   = {KC_E,    KC_D,    COMBO_END};
const uint16_t PROGMEM dc_combo[]   = {KC_D,    KC_C,    COMBO_END};

combo_t key_combos[] = {
    COMBO(dl_combo,   KC_DEL),
    COMBO(scsl_combo, KC_QUOT),
    COMBO(psc_combo,  KC_DQUO),
    COMBO(ol_combo,   KC_TILD),
    COMBO(ldt_combo,  KC_GRV),
    COMBO(ik_combo,   KC_PIPE),
    COMBO(kc_combo,   KC_BSLS),
    COMBO(uj_combo,   KC_PLUS),
    COMBO(jm_combo,   KC_EQL),
    COMBO(yh_combo,   KC_UNDS),
    COMBO(hn_combo,   KC_MINS),
    COMBO(tg_combo,   KC_LBRC),
    COMBO(gb_combo,   KC_RBRC),
    COMBO(rf_combo,   KC_LCBR),
    COMBO(fv_combo,   KC_RCBR),
    COMBO(ed_combo,   KC_LPRN),
    COMBO(dc_combo,   KC_RPRN),
};
