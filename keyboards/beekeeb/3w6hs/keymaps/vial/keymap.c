/* Copyright 2021 weteor
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
#include "sm_td.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    // your code here

    return true;
}

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(KC_A, KC_LEFT_CTRL)
        SMTD_MT(KC_S, KC_LEFT_ALT)
        SMTD_MT(KC_D, KC_LSFT)
        SMTD_MT(KC_F, KC_LEFT_GUI)
        SMTD_MT(KC_J, KC_LEFT_GUI)
        SMTD_MT(KC_K, KC_LSFT)
        SMTD_MT(KC_L, KC_LEFT_ALT)
        SMTD_MT(KC_SEMICOLON, KC_LEFT_CTRL)
    }

    return SMTD_RESOLUTION_UNHANDLED;
}

enum layers
{
    _BASE = 0,
    _NUM,
    _SYM,
    _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,                KC_W,                KC_E,                KC_R,                KC_T,                                         KC_Y,      KC_U,             KC_I,            KC_O,      KC_P,  
        KC_A,                KC_S,                KC_D,                KC_F,                KC_G,                                         KC_H,      KC_J,             KC_K,            KC_L,      KC_SEMICOLON,
        KC_Z,                KC_X,                KC_C,                KC_V,                KC_B,                                         KC_N,      KC_M,             KC_COMM,         KC_DOT,    KC_NONUS_BACKSLASH,
                                                  XXXXXXX,             KC_SPC,              MO(_NUM),                                     MO(_SYM),  MO(_NAV),         XXXXXXX         
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        A(KC_Q),             S(KC_EQUAL),         S(KC_3),             S(KC_4),             S(KC_7),                                      KC_EQUAL,  S(KC_0),          S(KC_9),         A(KC_O),   A(KC_P),
        KC_1,                KC_2,                KC_3,                KC_4,                KC_5,                                         KC_6,      KC_7,             KC_8,            KC_9,      KC_0,
        S(KC_MINUS),         KC_MINUS,            S(KC_COMM),          S(KC_DOT),           S(KC_8),                                      S(KC_5),   S(KC_6),          A(KC_COMM),      A(KC_DOT), KC_SLASH,
                                                  XXXXXXX,             XXXXXXX,             XXXXXXX,                                      KC_MEH,    KC_HYPR,          XXXXXXX
    ),
    [_SYM] = LAYOUT_split_3x5_3(
        A(KC_Q),             S(KC_EQUAL),         S(KC_3),             S(KC_4),             S(KC_7),                                      KC_EQUAL,  S(KC_0),          S(KC_9),         A(KC_O),   A(KC_P),
        A(KC_A),             S(KC_SLASH),         S(KC_LEFT_BRACKET),  S(KC_RIGHT_BRACKET), S(KC_1),                                      A(KC_H),   KC_RIGHT_BRACKET, KC_LEFT_BRACKET, A(KC_L),   A(KC_SEMICOLON), 
        S(KC_MINUS),         KC_MINUS,            S(KC_COMM),          S(KC_DOT),           S(KC_8),                                      S(KC_5),   S(KC_6),          A(KC_COMM),      A(KC_DOT), KC_SLASH,
                                                  XXXXXXX,             KC_BACKSLASH,        S(KC_2),                                      XXXXXXX,   XXXXXXX,          XXXXXXX         
    ),
    [_NAV] = LAYOUT_split_3x5_3(
        KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,                              KC_ESCAPE, KC_BACKSPACE,     KC_PAGE_UP,      KC_DELETE, KC_BRIGHTNESS_UP,
        KC_F1,               KC_F2,               KC_F3,               KC_F4,               KC_F5,                                        KC_LEFT,   KC_DOWN,          KC_UP,           KC_RGHT,   KC_ENTER,
        KC_F6,               KC_F7,               KC_F8,               KC_F9,               KC_F10,                                       KC_HOME,   KC_TAB,           KC_PAGE_DOWN,    KC_END,    KC_BRIGHTNESS_DOWN,
                                                  QK_BOOT,             KC_F11,              KC_F12,                                       KC_CAPS,   XXXXXXX,          XXXXXXX
    ),
    
};
