/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
_BASE = 0,
_EXTRA,
_TAP,
_BUTTON,
_NAV,
_MOUSE,
_MEDIA,
_NUM,
_SYM,
_FUN,
};

#define BASE     MO(_BASE)
#define BUTTON   MO(_BUTTON)
#define NAV      MO(_NAV)
#define MOUSE    MO(_MOUSE)
#define MEDIA    MO(_MEDIA)
#define NUM      MO(_NUM)
#define SYM      MO(_SYM)
#define FUN      MO(_FUN)

#define U_NA     KC_NO

enum {
    TD_BASE_SWITCH,
    TD_NUM_SWITCH,
    TD_NAV_SWITCH,
    TD_BUTTON_SWITCH,
    TD_MOUSE_SWITCH,
    TD_MEDIA_SWITCH,
    TD_SYM_SWITCH,
    TD_FUN_SWITCH,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_BASE_SWITCH] = ACTION_TAP_DANCE_DOUBLE(KC_TRNS, TO(_BASE)),
    [TD_NUM_SWITCH] = ACTION_TAP_DANCE_DOUBLE(KC_TRNS, TO(_NUM)),
    [TD_NAV_SWITCH] = ACTION_TAP_DANCE_DOUBLE(KC_TRNS, TO(_NAV)),
    [TD_BUTTON_SWITCH] = ACTION_TAP_DANCE_DOUBLE(KC_TRNS, TO(_BUTTON)),
    [TD_MOUSE_SWITCH] = ACTION_TAP_DANCE_DOUBLE(KC_TRNS, TO(_MOUSE)),
    [TD_MEDIA_SWITCH] = ACTION_TAP_DANCE_DOUBLE(KC_TRNS, TO(_MEDIA)),
    [TD_SYM_SWITCH] = ACTION_TAP_DANCE_DOUBLE(KC_TRNS, TO(_SYM)),
    [TD_FUN_SWITCH] = ACTION_TAP_DANCE_DOUBLE(KC_TRNS, TO(_FUN)),
};

#define REDO LGUI(LSFT(KC_Z))
#define PASTE LGUI(KC_V)
#define COPY LGUI(KC_C)
#define CUT LGUI(KC_X)
#define UNDO LGUI(KC_Z)
// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 * ,----------------------------------.          ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |          |   J  |   L  |   U  |   Y  | '  " |
 * |------+------+------+------+------|          |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |          |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+          +------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |          |   K  |   H  | ,  < | . >  | /  ? |
 * `-------------+------+------+------+---|   |--+------+------+------+-------------'
 *                   | Media| Nav  | Mouse|   | Sym  | Num  | Fun  |
 *                   | Esc  | Space| Tab  |   | Enter| Bksp | Del  |
 *                   ---------------------'   ---------------------'
 */
    [_BASE] = LAYOUT(
      KC_NO, KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,               KC_J,                              KC_L,              KC_U,              KC_Y,              KC_QUOT,            KC_NO,   \
      KC_NO, LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,               KC_M,                              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),       KC_NO,   \
      KC_NO, LT(BUTTON,KC_Z),   ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,               KC_K,  KC_NO,KC_NO, KC_NO,KC_NO,   KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(BUTTON,KC_SLSH), KC_NO, \
                                                                 KC_NO, LT(MEDIA,KC_ESC),LT(NAV,KC_SPC),   LT(MOUSE,KC_TAB), KC_NO, KC_NO,   LT(SYM,KC_ENT),  LT(NUM,KC_BSPC), LT(FUN,KC_DEL), KC_NO
    ),

/*
 * Nav Layer
 *
 * ,----------------------------------.          ,----------------------------------.
 * |      |      |      |      |      |          | Redo | Paste| Copy |  Cut | Undo |
 * |------+------+------+------+------|          |------+------+------+------+------|
 * | Cmd  |  Alt | Ctrl | Shift|      |          |CapsLk|  <-  |   ↑  |   ↓  |  ->  |
 * |------+------+------+------+------+          +------+------+------+------+------|
 * |      |      |      |      |      |          |Insert| Home | PgDn | PgUp | End  |
 * `-------------+------+------+------+---|   |--+------+------+------+-------------'
 *                   |      | ████ |      |   | Enter| Bksp | Del  |
 *                   ---------------------'   ---------------------'
 */
    [_NAV] = LAYOUT(
      KC_NO, U_NA,              KC_NO,             KC_NO,             TD(TD_BASE_SWITCH),U_NA,                                 REDO,             PASTE,             COPY,             CUT,             UNDO,     KC_NO,         \
      KC_NO, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                 CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,   KC_NO,         \
      KC_NO, U_NA,              KC_ALGR,           TD(TD_NUM_SWITCH), TD(TD_NAV_SWITCH), U_NA,   KC_NO,KC_NO, KC_NO,KC_NO,     KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,    KC_NO,         \
                                            KC_NO, U_NA,              U_NA,              U_NA,    KC_NO, KC_NO,       KC_ENT,            KC_BSPC,           KC_DEL, KC_NO
    ),

