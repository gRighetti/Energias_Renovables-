//se encarga de inicializar el archivo txt con la cabecera para despues poder ser leido en matlab o en exel
void Archivo(){
  archivo=false;
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
  dataFile.print("Dia");
  dataFile.print(";");
  dataFile.print("Mes");
  dataFile.print(";");
  dataFile.println("Anio");
  
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

