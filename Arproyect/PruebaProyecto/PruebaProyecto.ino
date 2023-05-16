const int buzzer = 4;// Pin para el buzzer
const int firePin = gm;//pin para e l sensor de fuego
int fireValor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);//El pin del buzzer como salida
 digitalWrite(buzzer, LOW);

}
/////loop//////
void loop() { 
   delay(500);
   //Lectura de los sensores
     fireValor = analogRead(firePin);

  if(fireValor <= 1000){
    Serial.println("Fuego detectado!");
    digitalWrite(buzzer, HIGH);//Activamos el buzzer en forma continuo
    delay(500);//Mantenemos el buzzer activo x 5 segundos
    digitalWrite(buzzer, LOW);//Lo desactivamos
  }
      Serial.println(fireValor);

  
}
