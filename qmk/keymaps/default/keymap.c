// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

void split_send_matrix(void);

enum layer_names {
    _0,
    _1,
    _2,
    _3
};

// RGB on Startup
void keyboard_post_init_user(void) {
    rgblight_enable();
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb(100, 100, 0); // Default to yellow (Layer 0)
}

// RGB on Layer Change
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _0:
            rgblight_setrgb(100, 100, 0); // Yellow
            break;
        case _1:
            rgblight_setrgb(0, 0, 100);   // Blue
            break;
        case _2:
            rgblight_setrgb(0, 100, 0);   // Green
            break;
        case _3:
            rgblight_setrgb(100, 100, 100);   // white
            break;
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        /*
            QWERTY
            ┌───┬───┬───┬───┬───┬───┐                    ┌───┬───┬───┬───┬───┬───┬───┬───┐
            │esc│ 1 │ 2 │ 3 │ 4 │ 5 │                    │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │BSP│
            ├───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼───┼───┤
            │Tab│ Q │ W │ E │ R │ T │                    │ Y │ U │ I │ O │ P │ [ │ ] │ \ │
            ├───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼───┼───┤
            │CAP│ A │ S │ D │ F │ G │                    │ H │ J │ K │ L │ ; │ ' │etr│
            ├───┼───┼───┼───┼───┼───┼                    ┼───┼───┼───┼───┼───┼───┼───┤
            │SFT│ Z │ X │ C │ V │ B │                    │ N │ M │ , │ . │ / │ up│del│
            ├───┼───┼───┼───┼───┼───┼                    ┼───┼───┼───┼───┼───┼───┼───┤
            │CTR│WIN│ALT│SPC│                            │SPC│MO2│TO1│lft│dwn│rgt│
            ├───┼───┼───┼───┼                            ┼───┼───┼───┼───┼───┼───┼


        */\
        [_0] = LAYOUT(
            KC_ESC,  KC_1,KC_2, KC_3, KC_4, KC_5, 
            KC_TAB,  KC_Q,KC_W, KC_E, KC_R, KC_T,
            MO(_3), KC_A,KC_S, KC_D, KC_F, KC_G,
            KC_LSFT, KC_Z,KC_X, KC_C, KC_V, KC_B,
            KC_LCTL, KC_LWIN, KC_LALT, KC_SPC,
            KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
            KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
            KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
            KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP, KC_DEL,
            KC_NO, KC_SPC, MO(_2), TO(_1), KC_LEFT, KC_DOWN, KC_RGHT
        ),
        /*
            mouse keys
            ┌───┬───┬───┬───┬───┬───┐                    ┌───┬───┬───┬───┬───┬───┬───┬───┐
            │esc│ 1 │ 2 │ 3 │ 4 │ 5 │                    │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │BSP│
            ├───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼───┼───┤
            │Tab│ Q │ W │ E │ R │ T │                    │ Y │ U │ I │ O │ P │ [ │ ] │ \ │
            ├───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼───┼───┤
            │CAP│ A │ S │ D │ F │ G │                    │ H │ J │ K │ L │ ; │m3 │etr│
            ├───┼───┼───┼───┼───┼───┼                    ┼───┼───┼───┼───┼───┼───┼───┤
            │SFT│ Z │ X │ C │ V │ B │                    │ N │ M │ , │ . │m1 │ up│m2 │
            ├───┼───┼───┼───┼───┼───┼                    ┼───┼───┼───┼───┼───┼───┼───┤
            │CTR│WIN│ALT│SPC│                            │SPC│MO2│TO1│lft│dwn│rgt│
            ├───┼───┼───┼───┼                            ┼───┼───┼───┼───┼───┼───┼

        */
        [_1] = LAYOUT(
            KC_ESC,  KC_1,KC_2, KC_3, KC_4, KC_5, 
            KC_TAB,  KC_Q,KC_W, KC_E, KC_R, KC_T,
            KC_NO, KC_A,KC_S, KC_D, KC_F, KC_G,
            KC_LSFT, KC_Z,KC_X, KC_C, KC_V, KC_B,
            KC_LCTL, KC_LWIN, KC_LALT, KC_SPC,
            KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
            KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
            KC_H, KC_J, KC_K, KC_L, KC_SCLN, MS_BTN3, KC_ENT,
            KC_N, KC_M, MS_WHLU, MS_WHLD, MS_BTN1, MS_UP, MS_BTN2,
            KC_NO, KC_SPC, MO(_2), TO(_0), MS_LEFT, MS_DOWN, MS_RGHT
        ),
      /*
            shortcut keys
            ┌───┬───┬───┬───┬───┬───┐                    ┌───┬───┬───┬───┬───┬───┬───┬───┐
            │na │F1 │F2 │F3 │F4 │F5 │                    │F6 │F7 │F8 │F9 │F10│F11│F12│na │
            ├───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼───┼───┤
            │na │na │na │na │na │na │                    │na │na │na │na │na │V+ │V- │POS│
            ├───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼───┼───┤
            │na │na │na │na │na │na │                    │na │na │na │na │BBK│BFW│na │
            ├───┼───┼───┼───┼───┼───┼                    ┼───┼───┼───┼───┼───┼───┼───┤
            │na │na │na │na │na │na │                    │na │na │na │na │ctl│sft│na │
            ├───┼───┼───┼───┼───┼───┼                    ┼───┼───┼───┼───┼───┼───┼───┤
            │na │na │na │na │                            │na │MO2│NO │na │na │na │
            ├───┼───┼───┼───┼                            ┼───┼───┼───┼───┼───┼───┼

        */
        [_2] = LAYOUT(
            KC_GRV,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, 
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_VOLD, KC_MPLY,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WBAK, KC_WFWD, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTL, KC_RSFT, KC_TRNS,
            KC_NO, KC_SPC, MO(_2), KC_NO, KC_TRNS, KC_TRNS, KC_TRNS
        ),
      /* numpad
            ┌───┬───┬───┬───┬───┬───┐                    ┌───┬───┬───┬───┬───┬───┬───┬───┐
            │na │na │na │na │na │na │                    │na │na │na │na │na │na │na │na │
            ├───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼───┼───┤
            │na │na │na │na │na │na │                    │ 7 │ 8 │ 9 │na │na │na │na │na │
            ├───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼───┼───┤
            │MO3│na │na │na │na │na │                    │ 4 │ 5 │ 6 │na │na │na │na │
            ├───┼───┼───┼───┼───┼───┼                    ┼───┼───┼───┼───┼───┼───┼───┤
            │na │na │na │na │na │na │                    │ 1 │ 2 │ 3 │na │na │na │na │
            ├───┼───┼───┼───┼───┼───┼                    ┼───┼───┼───┼───┼───┼───┼───┤
            │na │na │na │na │                            │na │na │na │na │na │na │
            ├───┼───┼───┼───┼                            ┼───┼───┼───┼───┼───┼───┼

        */
        [_3] = LAYOUT(
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            MO(_3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_P7, KC_P8, KC_P9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_P4, KC_P5, KC_P6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_P1, KC_P2, KC_P3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_NO, KC_P0, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS
        )

};