/*
 * Mouse Layer
 *
 * ,----------------------------------.          ,----------------------------------.
 * |      |      |      |      |      |          | Redo | Paste| Copy |  Cut | Undo |
 * |------+------+------+------+------|          |------+------+------+------+------|
 * | Cmd  |  Alt | Ctrl | Shift|      |          |      |  <-  |   ↑  |   ↓  |  ->  |
 * |------+------+------+------+------+          +------+------+------+------+------|
 * |      |      |      |      |      |          |      |  <-  |   ↑  |   ↓  |  ->  |
 * `-------------+------+------+------+---|   |--+------+------+------+-------------'
 *                   |      |      | ████ |   | Right | Left | Middle|
 *                   ---------------------'   -----------------------'
 */
    [_MOUSE] = LAYOUT(
      KC_NO, U_NA,              KC_NO,             KC_NO,             TD(TD_BASE_SWITCH),U_NA,                                 REDO,             PASTE,             COPY,             CUT,             UNDO,     KC_NO,         \
      KC_NO, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                 U_NA,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,   KC_NO,         \
      KC_NO, U_NA,              KC_ALGR,           TD(TD_SYM_SWITCH), TD(TD_MOUSE_SWITCH),U_NA,   KC_NO,KC_NO, KC_NO,KC_NO,     U_NA,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,   KC_NO,         \
                                           KC_NO, U_NA,              U_NA,              U_NA,    KC_NO, KC_NO,        KC_BTN2,           KC_BTN1,           KC_BTN3, KC_NO
    ),

/*
 * Button Layer
 *
 * ,----------------------------------.          ,----------------------------------.
 * | Undo |  Cut | Copy | Paste| Redo |          | Redo | Paste| Copy |  Cut | Undo |
 * |------+------+------+------+------|          |------+------+------+------+------|
 * | Cmd  |  Alt | Ctrl | Shift|      |          |      | Shift| Ctrl |  Alt |  Cmd |
 * |------+------+------+------+------+          +------+------+------+------+------|
 * | Undo |  Cut | Copy | Paste| Redo |          | Redo | Paste| Copy |  Cut | Undo |
 * `-------------+------+------+------+---|   |--+------+------+------+-------------'
 *                   |Middle| Left | Right|   | Right | Left | Middle|
 *                   ---------------------'   -----------------------'
 */
    [_BUTTON] = LAYOUT(
      KC_NO, UNDO,             CUT,             COPY,             PASTE,             REDO,                                REDO,             PASTE,             COPY,             CUT,             UNDO,     KC_NO,         \
      KC_NO, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                 U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,   KC_NO,         \
      KC_NO, UNDO,             CUT,             COPY,             PASTE,             REDO,   KC_NO,KC_NO, KC_NO,KC_NO,    REDO,             PASTE,             COPY,             CUT,             UNDO,     KC_NO,         \
                                            KC_NO, KC_BTN3,           KC_BTN1,           KC_BTN2,  KC_NO, KC_NO,   KC_BTN2,           KC_BTN1,           KC_BTN3, KC_NO
    ),

