int VALOR;
const int potPin = 34;


void setup() {
  Serial.begin(9600);
  
}

void loop() {
  VALOR = analogRead(potPin);
  Serial.println(VALOR);
  delay(5000);


}
