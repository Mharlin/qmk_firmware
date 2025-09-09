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

enum custom_keycodes {
    A_RING = SAFE_RANGE,
    A_UM,
    O_UM,
    VSCODE,
    INTELLIJ,
    ZEN,
    SLACK,
    WARP,
    LOGSEQ
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods() | get_oneshot_mods();
    bool shifted = mods & MOD_MASK_SHIFT;

    if (record->event.pressed) {
        switch (keycode) {
            case A_RING:
                tap_code16(LALT(KC_A));
                return false;
            case A_UM:
                if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(LALT(KC_U));
                    set_mods(mods);
                    tap_code(KC_A);
                } else {
                    tap_code16(LALT(KC_U));
                    tap_code(KC_A);
                }
                return false;
            case O_UM:
                if (shifted) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(LALT(KC_U));
                    set_mods(mods);
                    tap_code(KC_O);
                } else {
                    tap_code16(LALT(KC_U));
                    tap_code(KC_O);
                }
                return false;
            case VSCODE:
              register_code(KC_LGUI);
              tap_code(KC_SPACE);
              unregister_code(KC_LGUI);
              wait_ms(200);
              send_string("vsc");
              tap_code(KC_ENTER);
              return false;
            case INTELLIJ:
              register_code(KC_LGUI);
              tap_code(KC_SPACE);
              unregister_code(KC_LGUI);
              wait_ms(200);
              send_string("intellij");
              tap_code(KC_ENTER);
              return false;
            case ZEN:
              register_code(KC_LGUI);
              tap_code(KC_SPACE);
              unregister_code(KC_LGUI);
              wait_ms(200);
              send_string("zen");
              tap_code(KC_ENTER);
              return false;
            case WARP:
              register_code(KC_LGUI);
              tap_code(KC_SPACE);
              unregister_code(KC_LGUI);
              wait_ms(200);
              send_string("warp");
              tap_code(KC_ENTER);
              return false;
            case SLACK:
              register_code(KC_LGUI);
              tap_code(KC_SPACE);
              unregister_code(KC_LGUI);
              wait_ms(200);
              send_string("slack");
              tap_code(KC_ENTER);
              return false;
            case LOGSEQ:
              register_code(KC_LGUI);
              tap_code(KC_SPACE);
              unregister_code(KC_LGUI);
              wait_ms(200);
              send_string("logseq");
              tap_code(KC_ENTER);
              return false;
        }
    }
    return true;
}

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
      KC_NO, KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                                          KC_J,   KC_L,              KC_U,              KC_Y,              KC_QUOT,            KC_NO,   \
      KC_NO, LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,                                          KC_M,   LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),       KC_NO,   \
      KC_NO, LT(BUTTON,KC_Z),   ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,               KC_NO,KC_NO, KC_NO,KC_NO,  KC_K,   KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(BUTTON,KC_SLSH), KC_NO, \
                                                                 KC_NO, LT(MEDIA,KC_ESC),LT(NAV,KC_SPC),   LT(MOUSE,KC_TAB), KC_NO, KC_NO,   LT(SYM,KC_ENT),  LT(NUM,KC_BSPC), LT(FUN,KC_DEL), KC_NO
    ),

