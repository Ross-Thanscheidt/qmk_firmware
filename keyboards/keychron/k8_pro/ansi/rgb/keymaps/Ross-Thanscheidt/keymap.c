/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "k8_pro.h"
#include "process_combo.h"

enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN,
  KEYPAD,
  NAV
};

enum custom_keycodes {
    CKC_MAC = NEW_SAFE_RANGE,
    CKC_PC,
    CKC_KP,
    CKC_TERM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_tkl_ansi(
     KC_ESC,          KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV, KC_MPLY,      KC_MNXT,   KC_MUTE,      KC_VOLD,    KC_VOLU,                KC_SNAP,  KC_SIRI,  RGB_MOD,
     KC_GRV,          KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,    KC_8,         KC_9,      KC_0,         KC_MINS,    KC_EQL,       KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
     KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,         KC_O,      KC_P,         KC_LBRC,    KC_RBRC,      KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
     LT(NAV,KC_CAPS), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,    KC_K,         KC_L,      KC_SCLN,      KC_QUOT,                  KC_ENT,
     KC_LSFT,                   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,    KC_M,         KC_COMM,   KC_DOT,       KC_SLSH,                  KC_RSFT,            KC_UP,
     KC_LCTL,         KC_LOPTN, KC_LCMMD,                               KC_SPC,                                     KC_RCMMD,     KC_ROPTN,   MO(MAC_FN),   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_tkl_ansi(
     KC_TRNS,         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,   KC_F8,        KC_F9,     KC_F10,       KC_F11,     KC_F12,                 KC_TRNS,  KC_TRNS,  RGB_TOG,
     KC_TRNS,         BT_HST1,  BT_HST2,  BT_HST3,  CKC_MAC,  RGB_M_P,  RGB_M_B,  RGB_M_R, RGB_M_SW,     RGB_M_SN,  RGB_M_K,      RGB_M_X,    RGB_M_G,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     RGB_TOG,         RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS, KC_TRNS,      KC_TRNS,   DF(WIN_BASE), KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,         RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS, KC_TRNS,      KC_TRNS,   KC_TRNS,      KC_TRNS,                  KC_TRNS,
     KC_TRNS,                   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG, KC_NO,        KC_TRNS,   KC_TRNS,      KC_TRNS,                  KC_TRNS,            RGB_TOG,
     KC_TRNS,         KC_TRNS,  KC_TRNS,                                KC_TRNS,                                    KC_TRNS,      KC_TRNS,    KC_TRNS,      KC_TRNS,  RGB_RMOD, RGB_TOG,  RGB_MOD),

[WIN_BASE] = LAYOUT_tkl_ansi(
     KC_ESC,          KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,   KC_F8,        KC_F9,     KC_F10,       KC_F11,     KC_F12,                 KC_PSCR,  KC_SCRL,  KC_PAUS,
     KC_GRV,          KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,    KC_8,         KC_9,      KC_0,         KC_MINS,    KC_EQL,       KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
     KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,         KC_O,      KC_P,         KC_LBRC,    KC_RBRC,      KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
     LT(NAV,KC_CAPS), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,    KC_K,         KC_L,      KC_SCLN,      KC_QUOT,                  KC_ENT,
     KC_LSFT,                   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,    KC_M,         KC_COMM,   KC_DOT,       KC_SLSH,                  KC_RSFT,            KC_UP,
     KC_LCTL,         KC_LGUI,  KC_LALT,                                KC_SPC,                                     KC_RALT,      KC_APP,     MO(WIN_FN),   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_tkl_ansi(
     KC_TRNS,         KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV, KC_MPLY,      KC_MNXT,   KC_MUTE,      KC_VOLD,    KC_VOLU,                CKC_TERM, KC_MYCM,  KC_CALC,
     KC_TRNS,         BT_HST1,  BT_HST2,  BT_HST3,  CKC_PC,   RGB_M_P,  RGB_M_B,  RGB_M_R, RGB_M_SW,     RGB_M_SN,  RGB_M_K,      RGB_M_X,    RGB_M_G,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     RGB_TOG,         RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS, KC_TRNS,      KC_TRNS,   KC_NO,        KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,         RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS, KC_TRNS,      KC_TRNS,   KC_TRNS,      KC_TRNS,                  KC_TRNS,
     KC_TRNS,                   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG, DF(MAC_BASE), KC_TRNS,   KC_TRNS,      DF(KEYPAD),               KC_TRNS,            RGB_TOG,
     KC_TRNS,         KC_TRNS,  KC_TRNS,                                KC_TRNS,                                    KC_TRNS,      KC_TRNS,    KC_TRNS,      KC_TRNS,  RGB_RMOD, RGB_TOG,  RGB_MOD),

[KEYPAD] = LAYOUT_tkl_ansi(
     KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NUM,   KC_PSLS,  KC_PAST, KC_MINUS,     KC_TRNS,   KC_TRNS,      KC_TRNS,    KC_TRNS,                KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  CKC_KP,   KC_TRNS,  KC_TRNS,  KC_KP_7, KC_KP_8,      KC_KP_9,   KC_PPLS,      KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_KP_4, KC_KP_5,      KC_KP_6,   KC_PPLS,      KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_KP_1, KC_KP_2,      KC_KP_3,   KC_PENT,      KC_TRNS,                  KC_TRNS,
     KC_TRNS,                   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_KP_0,      KC_KP_0,   KC_PDOT,      KC_PENT,                  KC_TRNS,            KC_TRNS,
     KC_TRNS,         KC_TRNS,  KC_TRNS,                                KC_TRNS,                                    KC_TRNS,      KC_TRNS,    DF(WIN_BASE), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[NAV] = LAYOUT_tkl_ansi(
     KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,      KC_TRNS,   KC_TRNS,      KC_TRNS,    KC_TRNS,                KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,      KC_TRNS,   KC_TRNS,      KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_INS,       KC_TRNS,   KC_TRNS,      KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,         KC_HOME,  KC_TRNS,  KC_DEL,   KC_PGDN,  KC_TRNS,  KC_LEFT,  KC_DOWN, KC_UP,        KC_RGHT,   KC_TRNS,      KC_TRNS,                  KC_TRNS,
     KC_TRNS,                   KC_END,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGUP,  KC_TRNS, KC_TRNS,      KC_TRNS,   KC_TRNS,      KC_TRNS,                  KC_TRNS,            KC_TRNS,
     KC_TRNS,         KC_TRNS,  KC_TRNS,                                KC_TRNS,                                    KC_TRNS,      KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case CKC_MAC:
            if (record->event.pressed) {
                SEND_STRING("Mac");
            }
            break;

        case CKC_PC:
            if (record->event.pressed) {
                SEND_STRING("PC");
            }
            break;

        case CKC_KP:
            if (record->event.pressed) {
                SEND_STRING("Keypad");
            }
            break;

        case CKC_TERM:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r") SS_DELAY(500) "WT" SS_TAP(X_ENT));
            }
            break;
    }

    return true;
};

enum combo_events {
    EM_PERSONAL_EMAIL,
    EM_WORK_EMAIL,
    COMBO_LENGTH
};
const uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM personal_email_combo[] = {KC_E, KC_1, COMBO_END};
const uint16_t PROGMEM work_email_combo[] = {KC_E, KC_2, COMBO_END};

combo_t key_combos[] = {
    [EM_WORK_EMAIL] = COMBO_ACTION(work_email_combo),
    [EM_PERSONAL_EMAIL] = COMBO_ACTION(personal_email_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {

    switch(combo_index) {
        case EM_PERSONAL_EMAIL:
            if (pressed) {
                SEND_STRING("me@home.com");
            }
            break;

        case EM_WORK_EMAIL:
            if (pressed) {
                SEND_STRING("me@work.com");
            }
            break;
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}
