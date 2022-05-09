#include "6C_P3_Paz.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 115200 );
  RTC.RTC_init();
  MSD.MicroSD_init();

  mqtt.setup_WiFi ( );
  mqtt.set_MQTT_server ( );
  
}

void loop() {
  // put your main code here, to run repeatedly:
  tasks.currentMillis = millis();
  tasks.datalogger ( );
  tasks.taskMQTT ( );
}
