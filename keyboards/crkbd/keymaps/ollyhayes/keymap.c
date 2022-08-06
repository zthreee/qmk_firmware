/* Copyright 2022 Olly Hayes (@ollyhayes)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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
#include "ollyhayes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
// +------------+------+------+---------+----------+---------+--------+----------+---------+--------+---------+---------+
     KC_ESC  , KC_Q , KC_W , KC_F    , KC_P     , KC_G    , KC_J   , KC_L     , KC_U    , KC_Y   , KC_SCLN , KC_BSPC ,
     KC_LGUI , KC_A , KC_R , KC_S    , KC_T     , KC_D    , KC_H   , KC_N     , KC_E    , KC_I   , KC_O    , KC_NUHS  ,
     KC_LSFT , KC_Z , KC_X , KC_C    , KC_V     , KC_B    , KC_K   , KC_M     , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT ,
                                KC_LCTL , NAV_SWITCH , KC_TAB , NUM_SWITCH , MO(PUNC) , KC_DEL
// +------------+------+------+---------+----------+---------+--------+----------+---------+--------+---------+---------+
  ),

  [QWERTY] = LAYOUT_split_3x6_3(
// +---------+------+------+---------+---------+---------+---------+---------+---------+--------+---------+---------+
     KC_TRNS , KC_Q , KC_W , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O   , KC_P    , KC_TRNS ,
     KC_TRNS , KC_A , KC_S , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_TRNS ,
     KC_TRNS , KC_Z , KC_X , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_TRNS ,
                             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
// +---------+------+------+---------+---------+---------+---------+---------+---------+--------+---------+---------+
  ),

  [GAMES] = LAYOUT_split_3x6_3(
//  +---------+------+------+---------+---------+----------+---------+---------+---------+--------+---------+---------+
	  KC_TRNS , KC_Q , KC_W , KC_E    , KC_R    , KC_T     , KC_Y    , KC_U    , KC_I    , KC_O   , KC_P    , KC_TRNS ,
	  KC_TRNS , KC_A , KC_S , KC_D    , KC_F    , KC_G     , KC_H    , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_TRNS ,
	  KC_TRNS , KC_Z , KC_X , KC_C    , KC_V    , KC_B     , KC_N    , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_TRNS ,
							  KC_TRNS , KC_LALT , KC_SPACE , MO(ARR) , KC_TRNS , KC_TRNS
//  +---------+------+------+---------+---------+----------+---------+---------+---------+--------+---------+---------+
  ),

  [NUM] = LAYOUT_split_3x6_3(
//  +---------+---------------+------+--------+---------+-----------+-----------+------+--------+------+---------+---------+
	  KC_TRNS , KC_1          , KC_2   , KC_3   , KC_4    , KC_5        , KC_6      , KC_7    , KC_8      , KC_9    , KC_0    , KC_TRNS ,
	  KC_TRNS , MO(MEDIA)     , KC_NO  , KC_NO  , KC_NO   , KC_NO       , KC_NO     , KC_NO   , KC_NO     , KC_NO   , KC_NO   , KC_TRNS ,
	  KC_TRNS , MO(FUNCTIONS) , KC_NO  , KC_NO  , KC_NO   , KC_NO       , KC_NO     , KC_NO   , KC_TRNS   , KC_TRNS   , KC_TRNS   , KC_TRNS ,
									   KC_TRNS  , KC_TRNS , KC_TAB      , KC_TRNS   , KC_TRNS , KC_TRNS
//  +---------+---------------+------+--------+---------+-----------+-----------+------+--------+------+---------+---------+
  ),

  [FUNCTIONS] = LAYOUT_split_3x6_3(
//  +---------------+---------+---------+---------+---------+---------+---------+---------+---------+-------+---------+---------+
	  KC_TRNS       , KC_F1 , KC_F2    , KC_F3    , KC_F4   , KC_F5   , KC_F6  , KC_F7   , KC_F8   , KC_F9 , KC_F10  , KC_F11 ,
	  TG(FUNCTIONS) , KC_F12, KC_F13   , KC_F14   , KC_F15  , KC_NO   , KC_NO  , KC_NO   , KC_NO   , KC_NO , KC_TRNS , KC_TRNS ,
	  KC_TRNS       , KC_NO , KC_NO    , KC_NO    , KC_NO   , KC_NO   , KC_NO  , KC_NO   , KC_NO   , DF(BASE) , DF(GAMES) , DF(QWERTY) ,
										  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS, KC_TRNS , KC_TRNS
//  +---------------+---------+---------+---------+---------+---------+---------+---------+---------+-------+---------+---------+
  ),

  [ARR] = LAYOUT_split_3x6_3(
//  +---------+---------+-----------+---------+---------+------------+-----------+---------+---------+-----------+---------+---------+
	  KC_TRNS , KC_TRNS , KC_HOME   , KC_PGUP , KC_PGDN , KC_END     , KC_HOME   , KC_PGDN , KC_PGUP , KC_END    , KC_TRNS , KC_TRNS ,
	  KC_ENT  , KC_DEL  , KC_LEFT   , KC_UP   , KC_DOWN , KC_RGHT    , KC_LEFT   , KC_DOWN , KC_UP   , KC_RGHT   , KC_DEL  , KC_TRNS ,
	  KC_TRNS , KC_INS  , C(KC_LEFT), KC_LGUI , KC_LALT , C(KC_RGHT) , C(KC_LEFT), DOWN4   , UP4     , C(KC_RGHT), KC_INS  , KC_TRNS ,
								      KC_TRNS , KC_F12  , KC_TRNS    , KC_TRNS   , KC_F12  , KC_TRNS
//  +---------+---------+-----------+---------+---------+------------+-----------+---------+---------+-----------+---------+---------+
  ),

  [PUNC] = LAYOUT_split_3x6_3(
//  +---------+------------+-----------+-----------+-------------+------------+------------+-------------+------------+------------+-----------+---------+
	  ALTTAB  , S(KC_1)    , S(KC_2)   , S(KC_3)   , S(KC_4)     , S(KC_5)    , S(KC_6)    , S(KC_7)     , S(KC_8)    , S(KC_9)    , S(KC_0)   , KC_TRNS ,
	  KC_TRNS , S(KC_NUBS) , S(KC_GRV) , KC_LBRC   , S(KC_9)     , S(KC_LBRC) , S(KC_RBRC) , S(KC_0)     , S(KC_RBRC) , KC_MINS    , S(KC_EQL) , KC_TRNS ,
	  KC_TRNS , KC_NUBS    , KC_GRV    , KC_LGUI   , KC_LALT     , KC_NUHS    , S(KC_QUOT) , KC_LALT     , KC_LGUI    , S(KC_MINS) , KC_EQL    , KC_TRNS ,
										 KC_TRNS   , MO(DUBPUNC) , KC_MPLY    , KC_TRNS    , MO(DUBPUNC) , KC_TRNS
//  +---------+------------+-----------+-----------+-------------+------------+------------+-------------+------------+------------+-----------+---------+
  ),

  [MEDIA] = LAYOUT_split_3x6_3(
//  +------------+-----------+---------+---------+---------+----------------+----------------+---------+---------+---------+----------+---------+
	  RESET      , RGB_RMOD  , RGB_MOD , RGB_TOG , RGB_HUD , RGB_HUI        , RGB_HUD        , RGB_HUI , RGB_TOG , RGB_RMOD, RGB_MOD  , KC_SLEP ,
	  KC_TRNS    , KC_TRNS   , KC_TRNS , KC_VOLD , KC_VOLU , RGB_MODE_PLAIN , RGB_MODE_PLAIN , KC_VOLD , KC_VOLU , KC_TRNS , KC_TRNS  , KC_TRNS ,
	  KC_TRNS    , KC_TRNS   , RGB_VAD , RGB_VAI , RGB_SAD , RGB_SAI        , RGB_SAD        , RGB_SAI , RGB_VAD , RGB_VAI , KC_TRNS  , KC_TRNS ,
										 KC_TRNS , KC_TRNS , KC_TRNS        , KC_TRNS        , KC_TRNS , KC_TRNS
//  +------------+-----------+---------+---------+---------+----------------+----------------+---------+---------+---------+----------+---------+
  )
};

/*
[TEMPLATE] = LAYOUT_split_3x6_3(
//  +--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+
    KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      ,
    KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      ,
    KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      ,
                                                 KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS      , KC_TRNS
//  +--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+
),
*/
