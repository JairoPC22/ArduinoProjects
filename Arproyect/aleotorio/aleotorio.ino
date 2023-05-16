/*
 
Obtiene un numero aleatorio con semilla fija y lo muestra en monitor serie
*/
#include "WiFi.h"

const char* ssid = "INFINITUM1165_2.4";
const char* password = "penacastro44";
//Variable donde almacenaremos el numero aleatorio
long randomNumber;
 AsyncWebServer server(80);


//Función de inicialización
void setup() {
  
  //Inicializamos la comunicación serial
  Serial.begin(9600);
  
  //Escribimos por el puerto serie mensaje de inicio
  Serial.println("Inicio de sketch - secuencia de numeros aleatorios");
      
  //Establecemos la semilla fija
  randomSeed(39);         
}
 
//Bucle principal
void loop() {
 
  //Genera un numero aleatorio entre 1 y 100
  randomNumber = random(1,100);
  
  //Escribimos el numero aleatorio por el puerto serie
  Serial.print("El numero aleatorio es = ");
  Serial.println(randomNumber);
 
  //Esperamos 1 segundo para repetir
  delay(1000);
}
