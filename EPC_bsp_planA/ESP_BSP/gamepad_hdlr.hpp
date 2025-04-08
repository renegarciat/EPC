#ifndef GAMEPAD_HDLR_HPP
#define GAMEPAD_HDLR_HPP

#include <Arduino.h>
#include <Bluepad32.h>

class gamepad_hdlr {
public:
  gamepad_hdlr();
  void begin();
  void main(); 

private:
  static void onConnectedController(ControllerPtr ctl);
  static void onDisconnectedController(ControllerPtr ctl);
  void dumpGamepad(ControllerPtr ctl);
  void processGamepad(ControllerPtr ctl);
  void processControllers();
};

#endif // GAMEPAD_HDLR_HPP