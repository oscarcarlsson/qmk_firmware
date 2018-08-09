#include "atreus.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

#define _DEFT 0
#define _NAVI 1
#define _SYMB 2
#define _DUAL 3

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Each new keycode requires an unique number, the SAFE_RANGE macro
// helps us with this. These keys are added to our keymaps and handled
// in process_record_user.
enum custom_keycodes {
  DEFT = SAFE_RANGE,
  SYMB,
  NAVI
};

#define KC_LSHD SFT_T(KC_DOT)
#define KC_RSDT SFT_T(KC_Z)

// Dual purpose thumb keys, default layer
#define KC_LCBS CTL_T(KC_BSPC)
#define KC_LASP ALT_T(KC_SPC)

// Dual purpose thumb keys, other layers
#define KC_LCDE CTL_T(KC_DEL)
#define KC_LAEN ALT_T(KC_ENT)

enum unicode_name { POO, HERT, SML2, DEYE };

const uint32_t PROGMEM unicode_map[] = { [POO] = 0x1F4A9,
                                         [HERT] = 0x2764,
                                         [SML2] = 0x1F605,
};

#define KC_GUI1 LGUI(KC_1)
#define KC_GUI2 LGUI(KC_2)
#define KC_GUI3 LGUI(KC_3)
#define KC_GUI4 LGUI(KC_4)
#define KC_GUI5 LGUI(KC_5)
#define KC_GUI6 LGUI(KC_6)
#define KC_GUI7 LGUI(KC_7)
#define KC_GUI8 LGUI(KC_8)
#define KC_GUI9 LGUI(KC_9)
#define KC_GUI0 LGUI(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFT] = {
    { NO_AM,   NO_AE,   NO_OSLH, KC_P,    KC_Y,    _______, KC_F,    KC_G,    KC_C,    KC_R,   KC_L    },
    { KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______, KC_D,    KC_H,    KC_T,    KC_N,   KC_S    },
    { KC_LSHD, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LCBS, KC_B,    KC_M,    KC_W,    KC_V,   KC_RSDT },
    { KC_TAB,  KC_COMM, SYMB,    KC_LGUI, NAVI,    KC_LASP, SYMB,    NAVI,    NO_MINS, KC_APP, KC_ENT  }
  },

  [_NAVI] = {
    { KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_VOLU, _______, KC_PGUP, KC_7,    KC_8,    KC_9,    NO_ASTR },
    { KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, _______, KC_PGDN, KC_4,    KC_5,    KC_6,    NO_PLUS },
    { NO_COLN, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_LCDE, NO_SLSH, KC_1,    KC_2,    KC_3,    NO_BSLS },
    { _______, _______, _______, _______, _______, KC_LAEN, _______, _______, KC_0,    _______, NO_EQL  }
  },

  [_SYMB] = {
    { NO_LCBR, NO_RCBR, NO_LBRC, NO_RBRC, NO_DLR,  _______, NO_QUO2, NO_QUES, NO_AMPR, NO_LESS, NO_GRTR },
    { NO_SCLN, NO_SLSH, NO_LPRN, NO_RPRN, NO_PIPE, _______, KC_HASH, NO_CIRC, NO_TILD, NO_QUOT, NO_GRV  },
    { NO_COLN, NO_EQL,  NO_AT,   KC_EXLM, NO_BSLS, KC_LCDE, KC_PERC, NO_EURO, XXXXXXX, XXXXXXX, NO_ACUT },
    { KC_GESC, _______, _______, _______, _______, KC_LAEN, _______, _______, KC_COMM, _______, _______ }
  },

  [_DUAL] = {
    { KC_GUI1, KC_GUI2, KC_GUI3, KC_GUI4, KC_GUI5, _______, X(POO),  KC_F7,   KC_F8,   KC_F9,   KC_F10   },
    { KC_GUI6, KC_GUI7, KC_GUI8, KC_GUI9, KC_GUI0, _______, X(HERT), KC_F4,   KC_F5,   KC_F6,   KC_F11   },
    { KC_LSFT, KC_MPRV, KC_MPLY, KC_MNXT, RESET,   _______, X(SML2), KC_F1,   KC_F2,   KC_F3,   KC_F12   },
    { _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUSE }
  }
};

void matrix_init_user() {
  // give time for usb to initialize
  _delay_ms(500);
  set_unicode_input_mode(UC_LNX);
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Return true makes QMK deal with the key as usual, false means that
// we have the responsibility and enables us to do our magic
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case DEFT:
    if (record->event.pressed) {
      persistent_default_layer_set(1UL<<_DEFT);
    }
    return false;
    break;
  case SYMB:
    if (record->event.pressed) {
      layer_on(_SYMB);
      update_tri_layer(_SYMB, _NAVI, _DUAL);
    } else {
      layer_off(_SYMB);
      update_tri_layer(_SYMB, _NAVI, _DUAL);
    }
    return false;
    break;
  case NAVI:
    if (record->event.pressed) {
      layer_on(_NAVI);
      update_tri_layer(_SYMB, _NAVI, _DUAL);
    } else {
      layer_off(_NAVI);
      update_tri_layer(_SYMB, _NAVI, _DUAL);
    }
    return false;
    break;
  }
  return true;
}
