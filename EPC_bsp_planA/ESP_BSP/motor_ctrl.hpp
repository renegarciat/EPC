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
};
