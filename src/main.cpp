#include "IntervalTimer.h"
#include "Keyboard4x3.h"
#include <Arduino.h>

Keyboard4x3 keyboard43 = Keyboard4x3();

void handleSerialRead()
{
  if (Serial.available() > 0){
    String s = Serial.readString();
    Serial.write(123);
    keyboard43.readCommand(s);
  }
}

void handleKeyboardPress()
{
  keyboard43.handleKeyBoardPress();
}

IntervalTimer serialHandler(10, &handleSerialRead);
IntervalTimer keyboardHandler(10, &handleKeyboardPress);

void setup() {
  Serial.begin(115200);
  Serial.print("Well hello there");
} 

void loop() {
  unsigned long currMillis = millis();

  serialHandler.update(currMillis);
  keyboardHandler.update(currMillis);
}
