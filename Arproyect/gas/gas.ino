int VALOR;
const int buzzer = 0;// Pin para el buzzer


void setup(){
  Serial.begin(9600);
    pinMode(buzzer, OUTPUT);//El pin del buzzer como salida
 digitalWrite(buzzer, LOW);
}
void loop(){
  VALOR = analogRead(A0);
  if(fireValor <= 1000){
    Serial.println("Fuego detectado!");
    digitalWrite(buzzer, HIGH);//Activamos el buzzer en forma continuo
    delay(5000);//Mantenemos el buzzer activo x 5 segundos
    digitalWrite(buzzer, LOW);//Lo desactivamos
  }
}



