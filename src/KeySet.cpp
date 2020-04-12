#include "KeySet.h"

using namespace std;

KeySet::KeySet(){}

KeySet::KeySet(String text)
{
    this->text = text;
}

KeySet::KeySet(String text, char *language)
{
    this->text = text;
    this->language = language;
}

KeySet::KeySet(uint8_t *keyMap[KEY_MAP_SIZE])
{
    this->keypressMap[KEY_MAP_SIZE] = *keyMap[KEY_MAP_SIZE];
}


void KeySet::runAction()
{    
    if (strlen(language) != 0){
        Keyboard.language(language);
    } else {
        Keyboard.language();
    }

    for (uint8_t i=0; i < KEY_MAP_SIZE; i++){
        if (keypressMap[i] != NULL){
            Keyboard.press(keypressMap[i]);
        }
    }

    if (text.length() != 0){
        Keyboard.print(text);
    }
}

void KeySet::keyRelease()
{
    Keyboard.releaseAll();
}
