#include "gamepad_hdlr.hpp"
#include "MQTT.hpp"

gamepad_hdlr gamepad_o; 

const int ledPin = 2; // GPIO pin for the LED
mqtt_cfg_t mqtt_cfg = {
  .ssid = "your_ssid",
  .password = "your_password",
  .mqtt_server = "mqtt_server",
  .mqtt_topic = "mqtt_topic",
  .port = 1883,
  .mqtt_connected = 0,
};

MQTT mqtt_o(&mqtt_cfg);
String received_message;

void setup() {
  Serial.begin(115200);
  gamepad_o.begin();
  pinMode(ledPin, OUTPUT); // Set the LED pin as output

  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(ledPin, LOW);
}

void loop() 
{
  gamepad_o.main();
  mqtt_o.MQTT_main();

  mqtt_o.MQTT_readMessage(&received_message);
  if (received_message.length() > 0) {
    if (received_message == "ON") {
      digitalWrite(ledPin, HIGH); // Turn on the LED
    } else if (received_message == "OFF") {
      digitalWrite(ledPin, LOW); // Turn off the LED
    }
    received_message = ""; // Clear the message after processing
  }
  delay(10);
}
