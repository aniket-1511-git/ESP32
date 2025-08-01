#define PIR_PIN_u8 12
#define LED_u8 23
#define ON_u8 1
#define OFF_u8 0
uint16_t pirVtg_u16;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("PIR MOTION SENSOR");
  pinMode(PIR_PIN_u8, INPUT);
  pinMode(LED_u8, OUTPUT);
}

void loop() 
{
  pirVtg_u16=digitalRead(PIR_PIN_u8);
  if(ON_u8 == pirVtg_u16){
    digitalWrite(LED_u8, HIGH);
    Serial.println("LED On ");
  }
  else if(OFF_u8 == pirVtg_u16){
    digitalWrite(LED_u8, LOW);
    Serial.println("LED Off ");
  }
  delay(1000);
}
