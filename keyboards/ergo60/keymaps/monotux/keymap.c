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
#define _QW 0
#define _LW 1
#define _RS 2
#define _FN 3

// Fillers to make layering more clear
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A      | S      | D      | F      | G      | HOME   | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | FN     | SPACE  | SPACE  | SPACE  | SPACE  | SPACE  | RIGHT  | DOWN   | UP     | RIGHT  |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = LAYOUT_monotux(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  NO_AM,   NO_AE,   NO_OSLH, KC_P,    KC_Y,    NO_SCLN, NO_SLSH, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_COMM, \
  KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_HOME, KC_PGUP, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  KC_LSFT, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_END,  KC_PGDN, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_LGUI, MO(_RS),    KC_BSPC,            KC_SPC,      MO(_LW), KC_LALT, KC_RGUI, KC_RGHT, KC_RCTL \
 ),

 [_LW] = LAYOUT_monotux( /* LOWERED */
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_DEL , \
  ___T___, NO_LCBR, NO_RCBR, NO_LBRC, NO_RBRC, NO_DLR,  XXXXXXX, XXXXXXX, NO_QUO2, NO_QUES, NO_AMPR, NO_LESS, NO_GRTR, ___T___, \
  ___T___, NO_SCLN, NO_SLSH, NO_LPRN, NO_RPRN, NO_PIPE, XXXXXXX, XXXXXXX, NO_HASH, NO_CIRC, NO_EURO, NO_QUOT, NO_GRV,  XXXXXXX, \
  ___T___, NO_COLN, NO_EQL,  NO_AT,   KC_EXLM, NO_BSLS, XXXXXXX, XXXXXXX, KC_PERC, NO_TILD, XXXXXXX, XXXXXXX, NO_ACUT, XXXXXXX, \
  RESET,   XXXXXXX, ___T___, XXXXXXX, ___T___,    KC_DEL,            ___T___,      ___T___, ___T___, XXXXXXX, XXXXXXX, XXXXXXX \
 ),

 [_RS] = LAYOUT_monotux( /* LOWERED */
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    NO_ASTR, XXXXXXX, \
  ___T___, XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_4,    KC_5,    KC_6,    NO_PLUS, ___T___, \
  XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_1,    KC_2,    KC_3,    NO_BSLS, XXXXXXX, \
  ___T___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC, NO_TILD, KC_0,    XXXXXXX, NO_EQL,  XXXXXXX, \
  XXXXXXX, XXXXXXX, ___T___, XXXXXXX, ___T___,     ___T___,      ___T___,          ___T___, ___T___, XXXXXXX, XXXXXXX, XXXXXXX  \
 ),


/* FUNCTION
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = LAYOUT_monotux(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______
 )
};
