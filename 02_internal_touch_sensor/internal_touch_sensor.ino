#define touch_sensor_u8 4
#define LED_u8  2
#define  max_u16 150
void setup() {
  Serial.begin(9600);
  Serial.println("Internal Touch Sensor ");
  pinMode(LED_u8, OUTPUT);
}
void loop() 
{
  uint16_t val_u16 = touchRead(touch_sensor_u8);
  if(max_u16 > val_u16)
  {
    digitalWrite(LED_u8, HIGH);
  }
  else
  {
    digitalWrite(LED_u8, LOW);
  }
}
