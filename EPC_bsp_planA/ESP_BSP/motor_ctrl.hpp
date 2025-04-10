typedef enum {
  OFF,
  VERY_LOW_SPEED,
  LOW_SPEED,
  MID_SPEED,
  HIGH_SPEED
} motor_speed_t;

typedef enum {
  FRONT_LEFT,
  FRONT_RIGHT,
  REAR_LEFT,
  REAR_RIGHT,
} motor_id_t;

/*True: Forward 
False: Backward*/
typedef bool motor_direction_t;

class motor_ctrl {
public:
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
  
};
