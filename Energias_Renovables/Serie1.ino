
void Serie1() {
  while (Serial1.available()) {   
  
       Datos[contadorDatos] = Serial1.read();
    //   Serial.println(Datos[contadorDatos]);
       
    if (Datos[contadorDatos] == 255) {
      contadorHora++;
    }
    contadorDatos++;
    if (contadorHora == 3 && contadorDatos == 3) {
      Llega_Hora = true;
    }

    if (Llega_Hora == true && contadorDatos >= 8) {
  //    Serial.println("Horaaaa");
      Act=true;
      contadorDatos = 0;
      contadorHora = 0;
      fin_trama = true;
    }
    if (contadorDatos >= 23) {
    //  Serial.println("Datosss");
      Act=true;
      contadorDatos = 0;
      contadorHora = 0;
      Llega_Dato = true;
      fin_trama = true;
    }
    
  }


}
