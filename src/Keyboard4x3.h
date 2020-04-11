#ifndef KEYBOARD4X3
#define KEYBOARD4X3

#include <Arduino.h>
#include "KeySet.h"

class Keyboard4x3
{

private:
    int val = 0;
    int currentKey = KEY_NOT_PRESSED;
    KeySet currentKeySet[12];
public:
    Keyboard4x3(/* args */);
    Keyboard4x3(KeySet keySet[12]);
    ~Keyboard4x3();

    const int analogPin = A0;
    const int KEY_1 = 1;
    const int KEY_2 = 2;
    const int KEY_3 = 3;
    const int KEY_4 = 4;
    const int KEY_5 = 5;
    const int KEY_6 = 6;
    const int KEY_7 = 7; 
    const int KEY_8 = 8;
    const int KEY_9 = 9;
    const int KEY_10 = 10;
    const int KEY_11 = 11;
    const int KEY_12 = 12;
    const int KEY_NOT_PRESSED = 0;    

    void parseKeyboardButton(int value);
    void handleKeyBoardPress();
    void parseKeyboardButtonAction();
    void setKeySet(KeySet keyset);
};
    




#endif