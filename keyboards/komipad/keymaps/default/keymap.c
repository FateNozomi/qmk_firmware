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
#include "muse.h"

enum komipad_layers {
  _QWERTY,
  _NUMPAD,
  _NAV,
  _LAUNCH,
  _INVENT,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMPAD,
  NAV,
  LAUNCH,
  INVENT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LOW_DOT LT(_LOWER, KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Base */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    \
    RAISE,   KC_LALT, KC_LGUI, LOWER,   KC_SPC   \
  ),

  [_NUMPAD] = LAYOUT(
    KC_ESC,  KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
    KC_TAB,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
    KC_LCTL, KC_P4,   KC_P5,   KC_P6,   KC_BSPC, \
    KC_LSFT, KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
    RAISE,   KC_P0,   KC_P0,   LOW_DOT,  KC_SPC  \
  ),

  [_NAV] = LAYOUT(
    _______, _______, _______, _______, _______, \
    _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, \
    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______  \
  ),

  [_LAUNCH] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
    RAISE,   KC_LALT, KC_LGUI, LOWER,   KC_LCTL  \
  ),

  [_INVENT] = LAYOUT(
    _______, KC_F5,   KC_F6,   KC_NO,   KC_NO,   \
    _______, KC_E,    KC_G,    KC_C,    KC_NO,   \
    _______, KC_Z,    KC_NO,   KC_M,    KC_NO,   \
    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______  \
  ),

  [_LOWER] = LAYOUT(
    KC_DEL,  _______, _______, _______, _______, \
    _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, \
    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______  \
  ),

  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, \
    _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, \
    _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______  \
  ),

  [_ADJUST] = LAYOUT(
    KC_INS,  KC_PSCR, KC_SLCK, KC_PAUS, _______, \
    KC_CAPS, EEP_RST, AU_ON,   AU_OFF,  MUV_IN,  \
    _______, MU_MOD,  MU_ON,   MU_OFF,  MUV_DE,  \
    _______, QWERTY,  NUMPAD,  NAV,     LAUNCH,  \
    _______, _______, RESET,   _______, INVENT  \
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
    case NUMPAD:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_NUMPAD);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_NAV);
      }
      return false;
    case LAUNCH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_LAUNCH);
      }
      return false;
      break;
    case INVENT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_INVENT);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
