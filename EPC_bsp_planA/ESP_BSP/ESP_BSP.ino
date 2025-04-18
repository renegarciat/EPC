#include "gamepad_hdlr.hpp"
#include "motor_ctrl.hpp"

gamepad_hdlr gamepad_o; 
motor_ctrl motor_o;
void setup() {
  Serial.begin(115200);
  //gamepad_o.begin();
}

void loop() 
{
  //gamepad_o.main();
  motor_o.set_motor_speed(FRONT_LEFT, HIGH_SPEED, FORWARD);
  delay(1000);
  motor_o.set_motor_speed(FRONT_LEFT, LOW_SPEED, BACKWARD);
  delay(1000);
}
