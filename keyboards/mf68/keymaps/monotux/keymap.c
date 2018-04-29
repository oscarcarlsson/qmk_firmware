#include "mf68.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

#define _SVORAK 0
#define _SVORA5 1
#define _LFUNC2 2
#define KC_X0 LT(_FN2, KC_GRV)
#define KC_A5 MO(_SVORA5)
#define KC_X2 BL_STEP

// Common puncation
#define KC_NMNS NO_MINS
#define KC_NQU2 NO_QUO2
#define KC_NQUO NO_QUOT
#define KC_NCOM KC_COMM
#define KC_UMLT NO_UMLT

#define KC_NLBR NO_LBRC
#define KC_NRBR NO_RBRC

#define KC_NCLB NO_LCBR
#define KC_NCRB NO_RCBR

#define KC_NPIP NO_PIPE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_SVORAK] = KEYMAP(KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_NMNS,KC_EQL ,KC_BSPC,KC_HOME,KC_PGUP,
                     KC_TAB , NO_AM , NO_AE ,NO_OSLH, KC_P  , KC_Y  , KC_F  , KC_G  , KC_C  , KC_R  , KC_L  ,KC_NCOM,KC_UMLT,KC_NQUO,KC_END ,KC_PGDN,
                     KC_LCTL, KC_A  , KC_O  , KC_E  , KC_U  , KC_I  , KC_D  , KC_H  , KC_T  , KC_N  , KC_S  ,KC_NMNS,KC_ENT ,
                     KC_LSFT, KC_DOT, KC_Q  , KC_J  , KC_K  , KC_X  , KC_B  , KC_M  , KC_W  , KC_V  , KC_Z  ,KC_RSFT, KC_UP ,
                     KC_RCTL,KC_LGUI,KC_LALT,KC_SPC , KC_A5 ,KC_RALT,KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT),

  [_SVORA5] = KEYMAP( RESET , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,KC_DEL ,KC_INS ,KC_VOLU,
                     KC_TRNS,NO_LCBR,NO_RCBR,NO_LBRC,NO_RBRC,NO_DLR ,NO_QUO2,NO_QUES,NO_AMPR,NO_GRTR,NO_LESS,KC_TRNS,KC_TRNS,KC_TRNS,KC_DEL ,KC_VOLD,
                     KC_CAPS,NO_SCLN,NO_SLSH,NO_LPRN,NO_RPRN,NO_PIPE,NO_HASH,NO_CIRC,NO_TILD,NO_QUOT,NO_GRV ,KC_TRNS,KC_TRNS,
                     KC_TRNS,KC_TRNS,NO_EQL , NO_AT ,NO_EXCL,NO_BSLS,NO_PERC, KC_NO , KC_NO , KC_NO ,NO_ACUT,KC_TRNS,KC_MUTE,
                     KC_TRNS,KC_TRNS,KC_TRNS,KC_BSPC ,KC_TRNS,KC_TRNS,KC_TRNS,KC_MPRV,KC_MPLY,KC_MNXT),

  // Make this a qwerty layer later, accessible using a dual layer or similar?
  [_LFUNC2] = KEYMAP(KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MUTE,
                     KC_TRNS,KC_TRNS,KC_TRNS,KC_SPC ,KC_TRNS,KC_TRNS,KC_TRNS,KC_MPRV,KC_MPLY,KC_MNXT)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    } else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};
