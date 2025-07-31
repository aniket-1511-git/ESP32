#include "DHT.h"
#define DHT11_u8 2
uint16_t t,h;
DHT dht2(DHT11_u8,DHT11);

void setup() {
  
  Serial.begin(9600);
  Serial.println("DHT11 Temp Sensor ");
  Serial.println("TEMPERATURE \t HUMIDITY\n");
}
void loop() 
{
  
  t=dht2.readTemperature();
  h=dht2.readHumidity();
  if(h&&t)
  {
     Serial.print(t);
    Serial.print("\t      \t");
    Serial.println(h);
  }
 
}