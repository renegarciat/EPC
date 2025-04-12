#ifndef MQTT_H
#define MQTT_H
#include <WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>

typedef struct mqtt_cfg_t
{
    char* ssid;
    char* password;
    char* mqtt_server;
    char* mqtt_topic;
    int   port;
    int   mqtt_connected;
}mqtt_cfg_t;

class MQTT
{
 private:
     void MQTT_connect();
 public:
     mqtt_cfg_t* mqtt_config;
     MQTT(mqtt_cfg_t * mqtt_cfg);
     void MQTT_main();
     void MQTT_readMessage(String* message);
};
#endif
