class MQTT {
  
  public:
  public:
    void subscribe_MQTT ( void );
    void publish_MQTT ( void );
    void reconnect_MQTT ( void );
    void setup_WiFi ( void ); 
    void set_MQTT_server ( void );
  };

void MQTT :: set_MQTT_server ( void ) {

  client.setServer ( MQTT_SERVER, MQTT_PORT );
  
}

void MQTT :: subscribe_MQTT ( void ) {

  
}

void MQTT :: publish_MQTT ( void ) {

  Serial.println ( "Publicando información" );
  client.publish( TOPIC, MSD.JSON_STRING.c_str() );
  
}

void MQTT :: reconnect_MQTT ( void ) {

  if ( ! client.connected ( ) ) {

    while ( ! client.connected ( ) ) {
      
    Serial.print ( "Conectado nuevamente al servidor" );

    if ( client.connect ( "6A/E1" ) ) {
      
      Serial.println ( "Cliente conectado" );
      
      //client.subscribe("esp32/output");
      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
  }
  client.loop();
  
}

void MQTT :: setup_WiFi ( void ) {

  delay ( 10 );
  Serial.println ( "Configurando WiFi: " );
  WiFi.begin ( HOTSPOT_WIFI, HOTSPOT_PWD );
  
  
  while ( WiFi.status ( ) != WL_CONNECTED ) {
    
    delay ( 500 );
    Serial.print ( "." );
    
  }
  
  Serial.println ( "WiFi configurado con la IP: " );
  
}
