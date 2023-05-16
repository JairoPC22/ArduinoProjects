#define SENSOR 2

byte v_sensor = 1;
void setup(){
  Serial.begin(9600);
  pinMode(SENSOR. INPUT);
}
void loop(){
  v_sensor = digitalRead(SENSOR);
  if(v_sensor == 0){
    Serial.println("Aún no me riegues wey");
   
  }else {
    Serial.println("Ya riegame wey");
  }
}
