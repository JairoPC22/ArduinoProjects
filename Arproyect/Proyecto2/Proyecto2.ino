#include <WiFi.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <WiFiClientSecure.h>


const char* ssid = "INFINITUM65_2.4";
const char* password = "penacastro44";

#define token_Bot "6YdyiH6SII4A"

#define ID_Chat "5375718034"
WiFiClientSecure secured_client;
UniversalTelegramBot bot(token_Bot, secured_client);
const int buzzer = 0;// Pin para el buzzer
String mensaje = "";
const int firePin = 3;//pin para e l sensor de fuego
const int gasPin = 6;//Pin para el sensor de gas
int gasValor = 0;
int fireValor = 0;
////Setup////
void setup() {
  delay(5000);
  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);//El pin del buzzer como salida
  // Intenta conectarse a la red Wifi:
  Serial.print("Conectando a la red wifi... ");
  Serial.println(ssid);
  //Seteo de la red Wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); //Agregar certificado raíz para api.telegram.org
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("Conectado a la red wifi!!!");
  Serial.print("Dirección ip: ");
  Serial.println(WiFi.localIP());//Imprimimos la direción ip local
  bot.sendMessage(ID_Chat, "Sistema preparado!!!", "");//Enviamos un mensaje a telegram para informar que el sistema está listo
}
/////loop//////
void loop() {
   delay(500);
   //Lectura de los sensores
     fireValor = analogRead(firePin);
     gasValor = analogRead(gasPin);
  Serial.print("Sensor fuego: ");
  Serial.println(fireValor);  //Envío del valor al puerto serie
  Serial.print("Sensor gas: ");
  Serial.println(gasValor);  //Envío del valor al puerto serie
  if(fireValor <= 1000){
    Serial.println("Fuego detectado!");
    mensaje = "Se ha detectado fuego";//Mensaje
    bot.sendMessage(ID_Chat, mensaje, "");//Enviamos este mensaje a Telegram
    digitalWrite(buzzer, HIGH);//Activamos el buzzer en forma continuo
    delay(5000);//Mantenemos el buzzer activo x 5 segundos
    digitalWrite(buzzer, LOW);//Lo desactivamos
  }
    if(gasValor >= 1000){
    Serial.println("Escape de gas detectado!");
    mensaje = "Escape de gas detectado!";//Mensaje
    bot.sendMessage(ID_Chat, mensaje, "");//Enviamos este mensaje a Telegramm
for(int a =0; a <=28; a++){//Sonido del buzzer intermitente
   digitalWrite(buzzer, HIGH);
   delay(100);
  digitalWrite(buzzer, LOW); 
  delay(75);
    }
  }
}
