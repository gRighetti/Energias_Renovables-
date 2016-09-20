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

    SD.remove("info.txt");
    archivo = true;
    if (SD.exists("info.txt")) {
      Serial.println("info.txt exists.");
    }
    else {
      Serial.println("info.txt doesn't exist.");
    }

  }

}

