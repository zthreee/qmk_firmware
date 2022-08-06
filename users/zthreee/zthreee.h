/* Copyright 2019 @ninjonas
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
#pragma once
#include "quantum.h"
#include "version.h"
#include "eeprom.h"
#include "process_records.h"
#include "tap_dances.h"

#ifdef ENCODER_ENABLE
bool left_encoder_rotated;
bool right_encoder_rotated;
uint16_t encoder_rotated_timer;
#endif

#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4
#define _NUM 5
#define _FUNC 6

// Shortcut Keys
#define K_LOCK LGUI(LCTL(KC_Q)) // Locks screen on MacOS
#define K_CSCN LGUI(LSFT(KC_2)) // Copy a portion of the screen to the clipboard
#define K_CPRF LGUI(LSFT(KC_M)) //  Cmd + Shift + M. Used for switching Google Chrome profiles
#define K_UNDERSCORE LSFT(KC_MINS)

// Layer Keys
#define LT_LOW LT(_LOWER, KC_BSPC)
#define LT_RAI LT(_RAISE, KC_SPC)
#define LT_NUM LT(_NUM, KC_ENT)
#define LT_FUNC LT(_FUNC, KC_ENT)

// Mod-Tap Keys
#define MT_EQL MT(MOD_RSFT, KC_EQL)

// Layout blocks
#define _____________________QWERTY_L1______________________ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T
#define _____________________QWERTY_L2______________________ T_GUI, KC_A, KC_S, KC_D, KC_F, KC_G
#define _____________________QWERTY_L3______________________ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B

#define _____________________QWERTY_R1______________________ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS
#define _____________________QWERTY_R2______________________ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT
#define _____________________QWERTY_R3______________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MT_EQL

#define _____________________COLEMAK_L1_____________________ KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B
#define _____________________COLEMAK_L2_____________________ T_GUI, KC_A, KC_R, KC_S, KC_T, KC_G
#define _____________________COLEMAK_L3_____________________ KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V

#define _____________________COLEMAK_R1_____________________ KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS
#define _____________________COLEMAK_R2_____________________ KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT
#define _____________________COLEMAK_R3_____________________ KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, MT_EQL

#define _____________________NUM_LEFT_______________________ T_GRV, KC_1, KC_2, KC_3, KC_4, KC_5
#define _____________________NUM_RIGHT______________________ KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS

#define _____________________FUNC_LEFT______________________ KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define _____________________FUNC_RIGHT_____________________ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12

#define _____________________SYM_LEFT_______________________ KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC
#define _____________________SYM_LEFT_2_____________________ XXXXXXX, KC_LT, KC_LBRC, KC_LCBR, KC_LPRN, KC_PMNS

#define _____________________SYM_RIGHT______________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS
#define _____________________SYM_RIGHT_2____________________ KC_PPLS, KC_RPRN, KC_RCBR, KC_RBRC, KC_GT, KC_UNDS

#define _____________________LOWER_L1_______________________ KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K_CSCN
#define _____________________LOWER_L2_______________________ T_GUI, KC_LALT, KC_LCTL, KC_LSFT,  XXXXXXX, XXXXXXX
#define _____________________LOWER_L3_______________________ KC_LSFT, U_UND, U_CUT, U_CPY, U_PST, U_RDO

#define _____________________LOWER_R1_______________________ U_RDO, U_PST, U_CPY, U_CUT, U_UND, XXXXXXX
#define _____________________LOWER_R2_______________________ LGUI(KC_LEFT), _______________NAV_1______________, LGUI(KC_RIGHT)
#define _____________________LOWER_R3_______________________ XXXXXXX, _______________NAV_2______________, KC_END

#define _____________________ADJUST_L1______________________ M_MAKE, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define _____________________ADJUST_L2______________________ M_VRSN, M_MALL, RGB_SPI, RGB_SAI, RGB_HUI, RGB_VAI
#define _____________________ADJUST_L3______________________ M_FLSH, XXXXXXX, RGB_SPD, RGB_SAD, RGB_HUD, RGB_VAD

#define _____________________ADJUST_R1______________________ RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, QWERTY
#define _____________________ADJUST_R2______________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _____________________ADJUST_R3______________________ RGB_MOD, RGB_RMOD, RGB_M_R, RGB_M_B, RGB_M_P, XXXXXXX

#define _______________NAV_1______________ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
#define _______________NAV_2______________ KC_HOME, KC_PGDN, KC_PGUP, KC_END

#define _____________MOUSE_1______________ KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_D
#define _____________MOUSE_2______________ KC_MS_L, KC_MS_D, KC_MS_R,KC_WH_U

#define __________________________________ _______, _______, _______, _______

#define _________MEDIA_1_________ KC_BRIU, KC_MPLY, KC_MUTE
#define _________MEDIA_2_________ KC_BRID, KC_MFFD, KC__VOLUP
#define _________MEDIA_3_________ XXXXXXX, KC_MRWD, KC__VOLDOWN

#define ________MOD_LEFT_________ LCTL_T(KC_ESC), LT_RAI, KC_TAB
#define ________MOD_RIGHT________ LT_FUNC, LT_LOW, RALT_T(KC_DEL)

#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

// Layout wrappers
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_ergodox_wrapper(...) LAYOUT_ergodox(__VA_ARGS__)
