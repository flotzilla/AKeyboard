#ifndef KEYBOARD4X3
#define KEYBOARD4X3

#include <Arduino.h>
#include <KeyboardMultiLanguage.h>
#include "KeyboardMappingRU.h"

#define KEY_COUNT 12

class Keyboard4x3
{

private:
    int val = 0;
    int currentKey = KEY_NOT_PRESSED;
    int prevKey = KEY_NOT_PRESSED;
    const int analogPin = A0;

    void parseKeyboardButton(int value);
    void parseKeyboardButtonAction();
    void debounce();
    void parseCommand(String str);

public:
    Keyboard4x3();
  
    static const int KEY_1 = 1;
    static const int KEY_2 = 2;
    static const int KEY_3 = 3;
    static const int KEY_4 = 4;
    static const int KEY_5 = 5;
    static const int KEY_6 = 6;
    static const int KEY_7 = 7; 
    static const int KEY_8 = 8;
    static const int KEY_9 = 9;
    static const int KEY_10 = 10;
    static const int KEY_11 = 11;
    static const int KEY_12 = 12;
    static const int KEY_NOT_PRESSED = 0;    

    unsigned long lastDebounceTime = 0;
    unsigned int debounceDelayVal = 200;

    void handleKeyBoardPress();
    void readCommand(String command);
};
    
#endif