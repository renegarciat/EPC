#ifndef MOTOR_CTRL_HPP
#define MOTOR_CTRL_HPP

#include <Arduino.h> //Is this needed?

/* Data type used to set the speed of a motor. */
typedef enum {
  OFF,
  VERY_LOW_SPEED,
  LOW_SPEED,
  MID_SPEED,
  HIGH_SPEED
} motor_speed_t;

typedef enum { //We could use enum class here, but consider portability to C.
  FRONT_LEFT,
  FRONT_RIGHT,
  REAR_LEFT,
  REAR_RIGHT,
} motor_id_t;

/**
 * True: Forward 
 * False: Backward
*/
typedef bool motor_direction_t; // We could use enum class here, but consider portability to C.
const motor_direction_t FORWARD = true;
const motor_direction_t BACKWARD = false;

class motor_ctrl {
public:
  /**
   * @brief Default constructor for motor_ctrl class.
   * Initializes the motor control with default frequency and PWM resolution.
   */
  motor_ctrl();

  /**
   * @brief Initializes the motor control with specified frequency and PWM resolution.
   * @param frequency The frequency for PWM (default is 5 kHz).
   * @param pwm_resolution The resolution for PWM (default is 8 bits).
   */
  motor_ctrl(uint32_t frequency, uint8_t pwm_resolution);

  /**
   * @brief Sets the speed and direction of a motor.
   * @param motor The motor ID (0-3).
   * @param speed The desired motor speed (0-4).
   * @param direction The desired motor direction (true for forward, false for backward).
   * @return True if the operation was successful, false otherwise.
   */
  bool set_motor_speed(motor_id_t motor, motor_speed_t speed, motor_direction_t direction);

private:
  /*Note: Channels range from 0 to 15. Consider an array for this */
  const uint32_t frequency = 5000; //5 KHz
  const unsigned int hb1_pwm_ain1 = 34; //Corresponds to PWMA (pin 9 of shield) (pin D34 of ESP32) (GPIO?)
  const unsigned int hb1_channel = 0 ;//Start from channel 0
  const unsigned int pwm_resolution = 8; //[bits] Could be increased if needed.
  const uint8_t motorFL_PWM_pin = 2; //Corresponds to PWM of Front Left motor (pin 9 of shield) (pin 2 of ESP32)
  const uint8_t motorFL_direction_pin = 0; // Corresponds to direction of Front Left motor (pin 8 of shield) (pin 0 of ESP32)
  const uint8_t motorFR_PWM_pin = 4; //Corresponds to PWM of Front Right motor (pin 10 of shield) (pin 4 of ESP32)
  const uint8_t motorFR_direction_pin = 5; // Corresponds to direction of Front Right motor (pin 7 of shield) (pin 5 of ESP32)
  const uint8_t motorRL_PWM_pin = 18; //Corresponds to PWM of Rear Left motor (pin 11 of shield) (pin 18 of ESP32)
  const uint8_t motorRL_direction_pin = 19; // Corresponds to direction of Rear Left motor (pin 6 of shield) (pin 19 of ESP32)
  const uint8_t motorRR_PWM_pin = 21; //Corresponds to PWM of Rear Right motor (pin 12 of shield) (pin 21 of ESP32)
  const uint8_t motorRR_direction_pin = 22; // Corresponds to direction of Rear Right motor (pin 5 of shield) (pin 22 of ESP32)
  
  /**
   * @brief Converts the motor speed to a PWM value.
   * @param speed The desired motor speed (0-4). 
   * @return The corresponding PWM value (0-255).
   */
  uint32_t _get_PWM_value(motor_speed_t speed); //TODO: Modify to accept different resolutions. Use pwm_resolution variable.
};

#endif // MOTOR_CTRL_HPP