/* Copyright 2017 Oscar Carlsson
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
#include "xd75.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

// Fillers to make layering more clear
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _SV 0
#define _LW 1
#define _RS 2
#define _QW 3
#define _MD 4

// Magic keys
#define KC_LSHM SFT_T(NO_MINS) // shift when held, minus when tapped
#define KC_RSHC SFT_T(KC_COMM) // shift when held, comma when tapped

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_SV] = { /* SVORAK */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    NO_SLSH, NO_ASTR, NO_PLUS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
  { KC_LCTL, NO_AM,   NO_AE,   NO_OSLH, KC_P,    KC_Y,    KC_PGUP, KC_INS,  KC_HOME, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    NO_QUOT },
  { KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_PGDN, KC_UP,   KC_END,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT  },
  { KC_LSHM, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_LEFT, KC_DOWN, KC_RGHT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSHC },
  { NO_APOS, KC_LEAD, MO(_MD), KC_LGUI, KC_LCTL, MO(_RS), KC_BSPC, MO(_MD), KC_SPC,  MO(_LW), KC_LALT, KC_RGUI, KC_HYPR, KC_RCTL, NO_MINS },
 },

 [_LW] = { /* LOWERED */
  { KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_DEL   },
  { ___T___, NO_LCBR, NO_RCBR, NO_LBRC, NO_RBRC, NO_DLR,  XXXXXXX, XXXXXXX, XXXXXXX, NO_QUO2, NO_QUES, NO_AMPR, NO_LESS, NO_GRTR, ___T___  },
  { XXXXXXX, NO_SCLN, NO_SLSH, NO_LPRN, NO_RPRN, NO_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, NO_HASH, NO_CIRC, NO_EURO, NO_QUOT, NO_GRV,  XXXXXXX  },
  { ___T___, NO_COLN, NO_EQL,  NO_AT,   KC_EXLM, NO_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC, NO_TILD, XXXXXXX, XXXXXXX, NO_ACUT, XXXXXXX  },
  { RESET,   XXXXXXX, ___T___, XXXXXXX, XXXXXXX, ___T___, KC_DEL,  XXXXXXX, XXXXXXX, ___T___, XXXXXXX, ___T___, XXXXXXX, XXXXXXX, XXXXXXX  },
 },

 [_RS] = { /* LOWERED */
  { XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_7,    KC_8,    KC_9,    NO_ASTR, XXXXXXX  },
  { ___T___, NO_LCBR, KC_HOME, KC_UP,   KC_END,  NO_DLR,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_4,    KC_5,    KC_6,    NO_PLUS, ___T___  },
  { XXXXXXX, NO_SCLN, KC_LEFT, KC_DOWN, KC_RGHT, NO_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_1,    KC_2,    KC_3,    NO_BSLS, XXXXXXX  },
  { ___T___, XXXXXXX, NO_EQL,  NO_AT,   KC_EXLM, NO_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC, NO_TILD, KC_0,    XXXXXXX, NO_EQL,  XXXXXXX  },
  { XXXXXXX, XXXXXXX, ___T___, XXXXXXX, XXXXXXX, ___T___, XXXXXXX, XXXXXXX, XXXXXXX, ___T___, XXXXXXX, ___T___, XXXXXXX, XXXXXXX, XXXXXXX  },
 },

 [_QW] = { /* qwerty for gaming */
   { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    NO_SLSH, NO_ASTR, NO_PLUS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
   { ___T___, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    NO_MINS, KC_INS,  NO_GRV,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___T___ },
   { KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGUP, KC_DEL,  KC_HOME,  KC_H,    KC_J,    KC_K,    KC_L,    NO_AM,   KC_ENT  },
   { KC_LSFT, KC_DOT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_PGDN, KC_UP,   KC_END,   KC_B,    KC_N,    KC_M,    NO_OSLH, NO_AE,   KC_COMM },
   { NO_APOS, KC_LEAD, ___T___, KC_LSFT, KC_LCTL, KC_SPC,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPC, KC_LALT, MO(_LW), KC_HYPR, KC_RCTL, NO_MINS },
 },

 [_MD] = { /* some media buttons */
   { BL_TOGG, BL_DEC,  BL_INC,  BL_BRTG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
   { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
   { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
   { XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
   { XXXXXXX, XXXXXXX, ___T___, XXXXXXX, XXXXXXX, ___T___, XXXXXXX, ___T___, XXXXXXX, ___T___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
 },
};
