void SD_Leer(void){
  if(Lectura_de_SD){
    Lectura_de_SD=false;
  dataFile = SD.open("datalog.txt");
  if (dataFile) {
      Serial.println("Lectura del archivo datalog.txt: ");
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  } else {
    Serial.println("error opening datalog.txt");
  }

  dataArchivo = SD.open("info.txt");
  if (dataArchivo) {
      Serial.println("Lectura del archivo info.txt: ");
    while (dataArchivo.available()) {
      Serial.write(dataArchivo.read());
    }
    dataArchivo.close();
  } else {
    Serial.println("error opening info.txt");
  }
  
  }
}