/*
 * Num Layer
 *
 * ,----------------------------------.          ,----------------------------------.
 * |  {   |  &   |  *   |  (   |  }   |          |      |      |      |      |      |
 * |  [   |  7   |  8   |  9   |  ]   |          |      |      |      |      |      |
 * |------+------+------+------+------|          |------+------+------+------+------|
 * |  :   |  $   |  %   |  ^   |  +   |          |      |      |      |      |      |
 * |  ;   |  4   |  5   |  6   |  =   |          |      | Shift| Ctrl |  Alt |  Cmd |
 * |------+------+------+------+------+          +------+------+------+------+------|
 * |  ~   |  !   |  @   |  #   |  |   |          |      |      |      |      |      |
 * |  `   |  1   |  2   |  3   |  \   |          |      |      |      |      |      |
 * `-------------+------+------+------+---|   |--+------+------+------+-------------'
 *                   |  >   |  )   |  _   |   |      |      |      |
 *                   |  .   |  0   |  -   |   |      | ████ |      |
 *                   ---------------------'   ---------------------'
 */
    [_NUM] = LAYOUT(
      KC_NO, KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,                              U_NA,              TD(TD_BASE_SWITCH),KC_NO,             KC_NO,             U_NA,      KC_NO,         \
      KC_NO, KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,                               U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,   KC_NO,         \
      KC_NO, KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,  KC_NO,KC_NO, KC_NO,KC_NO,   U_NA,              TD(TD_NUM_SWITCH), TD(TD_NAV_SWITCH), KC_ALGR,           U_NA,      KC_NO,         \
                                            KC_NO, KC_DOT,            KC_0,              KC_MINS,  KC_NO, KC_NO,   U_NA,              U_NA,              U_NA, KC_NO
    ),

/*
 * Sym Layer
 *
 * ,----------------------------------.          ,----------------------------------.
 * |  {   |  &   |  *   |  (   |  }   |          |      |      |      |      |      |
 * |------+------+------+------+------|          |------+------+------+------+------|
 * |  :   |  $   |  %   |  ^   |  +   |          |      | Shift| Ctrl |  Alt |  Cmd |
 * |------+------+------+------+------+          +------+------+------+------+------|
 * |  ~   |  !   |  @   |  #   |  |   |          |      |      |      |      |      |
 * `-------------+------+------+------+---|   |--+------+------+------+-------------'
 *                   |      |      |  _   |   |      |      |      |
 *                   |  (   |  )   |  _   |   | ████ |      |      |
 *                   ---------------------'   ---------------------'
 */
    [_SYM] = LAYOUT(
      KC_NO, KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           U_NA,                              TD(TD_BASE_SWITCH),KC_NO,              KC_NO,             U_NA,               KC_NO, \
      KC_NO, KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           U_NA,                              KC_LSFT,           LCTL_T(SWEDISH_AA), LALT_T(SWEDISH_AE),LGUI_T(SWEDISH_OE), KC_NO,      \
      KC_NO, KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           U_NA,  KC_NO,KC_NO, KC_NO,KC_NO,   TD(TD_SYM_SWITCH), TD(TD_MOUSE_SWITCH),KC_ALGR,           U_NA,               KC_NO, \
                                            KC_NO, KC_LPRN,           KC_RPRN,           KC_UNDS,  KC_NO, KC_NO,   U_NA,              U_NA,              U_NA, KC_NO
    ),

