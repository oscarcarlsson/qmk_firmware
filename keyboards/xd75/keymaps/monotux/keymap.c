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
#define _QW 2
#define _MD 3

// Magic keys
#define KC_LSHM SFT_T(NO_MINS) // shift when held, minus when tapped
#define KC_RSHC SFT_T(KC_COMM) // shift when held, comma when tapped

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_SV] = { /* SVORAK */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    NO_SLSH, NO_ASTR, NO_PLUS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
  { TG(3),   NO_AM,   NO_AE,   NO_OSLH, KC_P,    KC_Y,    NO_MINS, KC_INS,  NO_GRV,   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    TG(2)   },
  { KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_PGUP, KC_DEL,  KC_HOME,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT  },
  { KC_LSHM, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_PGDN, KC_UP,   KC_END,   KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSHC },
  { NO_APOS, KC_LEAD, MO(_MD), KC_LGUI, KC_LCTL, KC_BSPC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_SPC,  KC_LALT, MO(_LW), KC_HYPR, KC_RCTL, NO_MINS },
 },

 [_LW] = { /* LOWERED */
  { XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, XXXXXXX  },
  { ___T___, NO_LCBR, NO_RCBR, NO_LBRC, NO_RBRC, NO_DLR,  XXXXXXX, XXXXXXX, XXXXXXX, NO_QUO2, NO_QUES, NO_AMPR, NO_LESS, NO_GRTR, ___T___  },
  { XXXXXXX, NO_SCLN, NO_SLSH, NO_LPRN, NO_RPRN, NO_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, KC_HASH, NO_CIRC, NO_TILD, NO_EURO, XXXXXXX, XXXXXXX  },
  { ___T___, XXXXXXX, NO_EQL,  NO_AT,   KC_EXLM, NO_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  },
  { RESET,   XXXXXXX, ___T___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___T___, XXXXXXX, XXXXXXX, XXXXXXX  },
 },

 [_QW] = { /* qwerty for gaming */
   { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    NO_SLSH, NO_ASTR, NO_PLUS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
   { ___T___, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    NO_MINS, KC_INS,  NO_GRV,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ___T___ },
   { KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGUP, KC_DEL,  KC_HOME,  KC_H,    KC_J,    KC_K,    KC_L,    NO_AM,   KC_ENT  },
   { KC_LSFT, KC_DOT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_PGDN, KC_UP,   KC_END,   KC_B,    KC_N,    KC_M,    NO_OSLH, NO_AE,   KC_COMM },
   { NO_APOS, KC_LEAD, ___T___, KC_LSFT, KC_LCTL, KC_SPC,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPC, KC_LALT, MO(_LW), KC_HYPR, KC_RCTL, NO_MINS },
 },

 [_MD] = { /* some media buttons */
   { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
   { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
   { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
   { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
   { XXXXXXX, XXXXXXX, ___T___, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
 },
};
