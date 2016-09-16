void SD_Guardar(void) {
  if (fin_trama) {
     dataFile = SD.open("datalog.txt", FILE_WRITE);
    fin_trama = false;
    if (Llega_Hora) {
      Llega_Hora = false;
      Serial.println("Se guarda Hora");
      Lectura_de_SD=true;
      for (int i = 0; i <= 7; i++) {
        dataFile.println(Datos[i]);
      }
    }
    if (Llega_Dato) {
      Llega_Dato = false;
      Serial.println("Se guarda Dato");
      for (int i = 0; i <= 22; i++) {
        dataFile.println(Datos[i]);

      }
    }
    // if the file is available, write to it:
    if (dataFile) {
     // dataFile.println(dataString);
      dataFile.close();
      // print to the serial port too:
     
      Serial.println("Se guardo correctamenteen la SD:");
      //Serial.println(dataString);
    }
    // if the file isn't open, pop up an error:
    else {
      Serial.println("error opening datalog.txt");
    }
  }
}