/*
 * Fun Layer
 *
 * ,----------------------------------.          ,----------------------------------.
 * |  F12 | F7   | F8   | F9   |PrtScn|          |      |      |      |      |      |
 * |------+------+------+------+------|          |------+------+------+------+------|
 * |  F11 | F4   | F5   | F6   | ScLck|          |      | Shift| Ctrl |  Alt |  Cmd |
 * |------+------+------+------+------+          +------+------+------+------+------|
 * |  F10 | F1   | F2   | F3   | Pause|          |      |      |      |      |      |
 * `-------------+------+------+------+---|   |--+------+------+------+-------------'
 *                   |  ☰  |  Spc  | Tab |   |      |      | ████ |
 *                   ---------------------'   ---------------------'
 */
    [_FUN] = LAYOUT(
      KC_NO, KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,                            U_NA,              TD(TD_BASE_SWITCH),KC_NO,  KC_NO,    U_NA,     KC_NO,          \
      KC_NO, KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,                            U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,  KC_NO,          \
      KC_NO, KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,  KC_NO,KC_NO, KC_NO,KC_NO, U_NA,              TD(TD_FUN_SWITCH),    TD(TD_MEDIA_SWITCH),  KC_ALGR,           U_NA,     KC_NO,          \
                                            KC_NO, KC_APP,            KC_SPC,            KC_TAB,  KC_NO, KC_NO,  U_NA,              U_NA,              U_NA, KC_NO
    ),

/*
 * Media Layer
 *
 * ,----------------------------------.          ,----------------------------------.
 * |      |      |      |      |      |          | Redo | Paste| Copy |  Cut | Undo |
 * |------+------+------+------+------|          |------+------+------+------+------|
 * | Cmd  |  Alt | Ctrl | Shift|      |          |      | Prev | VolUp| VolDn| Next |
 * |------+------+------+------+------+          +------+------+------+------+------|
 * |      |      |      |      |      |          |      |  <-  |   ↑  |   ↓  |  ->  |
 * `-------------+------+------+------+---|   |--+------+------+------+-------------'
 *                   | ████ |      |      |   | Stop | Play | Mute |
 *                   ---------------------'   ---------------------'
 */
    [_MOUSE] = LAYOUT(
      KC_NO, U_NA,              KC_NO,    KC_NO,  TD(TD_BASE_SWITCH),   U_NA,                            REDO,             PASTE,             COPY,             CUT,             UNDO,    KC_NO,          \
      KC_NO, KC_LGUI,           KC_LALT,  KC_LCTL,           KC_LSFT,           U_NA,                            U_NA,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,  KC_NO,          \
      KC_NO, U_NA,              KC_ALGR,  TD(TD_SYM_SWITCH),    TD(TD_MOUSE_SWITCH),  U_NA, KC_NO,KC_NO, KC_NO,KC_NO,  U_NA,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,  KC_NO,          \
                                          KC_NO, U_NA,              U_NA,              U_NA,  KC_NO, KC_NO,    KC_BTN2,           KC_BTN1,           KC_BTN3, KC_NO
    ),

};

