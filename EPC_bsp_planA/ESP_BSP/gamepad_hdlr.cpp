#include "gamepad_hdlr.hpp"

ControllerPtr myControllers[1];

struct sticksLastValue_T
{
    int leftStickX = 0;
    int leftStickY = 0;
    int rightStickX = 0;
    int rightStickY = 0;
};

sticksLastValue_T sticksLastValue;

gamepad_hdlr::gamepad_hdlr() 
{

}

void gamepad_hdlr::begin() 
{
  Serial.printf("Firmware: %s\n", BP32.firmwareVersion());
  const uint8_t* addr = BP32.localBdAddress();
  Serial.printf("BD Addr: %2X:%2X:%2X:%2X:%2X:%2X\n", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);

  BP32.setup(&onConnectedController, &onDisconnectedController);
}

void gamepad_hdlr::main() 
{
  bool dataUpdated = BP32.update();
  if (dataUpdated)
  {
    processControllers();
  }
}

void gamepad_hdlr::onConnectedController(ControllerPtr ctl) 
{
    bool foundEmptySlot = false;
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == nullptr) {
            Serial.printf("CALLBACK: Controller is connected, index=%d\n", i);
            // Additionally, you can get certain gamepad properties like:
            // Model, VID, PID, BTAddr, flags, etc.
            ControllerProperties properties = ctl->getProperties();
            Serial.printf("Controller model: %s, VID=0x%04x, PID=0x%04x\n", ctl->getModelName().c_str(), properties.vendor_id,
                           properties.product_id);
            myControllers[i] = ctl;
            foundEmptySlot = true;
            break;
        }
    }
    if (!foundEmptySlot) {
        Serial.println("CALLBACK: Controller connected, but could not found empty slot");
    }
}

void gamepad_hdlr::onDisconnectedController(ControllerPtr ctl) 
{
    bool foundController = false;

    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == ctl) {
            Serial.printf("CALLBACK: Controller disconnected from index=%d\n", i);
            myControllers[i] = nullptr;
            foundController = true;
            break;
        }
    }

    if (!foundController) {
        Serial.println("CALLBACK: Controller disconnected, but not found in myControllers");
    }
}

void gamepad_hdlr::dumpGamepad(ControllerPtr ctl) 
{
    Serial.printf(
        "idx=%d, dpad: 0x%02x, buttons: 0x%04x, axis L: %4d, %4d, axis R: %4d, %4d, brake: %4d, throttle: %4d, "
        "misc: 0x%02x, gyro x:%6d y:%6d z:%6d, accel x:%6d y:%6d z:%6d\n",
        ctl->index(),        // Controller Index
        ctl->dpad(),         // D-pad
        ctl->buttons(),      // bitmask of pressed buttons
        ctl->axisX(),        // (-511 - 512) left X Axis
        ctl->axisY(),        // (-511 - 512) left Y axis
        ctl->axisRX(),       // (-511 - 512) right X axis
        ctl->axisRY(),       // (-511 - 512) right Y axis
        ctl->brake(),        // (0 - 1023): brake button
        ctl->throttle(),     // (0 - 1023): throttle (AKA gas) button
        ctl->miscButtons(),  // bitmask of pressed "misc" buttons
        ctl->gyroX(),        // Gyro X
        ctl->gyroY(),        // Gyro Y
        ctl->gyroZ(),        // Gyro Z
        ctl->accelX(),       // Accelerometer X
        ctl->accelY(),       // Accelerometer Y
        ctl->accelZ()        // Accelerometer Z
    );
}

void gamepad_hdlr::processGamepad(ControllerPtr ctl) 
{
    /*Add all the function calls to motion controller here*/
    if (ctl->r1()) 
    {
        Serial.println("RB button pressed");
    }

    if (ctl->l1()) 
    {
        Serial.println("LB button pressed");
    }

    /*Sticks will only be reported if they move more than 10 units*/
    if((abs(sticksLastValue.leftStickX - ctl->axisX()) >= 10) || (abs(sticksLastValue.leftStickY - ctl->axisY()) >= 10))
    {
        sticksLastValue.leftStickX = ctl->axisX();
        sticksLastValue.leftStickY = ctl->axisY();
        Serial.printf("Left stick new values: x: %d y:%d\n", sticksLastValue.leftStickX, sticksLastValue.leftStickY);
    }

    if((abs(sticksLastValue.rightStickX - ctl->axisRX()) >= 10) || (abs(sticksLastValue.rightStickY - ctl->axisRY()) >= 10))
    {
        sticksLastValue.rightStickX = ctl->axisRX();
        sticksLastValue.rightStickY = ctl->axisRY();
        Serial.printf("Right stick new values: x: %d y:%d\n", sticksLastValue.rightStickX, sticksLastValue.rightStickY);
    }
}

void gamepad_hdlr::processControllers() 
{
  for (auto myController : myControllers) {
    if (myController && myController->isConnected() && myController->hasData()) 
    {
      if (myController->isGamepad()) 
      {
          processGamepad(myController);
      }
    }
  }
}