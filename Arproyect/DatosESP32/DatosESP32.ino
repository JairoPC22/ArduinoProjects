#include <WiFi.h>
  #include <HTTPClient.h>

int value1;

// Replace with your network credentials
const char* ssid     = "JISA.COM";
const char* password = "Mr.Robot22";

// REPLACE with your Domain name and URL path or IP address with path
const char* serverName = "http://192.168.0.104/ESP32/data.php";

// Keep this API Key value to be compatible with the PHP code provided in the project page. 
// If you change the apiKeyValue value, the PHP file /post-esp-data.php also needs to have the same key 
String apiKeyValue = "tPmAT5Ab3j7F9";

String location = "Clase";
String sensor = "Gas";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  }
}

void loop() 
{
  // Clears the trigPin
  value1 = analogRead(A0);

  
  
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;
    
    // Your Domain name with URL path or IP address with path
    http.begin(client, serverName);
    
    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    // Prepare your HTTP POST request data
    String httpRequestData = "api_key=" + apiKeyValue + "&sensor=" + sensor
                          + "&location=" + location +  "&value1" + value1;
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    

    // Send HTTP POST request
    int httpResponseCode = http.POST(httpRequestData);
  
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    
    // Free resources
    http.end();
    }
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  //Send an HTTP POST request every 30 seconds
  delay(3000);  

}


