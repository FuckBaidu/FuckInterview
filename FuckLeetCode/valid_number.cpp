/*
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all
 * requirements up front before implementing one.
 */
#include <assert.h>
#include <ctype.h>
enum InputType {
    kInvalid,
    kDigit,
    kDot,
    kExp,
    kSpace,
    kSign,
    kNumInputTypes,
};

enum State {
    kFail = -1,// invalid state
    kStart = 0,  // start or with heading spaces
    kDigits = 1, // integer, eg: 123
    kOnlyDot = 2,    // only dot at the begin of string
    kOnlySign = 3,   // only sign at the begin of string
    kDotDigits = 4, // float. eg: .5 123.1 2.
    kExpStart = 5,    // now number with "e" or "E" at the end. eg: 123E 123e
    kExpDigits = 6, // now number with "e" or "E" within. eg: 123e1 123.2E
    kExpDigitsSign = 7,  //now number has "e" or "E" inside, and with a sign at the end. eg: 123E+
    kTailingSpaces  = 8, // trailing sapces after numer
};

bool IsValidNumber(const char *s) {
    static State transitions[][kNumInputTypes] = {
      {kFail, kDigits, kOnlyDot, kFail, kStart, kOnlySign}, // next state for kStart
      {kFail, kDigits, kDotDigits, kExpStart, kTailingSpaces, kFail}, // next state for kDigits
      {kFail, kDotDigits, kFail, kFail, kFail, kFail}, // next state for kOnlyDot
      {kFail, kDigits, kOnlyDot, kFail, kFail, kFail}, // next state for kOnlySign
      {kFail, kDotDigits, kFail, kExpStart, kTailingSpaces, kFail}, // next state for kDotDigits
      {kFail, kExpDigits, kFail, kFail, kFail, kExpDigitsSign}, // next state for kExpStart
      {kFail, kExpDigits, kFail, kFail, kTailingSpaces, kFail}, // next state for kExpDigits
      {kFail, kExpDigits, kFail, kFail, kFail, kFail}, // next state for kExpDigitsSign
      {kFail, kFail, kFail, kFail, kTailingSpaces, kFail}, // next state for kTailingSpaces
    };
    if (!s || !*s)
        return false;
    State state = kStart;
    while (*s) {
        InputType input_type;
        if (isdigit(*s))
            input_type = kDigit;
        else if (*s == '+' || *s == '-')
            input_type = kSign;
        else if (*s == ' ')
            input_type = kSpace;
        else if (*s == '.')
            input_type = kDot;
        else if (*s == 'e' || *s == 'E')
            input_type = kExp;
        else
            input_type = kInvalid;
        state = transitions[(int)state][input_type];
        if (state == kFail)
            return false;
        s++;
    }
    return state == kDigits || state == kDotDigits || state == kExpDigits || state == kTailingSpaces;
}

int main() {
    assert(IsValidNumber("123"));
    assert(IsValidNumber("1."));
    assert(IsValidNumber("  .1 "));
    assert(IsValidNumber("  -.1 "));
    assert(IsValidNumber("  +.1 "));
    assert(!IsValidNumber("  - .1 "));
    assert(!IsValidNumber("   . "));
    assert(!IsValidNumber("123e"));
    assert(!IsValidNumber("123e1.2"));
    assert(IsValidNumber("123.23213e-2 "));
    assert(!IsValidNumber("e-2 "));
    return 0;
}
