#include <WiFi.h>
#include <FirebaseESP32.h>

#define WIFI_SSID "INFINITUM1165_2.4"
#define WIFI_PASSWORD "penacastro44"

#define API_KEY "https://esp32-73eb1-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "6pmMjlrxqec0Ei0xFnrBjy6HNg7CKWG6Pw92CG7y"
long randomNumber;


FirebaseData firebaseData;

String nodo = "/sensores";
bool iterar = true;

void setup() {
  Serial.begin(115200);
  Serial.println();


  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectado al Wi-Fi");
  while (WiFi.status()!= WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();

  Firebase.begin(API_KEY, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
    randomSeed(39);         


}

void loop() {
while(iterar){
    randomNumber = random(1,100);

  Firebase.getInt(firebaseData, nodo + "/sensor1");
  Serial.println(firebaseData.intData());
  delay(250);
  Firebase.getString(firebaseData, nodo + "/sensor2");
  Serial.println(firebaseData.stringData());

  Firebase.setInt(firebaseData, nodo + "/sensor1", 512);
  Serial.println(randomNumber);

  Firebase.setString(firebaseData, nodo + "/sensor2", "On");
  Firebase.setBool(firebaseData, nodo + "/iterar", false);
 
  //Esperamos 1 segundo para repetir
  delay(1000);

  iterar = false;

  Firebase.end(firebaseData);
}
}
