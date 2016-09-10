
#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>
const int chipSelect = 4;

  
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0x98, 0x4F, 0xEE, 0x01, 0x0D, 0x98
};
IPAddress ip(169, 254, 203, 190);
// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);
void setup() {
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


}

int TENSIONDELINEA, CORRIENTEDELINEA, TENSIONDELINVERSOR, CORRIENTEDELINVERSOR, FRECUENCIA, FASE, TEMPERATURA, dato, OTRO, i;
String ESTADO;
int contador = 0;
byte  deltaTensionRed, contadorDePaquetes, freTenDec, freTenEnt, freCorDec, freCorEnt, desfDec, desfEnt, tenTierra, delTensInt, corrInt, tenCont, estado, corrCont;

byte Datos[22];
int contadorDatos = 0;
int contadorHora = 0;
boolean fin_trama = false;
boolean Llega_Hora = false;
boolean Llega_Dato = false;
boolean Lectura_de_SD=false;
//boolean Actualizar = false;
File dataFile ;

void loop() {
  TENSIONDELINEA = Datos[2];
  CORRIENTEDELINEA = Datos[2];
  TENSIONDELINVERSOR = Datos[4];
  CORRIENTEDELINVERSOR = Datos[5];
  FRECUENCIA=Datos[6];
  FASE=Datos[7];
  TEMPERATURA=Datos[12];
  OTRO=Datos[15];
  
  Serie1();
  
  WebServer();
  
  Actualizar();
  SD_Guardar();
  SD_Leer();
  Serie_Borrar_SD();
}


