void SD_Leer(void){


  if(Lectura_de_SD){
    Lectura_de_SD=false;
  
// re-open the file for reading:

  dataFile = SD.open("datalog.txt");
  if (dataFile) {
      Serial.println("Lectura del archivo datalog.txt: ");
    
    // read from the file until there's nothing else in it:
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    // close the file:
    
    dataFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening datalog.txt");
  }
  }
}
