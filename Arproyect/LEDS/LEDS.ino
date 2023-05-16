#include <RH_ASK.h>
#include <SPI.h>


int  pull = 4;
int  pul2 = 5;

int lect1,lect2;
int contador = 0;
int contador1 = 0;


RH_ASK rf_driver;


void setup() 
{
  pinMode (pull,INPUT);
  pinMode (pul2,INPUT); 

  
  rf_driver.init();
  Serial.begin(9600);
  
}

void loop() 
{
  lect1=digitalRead(pull);
  lect2=digitalRead(pul2);

  //Serial.print(lect1);
  //Serial.println(lect2);

  if(lect1==HIGH)
  {
    contador++;
    if(contador >1)
    {
      contador = 0;
    }
    //Serial.println(contador);
  }
if (lect2==HIGH)
{
  contador1++;
  if(contador1>1)
  {
    contador1 =0;
  }
   //Serial.println(contador1);
}
  if(contador==1)
  {
    const char *msg = "1";
  rf_driver.send((uint8_t*)msg, strlen(msg));
  rf_driver.waitPacketSent();
  Serial.println("H L1");
  }

    if(contador==0)
  {
    const char *msg = "0";
  rf_driver.send((uint8_t*)msg, strlen(msg));
  rf_driver.waitPacketSent();
  Serial.println("L L1");
  }

  if(contador1==1)
  {
    const char *msg = "2";
  rf_driver.send((uint8_t*)msg, strlen(msg));
  rf_driver.waitPacketSent();

  Serial.println("H L2");
  }

    if(contador1==0)
  {
    const char *msg = "3";
  rf_driver.send((uint8_t*)msg, strlen(msg));
  rf_driver.waitPacketSent();
  Serial.println("L L2");
  }
  delay(100);
}
