int LED1=1;
int LED2=2;
int LED3=3;


void setup() 
{
  
  pinMode(LED1, OUTPUT);    
  pinMode(LED2, OUTPUT);  
  pinMode(LED3, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void loop() 
{
  digitalWrite(LED1, HIGH);
  delay(3000);
  digitalWrite(LED1, LOW);
  
  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED2, LOW);
  delay(500);


  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED2, LOW);
  delay(500);


  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED2, LOW);
  delay(500);

  
  digitalWrite(LED3, HIGH);
  delay(3000);
  digitalWrite(LED3, LOW);
  
  }
