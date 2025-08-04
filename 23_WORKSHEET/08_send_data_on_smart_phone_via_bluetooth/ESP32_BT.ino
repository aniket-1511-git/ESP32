#include "BluetoothSerial.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"

String  DATA;
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
void printDeviceAddress() {

const uint8_t* point = esp_bt_dev_get_address();

for (int i = 0; i < 6; i++) {
   char str[3];
   sprintf(str, "%02X", (int)point[i]);
   Serial.print(str);
   if (i < 5){
   Serial.print(":");}
}
Serial.println();
}

void setup()
{
DATA = "";

Serial.begin(9600);

pinMode(4, OUTPUT);
  SerialBT.begin("ESP32_Bluetooth");
  Serial.println("This is your Address");
  printDeviceAddress();

}


void loop()
{

    if (SerialBT.available()) {
      DATA = (SerialBT.readString());
      Serial.println("NEW DATA");
      Serial.println(DATA);
      if (DATA == "ON") {
        digitalWrite(4,HIGH);

      }
      if (DATA == "OFF") {
        digitalWrite(4,LOW);

      }

    }

}