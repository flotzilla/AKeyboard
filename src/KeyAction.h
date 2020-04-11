#ifndef KEY_ACTION_H
#define KEY_ACTION_H

#include <stdint.h>
#include <WString.h>

class KeyAction
{
private:

    const char language[] = {};

    // keyboard combinations
    const uint8_t keypressMap[6] = {};

    // text to print
    const String &text = "";
public:
    KeyAction(/* args */);
    ~KeyAction();
};

#endif