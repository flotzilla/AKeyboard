// #include <KeyboardMultiLanguage.h>
// #include "KeyboardMappingRU.h"
#include "IntervalTimer.h"
#include "Keyboard4x3.h"

using namespace std;

void handleSerialRead()
{
  if (Serial.available() > 0){
    String s = Serial.readString();
    Serial.println("I can hear you");
  }
}

Keyboard4x3 keyboard43;

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
