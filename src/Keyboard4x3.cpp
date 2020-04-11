#include "Keyboard4x3.h"
#include <KeyboardMultiLanguage.h>
#include "KeyboardMappingRU.h"

using namespace std;

Keyboard4x3::Keyboard4x3(/* args */)
{
}

Keyboard4x3::Keyboard4x3(KeySet keySet[12])
{
    // currentKeySet[12] = {
    //     keySet[0]
    // };
}

Keyboard4x3::~Keyboard4x3()
{
}

void Keyboard4x3::parseKeyboardButton(int value)
{
    if(value > 480 && value < 500){
      currentKey = KEY_4;
    } else if(value > 500 && value < 520){
      currentKey = KEY_8;
    } else if(value > 520 && value < 550){
      currentKey = KEY_12;
    } else if(value > 550 && value < 577){
      currentKey = KEY_3;
    } else if(value > 590 && value < 610){
      currentKey = KEY_7;
    } else if(value > 625 && value < 650){
      currentKey = KEY_11;
    } else if(value > 670 && value < 690){
      currentKey = KEY_2;
    } else if(value > 720 && value < 740){
      currentKey = KEY_6;
    } else if(value > 770 && value < 790){
      currentKey = KEY_10;
    } else if(value > 840 && value < 860){
      currentKey = KEY_1;
    } else if(value > 920 && value < 940){
      currentKey = KEY_5;
    } else if(value > 1020){
      currentKey = KEY_9;
    } else {
      currentKey = KEY_NOT_PRESSED;
    }
}

void Keyboard4x3::parseKeyboardButtonAction()
{
  if (currentKey == KEY_1){
    Keyboard.press('c');    
  }

  if (currentKey == KEY_2){
    Keyboard.language(Russian);
    Keyboard.print("Добрый день. Заинтересовала ваша вакансия, с удовольствием пообщаюсь");    
  }

}


void Keyboard4x3::handleKeyBoardPress()
{
  val = analogRead(analogPin); 
  parseKeyboardButton(val);
  parseKeyboardButtonAction();


  Keyboard.releaseAll();   
}