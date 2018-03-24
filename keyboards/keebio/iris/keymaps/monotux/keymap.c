#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

#include "keymap_nordic.h"
#include "keymap_swedish.h"

#define _DEFAULT 0
#define _LOWER 1
#define _NAVI 2
#define _DUAL 3
#define _CONFIG 4
#define _QWERTY 16

// I should try to understand QMK better
enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  LOWER,
  NAVI,
  DUAL,
  CONFIG,
  QWERTY,
};

#define _______ KC_TRNS
#define KC_XXXX KC_NO
#define KC_____ KC_TRNS

// Shift on hold, comma / dash upon tap
#define KC_SHMN MT(MOD_LSFT, NO_MINS)
#define KC_SHCM MT(MOD_RSFT, KC_COMM)

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
#define KC_CONF OSL(_CONFIG)

// TODO: Make these tap toggleable
#define KC_LOWR LOWER
#define KC_RASE NAVI
#define KC_REST RESET
#define KC_QWRT TT(_QWERTY)
#define KC_DEFT TO(_DEFAULT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = KEYMAP(KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_DEL,
                      KC_LALT, NO_AM,   NO_AE,   NO_OSLH, KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,     KC_L,    NO_MINS,
                      KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,     KC_S,    KC_ENTER,
                      KC_SHMN, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_BSPC,  KC_SPC, KC_B,    KC_M,    KC_W,    KC_V,     KC_Z,    KC_SHCM,
                                                          KC_LCTL, KC_RASE, KC_BSPC,  KC_SPC, KC_LOWR, KC_RGUI),

  // The Svorak A5 layer, but slightly adapted for my needs
  [_LOWER] = KEYMAP(KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
                    KC_QWRT, NO_LCBR, NO_RCBR, NO_LBRC, NO_RBRC, NO_DLR,                    NO_QUO2, NO_QUES, NO_AMPR,  NO_LESS, NO_GRTR, XXXXXXX,
                    _______, NO_SCLN, NO_SLSH, NO_LPRN, NO_RPRN, NO_PIPE,                   NO_PND,  NO_CIRC, NO_EURO,  KC_BSLS, NO_TILD, _______,
                    _______, NO_COLN, NO_EQL,  NO_AT,   KC_EXLM, NO_BSLS, KC_DEL,  KC_WBAK, KC_PERC, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______,
                                                        _______, _______, KC_DEL,  KC_WBAK, _______, KC_LALT),

  [_NAVI] = KEYMAP(KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    NO_ASTR, KC_REST,
                   XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
                   _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______,
                   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, KC_P0,   KC_PCMM, KC_PEQL, _______,
                                                       _______, _______, _______, _______, _______, _______),

  [_DUAL] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     CONF,ACL0,ACL1,ACL2,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ____,XXXX,XXXX,XXXX,XXXX,WH_U,               XXXX,BTN1,MS_U,BTN2,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ____,XXXX,XXXX,XXXX,XXXX,WH_D,               XXXX,MS_L,MS_D,MS_R,XXXX,XXXX,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     ____,LGU1,LGU2,LGU3,LGU4,LGU5,XXXX,     XXXX,LGU6,LGU7,LGU8,LGU9,LGU0,____,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                         ____,____,____,     ____,____,____),
  //                    `----+----+----'     `----+----+----'


  [_CONFIG] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ____,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     QWRT,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XXXX,____,XXXX,        XXXX,____,XXXX
  //                  `----+----+----'        `----+----+----'
),

  // Qwerty layout for dat gaming
  [_QWERTY] = KC_KEYMAP(ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
                        XXXX, Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,DEL ,
                        TAB,  A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
                        LSFT, Z  , X  , C  , V  , B  ,SPC ,     ENT , N  , M  ,COMM,DOT ,SLSH,RSFT,
                        Z,  LCTL,SPC ,     ENT ,LGUI,DEFT),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// I should really understand what this does at some point
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  case DEFAULT:
    if (record->event.pressed) {
      persistent_default_layer_set(1UL<<_DEFAULT);
    }
    return false;
    break;
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _NAVI, _DUAL);
    } else {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _NAVI, _DUAL);
    }
    return false;
    break;
  case NAVI:
    if (record->event.pressed) {
      layer_on(_NAVI);
      update_tri_layer(_LOWER, _NAVI, _DUAL);
    } else {
      layer_off(_NAVI);
      update_tri_layer(_LOWER, _NAVI, _DUAL);
    }
    return false;
    break;
  }
  return true;
}
