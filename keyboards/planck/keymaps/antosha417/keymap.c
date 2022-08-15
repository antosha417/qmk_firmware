// Copyright 2021 Anton Kavalkou (@antosha417)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "sendstring_dvorak.h"
#include "muse.h"

enum layers {
  _QWERTY,
  _DVORAK,
  _SYMBOLS,
  _NUMS,
  _RIGHT,
  _LEFT,
  _ADJUST
};

float USSR_SONG[][2] = SONG(B__NOTE(_G6),
  B__NOTE(_C7), W__NOTE(_G6), H__NOTE(_A6),
  B__NOTE(_B6), W__NOTE(_E6), W__NOTE(_E6),
  B__NOTE(_A6), W__NOTE(_G6), H__NOTE(_F6),
  B__NOTE(_G6), W__NOTE(_C6), W__NOTE(_C6),
  B__NOTE(_D6), W__NOTE(_D6), W__NOTE(_E6),
  B__NOTE(_D6), W__NOTE(_D6), W__NOTE(_G6),
  B__NOTE(_F6), W__NOTE(_G6), W__NOTE(_A6),
  B__NOTE(_B6),
  );

enum keycodes {
  QWERTY = SAFE_RANGE,

  RUS_LANG,
  EN_LANG,
  HEB_LANG,

  BRUDERSCHAFT,
};

#define SYMBOLS LT(_SYMBOLS, KC_ENT)
#define NUMS    LT(_NUMS, KC_ESC)
#define RIGHT   LT(_RIGHT, KC_BSPC)
#define LEFT    LT(_LEFT, KC_TAB)
#define LANG    TG(_DVORAK)

#define LSFT_SP LSFT_T(KC_SPC)
#define RSFT_SP RSFT_T(KC_SPC)

#define A_ALT LALT_T(KC_A)
#define O_GUI LGUI_T(KC_O)
#define U_CTRL LCTL_T(KC_U)

#define S_ALT RALT_T(KC_S)
#define N_GUI RGUI_T(KC_N)
#define H_CTRL RCTL_T(KC_H)

#define F_CTLQ LT(0, KC_F)
#define S_GUIQ LT(0, KC_S)
#define L_GUIQ LT(0, KC_L)
#define J_CTLQ LT(0, KC_J)
#define A_ALTQ LT(0, KC_A)
#define SCLN_Q LT(0, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Bottom| SPC  |Lower |Raise | SPC  |RIGHT |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    _______,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______,  A_ALTQ,  S_GUIQ,  KC_D,    F_CTLQ,  KC_G,    KC_H,    J_CTLQ,  KC_K,    L_GUIQ,  SCLN_Q,  _______,
    _______,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______,  LEFT,    LSFT_SP, SYMBOLS, NUMS,    RSFT_SP, RIGHT,   _______, _______, _______
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |      |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,     KC_C,    KC_R,   KC_L,    _______,
    _______, A_ALT,   O_GUI,   KC_E,    U_CTRL,  KC_I,    KC_D,    H_CTRL,   KC_T,    N_GUI,  S_ALT,   _______,
    _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,     KC_W,    KC_V,   KC_Z,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | F11  | _    |  -   |  ~   |  %   | '    |      |  ^   |  `   |  \   |  |   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  [   |  {   |  +   |  (   |  =   |  *   |   )  |   !  |  }   |  ]   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | LANG |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | [{}] |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_planck_grid(
    KC_F11,  KC_UNDS, KC_MINS,  KC_TILD, KC_PERC, KC_QUOT, _______, KC_CIRC,  KC_GRV,  KC_BSLS,  KC_PIPE, _______,
    _______, KC_LBRC, KC_LCBR,  KC_PLUS, KC_LPRN, KC_EQL,  KC_ASTR, KC_RPRN,  KC_EXLM, KC_RCBR,  KC_RBRC, _______,
    _______, _______, _______,  _______, LANG,    _______, _______, _______,  _______, _______,  _______, _______,
    _______, _______, _______,  _______, _______, _______, _______, _______,  _______, _______,  _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | F11  |      |      |  $   |  &   |      | :    |   ?  |   @  |   #  |   /  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  7   |  5   |  3   |  1   |  9   |  0   |  2   |  4   |  6   |  8   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F5  |  F3  |  F1  |  F9  |  F10 |  F2  |  F4  |  F6  |  F8  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | [{}] |      |      | End  | Home |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMS] = LAYOUT_planck_grid(
    KC_F11,  _______, _______, KC_DLR,  KC_AMPR, _______, KC_COLON, KC_QUES, KC_AT,  KC_HASH, KC_SLSH, KC_F12,
    _______, KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,    _______,
    _______, KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,   KC_F10,  KC_F2,   KC_F4,   KC_F6,   KC_F8,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,  KC_HOME, _______
),

