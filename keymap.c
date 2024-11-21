#include QMK_KEYBOARD_H

// clang-format off

enum layers {
  BASE,
  EDITOR,
  SPACE_MOVES,
  G_MOVES,
  T_MOVES,
  D_MOVES,
  C_MOVES,
  S_MOVES,
  SPECIAL,
};

enum keycodes {
    KC_SLSH_SEARCH = QK_USER,
    KC_A_ADD_CURSOR,
    KC_E_SELECTION,
    KC_DOT_SYMBOL,
    KC_W_WORD_NEXT,
    KC_B_WORD_PREV,
    KC_Q_COMMENT,
    KC_BSLS_BAR,
    KC_LBRC_BRACKET,
    KC_D_DEFINITION,
    KC_R_REFERENCES,
    KC_E_ERRORS,
    KC_C_CAMEL,
    KC_P_PASCAL,
    KC_E_ENUM,
    KC_S_SNAKE,
    KC_L_LOWER,
    KC_U_UPPER,
    KC_W_WORD,
    KC_T_TAG,
    KC_D_LINE,
    KC_B_BRACKETS,
    KC_F_FILES,
    KC_P_PROJECT,
    KC_H_SPLIT_LEFT,
    KC_J_SPLIT_DOWN,
    KC_K_SPLIT_UP,
    KC_L_SPLIT_RIGHT,
    KC_W_CLOSE,
    KC_A_CLOSE_ALL,
    KC_S_SPLIT_HORIZONTALLY,
    KC_V_SPLIT_VERTICALLY,
    KC_R_RENAME,
    KC_S_SUGESSTIONS,
    KC_A_ACTION,
    KC_R_CONSOLE,
    KC_R_DELETE_CONSOLE
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_60_ansi(
    QK_GRAVE_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    TO(EDITOR), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LWIN, KC_LALT, KC_SPC, KC_RALT, MO(SPACE_MOVES), MO(SPECIAL), KC_CAPS),

  [EDITOR] = LAYOUT_60_ansi(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_F5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F11, KC_EQL, _______,
    KC_TAB, KC_Q_COMMENT, KC_W_WORD_NEXT, KC_E_SELECTION, _______, _______, _______, _______, TO(BASE), KC_HOME, KC_END, KC_LBRC_BRACKET, _______, KC_BSLS_BAR,
    _______, KC_A_ADD_CURSOR, KC_S, OSL(D_MOVES), _______, OSL(G_MOVES), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B_WORD_PREV, _______, HYPR(KC_M), _______, KC_DOT_SYMBOL, KC_SLSH_SEARCH, KC_RSFT,
    KC_LCTL, KC_LWIN, KC_LALT, OSL(SPACE_MOVES), KC_RALT, _______, _______, _______),

