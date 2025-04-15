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
#define DIRA 32
#define PWMD 3 
#define DIRD 2 
#define PWMC 5 
#define DIRC 4 
#define PWMB 6 
#define DIRB 7 

class motor_ctrl {
public:
  /**
   * @brief Initializes the motor control pins.
   * Sets the motor control pins to output mode and initializes them to low.
   */
  motor_ctrl();

  /**
   * @brief Sets the speed and direction of a motor.
   * @param motor The motor ID (0-3).
   * @param speed The desired motor speed (0-4).
   * @param direction The desired motor direction (true for forward, false for backward).
   * @return True if the operation was successful, false otherwise.
   */
  bool set_motor_speed(motor_id_t motor, motor_speed_t speed, motor_direction_t direction);

private:
  /*Note: GPIO should be between 1 and 16 */
  const unsigned int hb1_pwm_ain1 = 15; //Corresponds to PWMA (pin 9 of shield) (pin D15 of ESP32) (GPIO15)
  const unsigned int hb1_pwm_ain2 = 32; //Corresponds to DIRA (pin 8 of shield) (pin D2 of ESP32) (GPIO32)
  const unsigned int hb1_pwm_bin1 = 32;
  const unsigned int hb1_pwm_bin2 = 33;
  const unsigned int hb2_pwm_ain1 = 25;
  const unsigned int hb2_pwm_ain2 = 26;
  const unsigned int hb2_pwm_bin1 = 27;
  const unsigned int hb2_pwm_bin2 = 14;

  /**
   * @brief Converts the motor speed to a PWM value.
   * @param speed The desired motor speed (0-4). 
   * @return The corresponding PWM value (0-255).
   */
  char _get_PWM_value(motor_speed_t speed);
};

#endif // MOTOR_CTRL_HPP