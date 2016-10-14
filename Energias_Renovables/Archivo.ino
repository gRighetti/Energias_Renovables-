//se encarga de inicializar el archivo txt con la cabecera para despues poder ser leido en matlab o en exel
void Archivo() {
  archivo = false;
  dataFile = SD.open("datalog.txt", FILE_WRITE);
  dataFile.print("Tension-RED");
  dataFile.print(";");
  dataFile.print("Corrient-RED");
  dataFile.print(";");
  dataFile.print("Frecuencia");
  dataFile.print(";");
  dataFile.print("Desfasaje");
  dataFile.print(";");
  dataFile.print("Tensiion-tierra");
  dataFile.print(";");
  dataFile.print("Tension-Interna");
  dataFile.print(";");
  dataFile.print("Corriente-Interna");
  dataFile.print(";");
  dataFile.print("Tension-Continua");
  dataFile.print(";");
  dataFile.print("Corriente-Continua");
  dataFile.print(";");
  dataFile.print("Estado");
  dataFile.print(";");
  dataFile.print("Temperatura1");
  dataFile.print(";");
  dataFile.print("Temperatura2");
  dataFile.print(";");
  dataFile.print("Temperatura3");
  dataFile.print(";");
  dataFile.print("Temperatura4");
  dataFile.print(";");
  dataFile.print("Humedad");
  dataFile.print(";");
  dataFile.print("PWM");
  dataFile.print(";");
  dataFile.print("Hora");
  dataFile.print(";");
   dataFile.print("Minuto");
  dataFile.print(";");
   dataFile.print("Segundo");
  dataFile.print(";");
  dataFile.print("Dia");
  dataFile.print(";");
  dataFile.print("Mes");
  dataFile.print(";");
  dataFile.println("Anio");
 

  if (dataFile) {
    // dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:

    Serial.println("Se guardo correctamenteen la SD: datalog.txt");
    //Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }

// se crea un segundo archivo con los datos que llegan 


  dataArchivo = SD.open("info.txt", FILE_WRITE);
  dataArchivo.print("BYTE0");
  dataArchivo.print(";");
  dataArchivo.print("BYTE1");
  dataArchivo.print(";");
   dataArchivo.print("BYTE2");
  dataArchivo.print(";");
   dataArchivo.print("BYTE3");
  dataArchivo.print(";");
   dataArchivo.print("BYTE4");
  dataArchivo.print(";");
   dataArchivo.print("BYTE5");
  dataArchivo.print(";");
   dataArchivo.print("BYTE6");
  dataArchivo.print(";");
   dataArchivo.print("BYTE7");
  dataArchivo.print(";");
   dataArchivo.print("BYTE8");
  dataArchivo.print(";");
   dataArchivo.print("BYTE9");
  dataArchivo.print(";");
   dataArchivo.print("BYTE10");
  dataArchivo.print(";");
   dataArchivo.print("BYTE11");
  dataArchivo.print(";");
   dataArchivo.print("BYTE12");
  dataArchivo.print(";");
   dataArchivo.print("BYTE13");
  dataArchivo.print(";");
   dataArchivo.print("BYTE14");
  dataArchivo.print(";");
   dataArchivo.print("BYTE15");
  dataArchivo.print(";");
   dataArchivo.print("BYTE16");
  dataArchivo.print(";");
   dataArchivo.print("BYTE17");
  dataArchivo.print(";");
   dataArchivo.print("BYTE18");
  dataArchivo.print(";");
   dataArchivo.print("BYTE19");
  dataArchivo.print(";");
  dataArchivo.print("BYTE20");
  dataArchivo.print(";");
   dataArchivo.print("BYTE21");
  dataArchivo.print(";");
   dataArchivo.println("BYTE22");
  

  if (dataArchivo) {
    // dataFile.println(dataString);
    dataArchivo.close();
    // print to the serial port too:

    Serial.println("Se guardo correctamenteen la SD: info.txt");
    //Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening info.txt");
  }





}

