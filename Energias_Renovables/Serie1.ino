
void Serie1() {
  while (Serial1.available()) {
    //if (Serial1.available()) {
    Datos[contadorDatos] = Serial1.read();
    if (Datos[contadorDatos] == 255) {
      contadorHora++;
    }
    contadorDatos++;
    if (contadorHora == 3 && contadorDatos == 3) {
      Llega_Hora = true;
    }

    if (Llega_Hora == true && contadorDatos >= 8) {
      contadorDatos = 0;
      contadorHora = 0;
      fin_trama = true;
    }
    if (contadorDatos >= 23) {
      contadorDatos = 0;
      contadorHora = 0;
      Llega_Dato = true;
      fin_trama = true;
    }
  }


}
