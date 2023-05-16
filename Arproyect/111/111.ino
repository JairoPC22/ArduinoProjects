int VALOR;
int  pull = 0;
int lect1;

void setup() {
    pinMode (pull,INPUT);

  Serial.begin(9600);
  
}

void loop() {
  lect1=digitalRead(pull);
  Serial.println(lect1);
  delay(300);


}
