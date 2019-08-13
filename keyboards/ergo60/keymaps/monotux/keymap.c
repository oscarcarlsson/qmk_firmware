/*
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
#include "ergo60.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

// Layer shorthand
#define _DV 0
#define _LW 1
#define _RS 2
#define _FN 3
#define _CO 4
#define _QW 5

// Note to self: These are the custom keycodes that should be used in
// the layout below, and these are later used in process_record_user
// to create our desired tri layer functionality.

// Not sure the FUNCTION and CONFIG keycodes are even needed?
enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
  QWERTY,
  TBLFLIP,
  SIGNATU,
  REGARDS,
};

enum unicode_names {
  MWNG, // money with wings
  PLED, // pleading face
};

const uint32_t PROGMEM unicode_map[] = {
  [MWNG] = 0x1F4B8,
  [PLED] = 0x1F97A
};

// Fillers to make layering more clear
#define ___T___ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_CNFG OSL(_CO)
#define KC_LW LOWER
#define KC_RS RAISE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_DV] = LAYOUT_monotux(
   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    NO_MINS, NO_EQL,  KC_DEL,  \
   KC_TAB,  NO_AM,   NO_AE,   NO_OSLH, KC_P,    KC_Y,    NO_SCLN, NO_SLSH, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_COMM, \
   KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_HOME, KC_PGUP, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,  \
   KC_LSFT, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_END,  KC_PGDN, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
   KC_LGUI, KC_LGUI, KC_LALT, KC_LGUI, KC_RS,    KC_BSPC,            KC_SPC,        KC_LW,   KC_LALT, KC_RGUI, KC_RGHT, KC_LGUI  \
 ),

 [_LW] = LAYOUT_monotux( /* LOWERED */
   KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  \
   ___T___, NO_LCBR, NO_RCBR, NO_LBRC, NO_RBRC, NO_DLR,  XXXXXXX, XXXXXXX, NO_QUO2, NO_QUES, NO_AMPR, NO_LESS, NO_GRTR, ___T___, \
   ___T___, NO_SCLN, NO_SLSH, NO_LPRN, NO_RPRN, NO_PIPE, XXXXXXX, XXXXXXX, NO_HASH, NO_CIRC, NO_EURO, NO_QUOT, NO_GRV,  XXXXXXX, \
   ___T___, NO_COLN, NO_EQL,  NO_AT,   KC_EXLM, NO_BSLS, XXXXXXX, XXXXXXX, KC_PERC, NO_TILD, XXXXXXX, XXXXXXX, NO_ACUT, XXXXXXX, \
   ___T___,   XXXXXXX, ___T___, XXXXXXX, ___T___,    ___T___,          ___T___,     ___T___, ___T___, XXXXXXX, XXXXXXX, ___T___  \
 ),

 [_RS] = LAYOUT_monotux( /* RAISED */
   XXXXXXX, SIGNATU, REGARDS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    NO_ASTR, KC_INS,  \
   ___T___, XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_4,    KC_5,    KC_6,    NO_PLUS, ___T___, \
   XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_1,    KC_2,    KC_3,    NO_MINS, XXXXXXX, \
   ___T___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC, NO_TILD, KC_0,    XXXXXXX, NO_EQL,  ___T___, \
   ___T___, XXXXXXX, ___T___, XXXXXXX, ___T___,     ___T___,      ___T___,          ___T___, ___T___, XXXXXXX, XXXXXXX, ___T___  \
 ),

 [_FN] = LAYOUT_monotux(
   KC_CNFG, X(MWNG), X(PLED), TBLFLIP, _______, _______, _______, _______, _______, _______, _______, _______, UC_MOD,  _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   RESET,   _______, _______, _______, _______,       _______,       _______,       _______, _______, _______, _______, _______
 ),

 // I could probably omit this layer at some point?
 [_CO] = LAYOUT_monotux(
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
   TT(_QW), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,        XXXXXXX,        XXXXXXX,     _______, XXXXXXX, XXXXXXX, XXXXXXX, TO(_DV)
 ),

 [_QW] = LAYOUT_monotux(
   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, \
   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
   KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, _______,      KC_SPC,           KC_SPC,      _______, KC_LEFT, KC_DOWN, KC_UP,   TO(_DV)  \
 )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QW);
    }
    return false;
    break;
  case DVORAK:
    if (record->event.pressed) {
      persistent_default_layer_set(1UL<<_DV);
    }
    return false;
    break;
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LW);
      update_tri_layer(_LW, _RS, _FN);
    } else {
      layer_off(_LW);
      update_tri_layer(_LW, _RS, _FN);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
      layer_on(_RS);
      update_tri_layer(_LW, _RS, _FN);
    } else {
      layer_off(_RS);
      update_tri_layer(_LW, _RS, _FN);
    }
    return false;
    break;
  case TBLFLIP:
    if (record->event.pressed) {
      send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
    }
    break;
  case SIGNATU:
    if (record->event.pressed) {
      // Med vänliga hälsningar...
      /* send_unicode_hex_string("0048 00E4 006C 0073 006E 0069 006E 0067 0061 0072 002C 000A 004F 0073 0063 0061 0072 0020 0043 0061 0072 006C 0073 0073 006F 006E 000A 004C 004B 0041 0042 0020 0049 0054 0020 0061 0070 0070 006C 0069 006B 0061 0074 0069 006F 006E 0073 0064 0072 0069 0066 0074 0065 006E"); */
      SEND_STRING("Hälsningar,\nOscar Carlsson\nLKAB IT applikationsdriften\n");
    }
    break;
  case REGARDS:
    if (record->event.pressed) {
      SEND_STRING("Regards,\nOscar Carlsson\nLKAB IT application operations\n");
    }
    break;
  }
  return true;
}

// gimme unicodez
void eeconfig_init_user(void) {
    set_unicode_input_mode(UC_LNX);
}
