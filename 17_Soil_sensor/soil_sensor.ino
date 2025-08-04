#define soilSensor_u8  27   
void setup() {
  Serial.begin(9600);

}

void loop() {
 Serial.print(("Soil Sensor = ");
 Serial.println(analogRead(soilSensor_u8));
  delay(3000);
 }
