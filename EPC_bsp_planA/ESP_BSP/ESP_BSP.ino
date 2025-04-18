#include "motor_ctrl.hpp"

motor_ctrl motor_o;
void setup() {
  Serial.begin(115200);
}

void loop() 
{
  // Move forward for 3 seconds
  motor_o.set_motor_speed(FRONT_LEFT, HIGH_SPEED, FORWARD);
  delay(3000);
  // Slowly move backward for 3 seconds.
  motor_o.set_motor_speed(FRONT_LEFT, VERY_LOW_SPEED, BACKWARD);
  delay(3000);
}
