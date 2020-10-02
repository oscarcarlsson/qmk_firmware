#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

#include "keymap_nordic.h"
#include "keymap_swedish.h"

#define _DEFAULT 0
#define _LOWER 1
#define _NAVI 2
#define _QWERTY 16

// I should try to understand QMK better
enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  LOWER,
  NAVI,
  QWERTY,
};

#define _______ KC_TRNS

// Shift on hold, comma / dash upon tap
#define KC_SHMN MT(MOD_LSFT, NO_MINS)
#define KC_SHCM MT(MOD_RSFT, KC_COMM)

// TODO: Make these tap toggleable
#define KC_LOWR LOWER
#define KC_RASE NAVI
#define KC_REST RESET
#define KC_QWRT QWERTY
#define KC_DEFT TO(_DEFAULT)

// TODO: Too lazy to fix these names
#define KC_BSCT ALT_T(KC_SPC)
#define KC_SPAL CTL_T(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = KEYMAP(KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_BSPC,
                      KC_RASE, NO_AM,   NO_AE,   NO_OSLH, KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,     KC_L,    KC_COMM,
                      KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,     KC_S,    KC_ENTER,
                      KC_SHMN, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_SPAL, KC_BSCT, KC_B,    KC_M,    KC_W,    KC_V,     KC_Z,    KC_SHCM,
                                                          KC_LCTL, KC_LGUI, KC_SPAL, KC_BSCT, KC_LOWR, KC_RASE),

  // The Svorak A5 layer, but slightly adapted for my needs
  [_LOWER] = KEYMAP(KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
                    KC_QWRT, NO_LCBR, NO_RCBR, NO_LBRC, NO_RBRC, NO_DLR,                    NO_QUO2, NO_QUES, NO_AMPR,  NO_LESS, NO_GRTR, _______,
                    _______, NO_SCLN, NO_SLSH, NO_LPRN, NO_RPRN, NO_PIPE,                   NO_PND,  NO_CIRC, NO_EURO,  KC_BSLS, NO_TILD, _______,
                    _______, NO_COLN, NO_EQL,  NO_AT,   KC_EXLM, NO_BSLS, _______, KC_WBAK, KC_PERC, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______,
                                                        _______, _______, _______, KC_WBAK, _______, _______),

  [_NAVI] = KEYMAP(_______, _______, _______, _______, _______, _______,                   KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PAST, _______,
                   _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
                   _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   _______, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______,
                   _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_P0,   KC_PCMM, KC_PEQL, _______,
                                                       _______, _______, _______, _______, _______, _______),

  // Qwerty layout for dat gaming
  [_QWERTY] = KC_KEYMAP(ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
                        TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,DEL ,
                        RASE, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
                        LSFT, Z  , X  , C  , V  , B  ,SPC ,     ENT , N  , M  ,COMM,DOT ,SLSH,RSFT,
                        Z,LCTL,SPC ,     ENT ,LGUI,DEFT)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// I should really understand what this does at some point
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DEFAULT:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DEFAULT);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _NAVI, _QWERTY);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _NAVI, _QWERTY);
      }
      return false;
      break;
    case NAVI:
      if (record->event.pressed) {
        layer_on(_NAVI);
        update_tri_layer(_LOWER, _NAVI, _QWERTY);
      } else {
        layer_off(_NAVI);
        update_tri_layer(_LOWER, _NAVI, _QWERTY);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        layer_on(_QWERTY);
      } else {
        layer_off(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
