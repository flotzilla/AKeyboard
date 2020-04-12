#ifndef KEYSET_H
#define KEYSET_H

#include <KeyboardMultiLanguage.h>
#include "KeyboardMappingRU.h"
#include <stdint.h>
#include <WString.h>

#define KEY_MAP_SIZE 6
class KeySet
{
private:

     char* language;

    // keyboard combinations
    uint8_t keypressMap[KEY_MAP_SIZE] = {};

    // text to print
    String text = "";

public:
    KeySet(/* args */);
    KeySet(String text);
    KeySet(String text, char *language);
    KeySet(uint8_t *keyMap[KEY_MAP_SIZE]);

    void runAction();
    void keyRelease();
};

#endif