#include <SD.h>
#include <Ethernet.h>
#include <Time.h>
#include <TimeLib.h>
#include <SPI.h>

const int chipSelect = 4;

  
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0x98, 0x4F, 0xEE, 0x01, 0x0D, 0x98
};
//IPAddress ip(100, 100, 144, 210);   //ucc facu
IPAddress ip(192, 168, 0, 102);
// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);
void setup() {
  pinMode(13, OUTPUT);
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600); delay(5000);
  Serial1.begin(9600); delay(5000);
  // start the Ethernet connection and the server:
   Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());


   Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
   //  don't do anything more:
    return;
  }
  Serial.println("card initialized.");
 // system("install vsftpd openssh-sftp-server");


}

int TENSIONDELINEA, CORRIENTEDELINEA, TENSIONDELINVERSOR, CORRIENTEDELINVERSOR, FRECUENCIA, FASE, TEMPERATURA, dato, OTRO, i;
String ESTADO,t;
String direccion_mail,direccion_mail1,direccion_mail2;
int contador = 0;
byte  TensiondeRed, CorrientedeRed, freTenDec, freTenEnt, freCorDec, freCorEnt, desfDec, TensionTierra, delTensInt, corrInt, tenCont, estado, corrCont;
byte Estado, temp11,temp12,temp21,temp22,temp31,temp32,temp41,temp42,Humedad,PWM,ff1,ff2,ff3,ff4,hora1,hora2,hora3,hora4;
uint32_t hora11,hora21,hora31,hora41,horaUnix,hora,segundo,minuto,dia,mes,anio;
uint16_t desfEnt;
byte Datos[23];
int contadorDatos = 0;
int contadorHora = 0;
boolean fin_trama = false;
boolean Llega_Hora = false;
boolean Llega_Dato = false;
boolean Lectura_de_SD=false;
boolean Act = false;
boolean archivo=false;
boolean mail=false;
File dataFile, dataArchivo,mailFile ;

void loop() {

    
  if(archivo==true){
    Serial.println(Ethernet.localIP());
    Archivo();
  }
 // Serie1();
  WebServer();
  Actualizar(contadorDatos);
   SD_Guardar();
   SD_Leer();
  Serie_Borrar_SD();

  if(mail){
    mail=false;

    mailFile = SD.open("mail.txt", FILE_WRITE);
    mailFile.print(direccion_mail);
    mailFile.close();

    mailFile = SD.open("mail.txt");
   if (mailFile) {
      Serial.println("Lectura del archivo mail.txt: ");
    while (mailFile.available()) {
      Serial.write(mailFile.read());
    }
    Serial.println("");
    mailFile.close();
  } else {
    Serial.println("error opening mail.txt");
  }

    
    Serial.println("mandando mail");
    system("python /media/realroot/mail5.py");
   
    SD.remove("mail.txt");
    if (SD.exists("mail.txt")) {
      Serial.println("mail.txt exists.");
    }
    else {
      Serial.println("mail.txt doesn't exist.");
    }
    
  }
  
   
}


