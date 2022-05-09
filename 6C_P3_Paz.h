#include <ArduinoJson.h>

#define MICROSD_PIN 5
#define EXTENSION ".json"

#include "SPI.h"
#include <SD.h>

#include <Wire.h>
#include <RTClib.h>
String nombre = "Alfredo Paz";
// Create RTC object
RTC_DS1307 rtc;

File MicroSD_File;

#include <WiFi.h>
  WiFiClient ESP32_WIFI;

#include <PubSubClient.h>
  PubSubClient client ( ESP32_WIFI );

const char* HOTSPOT_WIFI = "tony";
const char* HOTSPOT_PWD = "tonyholamundo";  
const char* MQTT_SERVER = "test.mosquitto.org";
#define MQTT_PORT 1883
#define TOPIC "charibu"

#include "rtc.h"
DS1307_RTC RTC;

#include "microsd.h"
MicroSD MSD;

#include "mqtt.h"
 MQTT mqtt;

#include "tasks.h"
Tareas tasks;
