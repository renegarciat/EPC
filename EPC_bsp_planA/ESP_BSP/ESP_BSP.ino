#include "gamepad_hdlr.hpp"
#include "motor_ctrl.hpp"

gamepad_hdlr gamepad_o; 
motor_ctrl motor_o;
void setup() {
  Serial.begin(115200);
  gamepad_o.begin();
  motor_o.begin();
}

void loop() 
{
  gamepad_o.main();
  delay(10);
}
