int buzzer = 0;      // selecciona el pin para el zumbador
int valorSensor = 3;  // variable para almacenar el valor proveniente del sensor
int valorSensor2 = 3;  // variable para almacenar el valor proveniente del sensor

void setup() {
  //Seteo de la velocidad del puerto serial
  Serial.begin(9600);
  // declarar buzzer como una SALIDA:
  pinMode(buzzer, OUTPUT);
}
void loop() {
  // leer el valor del sensor:
  valorSensor = analogRead(A0);
  Serial.println(valorSensor);
  // activa el buzzer
  if (valorSensor < 500) {
    for(int a =0; a <=28; a++){//Sonido del buzzer intermitente
   digitalWrite(buzzer, HIGH);
   delay(100);
  digitalWrite(buzzer, LOW); 
  delay(75);
  }
  valorSensor2 = analogRead(A0);
  Serial.println(valorSensor2);
  if (valorSensor2 >= 1000) {
for(int a =0; a <=28; a++){//Sonido del buzzer intermitente
   digitalWrite(buzzer, HIGH);
   delay(100);
  digitalWrite(buzzer, LOW); 
  delay(75);
    }
}}