/* RIGHT
 * ,-----------------------------------------------------------------------------------
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Pg_up |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Down | Up   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | [{}] |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RIGHT] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_DOWN, KC_UP,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* LEFT
 * ,-----------------------------------------------------------------------------------
 * |      |      |      |      |      |      |      |      |      |      | ->   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Pgdown| <-   |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Vold | Volu |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | [{}] |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LEFT] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------
 * |      | Reset|Debug |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Aud on|Audoff|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Mus on|Musoff|      |      |      |      |      |      |      |      | USSR |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | [{}] | [{}] |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
    _______, AU_ON,   AU_OFF,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, MU_ON,   MU_OFF,  _______, _______, _______, _______, _______, _______, _______, _______, BRUDERSCHAFT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

void keyboard_post_init_user(void) {
  layer_on(_DVORAK);
}

void set_english_language(void) {
    layer_on(_DVORAK);
    SEND_STRING(SS_LSFT(SS_LCTL(SS_LGUI(SS_TAP(X_1)))));
}

void set_russian_language(void) {
    layer_off(_DVORAK);
    SEND_STRING(SS_LSFT(SS_LCTL(SS_LGUI(SS_TAP(X_2)))));
}

void set_hebrew_language(void) {
    layer_off(_DVORAK);
    SEND_STRING(SS_LSFT(SS_LCTL(SS_LGUI(SS_TAP(X_3)))));
}

#define CASE_MOD_TAP_KEY_HOLD(keycode, key_hold_pressed_action, key_hold_released_action) \
  case (keycode):                                                                         \
    if (!record->tap.count) {                                                             \
      if (record->event.pressed) {                                                        \
        key_hold_pressed_action;                                                          \
      } else {                                                                            \
        key_hold_released_action;                                                         \
      }                                                                                   \
      return false;                                                                       \
    }                                                                                     \
    break;                                                                                \

#define CASE(keycode, key_pressed_action, key_released_action)  \
  case (keycode):                                               \
    if (record->event.pressed) {                                \
      key_pressed_action;                                       \
    } else {                                                    \
      key_released_action;                                      \
    }                                                           \
    return false;

#define CASE_PRESSED(keycode, key_pressed_action) CASE(keycode, key_pressed_action, {});

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    CASE_PRESSED(BRUDERSCHAFT, PLAY_SONG(USSR_SONG));

    CASE_PRESSED(EN_LANG, set_english_language());
    CASE_PRESSED(RUS_LANG, set_russian_language());
    CASE_PRESSED(HEB_LANG, set_hebrew_language());

    CASE_MOD_TAP_KEY_HOLD(F_CTLQ, {layer_on(_DVORAK); register_code(KC_LCTL);}, {layer_off(_DVORAK); unregister_code(KC_LCTL);});
    CASE_MOD_TAP_KEY_HOLD(S_GUIQ, {layer_on(_DVORAK); register_code(KC_LGUI);}, {layer_off(_DVORAK); unregister_code(KC_LGUI);});
    CASE_MOD_TAP_KEY_HOLD(L_GUIQ, {layer_on(_DVORAK); register_code(KC_RGUI);}, {layer_off(_DVORAK); unregister_code(KC_RGUI);});
    CASE_MOD_TAP_KEY_HOLD(J_CTLQ, {layer_on(_DVORAK); register_code(KC_RCTL);}, {layer_off(_DVORAK); unregister_code(KC_RCTL);});
    CASE_MOD_TAP_KEY_HOLD(A_ALTQ, {layer_on(_DVORAK); register_code(KC_LALT);}, {layer_off(_DVORAK); unregister_code(KC_LALT);});
    CASE_MOD_TAP_KEY_HOLD(SCLN_Q, {layer_on(_DVORAK); register_code(KC_RALT);}, {layer_off(_DVORAK); unregister_code(KC_RALT);});
  }

  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_NUMS)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
  return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
  return true;
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case NUMS:
    case SYMBOLS:
      return false;
    default:
      return true;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYMBOLS, _NUMS, _ADJUST);
}

enum combo_events {
  // combos for dvorak layer
  RU_COMBO,
  EN_COMBO,
  HEB_COMBO,
  TAB_COMBO,
  DEL_COMBO,
  BSPC_COMBO,
  BSPCW_COMBO,

  // combos for qwerty layer
  RUQ_COMBO,
  ENQ_COMBO,
  HEBQ_COMBO,
  TABQ_COMBO,
  DELQ_COMBO,
  BSPCQ_COMBO,
  BSPCWQ_COMBO,

  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM ru_combo[] = {KC_R, U_CTRL, COMBO_END};
const uint16_t PROGMEM en_combo[] = {U_CTRL, S_ALT, COMBO_END};
const uint16_t PROGMEM heb_combo[] = {KC_I, KC_V, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_T, A_ALT, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_D, KC_E, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_C, H_CTRL, COMBO_END};
const uint16_t PROGMEM bspcw_combo[] = {N_GUI, U_CTRL, COMBO_END};

const uint16_t PROGMEM ruq_combo[] = {KC_O, F_CTLQ, COMBO_END};
const uint16_t PROGMEM enq_combo[] = {F_CTLQ, SCLN_Q, COMBO_END};
const uint16_t PROGMEM hebq_combo[] = {KC_G, KC_DOT, COMBO_END};
const uint16_t PROGMEM tabq_combo[] = {KC_K, A_ALTQ, COMBO_END};
const uint16_t PROGMEM delq_combo[] = {KC_H, KC_D, COMBO_END};
const uint16_t PROGMEM bspcq_combo[] = {KC_I, J_CTLQ, COMBO_END};
const uint16_t PROGMEM bspcwq_combo[] = {L_GUIQ, F_CTLQ, COMBO_END};

combo_t key_combos[] = {
  [RU_COMBO] = COMBO(ru_combo, RUS_LANG),
  [EN_COMBO] = COMBO(en_combo, EN_LANG),
  [HEB_COMBO] = COMBO(heb_combo, HEB_LANG),
  [TAB_COMBO] = COMBO(tab_combo, KC_TAB),
  [DEL_COMBO] = COMBO(del_combo, KC_DEL),
  [BSPC_COMBO] = COMBO(bspc_combo, KC_BSPC),
  [BSPCW_COMBO] = COMBO(bspcw_combo, A(KC_BSPC)),

  [RUQ_COMBO] = COMBO(ruq_combo, RUS_LANG),
  [ENQ_COMBO] = COMBO(enq_combo, EN_LANG),
  [HEBQ_COMBO] = COMBO(hebq_combo, HEB_LANG),
  [TABQ_COMBO] = COMBO(tabq_combo, KC_TAB),
  [DELQ_COMBO] = COMBO(delq_combo, KC_DEL),
  [BSPCQ_COMBO] = COMBO(bspcq_combo, KC_BSPC),
  [BSPCWQ_COMBO] = COMBO(bspcwq_combo, A(KC_BSPC)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NUMS:
    case SYMBOLS:
    case LEFT:
    case A_ALT:
    case S_ALT:
    case A_ALTQ:
    case SCLN_Q:
      return TAPPING_TERM * 3;
    default:
      return TAPPING_TERM;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NUMS:
    case SYMBOLS:
      // Immediately select the hold action when another key is pressed.
      return true;
    default:
      // Do not select the hold action when another key is pressed.
      return false;
  }
}
