void Serie_Borrar_SD() {
  while (Serial.available()) {
    Serial.read();
    // delete the file:
  Serial.println("Removing example.txt...");
 // SD.open("datalog.txt");
  SD.remove("datalog.txt");
  //dataFile.close();

  if (SD.exists("dataFile.txt")){ 
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");  
  }
    
  }
    
}