  [SPACE_MOVES] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_R_CONSOLE, OSL(T_MOVES), _______, _______, _______, _______, KC_P_PROJECT, _______, _______, _______,
    _______, _______, OSL(S_MOVES), _______, KC_F_FILES, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, OSL(C_MOVES), _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______),

  [G_MOVES] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_E_ERRORS, KC_R_REFERENCES, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_D_DEFINITION, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______),

  [T_MOVES] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_E_ENUM, _______, _______, _______, KC_U_UPPER, _______, _______, KC_P_PASCAL, _______, _______, _______,
    _______, _______, KC_S_SNAKE, _______, _______, _______, _______, _______, _______, KC_L_LOWER, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______),

  [D_MOVES] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_W_WORD, _______, KC_R_DELETE_CONSOLE, KC_T_TAG, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_D_LINE, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_B_BRACKETS, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______),

  [S_MOVES] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_W_CLOSE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_A_CLOSE_ALL, KC_S_SPLIT_HORIZONTALLY, _______, _______, _______, KC_H_SPLIT_LEFT, KC_J_SPLIT_DOWN, KC_K_SPLIT_UP, KC_L_SPLIT_RIGHT, _______, _______, _______,
    _______, _______, _______, _______, KC_V_SPLIT_VERTICALLY, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______),

  [C_MOVES] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_R_RENAME, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_A_ACTION, KC_S_SUGESSTIONS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______),


  [SPECIAL] = LAYOUT_60_ansi(
    QK_BOOTLOADER, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
  switch (keycode) {
  case KC_A_ADD_CURSOR:
    if (!record -> event.pressed) {
      return false;
    }

    tap_code16(A(KC_BSLS));

    return false;
    break;

  case KC_SLSH_SEARCH:
    if (!record -> event.pressed) {
      return false;
    }

    tap_code16(C(KC_F));
    layer_off(EDITOR);
    layer_on(BASE);

    return false;
    break;

  case KC_Q_COMMENT:
    if (!record -> event.pressed) {
      return false;
    }

    tap_code16(C(KC_SLSH));

    return false;
    break;

  case KC_E_SELECTION:
    if (!record -> event.pressed) {
      return false;
    }

    if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
					tap_code16(HYPR(KC_E));
					return false;
				} else {
					tap_code16(LCAG(KC_E));
					return false;
				}

    return false;

    break;

  case KC_W_WORD_NEXT:
    if (!record -> event.pressed) {
      return false;
    }

    if (keyboard_report->mods & MOD_BIT(KC_LALT)) {
					tap_code16(LCAG(KC_RGHT));
					return false;
				} else {
					tap_code16(C(KC_RGHT));
					return false;
				}

    return false;

    break;

  case KC_B_WORD_PREV:
    if (!record -> event.pressed) {
      return false;
    }

    if (keyboard_report->mods & MOD_BIT(KC_LALT)) {
					tap_code16(LCAG(KC_LEFT));
					return false;
				} else {
					tap_code16(C(KC_LEFT));
					return false;
				}

    return false;

    break;

    case KC_LBRC_BRACKET:
    if (!record -> event.pressed) {
      return false;
    }

    if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
					tap_code16(C(S(KC_9)));
					return false;
				} else {
					tap_code16(C(S(KC_BSLS)));
					return false;
				}

    return false;

    break;

  case KC_DOT_SYMBOL:
    if (!record -> event.pressed) {
      return false;
    }

    if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
					tap_code16(S(KC_F7));
					return false;
				} else {
					tap_code16(KC_F7);
					return false;
				}


    return false;

    break;

  case KC_E_ERRORS:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(HYPR(KC_F8));

    break;

  case KC_D_DEFINITION:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_K));
    tap_code16(KC_F12);
    break;

  case KC_R_REFERENCES:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(S(A(KC_F12)));
    break;

  case KC_E_ENUM:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F12));
		tap_code16(KC_E);

    break;

  case KC_P_PASCAL:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F12));
		tap_code16(KC_P);

    break;

  case KC_S_SNAKE:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F12));
		tap_code16(KC_S);

    break;

  case KC_C_CAMEL:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F12));
		tap_code16(KC_C);

    break;

  case KC_L_LOWER:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F12));
		tap_code16(KC_L);

    break;

  case KC_U_UPPER:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F12));
		tap_code16(KC_U);

    break;

  case KC_D_LINE:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(S(KC_K)));

    break;

  case KC_B_BRACKETS:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(A(KC_BACKSPACE)));

    break;
  case KC_W_WORD:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F13));
		tap_code16(KC_W);

    break;
  case KC_T_TAG:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F13));
		tap_code16(KC_T);

    break;

  case KC_F_FILES:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_P));

    layer_off(EDITOR);
    layer_on(BASE);

    break;

  case KC_P_PROJECT:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(S(KC_F)));

    layer_off(EDITOR);
    layer_on(BASE);

    break;

  case KC_S_SPLIT_HORIZONTALLY:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_BSLS));

    break;

  case KC_V_SPLIT_VERTICALLY:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_K));
		tap_code16(C(KC_BSLS));

    break;

  case KC_W_CLOSE:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_W));

    break;

  case KC_A_CLOSE_ALL:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_K));
		tap_code16(KC_W);

    break;

  case KC_H_SPLIT_LEFT:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F14));
		tap_code16(KC_LEFT);

    break;

  case KC_J_SPLIT_DOWN:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F14));
		tap_code16(KC_DOWN);

    break;

  case KC_K_SPLIT_UP:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F14));
		tap_code16(KC_UP);

    break;

  case KC_L_SPLIT_RIGHT:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F14));
		tap_code16(KC_RGHT);

    break;

  case KC_BSLS_BAR:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_B));

    break;

  case KC_S_SUGESSTIONS:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_SPACE));

    break;

  case KC_A_ACTION:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_DOT));

    break;

  case KC_R_RENAME:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(KC_F2);

    break;

  case KC_R_CONSOLE:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(KC_F15));
		tap_code16(KC_R);

    break;

  case KC_R_DELETE_CONSOLE:
    if (!record -> event.pressed) {
      return false;
    }
		tap_code16(C(A(KC_F15)));
		tap_code16(KC_R);

    break;

  }


  return true;
};

bool rgb_matrix_indicators_kb(void) {
  if (!rgb_matrix_indicators_user()) {
    return false;
  }

  switch (get_highest_layer(layer_state | default_layer_state)) {

  case SPECIAL:
    rgb_matrix_set_color_all(128, 237, 153);
    break;
  case G_MOVES:
  case T_MOVES:
  case D_MOVES:
  case S_MOVES:
  case SPACE_MOVES:
  case EDITOR:
    rgb_matrix_set_color_all(120, 0, 0);
    break;
  case BASE:
    rgb_matrix_set_color_all(0, 32, 200);
    break;
  default:
    break;
  }

  return true;
}

void keyboard_post_init_user(void) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};