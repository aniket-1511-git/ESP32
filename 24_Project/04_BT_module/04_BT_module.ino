#include "BluetoothSerial.h"
#include<Wire.h>

#define UT_trig_u8 5
#define UT_echo_u8 18


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {

  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.begin(9600);
  pinMode(UT_trig_u8,OUTPUT);
  pinMode(UT_echo_u8,INPUT);
  SerialBT.println("Ultra_Sonic With ESP32!");
}

void loop() {
  digitalWrite(UT_trig_u8,LOW);
  delay(2);
  digitalWrite(UT_trig_u8,HIGH);
  delay(10);
  digitalWrite(UT_trig_u8,LOW);
  uint32_t time = pulseIn(UT_echo_u8,HIGH);
  uint32_t dist = (time /2.0)/29.1;
 if (SerialBT.available()) {
  if(10< dist && 40 >dist){
      SerialBT.print("Distance :- ");
      SerialBT.println(dist);
  }
 }
 Serial.println(dist);
 delay(1000);
}