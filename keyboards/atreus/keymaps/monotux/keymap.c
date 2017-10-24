#include "atreus.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

#define _DV 0
#define _RS 1
#define _LW 2
#define _A5 3
#define _QW 4

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define TAPPING_TOGGLE 2
#define KC_FN0 TO(_DV)
#define KC_FN1 MO(_RS)
#define KC_FN2 MO(_LW)
#define KC_FN3 MO(_A5)
#define KC_FN4 TO(_QW)

#define KC_LSHD SFT_T(KC_DOT)
#define KC_RSHZ MT(MOD_RSFT, KC_Z)
#define KC_RSHS MT(MOD_RSFT, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DV] = {
    { NO_AA,   NO_AE,   NO_OSLH,  KC_P,   KC_Y,    _______, KC_F,    KC_G,     KC_C,    KC_R,   KC_L    },
    { KC_A,    KC_O,    KC_E,     KC_U,   KC_I,    _______, KC_D,    KC_H,     KC_T,    KC_N,   KC_S    },
    { KC_LSHD, KC_Q,    KC_J,     KC_K,   KC_X,    KC_LCTL, KC_B,    KC_M,     KC_W,    KC_V,   KC_RSHZ },
    { KC_TAB,  KC_FN2,  KC_LGUI,  KC_FN1, KC_BSPC, KC_LALT, KC_SPC,  KC_FN3,   NO_MINS, KC_FN4, KC_ENT  }
  },

  [_RS] = {
    {KC_INS,  NO_AT,   KC_UP,   KC_MPLY, KC_VOLU, _______, KC_PGUP, KC_7,    KC_8, KC_9,    NO_ASTR },
    {KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, _______, KC_PGDN, KC_4,    KC_5, KC_6,    NO_PLUS },
    {_______, NO_RBRC, NO_LPRN, NO_RPRN, NO_AMPR, KC_LCTL, NO_SLSH, KC_1,    KC_2, KC_3,    NO_BSLS },
    {_______, _______, _______, _______, _______, KC_LALT, _______, _______, KC_0, _______, NO_EQL  }
  },

  [_LW] = {
    { KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10   },
    { KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN, _______, NO_QUOT, KC_F4,   KC_F5,   KC_F6,   KC_F11   },
    { XXXXXXX, KC_VOLU, KC_VOLD, XXXXXXX,   RESET, KC_LCTL, NO_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F12   },
    { KC_FN0,  _______, _______, _______, KC_BSPC, KC_LALT, _______, _______, KC_PSCR, KC_SLCK, KC_PAUSE }
  },

  [_A5] = {
    { NO_LCBR, NO_RCBR, NO_LBRC, NO_RBRC, NO_DLR,  _______, NO_QUO2, NO_QUES, NO_AMPR, NO_LESS, NO_GRTR },
    { NO_SCLN, NO_SLSH, NO_LPRN, NO_RPRN, NO_PIPE, _______, KC_HASH, NO_CIRC, NO_TILD, KC_BSLS, NO_ASTR },
    { _______, NO_EQL,  NO_AT,   KC_EXLM, NO_BSLS, KC_LCTL, KC_PERC, NO_EURO, _______, _______, _______ },
    { KC_GESC, _______, _______, _______, KC_DELT, KC_LALT, _______, _______, KC_COMM, _______, _______ }
  },

  [_QW] = {
    { KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    _______, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P },
    { KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    _______, KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN },
    { KC_LSHD, KC_X,    KC_C,    KC_V,   KC_B,    KC_LCTL, KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_RSHS },
    { KC_ESC,  KC_TAB,  KC_LGUI, KC_FN0, KC_BSPC, KC_LALT, KC_SPC, KC_FN1, KC_MINS, KC_QUOT, KC_ENT },
  }
};
