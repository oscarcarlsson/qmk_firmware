#include "mf68.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

#define _SVORAK 0
#define _SVORA5 1
#define _NAVIG8 2
#define _DUALLR 3
#define _CONFIG 4
#define _QWERTY 5

enum custom_keycodes {
  SVORAK = SAFE_RANGE,
  SVORA5,
  NAVIG8,
  DUALLR,
  CONFIG,
  QWERTY,
};

#define KC_SVA5     SVORA5
#define KC_CONF OSL(_CONFIG)
#define KC_QWRT  TT(_QWERTY)
#define KC_DEFT  TO(_SVORAK)
#define KC_NAVI     NAVIG8
#define _______     KC_TRNS

// For the dual layer
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_SVORAK] = KEYMAP(KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,NO_PLUS,NO_ACUT,KC_BSPC,KC_HOME,KC_PGUP,
                     KC_TAB , NO_AM , NO_AE ,NO_OSLH, KC_P  , KC_Y  , KC_F  , KC_G  , KC_C  , KC_R  , KC_L  ,KC_COMM,NO_UMLT,NO_QUOT,KC_END ,KC_PGDN,
                     KC_LCTL, KC_A  , KC_O  , KC_E  , KC_U  , KC_I  , KC_D  , KC_H  , KC_T  , KC_N  , KC_S  ,NO_MINS,KC_ENT ,
                     KC_LSFT, KC_DOT, KC_Q  , KC_J  , KC_K  , KC_X  , KC_B  , KC_M  , KC_W  , KC_V  , KC_Z  ,KC_RSFT, KC_UP ,
                     KC_RCTL,KC_LGUI,KC_LALT,KC_SPC ,KC_SVA5,KC_NAVI,KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT),

  [_SVORA5] = KEYMAP(NO_HALF, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,KC_DEL ,KC_INS ,KC_VOLU,
                     _______,NO_LCBR,NO_RCBR,NO_LBRC,NO_RBRC,NO_DLR ,NO_QUO2,NO_QUES,NO_AMPR,NO_GRTR,NO_LESS,_______,_______,_______,KC_DEL ,KC_VOLD,
                     KC_CAPS,NO_SCLN,NO_SLSH,NO_LPRN,NO_RPRN,NO_PIPE,NO_HASH,NO_CIRC,NO_TILD,NO_QUOT,NO_GRV ,_______,_______,
                     _______,_______,NO_EQL , NO_AT ,NO_EXCL,NO_BSLS,NO_PERC,XXXXXXX,XXXXXXX,XXXXXXX,NO_ACUT,_______,KC_MUTE,
                     _______,KC_APP ,_______,KC_BSPC,_______,_______,_______,KC_MPRV,KC_MPLY,KC_MNXT),

  [_NAVIG8] = KEYMAP(XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_WBAK,XXXXXXX,XXXXXXX,
                     _______,KC_HOME, KC_UP ,KC_END ,KC_PGUP,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     _______,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     XXXXXXX,XXXXXXX,_______,XXXXXXX,_______,_______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX),

  [_DUALLR] = KEYMAP(KC_CONF,KC_LGU1,KC_LGU2,KC_LGU3,KC_LGU4,KC_LGU5,KC_LGU6,KC_LGU7,KC_LGU8,KC_LGU9,KC_LGU0,XXXXXXX,XXXXXXX, RESET ,XXXXXXX,XXXXXXX,
                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,_______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX),

  [_CONFIG] = KEYMAP(_______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     XXXXXXX,KC_QWRT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_DEFT,XXXXXXX,XXXXXXX,XXXXXXX),

  // Make this a qwerty layer later, accessible using a dual layer or similar?
  [_QWERTY] = KC_KEYMAP(ESC , 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,MINS,EQL ,BSPC,HOME,PGUP,
                        TAB , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,LBRC,RBRC,BSLS,END ,PGDN,
                        LCTL, A  , S  , D  , F  , G  , H  , J  , K  , L  ,SCLN,QUOT,ENT ,
                        LSFT, Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH,RSFT, UP ,
                        LCTL,LGUI,LALT, SPC,SVA5,RALT,DEFT,LEFT,DOWN,RGHT)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  case SVORAK:
    if (record->event.pressed) {
      persistent_default_layer_set(1UL<<_SVORAK);
    }
    return false;
    break;
  case SVORA5:
    if (record->event.pressed) {
      layer_on(_SVORA5);
      update_tri_layer(_SVORA5, _NAVIG8, _DUALLR);
    } else {
      layer_off(_SVORA5);
      update_tri_layer(_SVORA5, _NAVIG8, _DUALLR);
    }
    return false;
    break;
  case NAVIG8:
    if (record->event.pressed) {
      layer_on(_NAVIG8);
      update_tri_layer(_SVORA5, _NAVIG8, _DUALLR);
    } else {
      layer_off(_NAVIG8);
      update_tri_layer(_SVORA5, _NAVIG8, _DUALLR);
    }
    return false;
    break;
  }
  return true;
}
