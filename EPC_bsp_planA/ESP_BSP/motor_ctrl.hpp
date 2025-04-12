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

// ESP32 GPIO pin definitions for motor control
#define PWMD 3 
#define DIRD 2 
#define PWMC 5 
#define DIRC 4 
#define PWMB 6 
#define DIRB 7 
#define PWMA 9 
#define DIRA 8

class motor_ctrl {
public:
  void begin() {
    pinMode(DIRA, OUTPUT);
    pinMode(PWMA, OUTPUT);  
    pinMode(DIRB, OUTPUT);
    pinMode(PWMB, OUTPUT); 
    pinMode(DIRC, OUTPUT);
    pinMode(PWMC, OUTPUT);
    pinMode(DIRD, OUTPUT);
    pinMode(PWMD, OUTPUT);
  }

  bool set_motor_speed(motor_id_t motor, motor_speed_t speed, motor_direction_t direction);
private:
  const unsigned int hb1_pwm_ain1 = 34;
  const unsigned int hb1_pwm_ain2 = 35;
  const unsigned int hb1_pwm_bin1 = 32;
  const unsigned int hb1_pwm_bin2 = 33;
  const unsigned int hb2_pwm_ain1 = 25;
  const unsigned int hb2_pwm_ain2 = 26;
  const unsigned int hb2_pwm_bin1 = 27;
  const unsigned int hb2_pwm_bin2 = 14;
  char _get_PWM_value(motor_speed_t speed) {
    switch (speed) {
      case OFF: return 0;
      case VERY_LOW_SPEED: return 50;
      case LOW_SPEED: return 100;
      case MID_SPEED: return 150;
      case HIGH_SPEED: return 200;
      default: return 0; // Invalid speed
    }
  }
}
