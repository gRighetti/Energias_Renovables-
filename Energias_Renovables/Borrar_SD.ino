void Serie_Borrar_SD() {
  while (Serial.available()) {
    Serial.read();
    Serial.println("Removing datalog.txt...");
    SD.remove("datalog.txt");
    archivo = true;
    if (SD.exists("datalog.txt")) {
      Serial.println("datalog.txt exists.");
    }
    else {
      Serial.println("datalog.txt doesn't exist.");
    }

  }

}

