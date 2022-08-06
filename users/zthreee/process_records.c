#include "zthreee.h"

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

#ifdef OLED_ENABLE
__attribute__((weak))
bool process_record_oled(uint16_t keycode, keyrecord_t *record) { return true; }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Sends pyenv to activate 'jira' environment
    case M_PYNV:
      if (record->event.pressed) {
        SEND_STRING("pyenv activate jira\n");
      }
      break;

    // Sends Cmd + alt + shift to a keycode to activate shiftit. See: https://github.com/fikovnik/ShiftIt
    case M_SHFT:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
      }
      break;

    // Opens Terminal
    case M_TERM:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPACE) SS_UP(X_LGUI));
        wait_ms(250);
        SEND_STRING("terminal\n");
      }
      break;

    // BEGIN: Layer macros
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      break;
    // END: Layer macros
  }

  return process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
         #ifdef OLED_ENABLE
         && process_record_oled(keycode, record)
         #endif
         ; // Close return
}
