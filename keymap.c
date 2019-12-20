/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_steno.h"


#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion
#define STENO 3 // numbers/motion
#define MOVE 4 // numbers/motion


/*
*
*
*   This section down underneath is for a trial run of steno
*
*

#define ST_GEM  QK_STENO_GEMINI

*/

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  BCSP  |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |  D   |   F  |   G  | ' "  |           |  ' " |   H  |   J  |   K  |   L  | ;  : |  ENTER |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | RShift |   Z  |   X  |   C  |   V  |   B  | BCSP |           |  DEL |   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .-----------.   .-----.
 *                    | ENTER    |   |L4/ENTR|                                 | L1/SPACE  |   |ENTR |
 *                    '----------'   '-------'                                 `-----------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        | ESC   |                      | TAB   |
 *                                 ,------|-------|                      |-------|--------.
 *                                 | L1/  | BACK  |                      | L2/   | SPACE/  |
 *                                 | ENTER| SPACE |                      | SPACE |  SHIFT  |
 *                                 |      |       |                      |       |         |
 *                                 `--------------'                      `-----------------'
 *
*
*
 KC_RSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC, KC_ESC, KC_TAB, KC_DEL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS, 
 */

[BASE] = LAYOUT_gergo(
    KC_TAB,       KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                                      KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_BSPC,
    MT(MOD_LCTL, KC_BSPC),  KC_A,  KC_S,   KC_D,   KC_F, KC_G, KC_QUOT,                                   KC_QUOT,  KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, KC_PENT,
    KC_RSFT,                KC_Z,  KC_X,   KC_C,   KC_V, KC_B, KC_BSPC, KC_ESC,                       KC_TAB, KC_DEL,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
                                KC_PENT, LT(4,KC_ENT), LT(1,KC_ENT), KC_BSPC,                        LT(2,KC_SPC), MT( MOD_LSFT, KC_SPACE), LT(1,KC_SPC), KC_PENT

    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  7   |  8   |  9   |  (   |  < , |                         |  > . |   )  |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  4   |  5   |  6   |  -   |  ?   | DEL  |           | DEL  |  !   |  _   |      |      |      |  ENTER |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |    0   |  1   |  2   |  3   |  :   |      | BCSP |           | BCSP |   &  |  : ; |      |      |      |NKRO OFF|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     | NKRO  |      |
 *                                 |      |       |                     |   ON  |      |
 *                                 `--------------'                     `--------------' 
 * 
 * 
 * (KC_NO, KC_P7, KC_P8, KC_P9, KC_LPRN, KC_COMM, KC_DOT, KC_RPRN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_QUES, KC_DEL, KC_DEL, KC_EXLM, KC_UNDS, KC_NO, KC_NO, KC_NO, KC_PENT, KC_P0, KC_P1, KC_P2, KC_P3, KC_COLN, KC_NO, KC_BSPC, KC_NO, KC_NO, KC_BSPC, KC_AMPR, KC_SCLN, KC_NO, KC_NO, KC_NO, MAGIC_UNHOST_NKRO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, MAGIC_HOST_NKRO, KC_NO, KC_NO, KC_NO)
 * 
 * 
 * 
 */
[SYMB] = LAYOUT_gergo(  
    KC_NO, KC_P7, KC_P8, KC_P9, KC_LPRN, KC_COMM,                                               KC_DOT, KC_RPRN, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_QUES, KC_DEL,                               KC_DEL, KC_EXLM, KC_UNDS, KC_NO, KC_NO, KC_NO, KC_PENT,
     KC_P0, KC_P1, KC_P2, KC_P3, KC_COLN, KC_NO, KC_BSPC, KC_NO,                 KC_NO, KC_BSPC, KC_AMPR, KC_SCLN, KC_NO, KC_NO, KC_NO, MAGIC_UNHOST_NKRO,
                                   KC_NO, KC_TRNS, KC_TRNS,KC_NO,                  MAGIC_HOST_NKRO, KC_NO, KC_NO, KC_NO
     
    ),

/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  1 ! |  2 @ |  3 # |  4 $ |  5 % |                         |  6 ^ |  7 & |  8 * |  9 ( |  0 ) | TO [3] |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  F1  | F2   | F3   | F4   | F5   | F6   |           |      | LEFT | DOWN |  UP  | RIGHT|VolDn | VolUp  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  F7  | F8   | F9   | F10  | F11  | F12  |           |      | MLFT | MDWN | MUP  | MRGHT|Ply/Pa|  Skip  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 * 
 * 
 *  KC_UP, KC_RGHT, KC_VOLD, KC_VOLU, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 * 
 */
[NUMB] = LAYOUT_gergo(
    KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TO(3),
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_TRNS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,     KC_TRNS, KC_TRNS,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MPLY, KC_MNXT,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),


/* Keymap 3:ENGLISH STENOGRAPHY
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |  TO[0] |      |      |      |      |SPACE |                         |ENTER |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |   S  |  S   |   T  |  P   |   H  |   *  |           |  *   |   F  |  P   |  L   |   T  |   D  |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |   S  |  S   |   K  |  W   |   R  |   *  |           |  *   |   R  |  B   |  G   |   P  |  Z   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |  BCSP |       |  DEL  |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |  A   |  O    |       |  E    |   U  |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 * 
 */

[STENO] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, STN_S1, STN_S1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),



/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |  s    |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 * 
 */

[MOVE] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, STN_N1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};





// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};