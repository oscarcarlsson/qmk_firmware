#include "atreus.h"
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
#define KC_RGMS RGUI_T(SE_MINS)

enum unicode_name { POO, HERT, SML2, YAY, MNKY, MASK };

const uint32_t PROGMEM unicode_map[] = { [POO] =  0x1F4A9,
                                         [HERT] = 0x2764,
                                         [SML2] = 0x1F605,
                                         [YAY] =  0x1F64C,
                                         [MNKY] = 0x1F412,
                                         [MASK] = 0x1F637,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFT] = {
    { SE_ARNG, SE_ADIA, SE_ODIA, KC_P,    KC_Y,    _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L     },
    { KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S     },
    { KC_LSHD, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LCTL, KC_B,    KC_M,    KC_W,    KC_V,    KC_RSDT  },
    { KC_TAB,  KC_COMM, KC_LGUI, NAVI,    KC_BSPC, KC_LALT, KC_SPC,  SYMB,    KC_RGMS, KC_RALT, KC_ENT   }
  },

  [_NAVI] = {
    { KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_VOLU, _______, KC_PGUP, KC_7,    KC_8,    KC_9,    SE_ASTR },
    { KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, _______, KC_PGDN, KC_4,    KC_5,    KC_6,    SE_PLUS },
    { _______, DM_REC1, DM_RSTP, DM_PLY1, KC_MPLY, KC_LCTL, SE_SLSH, KC_1,    KC_2,    KC_3,    _______ },
    { _______, _______, _______, _______, _______, KC_LALT, _______, _______, KC_0,    _______, _______ }
  },

  [_SYMB] = {
    { SE_LCBR, SE_RCBR, SE_LBRC, SE_RBRC, SE_DLR,  _______, SE_QUO2, SE_QUES, SE_AMPR, SE_LESS, SE_GRTR },
    { SE_SCLN, SE_SLSH, SE_LPRN, SE_RPRN, SE_PIPE, _______, SE_HASH, SE_CIRC, SE_TILD, SE_QUOT, SE_GRV  },
    { _______, SE_EQL,  SE_AT,   SE_EXLM, SE_BSLS, KC_LCTL, SE_PERC, SE_EURO, SE_MINS, XXXXXXX, SE_ACUT },
    { KC_GESC, _______, _______, _______, _______, KC_LALT, _______, _______, _______, KC_APP,   _______ }
  },

  [_DUAL] = {
    { KC_ACL0, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, X(POO),  KC_F7,   KC_F8,   KC_F9,   KC_F10  },
    { KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, X(HERT), KC_F4,   KC_F5,   KC_F6,   KC_F11  },
    { KC_ACL2, KC_MPRV, KC_MPLY, KC_MNXT, X(MNKY), _______, X(SML2), KC_F1,   KC_F2,   KC_F3,   KC_F12  },
    { RESET,   UC_LNX,  _______, _______, X(MASK), _______, X(YAY),  _______, KC_PSCR, KC_SLCK, KC_PAUS }
  }
};

void matrix_init_user() {
  // give time for usb to initialize
  _delay_ms(500);
  set_unicode_input_mode(UC_WINC);
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
