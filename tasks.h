#define TIME_MQTT 15000
#define TIME_DATA 10000

class Tareas {
  public:
    unsigned long data10s = 0, 
                  mqtt15s = 0,
                  currentMillis = 0;   
    void datalogger( void );
    void taskMQTT( void );
};

void Tareas::datalogger( void ){

  if( ( currentMillis - data10s ) >= TIME_MQTT ){
    RTC.get_time();
    MSD.JSON();
    data10s = currentMillis;
  }
}

void Tareas::taskMQTT( void ){

  if( ( currentMillis - mqtt15s ) >= TIME_DATA ){
    mqtt.reconnect_MQTT ( );
    mqtt.publish_MQTT ( );
    mqtt15s = currentMillis;
  }
}
