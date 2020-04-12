#include "Keyboard4x3.h"

using namespace std;

Keyboard4x3::Keyboard4x3(/* args */){}

void Keyboard4x3::parseKeyboardButton(int value)
{
  if (value > 480 && value < 500){
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
  switch (currentKey)
  {
  case KEY_1:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F1);
    break;
  case KEY_2:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F2);
    break;
  case KEY_3:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F3);
    break;
  case KEY_4:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F4);
    break;
  case KEY_5:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F5);
    break;
  case KEY_6:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F6);
    break;
  case KEY_7:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F7);
    break;
  case KEY_8:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F8);
    break;
  case KEY_9:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F9);
    break;
  case KEY_10:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F10);
    break;
  case KEY_11:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F11);
    break;
  case KEY_12:
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F12);
    break;
  default:
    break;
  }
}

void Keyboard4x3::debounce()
{
  int v = analogRead(analogPin); 
  parseKeyboardButton(v);

  int currentMills = millis();

  if ((currentMills - lastDebounceTime) > debounceDelayVal){
    lastDebounceTime = currentMills;
    parseKeyboardButtonAction();
    Keyboard.releaseAll();
  }
}

void Keyboard4x3::handleKeyBoardPress()
{
    debounce();
    //or handle layout
}

void Keyboard4x3::readCommand(String command)
{
  Serial.println("reading command");
  Serial.println(command);
}

void Keyboard4x3::parseCommand(String str)
{

}
