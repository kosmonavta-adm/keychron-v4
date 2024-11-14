#include QMK_KEYBOARD_H

// clang-format off

enum layers {
  BASE,
  _FN0,
  _FN1,
  _FN2,
};

enum keycodes {
    KC_SEARCH = QK_USER,
    KC_ADD_SELECTION,
    KC_SELECTION,
    KC_SYMBOL
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_60_ansi(
    QK_GRAVE_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    TO(_FN0), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LWIN, KC_LALT, KC_SPC, KC_RALT, MO(_FN1), MO(_FN2), KC_CAPS),

  [_FN0] = LAYOUT_60_ansi(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_F5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F11, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, C(KC_RGHT), KC_SELECTION, KC_R, HYPR(KC_4), HYPR(KC_F5), KC_F6, TO(BASE), KC_HOME, KC_END, KC_LBRC, KC_RBRC, HYPR(KC_BSLS),
    KC_F16, KC_ADD_SELECTION, KC_S, KC_D, KC_F, KC_G, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, C(KC_LEFT), HYPR(KC_F11), HYPR(KC_F12), HYPR(KC_COMM), KC_SYMBOL, KC_SEARCH, KC_RSFT,
    KC_LCTL, KC_LWIN, KC_LALT, QK_LEAD, KC_RALT, MO(_FN1), MO(_FN2), KC_CAPS),

  [_FN1] = LAYOUT_60_ansi(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_MSTP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MNXT, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO),

  [_FN2] = LAYOUT_60_ansi(
    QK_BOOTLOADER, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
  switch (keycode) {
  case KC_ADD_SELECTION:
    if (!record -> event.pressed) {
      return false;
    }

    tap_code16(C(KC_D));

    return false;
    break;

  case QK_LEAD:
    if (!record -> event.pressed) {
      layer_off(_FN0);
      layer_on(BASE);
    }

    break;

  case KC_SEARCH:
    if (!record -> event.pressed) {
      return false;
    }

    tap_code16(C(KC_F));
    layer_off(_FN0);
    layer_on(BASE);

    return false;
    break;

  case KC_SELECTION:
    if (!record -> event.pressed) {
      return false;
    }

    if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
					tap_code16(S(A(KC_LEFT)));
					return false;
				} else {
					tap_code16(S(A(KC_RGHT)));
					return false;
				}

    return false;

    break;

  case KC_SYMBOL:
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
  }
  return true;
};

bool rgb_matrix_indicators_kb(void) {
  if (!rgb_matrix_indicators_user()) {
    return false;
  }

  switch (get_highest_layer(layer_state | default_layer_state)) {

  case _FN2:
    rgb_matrix_set_color_all(128, 237, 153);
    break;
  case _FN1:
    rgb_matrix_set_color_all(102, 0, 255);
    break;
  case _FN0:
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

void leader_end_user(void) {
  if (leader_sequence_one_key(KC_F)) {
    tap_code16(C(KC_P));
  } else if (leader_sequence_two_keys(KC_F, KC_F)) {
    tap_code16(C(S(KC_F)));
  } else if (leader_sequence_one_key(KC_D)) {
    tap_code16(C(S(KC_K)));

    layer_on(_FN0);
    layer_off(BASE);
  } else if (leader_sequence_two_keys(KC_D, KC_B)) {
    tap_code16(C(A(KC_BSPC)));

    layer_on(_FN0);
    layer_off(BASE);
  } else if (leader_sequence_one_key(KC_S)) {
    tap_code16(C(KC_BSLS));

    layer_on(_FN0);
    layer_off(BASE);
  } else if (leader_sequence_two_keys(KC_S, KC_V)) {
    tap_code16(C(KC_K));
    tap_code16(C(KC_BSLS));

    layer_on(_FN0);
    layer_off(BASE);
  } else if (leader_sequence_two_keys(KC_V, KC_E)) {
    tap_code16(C(S(KC_E)));

    layer_on(_FN0);
    layer_off(BASE);
  } else if (leader_sequence_two_keys(KC_V, KC_G)) {
    tap_code16(C(S(KC_G)));

    layer_on(_FN0);
    layer_off(BASE);
  } else if (leader_sequence_two_keys(KC_V, KC_X)) {
    tap_code16(C(S(KC_X)));

    layer_on(_FN0);
    layer_off(BASE);
  } else if (leader_sequence_two_keys(KC_V, KC_T)) {
    tap_code16(C(KC_GRAVE));

    layer_on(_FN0);
    layer_off(BASE);
  } else if (leader_sequence_two_keys(KC_C, KC_R)) {
    tap_code16(KC_F2);
  } else if (leader_sequence_two_keys(KC_C, KC_S)) {
    tap_code16(C(KC_SPC));

    layer_on(_FN0);
    layer_off(BASE);
  } else if (leader_sequence_two_keys(KC_C, KC_A)) {
    tap_code16(C(KC_DOT));

    layer_on(_FN0);
    layer_off(BASE);
  } else if (leader_sequence_two_keys(KC_G, KC_D)) {
    tap_code16(KC_F12);

    layer_on(_FN0);
    layer_off(BASE);
  } else if (leader_sequence_two_keys(KC_G, KC_R)) {
    tap_code16(S(A(KC_F12)));

    layer_on(_FN0);
    layer_off(BASE);
  }
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