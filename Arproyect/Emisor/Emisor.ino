#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;
char opcion = ' ';

void setup() 
{
  rf_driver.init();
  Serial.begin(9600);}

void loop() {

if(Serial.available() !=0)
{
  opcion=Serial.read();
  
  if(opcion =='H')
  {
    const char *msg = "1";
  rf_driver.send((uint8_t*)msg, strlen(msg));
  rf_driver.waitPacketSent();
  Serial.println("SE ENCENDIO");
  }

    if(opcion =='L')
  {
    const char *msg = "0";
  rf_driver.send((uint8_t*)msg, strlen(msg));
  rf_driver.waitPacketSent();
  Serial.println("SE APAGO");
  }
}
  
}
