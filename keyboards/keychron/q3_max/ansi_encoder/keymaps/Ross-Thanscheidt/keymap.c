/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "transport.h"
#include "keychron_common.h"
#include "process_combo.h"

enum layers {
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
    CKC_TERM,
    CKC_WT1,
    CKC_WT2,
    CKC_WT3,
    CKC_WT4,
    CKC_WT5,
    CKC_WT6,
    CKC_WT7,
    CKC_WT8,
    CKC_WT9,
    CKC_WT0,
    CKC_BT,
    CKC_USB,
    CKC_P2P4
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,          KC_F1,    KC_F2,   KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,        KC_F9,    KC_F10,       KC_F11,     KC_F12,       KC_MUTE,  KC_SNAP,  KC_SIRI, RGB_MOD,
        KC_GRV,          KC_1,     KC_2,    KC_3,     KC_4,     KC_5,    KC_6,    KC_7,    KC_8,         KC_9,     KC_0,         KC_MINS,    KC_EQL,       KC_BSPC,  KC_INS,   KC_HOME, KC_PGUP,
        KC_TAB,          KC_Q,     KC_W,    KC_E,     KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,         KC_O,     KC_P,         KC_LBRC,    KC_RBRC,      KC_BSLS,  KC_DEL,   KC_END,  KC_PGDN,
        LT(NAV,KC_CAPS), KC_A,     KC_S,    KC_D,     KC_F,     KC_G,    KC_H,    KC_J,    KC_K,         KC_L,     KC_SCLN,      KC_QUOT,                  KC_ENT,
        KC_LSFT,                   KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,         KC_COMM,  KC_DOT,       KC_SLSH,                  KC_RSFT,            KC_UP,
        KC_LCTL,         KC_LOPTN, KC_LCMMD,                             KC_SPC,                                   KC_RCMMD,     KC_ROPTN,   MO(MAC_FN),   KC_RCTL,  KC_LEFT,  KC_DOWN, KC_RIGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        _______,         KC_BRID,  KC_BRIU, KC_MCTRL, KC_LNPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY,      KC_MNXT,  KC_MUTE,      KC_VOLD,    KC_VOLU,      RGB_TOG,  _______,  _______, RGB_TOG,
        _______,         BT_HST1,  BT_HST2, BT_HST3,  P2P4G,    RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,     RGB_M_SN, RGB_M_K,      RGB_M_X,    RGB_M_G,      CKC_MAC,  _______,  _______, _______,
        RGB_TOG,         RGB_MOD,  RGB_VAI, RGB_HUI,  RGB_SAI,  RGB_SPI, _______, _______, _______,      _______,  DF(WIN_BASE), _______,    _______,      _______,  _______,  _______, _______,
        _______,         RGB_RMOD, RGB_VAD, RGB_HUD,  RGB_SAD,  RGB_SPD, _______, _______, _______,      CKC_BT,   CKC_USB,      CKC_P2P4,                 _______,
        _______,                   _______, _______,  _______,  _______, BAT_LVL, NK_TOGG, KC_NO,        _______,  _______,      _______,                  _______,            RGB_TOG,
        _______,         _______,  _______,                              _______,                                  _______,      _______,    _______,      _______,  RGB_RMOD, RGB_TOG, RGB_MOD),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,          KC_F1,    KC_F2,   KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,        KC_F9,    KC_F10,       KC_F11,     KC_F12,       KC_MUTE,  KC_PSCR,  KC_SCRL, KC_PAUS,
        KC_GRV,          KC_1,     KC_2,    KC_3,     KC_4,     KC_5,    KC_6,    KC_7,    KC_8,         KC_9,     KC_0,         KC_MINS,    KC_EQL,       KC_BSPC,  KC_INS,   KC_HOME, KC_PGUP,
        KC_TAB,          KC_Q,     KC_W,    KC_E,     KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,         KC_O,     KC_P,         KC_LBRC,    KC_RBRC,      KC_BSLS,  KC_DEL,   KC_END,  KC_PGDN,
        LT(NAV,KC_CAPS), KC_A,     KC_S,    KC_D,     KC_F,     KC_G,    KC_H,    KC_J,    KC_K,         KC_L,     KC_SCLN,      KC_QUOT,                  KC_ENT,
        KC_LSFT,                   KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,         KC_COMM,  KC_DOT,       KC_SLSH,                  KC_RSFT,            KC_UP,
        KC_LCTL,         KC_LWIN,  KC_LALT,                              KC_SPC,                                   KC_RALT,      KC_APP,     MO(WIN_FN),   KC_RCTL,  KC_LEFT,  KC_DOWN, KC_RIGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        _______,         KC_BRID,  KC_BRIU, KC_TASK,  KC_FILE,  RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY,      KC_MNXT,  KC_MUTE,      KC_VOLD,    KC_VOLU,      RGB_TOG,  CKC_TERM, KC_MYCM, KC_CALC,
        _______,         BT_HST1,  BT_HST2, BT_HST3,  P2P4G,    RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,     RGB_M_SN, RGB_M_K,      RGB_M_X,    RGB_M_G,      CKC_PC,   _______,  _______, _______,
        RGB_TOG,         RGB_MOD,  RGB_VAI, RGB_HUI,  RGB_SAI,  RGB_SPI, _______, _______, _______,      _______,  KC_NO,        _______,    _______,      _______,  _______,  _______, _______,
        _______,         RGB_RMOD, RGB_VAD, RGB_HUD,  RGB_SAD,  RGB_SPD, _______, _______, _______,      CKC_BT,   CKC_USB,      CKC_P2P4,                 _______,
        _______,                   _______, _______,  _______,  _______, BAT_LVL, NK_TOGG, DF(MAC_BASE), _______,  _______,      DF(KEYPAD),               _______,            RGB_TOG,
        _______,         _______,  _______,                              _______,                                  _______,      _______,    _______,      _______,  RGB_RMOD, RGB_TOG, RGB_MOD),

    [KEYPAD] = LAYOUT_tkl_ansi(
        _______,         _______,  _______, _______,  _______,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,      _______,  _______,      _______,    _______,      KC_MUTE,  _______,  _______, _______,
        _______,         _______,  _______, _______,  CKC_KP,   _______, _______, KC_KP_7, KC_KP_8,      KC_KP_9,  KC_PPLS,      _______,    _______,      _______,  _______,  _______, _______,
        _______,         _______,  _______, _______,  _______,  _______, _______, KC_KP_4, KC_KP_5,      KC_KP_6,  KC_PPLS,      _______,    _______,      _______,  _______,  _______, _______,
        _______,         _______,  _______, _______,  _______,  _______, _______, KC_KP_1, KC_KP_2,      KC_KP_3,  KC_PENT,      _______,                  _______,
        _______,                   _______, _______,  _______,  _______, _______, _______, _______,      KC_KP_0,  KC_PDOT,      KC_PENT,                  _______,            _______,
        _______,         _______,  _______,                              _______,                                  _______,      _______,    DF(WIN_BASE), _______,  _______,  _______, _______),

    [NAV] = LAYOUT_tkl_ansi(
        _______,         _______,  _______, _______,  _______,  _______, _______, _______, _______,      _______,  _______,      _______,    _______,      KC_MUTE,  _______,  _______, _______,
        KC_ENT,          CKC_WT1,  CKC_WT2, CKC_WT3,  CKC_WT4,  CKC_WT5, CKC_WT6, CKC_WT7, CKC_WT8,      CKC_WT9,  CKC_WT0,      _______,    _______,      _______,  _______,  _______, _______,
        _______,         KC_HOME,  KC_UP,   KC_PGUP,  _______,  _______, _______, _______, KC_INS,       _______,  _______,      _______,    _______,      _______,  _______,  _______, _______,
        _______,         KC_LEFT,  KC_DOWN, KC_RIGHT, KC_PGDN,  _______, KC_LEFT, KC_DOWN, KC_UP,        KC_RIGHT, _______,      _______,                  _______,
        _______,                   KC_END,  KC_DEL,   KC_PGDN,  _______, KC_PGUP, _______, _______,      _______,  _______,      _______,                  _______,            _______,
        _______,         _______,  _______,                              _______,                                  _______,      _______,    _______,      _______,  _______,  _______, _______),

};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [KEYPAD] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [NAV]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

