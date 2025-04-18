#include "motor_ctrl.hpp"

bool motor_ctrl::set_motor_speed(motor_id_t motor, motor_speed_t speed, motor_direction_t direction) {
  /*NOTE: 
  * Be careful when calling this function multiple times in a short period of time, consider deadtime between calls to avoid shorting the motors.
  */
  // Convert motor_speed_t to duty cycle value (0-255)
  // uint8_t duty_cycle = map(speed, 0, 4, 0, 255); // Map speed to duty cycle (0-255)
  uint32_t pwm_value = _get_PWM_value(speed);
  switch (motor) {
    case FRONT_LEFT:
      if (direction == FORWARD) { // Forward
        digitalWrite(DIRA,HIGH);
      }
      else { // Backward
        digitalWrite(DIRA,LOW);
      }
      //analogWrite(PWMA,pwm_value);
      ledcWrite(2, pwm_value); // Set PWM value for motor A
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

uint32_t motor_ctrl::_get_PWM_value(motor_speed_t speed) {
  switch (speed) {
    case OFF: return 0;
    case VERY_LOW_SPEED: return 50;
    case LOW_SPEED: return 100;
    case MID_SPEED: return 150;
    case HIGH_SPEED: return 200;
    default: return 0; // Invalid speed
  }
}
  // motor_ctrl::motor_ctrl(uint32_t frequency, uint8_t pwm_resolution) {
  // this->frequency = frequency;
  // this->pwm_resolution = pwm_resolution;
  // // Configure the 4 PWM channels
  // ledcSetup(pwm_pin0, frequency, pwm_resolution);
  // ledcSetup(pwm_pin1, frequency, pwm_resolution);
  // ledcSetup(pwm_pin2, frequency, pwm_resolution);
  // ledcSetup(pwm_pin3, frequency, pwm_resolution);
  // pinMode(DIRA, OUTPUT);
  // }

  motor_ctrl::motor_ctrl() {
  ledcAttach(2, frequency, pwm_resolution);
  pinMode(DIRA, OUTPUT);
  // pinMode(PWMA, OUTPUT);  
  // pinMode(DIRB, OUTPUT);
  // pinMode(PWMB, OUTPUT); 
  // pinMode(DIRC, OUTPUT);
  // pinMode(PWMC, OUTPUT);
  // pinMode(DIRD, OUTPUT);
  // pinMode(PWMD, OUTPUT);
}