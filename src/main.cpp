#include <KeyboardMultiLanguage.h>
#include "KeyboardMappingRU.h"

//#include "Keyboard.h"

const int LED_RX = 17;
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

int val = 0;
int currentKey = KEY_NOT_PRESSED;

void setup() {
  Serial.begin(115200);
  pinMode(LED_RX, OUTPUT);
//  Keyboard.begin();

  Keyboard.language(Russian);
  Keyboard.println("Я могу есть стекло, оно мне не вредит.");
} 

void blink()
{
  Serial.println ("Hello World!");
  digitalWrite(LED_RX, LOW);
  delay(1000);
  digitalWrite(LED_RX, HIGH);
  delay(1000);  
}

void parseKeyboardButton(int value)
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

void loop() {
  val = analogRead(analogPin); 
  parseKeyboardButton(val);
//  Serial.println(currentKey);

  if (currentKey == KEY_1){
    Keyboard.press('c');    
  }

  if (currentKey == KEY_2){
    Keyboard.language(Russian);
    Keyboard.print("Добрый день. Заинтересовала ваша вакансия, с удовольствием пообщаюсь");    
  }

  delay(100);   
  Keyboard.releaseAll();   
}
