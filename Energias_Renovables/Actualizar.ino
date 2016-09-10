void Actualizar() {
  if (fin_trama) {
   // fin_trama = false;
    if (Llega_Hora) {
      //Borrar esto de abajo era prueba
      ESTADO = "HORA";
             //  Llega_Hora = false;
      Serial.println("LLegoHora");
      for (int i = 0; i <= 7; i++) {
        Serial.print("Datos");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(Datos[i]);

      }

    }
    if (Llega_Dato) {
      //Borrar esto de abajo era prueba
      ESTADO = "DATO";
             //  Llega_Dato = false;
      Serial.println("LLegoDato");
      for (int i = 0; i <= 22; i++) {
        Serial.print("Datos");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(Datos[i]);

      }
    }
  }
}
