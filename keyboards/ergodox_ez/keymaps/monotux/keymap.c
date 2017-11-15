#include "ergodox_ez.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NAVI 2 // media keys
#define QWRT 3 // gam...qwerty layer

#define KC_SHMN MT(MOD_LSFT, NO_MINS)
#define KC_SHCM MT(MOD_RSFT, KC_COMM)
#define KC_BASE TT(BASE)
#define KC_SYMB TT(SYMB)
#define KC_NAVI TT(NAVI)
#define KC_QWRT TT(QWRT)
#define KC_WSPC GUI_T(KC_SPC)

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 3
//#define PERMISSIVE_HOLD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   /    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   .    |   Å  |   Ä  |   Ö  |   P  |   Y  |  L1  |           |  L1  |   F  |   G  |   C  |   R  |   L  |   ,    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | TAB    |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|   -    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  | LGui | Left | Right|                                       |  Up  | Down |   !  |   ?  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | Home |       | PgUp |  Esc   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 |Backsp| Ctrl |------|       |------|  Alt   | Space|
 *                                 |ace   |      | L1   |       | L2   |        |      |
 *                                 `--------------------'       `----------------------'
 */

// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_SYMB,
        KC_QWRT, NO_AA,   NO_AE,   NO_OSLH, KC_P,   KC_Y,   NO_SCLN,
        KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,   KC_I,
        KC_SHMN, KC_DOT,  KC_Q,    KC_J,    KC_K,   KC_X,   KC_TAB,
        KC_DEL,  KC_RALT, KC_APP,  KC_LGUI, KC_NAVI,

                 KC_COPY,  KC_PSTE,
                           KC_END,
        KC_BSPC, KC_LCTRL, KC_SYMB,

        // right hand
        KC_NAVI,   KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     NO_GRV,
        NO_SLSH,   KC_F,    KC_G,    KC_C,    KC_R,     KC_L,     TD(TD_QUOTE_DANCE),
                   KC_D,    KC_H,    KC_T,    KC_N,     KC_S,     KC_ENTER,
        KC_ENTER,  KC_B,    KC_M,    KC_W,    KC_V,     KC_Z,     KC_SHCM,
                            KC_SYMB, KC_RGUI, NO_MINS,  NO_MINS,  KC_ESC,

        KC_PGUP, KC_RALT,
        KC_PGDN,
        KC_NAVI, KC_LALT, KC_SPC
                  ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   {  |   }  |   [  |   ]  |   $  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   ;  |   /  |   (  |   )  |   |  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   =  |   @  |   !  |   \  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   ~  |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       XXXXXXX, NO_LCBR, NO_RCBR, NO_LBRC, NO_RBRC, NO_DLR,  XXXXXXX,
       _______, NO_SCLN, NO_SLSH, NO_LPRN, NO_RPRN, NO_PIPE,
       XXXXXXX, NO_COLN, NO_EQL,  NO_AT,   KC_EXLM, NO_BSLS, XXXXXXX,
       XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, _______,
       _______, _______,
       _______,
       _______, _______, KC_DEL,

       // right hand
       _______, KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,
       XXXXXXX, NO_QUO2, NO_QUES, NO_AMPR,  NO_LESS, NO_GRTR, KC_F12,
                NO_PND,  NO_CIRC, NO_EURO,  KC_BSLS, NO_TILD, _______,
       XXXXXXX, KC_PERC, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______,
                         _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
       _______, _______,
       _______,
       _______, _______, _______
                ),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[NAVI] = KEYMAP(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
       XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, XXXXXXX,
       XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,
       XXXXXXX, KC_MSEL, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX,  XXXXXXX, KC_7,    KC_8,    KC_9,    NO_ASTR, XXXXXXX,
                 XXXXXXX, KC_4,    KC_5,    KC_6,    NO_PLUS, _______,
       XXXXXXX,  XXXXXXX, KC_1,    KC_2,    KC_3,    NO_SLSH, XXXXXXX,
                          _______, KC_0,    KC_COMM, NO_EQL,  XXXXXXX,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
                ),

[QWRT] = KEYMAP(// left hand
                NO_EQL,  KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
                _______, KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   _______,
                KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
                KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
                KC_LCTRL, KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                ALT_T(KC_APP),  KC_LGUI,
                KC_HOME,
                KC_SPC,KC_LCTRL,KC_END,
                
                // right hand
                KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
                TG(SYMB),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                KC_H,   KC_J,  KC_K,   KC_L,   KC_NAVI,GUI_T(KC_QUOT),
                MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
                KC_LALT,        CTL_T(KC_ESC),
                KC_PGUP,
                KC_PGDN,KC_TAB, KC_ENT
                )
};