/*
 * Nav Layer
 *
 * ,------------------------------------.          ,----------------------------------.
 * | Slack| Warp |VsCode|IntelliJ|  Zen |          | Redo | Paste| Copy |  Cut | Undo |
 * |------+------+------+--------+------|          |------+------+------+------+------|
 * | Cmd  |  Alt | Ctrl | Shift  |LogSeq|          |CapsLk|  <-  |   ↑  |   ↓  |  ->  |
 * |------+------+------+--------+------+          +------+------+------+------+------|
 * |      |      |      |        |      |          |Insert| Home | PgDn | PgUp | End  |
 * `-------------+------+--------+------+---|   |--+------+------+------+-------------'
 *                   |      | █████  |      |   | Enter| Bksp | Del  |
 *                   -----------------------'   ---------------------'
 */
    [_NAV] = LAYOUT(
      KC_NO, SLACK,             WARP,              VSCODE,            INTELLIJ,          ZEN,                                  REDO,              PASTE,             COPY,              CUT,               UNDO,      KC_NO,         \
      KC_NO, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           LOGSEQ,                               CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,   KC_NO,         \
      KC_NO, U_NA,              TD(TD_BASE_SWITCH),TD(TD_NUM_SWITCH), TD(TD_NAV_SWITCH), U_NA,   KC_NO,KC_NO, KC_NO,KC_NO,     KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,    KC_NO,         \
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
      KC_NO, U_NA,              KC_NO,             KC_NO,             TD(TD_BASE_SWITCH),U_NA,                                 REDO,              PASTE,             COPY,              CUT,               UNDO,      KC_NO,         \
      KC_NO, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                 U_NA,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,   KC_NO,         \
      KC_NO, U_NA,              KC_ALGR,           TD(TD_SYM_SWITCH), TD(TD_MOUSE_SWITCH),U_NA,   KC_NO,KC_NO, KC_NO,KC_NO,    U_NA,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,   KC_NO,         \
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
      KC_NO, KC_LGUI,          KC_LALT,         KC_LCTL,          KC_LSFT,           U_NA,                                U_NA,             KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,   KC_NO,         \
      KC_NO, UNDO,             CUT,             COPY,             PASTE,             REDO,   KC_NO,KC_NO, KC_NO,KC_NO,    REDO,             PASTE,             COPY,             CUT,             UNDO,     KC_NO,         \
                                            KC_NO, KC_BTN3,           KC_BTN1,           KC_BTN2,  KC_NO, KC_NO,   KC_BTN2,           KC_BTN1,           KC_BTN3, KC_NO
    ),

/*
 * Num Layer
 *
 * ,----------------------------------.          ,----------------------------------.
 * |  {   |  &   |  *   |  (   |  }   |          |      |      |      |      |      |
 * |  [   |  7   |  8   |  9   |  ]   |          |      |  Å   |  Ä   |  Ö   |      |
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
      KC_NO, KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,                              U_NA,              TD(TD_BASE_SWITCH),A_RING,            A_UM,              O_UM,      KC_NO,         \
      KC_NO, KC_SCLN,           KC_4,              KC_5,              LSFT_T(KC_6),      KC_EQL,                               U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,   KC_NO,         \
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
      KC_NO, KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,                                      U_NA,   TD(TD_BASE_SWITCH),KC_NO,              KC_NO,             U_NA,               KC_NO, \
      KC_NO, KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,                                      U_NA,   KC_LSFT,           KC_NO,              KC_NO,             U_NA,               KC_NO,      \
      KC_NO, KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,            KC_NO,KC_NO, KC_NO,KC_NO, U_NA,   TD(TD_SYM_SWITCH), TD(TD_MOUSE_SWITCH),KC_ALGR,           U_NA,               KC_NO, \
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
      KC_NO, KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,                            U_NA,              TD(TD_BASE_SWITCH),KC_NO,              KC_NO,    U_NA,     KC_NO,          \
      KC_NO, KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,                            U_NA,              KC_LSFT,           KC_LCTL,            KC_LALT,  KC_LGUI,  KC_NO,          \
      KC_NO, KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,  KC_NO,KC_NO, KC_NO,KC_NO, U_NA,              TD(TD_FUN_SWITCH), TD(TD_MEDIA_SWITCH),KC_ALGR,  U_NA,     KC_NO,          \
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
    [_MEDIA] = LAYOUT(
      KC_NO, U_NA,              KC_NO,    KC_NO,            TD(TD_BASE_SWITCH), U_NA,                            REDO,             PASTE,             COPY,              CUT,               UNDO,     KC_NO,          \
      KC_NO, KC_LGUI,           KC_LALT,  KC_LCTL,          KC_LSFT,            U_NA,                            U_NA,             KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,  KC_NO,          \
      KC_NO, U_NA,              KC_ALGR,  TD(TD_SYM_SWITCH),TD(TD_MOUSE_SWITCH),U_NA, KC_NO,KC_NO, KC_NO,KC_NO,  U_NA,             KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,  KC_NO,          \
                                          KC_NO, U_NA,       U_NA,              U_NA,  KC_NO, KC_NO,    KC_BTN2,           KC_BTN1,           KC_MUTE, KC_NO
    ),
};
