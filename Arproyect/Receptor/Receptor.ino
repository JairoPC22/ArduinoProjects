#include <RH_ASK.h>
#include <SPI.h>
RH_ASK rf_driver;

int LED1=3;
int LED2=4;

void setup() {

  rf_driver.init();

  pinMode(LED1, OUTPUT);
  Serial.begin(9600);

}

void loop() {
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);

    if(rf_driver.recv(buf, &buflen))
    
    {
      Serial.print("Mensaje: ");
      Serial.println((char*)buf);

      if((char)buf[0]=='0')
      {
        digitalWrite(LED1,LOW);
      }
            if((char)buf[0]=='1')
      {
                digitalWrite(LED1,HIGH);

      }
      if((char)buf[11]=='11')
      {
        digitalWrite(LED2,HIGH);
      }
      if((char)buf[00]=='00')
      {
        digitalWrite(LED2,LOW);
      }
      
    }

}
