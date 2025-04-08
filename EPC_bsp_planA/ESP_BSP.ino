#include "gamepad_hdlr.hpp"

gamepad_hdlr gamepad_o; 

void setup() {
  Serial.begin(115200);
  gamepad_o.begin();
}

void loop() 
{
  gamepad_o.main();
  delay(10);
}
