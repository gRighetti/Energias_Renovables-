void Serie_Borrar_SD() {
  while (Serial.available()) {
    Serial.read();
    // delete the file:
  Serial.println("Removing example.txt...");
  SD.remove("dataFile.txt");

  if (SD.exists("dataFile.txt")){ 
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");  
  }
    
  }
    
}

