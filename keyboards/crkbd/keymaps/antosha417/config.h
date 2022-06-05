// Copyright 2021 Anton Kavalkou (@antosha417)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

/* Select hand configuration */

//#define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define TAPPING_FORCE_HOLD
// how match to hold to activate mod tap key
#define TAPPING_TERM 150
// tapping term can be set up per key
#define TAPPING_TERM_PER_KEY
// immediately select the hold action when another key is pressed, configured per key
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

#define COMBO_TERM 30
