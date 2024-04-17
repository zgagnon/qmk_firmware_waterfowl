/* Default.nix */
/* :PROPERTIES: */
/* :header-args: :tangle keymap.c :comments org */
/* :END: */

/* Thanks CyanDuck!! */

/* Copyright 2022  CyanDuck
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include QMK_KEYBOARD_H

/* Layers */
/* Create the layers we well use. The layers are: */
/* - Base layer for mac */
/* - Base layer for linux */
/* - Base layer for windows */
/* - Supershift (symbols) */
/* - DeShift (numbers and arrow) */
/* - Function Keys */
/* - Window Management */

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK,
    _COLELINX,
    _SUSHIFT,
    _DESHIFT,
    _FUNC,
    _SPOON,
};

/* Custom Keycodes */
/* Custom keycodes for various arrows, useful in programming */

enum custom_keycodes {
    QK_RARO = SAFE_RANGE,
    QK_LARO,
    QK_EARO,
    QK_LEQU,
    QK_GEQU,
    QK_SHRUGGIE,
    QK_ELXPIP,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_RARO:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case QK_LARO:
            if (record->event.pressed) {
                SEND_STRING("<-");
            }
            break;
        case QK_EARO:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
        case QK_LEQU:
            if (record->event.pressed) {
                SEND_STRING("<=");
            }
            break;
        case QK_GEQU:
            if (record->event.pressed) {
                SEND_STRING(">=");
            }
            break;
        case QK_ELXPIP:
            if (record->event.pressed) {
                SEND_STRING("|>");
            }
            break;
    }
    return true;
}

/* Combo Keys */
/* Add a combo for accessing the function keys */



const uint16_t PROGMEM function_keys[] = {KC_LSFT, KC_ESC, COMBO_END};

combo_t key_combos[] = {
    COMBO(function_keys, MO(_FUNC)),
};

/* Layers */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLMAK (Mac Base) */

/* | 1L | 2L | 3L | 4L      | 5L      | L Roller | R Roller   | 1R    | 2R     | 3R | 4R | 5R | */
/* | Q  | W  | F  | P       | G       | -        | -          | J     | L      | U  | Y  | "  | */
/* | A  | R  | S  | T       | D       | -        | -          | H     | N      | E  | I  | O  | */
/* | Z  | X  | C  | V       | B       | ESC      | Screenshot | K     | M      | ,  | .  | :  | */
/* |    | 1  |    | SuShift | DeShift | Shift    | Enter      | Space | Escape |    | 4  |    | */




    [_COLEMAK] = LAYOUT(
      KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT,
      MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_R), MT(MOD_LCTL, KC_S), KC_T, KC_D, KC_H, MT(MOD_LSFT, KC_N), MT(MOD_LCTL, KC_E), KC_I, MT(MOD_LGUI, KC_O),
      KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SCLN,
      KC_1, MO(_SUSHIFT), LT(_DESHIFT, KC_BSPC), KC_LSFT, KC_ESC, LGUI(LCTL(LSFT(KC_4))), KC_ENT, LT(_SPOON, KC_SPC), KC_ESC, KC_4),

/* Super Shift */

/* A layer for all the symbols. Includes commonly used arrows */
/* | 1L | 2L | 3L | 4L      | 5L        | L Roller | R Roller | 1R        | 2R      | 3R          | 4R | 5R | */
/* | %  | @  | [  | ]       | \         | -        | -        | /         | <-      | ->          | ^  | -  | */
/* | #  | !  | (  | )       | \pipe     | -        | -        | =         | < =     | equal arrow | >= | +  | */
/* | $  | -  | {  | }       | &         | CAPS     | Numlock  | 0         | ~       | `           | ?  | *  | */
/* | -  | 1  | -  | Colmack | Backspace | Shift    | -        | Backspace | Raycast | -           | 4  | -  | */


    [_SUSHIFT] = LAYOUT(
      KC_PERC, KC_AT, KC_LBRC, KC_RBRC, KC_BSLS, KC_SLSH, QK_LARO, QK_RARO, KC_CIRC, KC_MINS,
      KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_PIPE, KC_EQL, QK_LEQU, QK_EARO, QK_GEQU, KC_PLUS,
      KC_DLR, KC_NO, KC_LCBR, KC_RCBR, KC_AMPR, KC_0, KC_TILD, KC_GRV, KC_QUES, KC_ASTR,
      KC_1, TO(_COLEMAK), KC_BSPC, KC_LSFT, KC_CAPS, KC_NUM, KC_NO, KC_BSPC, LGUI(KC_F2), KC_4),

