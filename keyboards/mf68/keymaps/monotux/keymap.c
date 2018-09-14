#include "mf68.h"

#define _QWERTY 0
#define _FN1 1
#define KC_ KC_TRNS
#define KC_FN MO(_FN1)
#define KC_FS LT(_FN1, KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KC_KEYMAP(
 /*,----+----+----+----+----+----+----+----+----+----+----+----+----+--------.  ,----+----. */
    ESC , 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,MINS,EQL ,  BSPC  ,   HOME,PGUP,
 /*|----`----`----`----`----`----`----`----`----`----`----`----`----`--------|  |----`----| */
    TAB   , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,LBRC,RBRC, BSLS ,   END ,PGDN,
 /*|------`----`----`----`----`----`----`----`----`----`----`----`----`------|  `----`----' */
    LCTL   , A  , S  , D  , F  , G  , H  , J  , K  , L  ,SCLN,QUOT,    ENTER ,
 /*|-------`----`----`----`----`----`----`----`----`----`----`----`----------|  ,----. */
    LSFT     , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH,       RSFT  ,    UP ,
 /*|---------`----`----`----`----`----`----`----`----`----`----`-------------.--|----|----. */
    LCTL ,LGUI ,LALT ,            FS                ,  RALT, FN  ,RCTL ,    LEFT,DOWN,RGHT
 /*`-----+-----+-----+------------------------------+------+-----+-----'   `----+----+----' */
  ),

  [_FN1] = KC_KEYMAP(
 /*,----+----+----+----+----+----+----+----+----+----+----+----+----+--------.  ,----+----. */
    GRV , F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 , DELETE ,   INS ,VOLU,
 /*|esc-`-1--`-2--`-3--`-4--`-5--`-6--`-7--`-8--`-9--`-0--`mnus`plus`--bksp--|  |ins-`pgup| */
          ,    ,HOME, UP ,END ,    ,    ,    ,    ,    ,    ,    ,    ,      ,   DEL ,VOLD,
 /*|tab---`-q--`-w--`-e--`-r--`-t--`-y--`-u--`-i--`-o--`-p--`-{--`-}--`--|---|  `del-`pgdn' */
     CAPS  ,    ,LEFT,DOWN,RGHT,    ,    ,    ,    ,    ,    ,    ,          ,
 /*|caps---`-a--`-s--`-d--`-f--`-g--`-h--`-j--`-k--`-l--`-;--`-'--`----enter-|  ,----. */
             ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,             ,   MUTE,
 /*|shift----`-z--`-x--`-c--`-v--`-b--`-n--`-m--`-,--`-.--`-/--`-------shift-.--|-up-|----. */
         ,     ,     ,                              ,      ,     ,     ,    MPRV,MPLY,MNXT
 /*`ctrl-+-gui-+-alt-+----------space---------------+-fn---+-alt-+ctrl-'   `left+down+rght' */
  ),
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
