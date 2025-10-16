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

/* Enable Permissive Hold mode for all dual-role keys to make hold and tap keys work better for faster typists */
#define PERMISSIVE_HOLD

/* Activate Caps Word by double tapping Left Shift */
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

/* Disable the parts of factory_test that conflict with this keyboard customizations - initially rgb_matrix_indicators_user() */
#define DISABLE_FACTORY_TEST

/* Disable bluetooth_pre_task() for the keyboard so it can be defined at the keymap level */
#define DISABLE_KB_BLUETOOTH_PRE_TASK
