// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H


#define SPC_SH   RSFT_T(KC_SPC)
#define ENT_AL   LCA_T(KC_ENT)
#define SPC_SHL  LSFT_T(KC_SPC)
#define BSP_CT   LCTL_T(KC_BSPC)

#define RAISE    MO(_RAISE)
#define LOWER    MO(_LOWER)

#define COLM     TG(_COLEMAK_DH)


enum layer_names {
  _COLEMAK_DH,
  _RAISE,
  _LOWER,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* COLEMAK_DH
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ; │ - │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Gui│ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │ \ │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Rai├───┐           ┌───┤Low│
      *               └───┤Spc├───┐   ┌───┤Spc├───┘
      *                   └───┤Del│   │Ent├───┘
      *                       └───┘   └───┘
      */
    [_COLEMAK_DH] = LAYOUT_split_3x6_3(
        KC_ESC  , KC_Q , KC_W , KC_F , KC_P  , KC_B ,                     KC_J   , KC_L , KC_U    , KC_Y   , KC_SCLN , KC_MINS ,
        KC_TAB  , KC_A , KC_R , KC_S , KC_T  , KC_G ,                     KC_M   , KC_N , KC_E    , KC_I   , KC_O    , KC_QUOT ,
        KC_LGUI , KC_Z , KC_X , KC_C , KC_D  , KC_V ,                     KC_K   , KC_H , KC_COMM , KC_DOT , KC_SLSH , KC_BSLS ,
                                       RAISE , SPC_SHL, BSP_CT , ENT_AL , SPC_SH , LOWER
    ),
     /* RAISE
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │ & │ ` │   │       │Dwn│Rgh│End│PgD│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ @ │ ^ │ % │ * │ _ │       │ # │ $ │ ? │ ! │ ~ │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │Up │Lft│Hom│PgU│Ins│   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ # ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_RAISE] = LAYOUT_split_3x6_3(
        _______ , XXXXXXX , XXXXXXX , KC_AMPR , KC_GRV  , XXXXXXX ,                     KC_DOWN , KC_RGHT , KC_END , KC_PGDN , XXXXXXX , XXXXXXX ,
        _______ , KC_AT   , KC_CIRC , KC_PERC , KC_ASTR , KC_UNDS ,                     KC_HASH , KC_DLR , KC_QUES , KC_EXLM , KC_TILD , XXXXXXX ,
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                     KC_UP  , KC_LEFT , KC_HOME , KC_PGUP , KC_INS  , XXXXXXX ,
                                                _______ , _______ , _______ , _______ , _______ , _______
    ),
     /* LOWER
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │ 7 │ 8 │ 9 │ : │       │ + │ [ │ ] │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ 4 │ 5 │ 6 │ . │       │ - │ ( │ ) │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ 1 │ 2 │ 3 │ , │       │ = │ { │ } │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤ # │
      *               └───┤ 0 ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_LOWER] = LAYOUT_split_3x6_3(
        _______ , XXXXXXX , KC_7 , KC_8 , KC_9    , KC_DOT ,                     KC_PLUS , KC_LBRC , KC_RBRC , XXXXXXX  , XXXXXXX , XXXXXXX ,
        _______ , XXXXXXX , KC_4 , KC_5 , KC_6    , KC_COLON ,                     KC_MINS , KC_LPRN , KC_RPRN , XXXXXXX , XXXXXXX , XXXXXXX ,
        _______ , XXXXXXX , KC_1 , KC_2 , KC_3    , KC_COMMA ,                     KC_EQL  , KC_LCBR , KC_RCBR , XXXXXXX , XXXXXXX , XXXXXXX ,
                                          _______ , KC_0    , _______ , _______ , _______ , _______
    ),
     /* ADJUST
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │F10│F7 │F8 │F9 │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │F11│F4 │F5 │F6 │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │F12│F1 │F2 │F3 │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ # ├───┐           ┌───┤ # │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_ADJUST] = LAYOUT_split_3x6_3(
        _______ , KC_F10 , KC_F7 , KC_F8 , KC_F9   , XXXXXXX ,                     _______ , _______ , _______ , _______ , _______ , _______    ,
        _______ , KC_F11 , KC_F4 , KC_F5 , KC_F6   , XXXXXXX ,                     _______ , _______ , _______ , _______ , _______ , _______    ,
        _______ , KC_F12 , KC_F1 , KC_F2 , KC_F3   , XXXXXXX ,                     _______ , _______ , _______ , _______ , _______ , _______ ,
                                           _______ , _______ , _______ , _______ , _______ , _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, BSP_CT, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};
