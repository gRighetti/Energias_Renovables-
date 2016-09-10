
void Serie(){
  while (Serial1.available()) {
  contador++;
    switch (contador) {
      case (1):
      Serial.print("delta de tension:  " );
      deltaTensionRed=Serial1.read();
       Serial.println(deltaTensionRed);//char +- 311 offset
       TENSIONDELINEA=311+deltaTensionRed;
        break;
      
      case (2):
      Serial.print("delta de tension:  " );
      deltaTensionRed=Serial1.read();
       Serial.println(deltaTensionRed);//char +- 311 offset
       TENSIONDELINEA=311+deltaTensionRed;
        break;
      case (3):
          Serial.print("Corriente de red:  " );
          CORRIENTEDELINEA=Serial1.read();
       Serial.println(CORRIENTEDELINEA);
        break;
      case (4):
          freTenDec = Serial1.read();
          Serial.print("trama3 frecuencia de tencion decimal:  ");
       Serial.println(freTenDec);
        break;
      case (5):
          freTenEnt =Serial1.read();
          Serial.print("trama4 frecuencia de tension entera:  ");
       Serial.println(freTenEnt);
        break;
      case (6):
          freCorDec =Serial1.read();
          Serial.print("trama5 fecuencia de corriente decimal:  ");
       Serial.println(freCorDec);
        break;
      case (7):
         freCorEnt=Serial1.read();
          Serial.print("trama6 frecuencia de corriente entera:  " );
       Serial.println(freCorEnt);
        break;
      case (8):
          desfDec =Serial1.read();
          Serial.print("trama7 desfasaje decimal:  ");
       Serial.println(desfDec);
        break;
      case (9):
          desfEnt=Serial1.read();
          Serial.print("trama8:  " );
       Serial.println(desfEnt);
        break;
        case (10):
          tenTierra=Serial1.read();
          Serial.print("trama9 tension de tierra:  " );
       Serial.println(tenTierra);
        break;
        case (11):
          delTensInt=Serial1.read();
          Serial.print("trama10 delta de tension interna:  " );
       Serial.println(delTensInt);
        break;
        case (12):
          corrInt=Serial1.read();
          Serial.print("trama11 corriente interna:  " );
       Serial.println(corrInt);
        break;
        case (13):
          tenCont=Serial1.read();
          Serial.print("trama12 tension continua:  " );
       Serial.println(tenCont);
        break;
        case (14):
          corrCont =Serial1.read();
          Serial.print("trama13 corriente continua:  " );
       Serial.println(corrCont);
        break;
        case (15):
          estado=Serial1.read();
          Serial.print("trama14 estado:  " );
       Serial.println(estado);
       contador=0;
        break;
    
    
    
     }

  
    }
}

