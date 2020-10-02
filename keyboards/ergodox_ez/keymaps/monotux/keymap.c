#include "ergodox_ez.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define _BASE 0 // default layer
#define _SYMB 1 // symbols
#define _NAVI 2 // media keys
#define _SUPR 12

// I should try to understand QMK better
enum custom_keycodes {
  BASE = SAFE_RANGE,
  SYMB,
  NAVI,
  SUPR,
  REGR,
  HALS,
};

#define KC_SHMN MT(MOD_LSFT, NO_MINS)
#define KC_SHCM MT(MOD_RSFT, KC_COMM)
#define KC_BASE TT(_BASE)
#define KC_SYMB TT(_SYMB)
#define KC_NAVI TT(_NAVI)
#define KC_WSPC GUI_T(KC_SPC)

#define KC_LTNV LT(_NAVI, KC_BSPC)
#define KC_LTSM LT(_SYMB, KC_SPC)

#define KC_LGU1 LGUI(KC_1)
#define KC_LGU2 LGUI(KC_2)
#define KC_LGU3 LGUI(KC_3)
#define KC_LGU4 LGUI(KC_4)
#define KC_LGU5 LGUI(KC_5)
#define KC_LGU6 LGUI(KC_6)
#define KC_LGU7 LGUI(KC_7)
#define KC_LGU8 LGUI(KC_8)
#define KC_LGU9 LGUI(KC_9)
#define KC_LGU0 LGUI(KC_0)

#define KC_GLFT LGUI(KC_LEFT)
#define KC_GRGT LGUI(KC_RIGHT)
#define KC_GDWN LGUI(KC_DOWN)
#define KC_GUP  LGUI(KC_UP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ergodox(
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_SYMB,
        NO_MINS, NO_AM,   NO_AE,   NO_OSLH, KC_P,   KC_Y,   NO_SCLN,
        KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,   KC_I,
        KC_LSFT, KC_DOT,  KC_Q,    KC_J,    KC_K,   KC_X,   KC_TAB,
        KC_DEL,  KC_RALT, KC_APP,  KC_NAVI, KC_LGUI,

                 KC_COPY,  KC_PSTE,
                           KC_HOME,
        KC_LTNV, KC_LCTRL, KC_END,

        // right hand
        KC_NAVI,   KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     NO_GRV,
        NO_SLSH,   KC_F,    KC_G,    KC_C,    KC_R,     KC_L,     KC_COMM,
                   KC_D,    KC_H,    KC_T,    KC_N,     KC_S,     KC_ENTER,
        KC_ENTER,  KC_B,    KC_M,    KC_W,    KC_V,     KC_Z,     KC_RSFT,
                            KC_RGUI, KC_SYMB, NO_MINS,  NO_MINS,  KC_ESC,

        KC_PGUP, KC_RALT,
        KC_PGDN,
        KC_NAVI, KC_LALT, KC_LTSM
                  ),

// SYMBOLS
[_SYMB] = LAYOUT_ergodox(
       // left hand
       RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       XXXXXXX, NO_LCBR, NO_RCBR, NO_LBRC, NO_RBRC, NO_DLR,  XXXXXXX,
       _______, NO_SCLN, NO_SLSH, NO_LPRN, NO_RPRN, NO_PIPE,
       _______, NO_COLN, NO_EQL,  NO_AT,   KC_EXLM, NO_BSLS, XXXXXXX,
       _______, XXXXXXX, KC_PGUP, KC_PGDN, _______,
       _______, _______,
       _______,
       KC_DEL,  _______, _______,

       // right hand
       _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       XXXXXXX, NO_QUO2, NO_QUES, NO_AMPR, NO_LESS, NO_GRTR, KC_F12,
                NO_HASH, NO_TILD, NO_EURO, NO_QUOT, NO_GRV,  _______,
       XXXXXXX, KC_PERC, NO_CIRC, XXXXXXX, XXXXXXX, NO_ACUT, _______,
                         _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, _______,
       _______,
       _______, _______, _______
                ),

[_NAVI] = LAYOUT_ergodox(
       XXXXXXX, HALS,    REGR,    XXXXXXX, XXXXXXX, XXXXXXX, _______,
       XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, XXXXXXX,
       XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,
       XXXXXXX, KC_MSEL, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX,  KC_PGUP, KC_7,    KC_8,    KC_9,    NO_ASTR, XXXXXXX,
                 KC_PGDN, KC_4,    KC_5,    KC_6,    NO_PLUS, _______,
       XXXXXXX,  XXXXXXX, KC_1,    KC_2,    KC_3,    NO_SLSH, XXXXXXX,
                          _______, KC_0,    KC_COMM, NO_EQL,  XXXXXXX,
       _______, _______,
       _______,
       _______, _______, _______
                ),

[_SUPR] = LAYOUT_ergodox(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
       XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, XXXXXXX,
       XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,
       KC_LSFT, KC_MSEL, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_GLFT, KC_GDWN, KC_GUP,  KC_GRGT, _______,
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
       _______, _______,
       _______,
       _______, _______, _______
                ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case BASE:
    if (record->event.pressed) {
      persistent_default_layer_set(1UL<<_BASE);
    }
    return false;
    break;
  case SYMB:
    if (record->event.pressed) {
      layer_on(_SYMB);
      update_tri_layer(_SYMB, _NAVI, _SUPR);
    } else {
      layer_off(_SYMB);
      update_tri_layer(_SYMB, _NAVI, _SUPR);
    }
    return false;
    break;
  case NAVI:
    if (record->event.pressed) {
      layer_on(_NAVI);
      update_tri_layer(_SYMB, _NAVI, _SUPR);
    } else {
      layer_off(_NAVI);
      update_tri_layer(_SYMB, _NAVI, _SUPR);
    }
    return false;
    break;
  case HALS:
    if (record->event.pressed) {
      SEND_STRING("H'lsningar,\nOscar Carlsson\nLKAB IT applikationsdriften\n");
    }
    break;
  case REGR:
    if (record->event.pressed) {
      SEND_STRING("Regards,\nOscar Carlsson\nLKAB IT application operations\n");
    }
    break;
  }
  return true;
}
