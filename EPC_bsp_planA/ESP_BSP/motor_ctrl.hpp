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

// ESP32 GPIO pin definitions for motor control
#define PWMA 15
#define DIRA 0
#define PWMD 3 
#define DIRD 2 
#define PWMC 5 
#define DIRC 4 
#define PWMB 6 
#define DIRB 7 

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
  /*Note: Channels run from 0 to 15 */
  const unsigned int frequency = 5000; //5 KHz
  const unsigned int hb1_pwm_ain1 = 34; //Corresponds to PWMA (pin 9 of shield) (pin D34 of ESP32) (GPIO?)
  const unsigned int hb1_channel = 0 ;//Start from channel 0
  const unsigned int pwm_resolution = 8; //[bits] Could be increased if needed.
  uint8_t pwm_pin0 = 0; // PWM pin for motor 1 (left front)
  // const unsigned int hb1_pwm_ain2 = 35;
  // const unsigned int hb1_pwm_ain1 = 15; //Corresponds to PWMA (pin 9 of shield) (pin D34 of ESP32) (GPIO15)
  // const unsigned int hb1_pwm_ain2 = 32; //Corresponds to DIRA (pin 8 of shield) (pin D2 of ESP32) (GPIO32)
  // const unsigned int hb1_pwm_bin1 = 32;
  // const unsigned int hb1_pwm_bin2 = 33;
  // const unsigned int hb2_pwm_ain1 = 25;
  // const unsigned int hb2_pwm_ain2 = 26;
  // const unsigned int hb2_pwm_bin1 = 27;
  // const unsigned int hb2_pwm_bin2 = 14;

  /**
   * @brief Converts the motor speed to a PWM value.
   * @param speed The desired motor speed (0-4). 
   * @return The corresponding PWM value (0-255).
   */
  uint32_t _get_PWM_value(motor_speed_t speed);
};

#endif // MOTOR_CTRL_HPP