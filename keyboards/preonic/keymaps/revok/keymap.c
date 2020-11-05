#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

//Mod keys
#define SFT_ENT	    MT(MOD_RSFT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | GESC |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  { } |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | /  \ |EntShf|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | App  | Ctrl |  Alt |  GUI | Lower |    Space    |Raise | Left |  UP  | DOWN |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GESC,          KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC,  \
  KC_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,  \
  LALT(KC_SPACE),   KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  7   |  8   |  9   |  -   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  4   |  5   |  6   |      | [ ]  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  0   |  ,   |  .   |      |EntShf|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, KC_7,   KC_8,    KC_9,    KC_MINS,   KC_EQL,  \
  _______, _______, _______, _______, _______, _______, _______, KC_4,   KC_5,    KC_6,    _______,   KC_LCBR, \
  _______, _______, _______, _______, _______, _______, _______, KC_1,   KC_2,    KC_3,    _______,   KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, KC_0,   KC_COMM, KC_DOT,  _______,   SFT_ENT, \
  _______, _______, _______, _______, _______, _______, _______, _______,KC_MNXT, KC_VOLD, KC_VOLU,   KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      | ACL0 | ACL1 | ACL2 |      |      |      |      | CMD+F| CMD+T| Cut  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  mB2 |  mUp |  mB1 | scUp |      |      |      |      |      | Copy | Paste|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  mLt |  mDn |  mRt | scDn |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  \   | Safe |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Home | PgDn | PgUp |  END |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, LCTL(KC_F), LCTL(KC_T), LCTL(KC_X), KC_DEL,   \
  _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, _______, _______, _______, _______,    _______,    LCTL(KC_C), LCTL(KC_V), \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, _______,    _______,    _______,    _______,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______,    LCTL(KC_S),  \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,    KC_PGDN,    KC_PGDN,    KC_END    \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BRITE|      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, SFT_ENT, \
  BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
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
