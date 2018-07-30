/* Copyright 2018 Fate
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum ut47_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK

};

#define _______ KC_TRNS
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define KC_RSEN MT(MOD_RSFT, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-------------------------------------------------------------------------.
   * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | Bksp  |
   * |-------------------------------------------------------------------------+
   * | Ctrl |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | Esc |Lead | Alt | GUI |Lower |   Space   |Raise |Left |Down | Up  |Right|
   * `-------------------------------------------------------------------------'
   */

  [_QWERTY] = LAYOUT( /* Base */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSEN,
    KC_ESC,  KC_LEAD, KC_LALT, KC_LGUI, LOWER,      KC_SPC,        RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

  /* Colemak
   * ,-------------------------------------------------------------------------.
   * | Tab |  Q  |  W  |  F  |  P  |  G  |  J  |  L  |  U  |  Y  |  ;  | Bksp  |
   * |-------------------------------------------------------------------------+
   * | Ctrl |  A  |  R  |  S  |  T  |  D  |  H  |  N  |  E  |  I  |  O  |   '  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  K  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | Esc |Lead | Alt | GUI |Lower |   Space   |Raise |Left |Down | Up  |Right|
   * `-------------------------------------------------------------------------'
   */

[_COLEMAK] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSEN,
    KC_ESC,  KC_LEAD, KC_LALT, KC_LGUI, LOWER,      KC_SPC,        RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

  /* Lower
   * ,-------------------------------------------------------------------------.
   * |     |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |       |
   * |-------------------------------------------------------------------------+
   * |      | F1  | F2  | F3  | F4  | F5  | F6  |  _  |  +  |  {  |  }  |  |   |
   * |-------------------------------------------------------------------------+
   * |       | F7  | F8  | F9  | F10 | F11 | F12 |  ~  |     |     | App |     |
   * |-------------------------------------------------------------------------+
   * | Del |     |     |     |      |          |       |Home |PgDn |PgUp | End |
   * `-------------------------------------------------------------------------'
   */

[_LOWER] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TILD, _______, _______, KC_APP,  _______,
    KC_DEL,  _______, _______, _______, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

  /* Raise
   * ,-------------------------------------------------------------------------.
   * |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |       |
   * |-------------------------------------------------------------------------+
   * |      | F1  | F2  | F3  | F4  | F5  | F6  |  -  |  =  |  [  |  ]  |  \   |
   * |-------------------------------------------------------------------------+
   * |       | F7  | F8  | F9  | F10 | F11 | F12 |  `  |     |     | App |     |
   * |-------------------------------------------------------------------------+
   * | Del |     |     |     |      |          |       |Home |PgDn |PgUp | End |
   * `-------------------------------------------------------------------------'
   */

[_RAISE] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_GRV,  _______, _______, KC_APP,  _______,
    KC_DEL,  _______, _______, _______, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

  /* Adjust
   * ,-------------------------------------------------------------------------.
   * |Caps |BTN1 |MS_U |BTN2 |     |     |     |PSCR |SLCK |PAUS |     |       |
   * |-------------------------------------------------------------------------+
   * |      |MS_L |MS_D |MS_R |     |     |     | Qwe | Col |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     | RST |     |     |     |     |Play |     |
   * |-------------------------------------------------------------------------+
   * | Ins |     |     |     |      |          |       |Prev |Vol- |Vol+ |Next |
   * `-------------------------------------------------------------------------'
   */

[_ADJUST] = LAYOUT(
    KC_CAPS, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, QWERTY,  COLEMAK, _______, _______, _______,
    _______, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, KC_MPLY, _______,
    KC_INS,  _______, _______, _______, _______,     _______,      _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_ONE_KEY(KC_X) {
      register_code(KC_LALT);
      register_code(KC_F4);
      unregister_code(KC_F4);
      unregister_code(KC_LALT);
    }
    SEQ_ONE_KEY(KC_W) {
      register_code(KC_LCTL);
      register_code(KC_RGHT);
      unregister_code(KC_RGHT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_B) {
      register_code(KC_LCTL);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      unregister_code(KC_LCTL);
    }
  }
}
