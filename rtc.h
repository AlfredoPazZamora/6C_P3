class DS1307_RTC{
  public:
    uint8_t hora, minuto, segundo, dia, mes;
    uint16_t anio;
    String fecha = "", tiempo = "";
    
  public:
    void RTC_init ( void );
    void get_time ( void );
    void format_date ( void );
    void format_time ( void );
};

void DS1307_RTC::RTC_init ( void ){
  while (! rtc.begin()) {
    Serial.println(F(":') No sirve el RTC"));
    Serial.flush();
  }

  Serial.println(F("RTC FUNCIONA FIN ... SIGUE CON TU VIDA"));
}

void DS1307_RTC::get_time ( void ){

  DateTime now = rtc.now();

  anio = now.year();
  mes = now.month();
  dia = now.day();

  segundo = now.second();
  minuto = now.minute();
  hora = now.hour();
  
}

void DS1307_RTC::format_date ( void ){
  fecha = "";

  if (dia < 10 ) fecha += '0';
  fecha += dia;
  fecha += "/";

  if (mes < 10 ) fecha += '0';
  fecha += mes;
  fecha += "/";

  fecha += anio;
  
}

void DS1307_RTC::format_time ( void ){
   tiempo = "";

  if (hora < 10 ) tiempo += '0';
  tiempo += hora;
  tiempo += ":";

  if (minuto < 10 ) tiempo += '0';
  tiempo += minuto;
  tiempo += ":";

  if (segundo < 10 ) tiempo += '0';
  tiempo += segundo;
}
