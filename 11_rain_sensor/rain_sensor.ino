#define rain_sensor_u8 13
#define buzzer_u8 23
#define ON_u8 1
#define OFF_u8 0
uint8_t senOutput_u8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Rain Sensor");
  pinMode(buzzer_u8, OUTPUT);
  pinMode(rain_sensor_u8, OUTPUT);
}

void loop() {
  senOutput_u8 = digitalRead(rain_sensor_u8);
  if (ON_u8 == senOutput_u8 )
  {
    digitalWrite(buzzer_u8, HIGH);
  }
  else
  {
    digitalWrite(buzzer_u8, LOW);
  }
  delay(1000);
}