/* DeShift */
/* Contains arrow keys and numbers */
/* | 1L      | 2L      | 3L   | 4L        | 5L    | L Roller  | R Roller | 1R          |        2R | 3R | 4R | 5R            | */
/* | Home    | Page Up | Up   | Page Down | -     | -         | -        | Elixir Pipe |         7 |  8 |  9 | Constant Mode | */
/* | Command | Left    | Down | Right     | End   | -         | -        | _           |         4 |  5 |  6 | -             | */
/* | -       | Cut     | Copy | Paste     | CW    | Caps Lock | Num Lock | 0           |         1 |  2 |  3 | -             | */
/* | -       | 1       | -    | Colmak    | Space | Shift     | Enter    | Tab         | Functions |  - |  4 | -             | */



    [_DESHIFT] = LAYOUT(
      KC_HOME, KC_PGUP, KC_UP, KC_PGDN, KC_NO, QK_ELXPIP, KC_7, KC_8, KC_9, QK_CAPS_WORD_TOGGLE,
      MOD_LGUI, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_UNDS, KC_4, KC_5, KC_6, KC_NO,
      KC_NO, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), CW_TOGG, KC_0, KC_1, KC_2, KC_3, KC_NO,
      KC_1, TO(_COLEMAK), LT(1, KC_SPC), KC_LSFT, KC_CAPS, KC_NUM, KC_TAB, KC_TAB, TO(_FUNC), KC_4),

/* Function Key Layer */
/* Contains an expanded functions key set (some cobol screens go up to F-23) */
/* | 1L    | 2L  | 3L  | 4L      | 5L      | L Roller  | R Roller | 1R    | 2R     | 3R  | 4R  | 5R  | */
/* | -     | F16 | F17 | F18     | -       | -         | -        | F3    | F6     | F9  | F12 | F15 | */
/* | ALT   | -   | -   | -       | -       | -         | -        | F2    | F5     | F8  | F11 | F14 | */
/* | Reset | -   | -   | -       | -       | Caps Lock | Num Lock | F1    | F7     | F10 | F13 | -   | */
/* |       | 1   |     | SuShift | DeShift | Shift     | Enter    | Space | Escape |     | 4   |     | */


    [_FUNC] = LAYOUT(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F11,
      KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F12,
      QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_F13,
      KC_1, TO(_COLEMAK), LT(1, KC_SPC), KC_ESC, KC_CAPS, KC_NUM, KC_ENT, KC_BSPC, LT(2, KC_ENT), KC_4),

/* PaperWM Layer */
/* Controlling windows in a tiling window manager */
/* | 1L | 2L        | 3L        | 4L         | 5L | L Roller | R Roller | 1R       | 2R         | 3R         | 4R          | 5R             | */
/* | -  | -         | swap up   | -          | -  | -        | -        | suck in  |            | Focus up   |             | to main screen | */
/* |    | swap left | swap down | swap right |    |          |          | barf out | Focus left | Focus Down | Focus right | to laptop      | */
/* |    |           |           |            |    |          |          | Center   | fullscreen | wider      | taller      | to side screen | */


    [_SPOON] = LAYOUT(
      KC_NO, KC_NO, LGUI(LCTL(LALT(LSFT(KC_UP)))), KC_NO, KC_NO,
      LGUI(LCTL(LALT(KC_I))), LGUI(LCTL(LALT(KC_COMMA))), LGUI(LCTL(LALT(KC_UP))), LGUI(LCTL(LALT(KC_DOT))), LGUI(LCTL(LALT(LSFT(KC_1)))),
      KC_NO, LGUI(LCTL(LALT(LSFT(KC_LEFT)))), LGUI(LCTL(LALT(LSFT(KC_DOWN)))), LGUI(LCTL(LALT(LSFT(KC_RIGHT)))), KC_NO,
      LGUI(LCTL(LALT(KC_O))), LGUI(LCTL(LALT(KC_LEFT))), LGUI(LCTL(LALT(KC_DOWN))), LGUI(LCTL(LALT(KC_RIGHT))), LGUI(LCTL(LALT(LSFT(KC_2)))),
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      LGUI(LCTL(LALT(KC_C))), LGUI(LCTL(LALT(KC_F))), LGUI(LCTL(LALT(KC_R))), LGUI(LCTL(LALT(LSFT(KC_R)))), LGUI(LCTL(LALT(LSFT(KC_3)))),
      KC_1, TO(_COLEMAK), LT(1, KC_SPC), KC_ESC, KC_CAPS, KC_NUM, KC_ENT, KC_BSPC, LT(2, KC_ENT), KC_4),
};
