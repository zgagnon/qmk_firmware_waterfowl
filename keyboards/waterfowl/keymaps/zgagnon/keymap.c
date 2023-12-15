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

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK,
    _SYMNUM,
    _NAV,
    _FUNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _COLEMAK
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |                      |   J  |   L  |   U  |   Y  |   "  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |                      |   H  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  |ESC |    |SCRNST| |   K  |   M  |   ,  |   .  |   :  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   | NAV  | BS | SHIFT  |            |  ENT  | SPAC | TAB |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_COLEMAK] = LAYOUT(
	KC_Q,				KC_W,				KC_F,				KC_P,				KC_G,			KC_J,	KC_L,				KC_U,				KC_Y,				KC_QUOT,
	MT(MOD_LGUI, KC_A),	MT(MOD_LALT, KC_R),	MT(MOD_LCTL, KC_S),	MT(MOD_LSFT, KC_T),	KC_D,			KC_H,	MT(MOD_LSFT, KC_N),	MT(MOD_LCTL, KC_E),	MT(MOD_LALT, KC_I),	MT(MOD_LGUI, KC_O),
	KC_Z,				KC_X,				KC_C,				KC_V,				KC_B,			KC_K,	KC_M,				KC_COMM,			KC_DOT,				KC_SCLN,
	KC_1,				TG(_SYMNUM),		KC_BSPC,			KC_LSFT,			KC_ESC,		LGUI(LCTL(LSFT(KC_4))),	KC_ENT,				KC_SPC,				KC_TAB,		KC_4
),

/* _SYMNUM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   %  |   @  |   [  |   ]  |   \  |                      |   /  |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   #  |   !  |   (  |   )  |   |  |                      |   =  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   $  |   £  |   {  |   }  |   &  |  |CAPS |    |NUMLK|  |   0  |   1  |   2  |   3  |   *  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   | L1 |  BS    | SHIFT  |            |  NAV  | RC | FUNC  |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_SYMNUM] = LAYOUT(
	KC_PERC,	KC_AT,			KC_LBRC,		KC_RBRC,	KC_BSLS,			KC_SLSH,	KC_7,	KC_8,		KC_9,			KC_MINS,
	KC_HASH,	KC_EXLM,		KC_LPRN,		KC_RPRN,	KC_PIPE,			KC_EQL,		KC_4,	KC_5,		KC_6,			KC_PLUS,
	KC_DLR,		KC_NO,			KC_LCBR,		KC_RCBR,	KC_AMPR,			KC_0,		KC_1,	KC_2,		KC_3,			KC_ASTR,
	KC_1,		TO(_COLEMAK),	KC_BSPC,		KC_LSFT,	KC_CAPS,			KC_NUM,		TG(_NAV),LGUI(KC_F2),	TG(_FUNC),		KC_4
),

/* _NAV
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      | PgUp |  UP  | PgDn |      |                      |      |      |   ^  |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * | Home | Left | Down | Right| End  |                      |   _  |   '  |   "  |   ~  |   `  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |  CUT | COPY | PASTE|      |  |CAPS |    |NUMLK|  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   | L1  | SPACE | ESC  |            |  ENT  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_NAV] = LAYOUT(
	KC_NO,		KC_PGUP,		KC_UP,			KC_PGDN,	KC_NO,			KC_NO,		KC_NO,		KC_CIRC,	KC_NO,			KC_NO,
	KC_HOME,	KC_LEFT,		KC_DOWN,		KC_RGHT,	KC_END,			KC_UNDS,	KC_QUOT,	KC_DQT,		KC_TILD,		KC_GRV,
	KC_NO,		LGUI(KC_X),		LGUI(KC_C),		LGUI(KC_V),		KC_NO,			KC_NO,		KC_NO,		KC_NO,		KC_NO,			KC_NO,
	KC_1,		TO(_COLEMAK),	LT(1,KC_SPC),	KC_ESC,		KC_CAPS,		KC_NUM,		KC_ENT,		KC_BSPC,	LT(2,KC_ENT),	KC_4
),

/* FUNC
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      |      |  F7  |  F8  |  F9  |  F11 |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      |      |      |      |      |                      |      |  F4  |  F5  |  F6  |  F12 |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * | Reset|      |      |      |      |  |CAPS |    |NUMLK|  |  F10 |  F1  |  F2  |  F3  |  F13 |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   | L1 | SPACE | ESC  |            |  ENT  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_FUNC] =  LAYOUT(
	KC_NO,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_NO,	KC_F7,	KC_F8,		KC_F9,			KC_F11,
	KC_NO,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_NO,	KC_F4,	KC_F5,		KC_F6,			KC_F12,
	QK_BOOT,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_F10,	KC_F1,	KC_F2,		KC_F3,			KC_F13,
	KC_1,	TO(_COLEMAK),	LT(1,KC_SPC),	KC_ESC,	KC_CAPS,		KC_NUM,	KC_ENT,	KC_BSPC,	LT(2,KC_ENT),	KC_4
),
};
