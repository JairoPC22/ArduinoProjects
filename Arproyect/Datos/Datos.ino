#include <WiFi.h>
#include <FirebaseESP32.h>

#define WIFI_SSID "JISA.COM"
#define WIFI_PASSWORD "Mr.Robot22"

#define API_KEY "https://esp32-73eb1-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "6pmMjlrxqec0Ei0xFnrBjy6HNg7CKWG6Pw92CG7y"

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

}

void loop() {
while(iterar){
  Firebase.getInt(firebaseData, nodo + "/sensor1");
  Serial.println(firebaseData.intData());
  delay(250);
  Firebase.getString(firebaseData, nodo + "/sensor2");
  Serial.println(firebaseData.stringData());

  Firebase.setInt(firebaseData, nodo + "/sensor1", 666);
  Firebase.setString(firebaseData, nodo + "/sensor2", "Hector");
  Firebase.setBool(firebaseData, nodo + "/iterar", false);


  iterar = false;

  Firebase.end(firebaseData);
}
}
