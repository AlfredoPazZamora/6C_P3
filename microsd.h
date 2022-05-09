class MicroSD{
  public:
    String filename = "", JSON_STRING = "";
    
  public:
    void MicroSD_init ( void );
    void FileID ( void ); 
    void JSON ( void );
    void JSON_SaveFile ( DynamicJsonDocument *);
};

void MicroSD::MicroSD_init ( void ) {
  while (!SD.begin(MICROSD_PIN)) {
    Serial.println(F ("Card failed, or not present"));
    delay(1000);
  }
  Serial.println(F ("card initialized."));
}

void MicroSD::FileID ( void ) {
  filename = '/';
  if (RTC.dia < 10 ) filename += '0';
  filename += RTC.dia;
  
  if (RTC.mes < 10 ) filename += '0';
  filename += RTC.mes;
  
  filename += RTC.anio;
  
  filename += EXTENSION;
}

void MicroSD::JSON ( void ) {

  RTC.get_time();
  RTC.format_time();
  RTC.format_date();
  
  DynamicJsonDocument doc ( 1024 );
  doc ["nc"] = 20164920;
  doc ["birthday"] = RTC.fecha;
  doc ["nombre"] = nombre.c_str();

  JSON_SaveFile(&doc);
  
}

void MicroSD::JSON_SaveFile ( DynamicJsonDocument  *doc) {

  JSON_STRING = "";
  FileID();
  MicroSD_File = SD.open(filename, FILE_APPEND);
  if( MicroSD_File){
    serializeJson(*doc, JSON_STRING);
    MicroSD_File.print(JSON_STRING);
    MicroSD_File.println(',');
    MicroSD_File.close();
  }else{
    Serial.print(F("ERROR"));
    
  }
  
}
