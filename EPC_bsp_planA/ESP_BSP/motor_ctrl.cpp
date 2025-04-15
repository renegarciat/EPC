#include "motor_ctrl.hpp"

bool motor_ctrl::set_motor_speed(motor_id_t motor, motor_speed_t speed, motor_direction_t direction) {
  /*NOTE: 
  * Be careful when calling this function multiple times in a short period of time, consider deadtime between calls to avoid shorting the motors.
  */
  // Convert motor_speed_t to PWM value (0-255)
  char pwm_value = _get_PWM_value(speed);
  switch (motor) {
    case FRONT_LEFT:
      if (direction == FORWARD) { // Forward
        digitalWrite(DIRA,HIGH);
      }
      else { // Backward
        digitalWrite(DIRA,LOW);
      }
      analogWrite(PWMA,pwm_value);
      break;
    case FRONT_RIGHT:
      if (direction) { // Forward
        digitalWrite(DIRB,LOW);
      }
      else { // Backward
        digitalWrite(DIRB,HIGH);
      }
      analogWrite(PWMB,pwm_value);
      break;
    case REAR_LEFT:
      if (direction) { // Forward
        digitalWrite(DIRC,HIGH);
      }
      else { // Backward
        digitalWrite(DIRC,LOW);
      }
      analogWrite(PWMC,pwm_value);
      break;
    case REAR_RIGHT:
      if (direction) { // Forward
        digitalWrite(DIRD,LOW);
      }
      else { // Backward
        digitalWrite(DIRD,HIGH);
      }
      analogWrite(PWMD,pwm_value);
      break;
    default:
      return false; // Invalid motor ID
  return true; // Success
  }
}

char motor_ctrl::_get_PWM_value(motor_speed_t speed) {
  switch (speed) {
    case OFF: return 0;
    case VERY_LOW_SPEED: return 50;
    case LOW_SPEED: return 100;
    case MID_SPEED: return 150;
    case HIGH_SPEED: return 200;
    default: return 0; // Invalid speed
  }
}

  motor_ctrl::motor_ctrl() {
  pinMode(DIRA, OUTPUT);
  pinMode(PWMA, OUTPUT);  
  pinMode(DIRB, OUTPUT);
  pinMode(PWMB, OUTPUT); 
  pinMode(DIRC, OUTPUT);
  pinMode(PWMC, OUTPUT);
  pinMode(DIRD, OUTPUT);
  pinMode(PWMD, OUTPUT);
}