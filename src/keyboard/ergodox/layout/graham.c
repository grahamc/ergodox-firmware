/* ----------------------------------------------------------------------------
 * ergoDOX layout : GRAHAM (modified from the Kinesis layout)
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"
#include "dvorak-keys.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // layout: layer 0: default
// unused
0,
// left hand
 _dv_bracketL,            _1,            _2,         _3,      _4,    _5, _esc,
         _tab,     _dv_quote,     _dv_comma, _dv_period,   _dv_P, _dv_Y,    1,
         _esc,         _dv_A,         _dv_O,      _dv_E,   _dv_U, _dv_I,
      _shiftL, _dv_semicolon,         _dv_Q,      _dv_J,   _dv_K, _dv_X,    1,
       _ctrlL,     _dv_grave, _dv_backslash,    _arrowL, _arrowR,
                                                  _guiL,   _altL,
                                              0,      0,   _home,
                                            _bs,   _del,    _end,
// right hand
        3,    _6,      _7,      _8,        _9,         _0,  _dv_bracketR,
     _esc, _dv_F,   _dv_G,   _dv_C,     _dv_R,      _dv_L,     _dv_equal,
           _dv_D,   _dv_H,   _dv_T,     _dv_N,      _dv_S,      _dv_dash,
        1, _dv_B,   _dv_M,   _dv_W,     _dv_V,      _dv_Z,       _shiftR,
                  _arrowU, _arrowD, _dv_slash,  _dv_equal,         _guiR,
 _ctrlR,  _guiR,
 _pageU,      0,      0,
 _pageD, _enter, _space ),


	KB_MATRIX_LAYER(  // layout: layer 1: function and symbol keys
// unused
0,
// left hand
  0,        _F1,        _F2,       _F3,       _F4,       _F5, _F11,
  0,  _bracketL,  _bracketR, _bracketL, _bracketR,         0,    1,
  0, _semicolon,     _slash,     _dash,     _0_kp,_semicolon,
  0,      _6_kp,      _7_kp,     _8_kp,     _9_kp,    _equal,    2,
  0,          0,          0,     _prev,     _next,
                                                             0,  0,
                                                         0,  0,  0,
                                                         0,  0,  0,
// right hand
_F12,       _F6,    _F7,       _F8,       _F9,         _F10,   _power,
   0,         0,  _dash,    _comma,   _period,_currencyUnit, _volumeU,
     _backslash,  _1_kp,        _9,        _0,       _equal, _volumeD,
   2,        _8,  _2_kp,     _3_kp,     _4_kp,        _5_kp,    _mute,
                      0,         0,         0,            0,        0,
  0,  0,
  0,  0,  0,
  0,  0,  _playpause),


	KB_MATRIX_LAYER(  // layout: layer 2: keyboard functions
// unused
0,
// left hand
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,
              0,  0,
          0,  0,  0,
          0,  0,  0,
// right hand
      0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,
  0,  0,
  0,  0,  0,
  0,  0,  0 ),


	KB_MATRIX_LAYER(  // layout: layer 3: numpad
// unused
0,
// left hand
0,       0, 0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0, 0,
0, _insert, 0, 0, 0,
                     0, 0,
                  0, 0, 0,
                  0, 0, 0,
// right hand
3, 0,     3, _equal_kp, _div_kp,   _mul_kp, 0,
0, 0, _7_kp,     _8_kp,   _9_kp,   _sub_kp, 0,
   0, _4_kp,     _5_kp,   _6_kp,   _add_kp, 0,
0, 0, _1_kp,     _2_kp,   _3_kp, _enter_kp, 0,
          0,         0, _period, _enter_kp, 0,
0, 0,
0, 0,     0,
0, 0, _0_kp ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// aliases

// basic
#define  kprrel  &kbfun_press_release
#define  ktog    &kbfun_toggle
#define  ktrans  &kbfun_transparent
// media keys
#define  mprrel   &kbfun_mediakey_press_release
// --- layer push/pop functions
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
// ---

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // press: layer 0: default
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 s2kcap, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
        slpunum, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
         kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
         lpush1, kprrel, kprrel, kprrel, kprrel, kprrel, s2kcap,
                         kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // press: layer 1: function and symbol keys
// unused
NULL,
// left hand
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 dbtldr,sshprre,sshprre, kprrel, kprrel,   NULL,  ktrans,
 ktrans, kprrel, kprrel, kprrel, kprrel,sshprre,
 ktrans, kprrel, kprrel, kprrel, kprrel,sshprre, ktrans,
 ktrans, ktrans, ktrans, mprrel, mprrel,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        ktrans,   NULL, kprrel,sshprre,sshprre, kprrel, kprrel,
                kprrel, kprrel,sshprre,sshprre,sshprre, kprrel,
        ktrans,sshprre, kprrel, kprrel, kprrel, kprrel, kprrel,
                        ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, mprrel),


	KB_MATRIX_LAYER(  // press: layer 2: keyboard functions
// unused
NULL,
// left hand
 dbtldr,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                          NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


	KB_MATRIX_LAYER(  // press: layer 3: numpad
// unused
NULL,
// left hand
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, kprrel, ktrans, ktrans, ktrans,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
        ktrans, ktrans,slponum, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                        ktrans, ktrans, kprrel, kprrel, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, kprrel ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // release: layer 0: default
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   lpop1,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 s2kcap, kprrel, kprrel, kprrel, kprrel, kprrel,  lpop1,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
       slponum, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
         lpop1, kprrel, kprrel, kprrel, kprrel, kprrel, s2kcap,
                        kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // release: layer 1: function and symbol keys
// unused
NULL,
// left hand
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
   NULL,sshprre,sshprre, kprrel, kprrel,   NULL,   ktrans,
 ktrans, kprrel, kprrel, kprrel, kprrel,sshprre,
 ktrans, kprrel, kprrel, kprrel, kprrel,sshprre,  ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        ktrans,   NULL, kprrel,sshprre,sshprre, kprrel, kprrel,
                kprrel, kprrel,sshprre,sshprre,sshprre, kprrel,
        ktrans,sshprre, kprrel, kprrel, kprrel, kprrel, kprrel,
                        ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans ),


	KB_MATRIX_LAYER(  // release: layer 2: keyboard functions
// unused
NULL,
// left hand
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                          NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


	KB_MATRIX_LAYER(  // release: layer 3: numpad
// unused
NULL,
// left hand
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, kprrel, ktrans, ktrans, ktrans,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
          NULL, ktrans,   NULL, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                        ktrans, ktrans, kprrel, kprrel, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, kprrel ),


	KB_MATRIX_LAYER(  // release: layer 3: nothing (just making sure unused
			  // functions don't get compiled out)
// unused
NULL,
// other
 kprrel, lpush8,  lpop8,   NULL,   NULL,   NULL,   NULL,   NULL,
   ktog, lpush9,  lpop9,   NULL,   NULL,   NULL,   NULL,   NULL,
 ktrans,lpush10, lpop10,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush1,  lpop1,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush2,  lpop2, dbtldr,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush3,  lpop3,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush4,  lpop4, s2kcap,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush5,  lpop5,slpunum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush6,  lpop6,slponum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush7,  lpop7,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL )

};

