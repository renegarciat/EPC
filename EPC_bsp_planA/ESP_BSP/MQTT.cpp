#include "MQTT.hpp"

WiFiClient espClient;
PubSubClient mqttClient(espClient);
String message_buffer;

static void WiFi_connect(char* ssid, char* password);

static void WiFi_connect(char* ssid, char* password)
{
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
  }
}

static void callback(char* topic, byte* message, unsigned int length)
{
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    messageTemp += (char)message[i];
  }

  memcpy(&message_buffer, &messageTemp, messageTemp.length());
}

MQTT::MQTT(mqtt_cfg_t* mqtt_cfg)
{
  this->mqtt_config = mqtt_cfg;
  WiFi_connect(mqtt_cfg->ssid, mqtt_cfg->password);
  mqttClient.setServer(mqtt_cfg->mqtt_server, mqtt_cfg->port);
  mqttClient.setCallback(&callback);
}

void MQTT::MQTT_main()
{
  if (!mqttClient.connected())
  {
    MQTT_connect();
  }

  mqttClient.loop();
}

void MQTT::MQTT_connect()
{
  while (!(mqttClient.connected())) 
  {
    if(mqttClient.connect("ESP32Client"))
    {
      mqttClient.subscribe(this->mqtt_config->mqtt_topic);
    }
    delay(500);
  }
}

void MQTT::MQTT_readMessage(String* message)
{
  memcpy(message, &message_buffer, message->length());
}
