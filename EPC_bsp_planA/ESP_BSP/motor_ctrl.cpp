#include "motor_ctrl.hpp"
#include <Arduino.h>

bool motor_ctrl::set_motor_speed(motor_id_t motor, motor_speed_t speed, motor_direction_t direction) {
  /*NOTE: 
  * Be careful when calling this function multiple times in a short period of time, consider deadtime between calls to avoid shorting the motors.
  */
  // Convert motor_speed_t to PWM value (0-255)
  char pwm_value = _get_PWM_value(speed);
  switch (motor) {
    case FRONT_LEFT:
      if (direction) { // Forward
        digitalWrite(DIRA,HIGH);
        analogWrite(PWMA,pwm_value);
      }
      else { // Backward
        digitalWrite(DIRA,LOW);
        analogWrite(PWMA,pwm_value);
      }
      break;
    case FRONT_RIGHT:
      if (direction) { // Forward
        digitalWrite(DIRB,LOW);
        analogWrite(PWMB,pwm_value);
      }
      else { // Backward
        digitalWrite(DIRB,HIGH);
        analogWrite(PWMB,pwm_value);
      }
      break;
    case REAR_LEFT:
      if (direction) { // Forward
        digitalWrite(DIRC,HIGH);
        analogWrite(PWMC,pwm_value);
      }
      else { // Backward
        digitalWrite(DIRC,LOW);
        analogWrite(PWMC,pwm_value);
      }
      break;
    case REAR_RIGHT:
      if (direction) { // Forward
        digitalWrite(DIRD,LOW);
        analogWrite(PWMD,pwm_value);
      }
      else { // Backward
        digitalWrite(DIRD,HIGH);
        analogWrite(PWMD,pwm_value);
      }
      break;
    default:
      return false; // Invalid motor ID
  return true; // Success
  }
}