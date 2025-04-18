#include "motor_ctrl.hpp"

motor_ctrl::motor_ctrl(uint32_t frequency, uint8_t pwm_resolution) {
  this->frequency = frequency;
  this->pwm_resolution = pwm_resolution;
  _init_motor_pins(); // Initialize motor pins
  }

motor_ctrl::motor_ctrl() {
  _init_motor_pins(); // Initialize motor pins
  }

bool motor_ctrl::set_motor_speed(motor_id_t motor, motor_speed_t speed, motor_direction_t direction) {
  /*NOTE: 
  * Be careful when calling this function multiple times in a short period of time, consider deadtime between calls to avoid shorting the motors. (That might be prevented by hardware, but it is better to be safe than sorry).
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
      ledcWrite(motorFL_PWM_pin, pwm_value); // Set PWM value for motor Front Left
      break;
    case FRONT_RIGHT:
      if (direction) { // Forward
        digitalWrite(motorFR_direction_pin,LOW);
      }
      else { // Backward
        digitalWrite(motorFR_direction_pin,HIGH);
      }
      ledcWrite(motorFR_PWM_pin, pwm_value); // Set PWM value for motor Front Right
      break;
    case REAR_LEFT:
      if (direction) { // Forward
        digitalWrite(motorRL_direction_pin,HIGH);
      }
      else { // Backward
        digitalWrite(motorRL_direction_pin,LOW);
      }
      ledcWrite(motorRL_PWM_pin, pwm_value); // Set PWM value for motor Rear Left
      break;
    case REAR_RIGHT:
      if (direction) { // Forward
        digitalWrite(motorRR_direction_pin,LOW);
      }
      else { // Backward
        digitalWrite(motorRR_direction_pin,HIGH);
      }
      ledcWrite(motorRR_PWM_pin, pwm_value); // Set PWM value for motor Rear Right

      break;
    default:
      return false; // Invalid motor ID
  return true; // Success
  }
}

uint32_t motor_ctrl::_get_PWM_value(motor_speed_t speed) {
  // Consider the current resolution of the PWM
  //TODO: Use a LUT instead, to avoid the overhead of pow() and multiplication.
  uint32_t max_value = pow(2, pwm_resolution) - 1; // Maximum value for the given resolution
  switch (speed) {
    case OFF: return 0;
    case VERY_LOW_SPEED: return max_value * 0.1; // 10% duty cycle
    case LOW_SPEED: return max_value * 0.25; // 25% duty cycle
    case MID_SPEED: return max_value * 0.5; // 50% duty cycle
    case HIGH_SPEED: return max_value * 0.75; // 75% duty cycle
    default: return 0; // Invalid speed
  }
}

void motor_ctrl::_init_motor_pins() {
  // Note: ledcAttach function assigns a channel automatically.
  ledcAttach(motorFL_PWM_pin, frequency, pwm_resolution);
  pinMode(motorFL_direction_pin, OUTPUT);
  ledcAttach(motorFR_PWM_pin, frequency, pwm_resolution);
  pinMode(motorFR_direction_pin, OUTPUT);
  ledcAttach(motorRL_PWM_pin, frequency, pwm_resolution);
  pinMode(motorRL_direction_pin, OUTPUT);
  ledcAttach(motorRR_PWM_pin, frequency, pwm_resolution);
  pinMode(motorRR_direction_pin, OUTPUT);

  // This is the function used in bluepad library
  // ledcSetup(0,frequency,pwm_resolution);
  // ledcAttachPin(motorFL_PWM_pin,0);
}