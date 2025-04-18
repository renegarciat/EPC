#include "motor_ctrl.hpp"

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
  // Note: ledcAttach function assigns a channel automatically.
  ledcAttach(motorFL_PWM_pin, frequency, pwm_resolution);
  pinMode(motorFL_direction_pin, OUTPUT);
  ledcAttach(motorFR_PWM_pin, frequency, pwm_resolution);
  pinMode(motorFR_direction_pin, OUTPUT);
  ledcAttach(motorRL_PWM_pin, frequency, pwm_resolution);
  pinMode(motorRL_direction_pin, OUTPUT);
  ledcAttach(motorRR_PWM_pin, frequency, pwm_resolution);
  pinMode(motorRR_direction_pin, OUTPUT);
  }

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
        digitalWrite(motorFL_direction_pin,HIGH);
      }
      else { // Backward
        digitalWrite(motorFL_direction_pin,LOW);
      }
      ledcWrite(motorFL_PWM_pin, pwm_value); // Set PWM value for motor A
      break;
    case FRONT_RIGHT:
      if (direction) { // Forward
        digitalWrite(motorFR_direction_pin,LOW);
      }
      else { // Backward
        digitalWrite(motorFR_direction_pin,HIGH);
      }
      ledcWrite(motorFR_PWM_pin, pwm_value); // Set PWM value for motor B
      break;
    case REAR_LEFT:
      if (direction) { // Forward
        digitalWrite(motorRL_direction_pin,HIGH);
      }
      else { // Backward
        digitalWrite(motorRL_direction_pin,LOW);
      }
      ledcWrite(motorRL_PWM_pin, pwm_value); // Set PWM value for motor C
      break;
    case REAR_RIGHT:
      if (direction) { // Forward
        digitalWrite(motorRR_direction_pin,LOW);
      }
      else { // Backward
        digitalWrite(motorRR_direction_pin,HIGH);
      }
      ledcWrite(motorRR_PWM_pin, pwm_value); // Set PWM value for motor A

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