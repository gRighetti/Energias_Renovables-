//en datalog.txt se almacenan los datos procesados para ser mostrados
// en info.txt se almacenan los datos como vienen delinversor

void SD_Guardar(void) {
  if (fin_trama && archivo == false) {

    fin_trama = false;
    if (Llega_Hora) {
      //modificar el almacenamiento de esto porque esta mal
      dataArchivo = SD.open("info.txt", FILE_WRITE);
      Llega_Hora = false;
      Serial.println("Se guarda Hora");
      Lectura_de_SD = true;
      for (int i = 0; i <= 7; i++) {
        dataArchivo.print(Datos[i],BIN);
        if (i < 7) {
          dataArchivo.print(";");
        }
      }
      dataArchivo.println();
      if (dataArchivo) {
        dataArchivo.close();
       // Serial.println("Se guardo correctamenteen la SD: info.txt");
      }
      else {
        Serial.println("error opening info.txt");
      }
    }


    if (Llega_Dato) {
      //modificar el almacenamiento de esto porque esta mal
      dataArchivo = SD.open("info.txt", FILE_WRITE);
      Llega_Dato = false;
      Serial.println("Se guarda Dato");
      for (int i = 0; i <= 22; i++) {
        dataArchivo.print(Datos[i],BIN);
        if (i < 22) {
          dataArchivo.print(";");
        }
      }
      dataArchivo.println();
      if (dataArchivo) {
        dataArchivo.close();
       // Serial.println("Se guardo correctamenteen la SD: info.txt");
      }
      else {
        Serial.println("error opening info.txt");
      }

      dataFile = SD.open("datalog.txt", FILE_WRITE);
      dataFile.print(TensiondeRed);
      dataFile.print(";");

      dataFile.print(CorrientedeRed);
      dataFile.print(";");

      dataFile.print(freTenEnt);
      dataFile.print(".");
      dataFile.print(freTenDec);
      dataFile.print(";");

      dataFile.print(desfEnt);
      dataFile.print("°,");
      dataFile.print(desfDec);
      dataFile.print(";");

      dataFile.print(TensionTierra);
      dataFile.print(";");

      dataFile.print(delTensInt);
      dataFile.print(";");

      dataFile.print(corrInt);
      dataFile.print(";");

      dataFile.print(tenCont);
      dataFile.print(";");
      
       dataFile.print(corrCont);
      dataFile.print(";");
      
      dataFile.print(ESTADO);
      dataFile.print(";");


      dataFile.print(temp11);
      dataFile.print("." );
      dataFile.print(temp12);
      dataFile.print(";");

      dataFile.print(temp21);
      dataFile.print("." );
      dataFile.print(temp22);
      dataFile.print(";");

      dataFile.print(temp31);
      dataFile.print("." );
      dataFile.print(temp32);
      dataFile.print(";");

      dataFile.print(temp41);
      dataFile.print("." );
      dataFile.print(temp42);
      dataFile.print(";");

      dataFile.print(Humedad);
      dataFile.print(";");

      dataFile.print(PWM);
      dataFile.print(";");

      dataFile.print(hora);
      dataFile.print(";");
      dataFile.print(minuto);
      dataFile.print(";");
      dataFile.print(segundo);
      dataFile.print(";");
      dataFile.print(dia);
      dataFile.print(";");
      dataFile.print(mes);
      dataFile.print(";");
      dataFile.println(anio);


      if (dataFile) {
        dataFile.close();
        Serial.println("Se guardo correctamenteen la SD: datalog.txt");
      }
      else {
        Serial.println("error opening datalog.txt");
      }
    }


  }
}



