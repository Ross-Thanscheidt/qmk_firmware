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

#pragma once

/* The Dynamic Keymap Layer Count should match the keymaps array size defined in keymap.c */
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

/* Turn on NKRO by default */
#define FORCE_NKRO

/* Enable Permissive Hold mode for all dual-role keys to make hold and tap keys work better for faster typists */
#define PERMISSIVE_HOLD

/* Activate Caps Word by double tapping Left Shift */
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

/* Configure Caps Word to never time out */
#define CAPS_WORD_IDLE_TIMEOUT 0

/* Pressing the Shift key continues Caps Word and inverts the shift state */
// #define CAPS_WORD_INVERT_ON_SHIFT

/* Disable caps_word_press_user() in quantum/process_keycode/process_caps_word.c */
#define DISABLE_QUANTUM_CAPS_WORD_PRESS_USER

/* Disable the parts of factory_test that conflict with this keyboard customizations - initially rgb_matrix_indicators_user() */
#define DISABLE_FACTORY_TEST

/* Disable wireless_pre_task() at the Keychron Common level so it can be defined at the keymap level */
#define DISABLE_KEYCHRON_COMMON_WIRELESS_PRE_TASK