#ifdef DISABLE_KEYCHRON_COMMON_WIRELESS_PRE_TASK
void request_transport(transport_t transport);
transport_t get_last_transport(void);
#endif

bool shift_pressed = false;
bool num_lock_on = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case KC_LSFT:
        case KC_RSFT:
            if (record->event.pressed) {
                shift_pressed = true;
            }
            else {
                shift_pressed = false;
            }
            break;

        case KC_NUM:
            if (record->event.pressed) {
                num_lock_on = !num_lock_on;
            }
            break;

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

        case CKC_WT1:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r") SS_DELAY(500) "\%WT\% \"\%WT_1\%\"" SS_TAP(X_ENT));
            }
            break;

        case CKC_WT2:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r") SS_DELAY(500) "\%WT\% \"\%WT_2\%\"" SS_TAP(X_ENT));
            }
            break;

        case CKC_WT3:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r") SS_DELAY(500) "\%WT\% \"\%WT_3\%\"" SS_TAP(X_ENT));
            }
            break;

        case CKC_WT4:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r") SS_DELAY(500) "\%WT\% \"\%WT_4\%\"" SS_TAP(X_ENT));
            }
            break;

        case CKC_WT5:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r") SS_DELAY(500) "\%WT\% \"\%WT_5\%\"" SS_TAP(X_ENT));
            }
            break;

        case CKC_WT6:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r") SS_DELAY(500) "\%WT\% \"\%WT_6\%\"" SS_TAP(X_ENT));
            }
            break;

        case CKC_WT7:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r") SS_DELAY(500) "\%WT\% \"\%WT_7\%\"" SS_TAP(X_ENT));
            }
            break;

        case CKC_WT8:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r") SS_DELAY(500) "\%WT\% \"\%WT_8\%\"" SS_TAP(X_ENT));
            }
            break;

        case CKC_WT9:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r") SS_DELAY(500) "\%WT\% \"\%WT_9\%\"" SS_TAP(X_ENT));
            }
            break;

        case CKC_WT0:
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("r") SS_DELAY(500) "\%WT\% \"\%WT_0\%\"" SS_TAP(X_ENT));
            }
            break;

#ifdef DISABLE_KEYCHRON_COMMON_WIRELESS_PRE_TASK
        case CKC_BT:
            if (record->event.pressed) {
                request_transport(TRANSPORT_BLUETOOTH);
            }
            break;

        case CKC_USB:
            if (record->event.pressed) {
                request_transport(TRANSPORT_USB);
            }
            break;

        case CKC_P2P4:
            if (record->event.pressed) {
                request_transport(TRANSPORT_P2P4);
            }
            break;
#endif

    }

    return true;
};

enum combo_events {
    EM_PERSONAL_EMAIL,
    EM_WORK_EMAIL,
    EM_PERSONAL_SITE,
    COMBO_LENGTH
};
const uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM personal_email_combo[] = {KC_E, KC_1, COMBO_END};
const uint16_t PROGMEM work_email_combo[] = {KC_E, KC_2, COMBO_END};
const uint16_t PROGMEM personal_site_combo[] = {KC_E, KC_5, COMBO_END};

combo_t key_combos[] = {
    [EM_PERSONAL_EMAIL] = COMBO_ACTION(personal_email_combo),
    [EM_WORK_EMAIL] = COMBO_ACTION(work_email_combo),
    [EM_PERSONAL_SITE] = COMBO_ACTION(personal_site_combo)
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

        case EM_PERSONAL_SITE:
            if (pressed) {
                SEND_STRING("site.com");
            }
            break;
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

bool rgb_matrix_indicators_user(void)
{

    // Current Layer
    for (uint8_t layer = 0; layer < DYNAMIC_KEYMAP_LAYER_COUNT; layer++)
    {
        if (layer_state_cmp(layer_state | default_layer_state, layer)) {
            rgb_matrix_set_color(17 + layer, RGB_GREEN);
        }
    }

    // Transport Mode - USB
#ifdef DISABLE_KEYCHRON_COMMON_WIRELESS_PRE_TASK
    bool modeIsBT = get_last_transport() == TRANSPORT_BLUETOOTH;
#else
    bool modeIsBT = readPin(BT_MODE_SELECT_PIN) == 0;
#endif

    bool transportIsBT = get_transport() == TRANSPORT_BLUETOOTH;

    if (modeIsBT && transportIsBT)
    {
        rgb_matrix_set_color(23, RGB_GREEN);
    }
    else if (modeIsBT)
    {
        rgb_matrix_set_color(23, RGB_YELLOW);
    }
    else if (transportIsBT)
    {
        rgb_matrix_set_color(23, RGB_RED);
    }

    // Transport Mode - 2.4GHz
#ifdef DISABLE_KEYCHRON_COMMON_WIRELESS_PRE_TASK
    bool modeIsP2P4 = get_last_transport() == TRANSPORT_P2P4;
#else
    bool modeIsP2P4 = readPin(P2P4_MODE_SELECT_PIN) == 0;
#endif

    bool transportIsP2P4 = get_transport() == TRANSPORT_P2P4;

    if (modeIsP2P4 && transportIsP2P4)
    {
        rgb_matrix_set_color(25, RGB_GREEN);
    }
    else if (modeIsP2P4)
    {
        rgb_matrix_set_color(25, RGB_YELLOW);
    }
    else if (transportIsP2P4)
    {
        rgb_matrix_set_color(25, RGB_RED);
    }

    // Caps Lock
    if ((host_keyboard_led_state().caps_lock && !shift_pressed) ||
        (!host_keyboard_led_state().caps_lock && shift_pressed) ||
        is_caps_word_on())
    {

        for (uint8_t row = 2; row <= MATRIX_ROWS; row++)
        {
            for (uint8_t col = 0; col < MATRIX_COLS; col++)
            {
                uint8_t index = g_led_config.matrix_co[row][col];
                uint8_t keycode = keymap_key_to_keycode(get_highest_layer(layer_state), (keypos_t){col, row});

                if (index != NO_LED && ((keycode >= KC_A && keycode <= KC_Z) || keycode == KC_LSFT || keycode == KC_RSFT))
                {
                    rgb_matrix_set_color(index, RGB_RED);
                }
            }
        }
    }

    // Numeric Keypad Mode
    if (get_highest_layer(layer_state | default_layer_state) == KEYPAD)
    {
        for (uint8_t row = 0; row <= MATRIX_ROWS; row++)
        {
            for (uint8_t col = 0; col < MATRIX_COLS; col++)
            {
                uint8_t index = g_led_config.matrix_co[row][col];
                uint8_t keycode = keymap_key_to_keycode(KEYPAD, (keypos_t){col, row});

                if (index != NO_LED)
                {
                    if (keycode >= KC_KP_1 && keycode <= KC_KP_0)
                    {
                        if (num_lock_on)
                        {
                            rgb_matrix_set_color(index, RGB_GREEN);
                        }
                        else
                        {
                            rgb_matrix_set_color(index, RGB_YELLOW);
                        }
                    }
                    else if (keycode == KC_PENT || keycode == KC_NUM)
                    {
                        rgb_matrix_set_color(index, RGB_RED);
                    }
                    else if (keycode >= KC_NUM_LOCK && keycode <= KC_KP_DOT)
                    {
                        rgb_matrix_set_color(index, RGB_MAGENTA);
                    }
                }
            }
        }
    }

    return true;
}

#ifdef DISABLE_KEYCHRON_COMMON_WIRELESS_PRE_TASK
transport_t requested_transport = TRANSPORT_NONE;
transport_t last_transport = TRANSPORT_NONE;
transport_t current_transport = TRANSPORT_NONE;
uint8_t last_mode = 0;

void request_transport(transport_t transport)
{
    requested_transport = transport;
}

transport_t get_last_transport(void)
{
    return last_transport;
}

void determine_current_transport(void)
{
    static uint8_t current_mode = 0;

    current_mode = readPin(BT_MODE_SELECT_PIN) << 1 | readPin(P2P4_MODE_SELECT_PIN);

    if (current_mode != last_mode || requested_transport != TRANSPORT_NONE)
    {
        if (current_mode != last_mode)
        {
            switch (current_mode) {
                case 0x01:
                    current_transport = TRANSPORT_BLUETOOTH;
                    break;
                case 0x02:
                    current_transport = TRANSPORT_P2P4;
                    break;
                case 0x03:
                    current_transport = TRANSPORT_USB;
                    break;
                default:
                    break;
            }

            last_mode = current_mode;
        }
        else
        {
            current_transport = requested_transport;
        }

        requested_transport = TRANSPORT_NONE;
    }
}

void wireless_pre_task(void)
{
    static uint32_t time = 0;

    if (time == 0) {
        determine_current_transport();

        if (current_transport != last_transport)
        {
            time = timer_read32();
        }
    }

    if ((time && timer_elapsed32(time) > 100) || get_transport() == TRANSPORT_NONE) {
        time = 0;

        if ((readPin(BT_MODE_SELECT_PIN) << 1 | readPin(P2P4_MODE_SELECT_PIN)) == last_mode && requested_transport == TRANSPORT_NONE)
        {
            set_transport(current_transport);
            last_transport = current_transport;
        }
        else
        {
            determine_current_transport();

            if (current_transport != last_transport)
            {
                time = timer_read32();
            }
        }
    }
}
#endif
