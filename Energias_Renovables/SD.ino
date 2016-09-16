void SD_Guardar(void) {
  if (fin_trama && archivo==false) {
     dataFile = SD.open("datalog.txt", FILE_WRITE);
    fin_trama = false;
    if (Llega_Hora) {
      Llega_Hora = false;
      Serial.println("Se guarda Hora");
      Lectura_de_SD=true;
      for (int i = 0; i <= 7; i++) {
        dataFile.print(Datos[i]);
        if(i<7){
          dataFile.print(";");
        }
      }
      dataFile.println();
    }
    if (Llega_Dato) {
      Llega_Dato = false;
      Serial.println("Se guarda Dato");
      for (int i = 0; i <= 22; i++) {
        dataFile.print(Datos[i]);
        if(i<22){
          dataFile.print(";");
        }
      }
      dataFile.println();
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