/*
#define MIRYOKU_ALTERNATIVES_MEDIA \
TD(U_TD_BOOT),     KC_NO,    TD(U_TD_U_EXTRA),  TD(TD_BASE_SWITCH),   U_NA,              RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           \
U_NA,              KC_ALGR,           TD(TD_FUN_SWITCH),    TD(TD_MEDIA_SWITCH),  U_NA,              OU_AUTO,           U_NU,              U_NU,              U_NU,              U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP
// #define MIRYOKU_ALTERNATIVES_FUN \
// KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              TD(TD_BASE_SWITCH),   TD(U_TD_U_EXTRA),  KC_NO,    TD(U_TD_BOOT),     \
// KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
// KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              TD(TD_FUN_SWITCH),    TD(TD_MEDIA_SWITCH),  KC_ALGR,           U_NA,              \
// U_NP,              U_NP,              KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

// #define MIRYOKU_ALTERNATIVES_NUM \
// KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           U_NA,              TD(TD_BASE_SWITCH),   TD(U_TD_U_EXTRA),  KC_NO,    TD(U_TD_BOOT),     \
// KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
// KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           U_NA,              TD(TD_NUM_SWITCH),    TD(TD_NAV_SWITCH),    KC_ALGR,           U_NA,              \
// U_NP,              U_NP,              KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP
// #define MIRYOKU_ALTERNATIVES_BUTTON \
// UNDO,             CUT,             COPY,             PASTE,             U_RDO,             U_RDO,             PASTE,             COPY,             CUT,             UNDO,             \
// KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,              U_NU,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
// UNDO,             CUT,             COPY,             PASTE,             U_RDO,             U_RDO,             PASTE,             COPY,             CUT,             UNDO,             \
// U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP
// #define MIRYOKU_ALTERNATIVES_MOUSE \
// TD(U_TD_BOOT),     KC_NO,    TD(U_TD_U_EXTRA),  TD(TD_BASE_SWITCH),   U_NA,              U_RDO,             PASTE,             COPY,             CUT,             UNDO,             \
// KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           \
// U_NA,              KC_ALGR,           TD(TD_SYM_SWITCH),    TD(TD_MOUSE_SWITCH),  U_NA,              U_NU,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           \
// U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP
// #define MIRYOKU_ALTERNATIVES_NAV \
// TD(U_TD_BOOT),     KC_NO,    TD(U_TD_U_EXTRA),  TD(TD_BASE_SWITCH),   U_NA,              U_RDO,             PASTE,             COPY,             CUT,             UNDO,             \
// KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
// U_NA,              KC_ALGR,           TD(TD_NUM_SWITCH),    TD(TD_NAV_SWITCH),    U_NA,              KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            \
// U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP
// #define MIRYOKU_LAYER_BASE \
// KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
// LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),      \
// LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),\
// U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

// #define MIRYOKU_LAYER_SYM \
// KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           U_NA,              TD(TD_BASE_SWITCH),   TD(U_TD_U_EXTRA),  KC_NO,    TD(U_TD_BOOT),     \
// KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           U_NA,              KC_LSFT,           LCTL_T(SWEDISH_AA),LALT_T(SWEDISH_AE),LGUI_T(SWEDISH_OE),      \
// KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           U_NA,              TD(TD_SYM_SWITCH),    TD(TD_MOUSE_SWITCH),  KC_ALGR,           U_NA,              \
// U_NP,              U_NP,              KC_LPRN,           KC_RPRN,           KC_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

*/

// clang-format on

// enum layers {
//     _QWERTY = 0,
//     _DVORAK,
//     _COLEMAK_DH,
//     _NAV,
//     _SYM,
//     _FUNCTION,
//     _ADJUST,
// };

/*
// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/ *
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * /
    [_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                ADJUST , KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
    ),

/ *
 * Base Layer: Dvorak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   | ' "  | , <  | . >  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |Ctrl/- _|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift | ; :  |   Q  |   J  |   K  |   X  | [ {  |CapsLk|  |F-keys|  ] } |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * /
    [_DVORAK] = LAYOUT(
     KC_TAB  ,KC_QUOTE,KC_COMM,  KC_DOT,   KC_P ,   KC_Y ,                                        KC_F,   KC_G ,  KC_C ,   KC_R ,  KC_L , KC_BSPC,
     CTL_ESC , KC_A ,  KC_O   ,  KC_E  ,   KC_U ,   KC_I ,                                        KC_D,   KC_H ,  KC_T ,   KC_N ,  KC_S , CTL_MINS,
     KC_LSFT ,KC_SCLN, KC_Q   ,  KC_J  ,   KC_K ,   KC_X , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_B,   KC_M ,  KC_W ,   KC_V ,  KC_Z , KC_RSFT,
                                 ADJUST, KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
    ),

/ *
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * /
    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
     CTL_ESC , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                        KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , CTL_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                 ADJUST, KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
    ),

/ *
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * /
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/ *
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * /
    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/ *
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * /
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/ *
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * /
    [_ADJUST] = LAYOUT(
      _______, _______, _______, QWERTY , _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, DVORAK , _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, COLEMAK, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

// / *
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * /
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

 */

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */
