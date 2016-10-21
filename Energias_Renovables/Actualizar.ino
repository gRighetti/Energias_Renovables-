void Actualizar(int contDatos) {
    contador = 0;

  if (Act && Llega_Dato) {
    Serial.println("Entra a actualizar datos" );
    
    Act = false;
    //Llega_Dato = false;
    while (contador < 23) {

      contador++;
      switch (contador) {

        case (1):
  
          TensiondeRed = 311 + (signed char)Datos[0];

         // Serial.print("delta de tension:  " );
         // Serial.println(TensiondeRed );
          break;

        case (2):
          //Serial.print("Corriente de red:  " );
          CorrientedeRed = (uint8_t)Datos[1];
         // Serial.println(CorrientedeRed);

          break;
        case (3):
          //determinar bien la frcuencia
         // Serial.print("Frecuencia:  " );
          freTenDec = Datos[2];

          break;
        case (4):
          freTenEnt = Datos[3];
         // Serial.print(freTenEnt);
         // Serial.print("." );
         // Serial.println(freTenDec);

          break;
        case (5):
          desfDec = Datos[4] & 7;
          break;
        case (6):
          desfEnt = (uint16_t)Datos[5];
          desfEnt = desfEnt << 5;
          desfEnt = desfEnt | (Datos[4] >> 3);
          //Serial.print("Desfasaje" );
          //Serial.print(desfEnt);
          //Serial.print(" °. " );
          //Serial.println(desfDec);
          break;
        case (7):
          //Serial.print("Tension-Tierra" );
          TensionTierra = Datos[6];
          //Serial.println(TensionTierra);
          break;
        case (8):
          //determinar bien el valor
          delTensInt = 311 + (signed char)Datos[7];
        //  Serial.print("delta de tension interna:  " );
        //  Serial.println(delTensInt );;
          break;
        case (9):
         // Serial.print("Corriente Interna" );
          corrInt = Datos[8];
          //Serial.println(corrInt);
          break;
        case (10):
         // Serial.print("Tension-Continua  " );
          tenCont = Datos[9];
          //Serial.println(tenCont);
          break;
        case (11):
          //Serial.print("Corriente-Continua  " );
          corrCont = Datos[10];
          //Serial.println(corrCont);
          break;
        case (12):
          if (Datos[11] == 0) {
            //Serial.println("ESTADO: ");
            ESTADO = "OK";
           // Serial.println(ESTADO);

          } else {

            if ((Datos[11] & 1)) {

             // Serial.println("ESTADO: ");
              ESTADO = "High Voltage";
             // Serial.println(ESTADO);
            }

            if ((Datos[11] & 2)) {
             // Serial.println("ESTADO: ");
              ESTADO = "Low Voltage";
             // Serial.println(ESTADO);
            }
            if ((Datos[11] & 4)) {
              //Serial.println("ESTADO: ");
              ESTADO = "Low FREQ";
              //Serial.println(ESTADO);
            }
            if ((Datos[11] & 8)) {
             // Serial.println("ESTADO: ");
              ESTADO = "High FREQ";
             // Serial.println(ESTADO);
            }
            if ((Datos[11] & 16)) {
              //Serial.println("ESTADO: ");
              ESTADO = "High GND";
              //Serial.println(ESTADO);
            }
          }
          break;
        case (13):
       //   Serial.print("Temp11  " );
          temp11 = Datos[12];
         // Serial.println(temp11);
          break;
        case (14):
          //Serial.print("Temp12  " );
          temp12 = Datos[13];
        //  Serial.println(temp12);
          break;
        case (15):
        //  Serial.print("Temp21  " );
          temp21 = Datos[14];
         // Serial.println(temp21);
          break;
        case (16):
        //  Serial.print("Temp22   " );
          temp22 = Datos[15];
        //  Serial.println(temp22);
          break;
        case (17):
         // Serial.print("Temp31  " );
          temp31 = Datos[16];
          //Serial.println(temp31);
          break;
        case (18):
         // Serial.print("Temp32  " );
          temp32 = Datos[17];
         // Serial.println(temp32);
          break;
        case (19):
          //Serial.print("Temp41  " );
          temp41 = Datos[18];
          //Serial.println(temp41);
          break;
        case (20):
          //Serial.print("Temp42  " );
          temp42 = Datos[19];
          //Serial.println(temp42);
          break;
        case (21):
        //  Serial.print("Humedad  " );
          Humedad = Datos[20];
         // Serial.println(Humedad);
          break;
        case (22):
         // Serial.print("PWM  " );
          PWM = Datos[21];
          //Serial.println(PWM);
          break;
      }

    }
  }

  if (Act && Llega_Hora) {
    Serial.println("Entra a actualizar hora" );
    Act = false;
    //  Llega_Hora = false;
    while (contador < 8) {
      contador++;
      switch (contador) {

        case (1):
          //determinar bien el valor
        //  Serial.print("hora ff: ");
          ff1 = Datos[0];
          //Serial.println(ff1);
          break;

        case (2):
        //  Serial.print("hora ff: ");
          ff2 = Datos[1];
         // Serial.println(ff2);
          break;
        case (3):
         // Serial.print("hora ff: ");
          ff3 = Datos[2];
         // Serial.println(ff3);
          break;
        case (4):
        //  Serial.print("hora1: ");
          hora1 = Datos[3];
          hora11 = hora1;
        //  Serial.println(hora1);

          break;
        case (5):
        //  Serial.print("hora2: ");
          hora2 = Datos[4];
          hora21 = hora2 << 8;
        //  Serial.println(hora2);
          break;
        case (6):
        //  Serial.print("hora3: ");
          hora3 = Datos[5];
          hora31 = hora3 << 16;
        //  Serial.println(hora3);
          break;
        case (7):
       //   Serial.print("hora4: ");
          hora4 = Datos[6];
          hora41 = hora4 << 24;
        //  Serial.println(hora4);
          break;
        case (8):
        //  Serial.print("hora ff: ");
          ff4 = Datos[7];
        //  Serial.println(ff4);
          break;
      }
    }

    //acomodo la hora en un 32bits para unix
    
  ///*
    
    horaUnix = hora11 | hora21 | hora31 | hora41;
 //   Serial.print("hora ya en unix:  ");
  //  Serial.println(hora);
  //  Serial.println(hora, BIN);
    setTime(horaUnix) ;
    hora=hour();
  //  Serial.print(hour());
  //  Serial.print(" ");
    minuto=minute();
   // Serial.print(minute());
   // Serial.print(" ");
    segundo=second();
   // Serial.print(second());
  //  Serial.print(" ");
  //  Serial.print(" ");
    dia=day();
   // Serial.print(day());
   // Serial.print(" ");
    mes=month();
   // Serial.print(month());
   // Serial.print(" ");
    anio=year();
    //Serial.print(year());
    //Serial.println();
 // */ 
  }
}


