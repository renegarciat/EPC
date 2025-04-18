#ifndef MOTOR_CTRL_HPP
#define MOTOR_CTRL_HPP

#include <Arduino.h>

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
  uint32_t frequency = 5000; //5 KHz
  uint32_t pwm_resolution = 8; //[bits] Could be increased if needed.
  uint8_t motorFL_PWM_pin = 12; //Corresponds to PWM of Front Left motor (pin 9 of shield) (pin 12 of ESP32)
  uint8_t motorFL_direction_pin = 13; // Corresponds to direction of Front Left motor (pin 8 of shield) (pin 13 of ESP32)
  uint8_t motorFR_PWM_pin = 32; //Corresponds to PWM of Front Right motor (pin 6 of shield) (pin 32 of ESP32)
  uint8_t motorFR_direction_pin = 33; // Corresponds to direction of Front Right motor (pin 7 of shield) (pin 33 of ESP32)
  uint8_t motorRL_PWM_pin = 25; //Corresponds to PWM of Rear Left motor (pin 5 of shield) (pin 25 of ESP32)
  uint8_t motorRL_direction_pin = 26; // Corresponds to direction of Rear Left motor (pin 4 of shield) (pin 26 of ESP32)
  uint8_t motorRR_PWM_pin = 27; //Corresponds to PWM of Rear Right motor (pin 3 of shield) (pin 27 of ESP32)
  uint8_t motorRR_direction_pin = 14; // Corresponds to direction of Rear Right motor (pin 2 of shield) (pin 14 of ESP32)
  
  /**
   * @brief Converts the motor speed to a PWM value.
   * @param speed The desired motor speed (0-4). 
   * @return The corresponding PWM value.
   */
  uint32_t _get_PWM_value(motor_speed_t speed); //TODO: Modify to accept different resolutions. Use pwm_resolution variable.

  void _init_motor_pins();
  
};

#endif // MOTOR_CTRL_HPP