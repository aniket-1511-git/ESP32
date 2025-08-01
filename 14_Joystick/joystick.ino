#define joystick_A_u8 34
#define joystick_B_u8 35

uint16_t outPutA_u16,outPutB_u16;

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  outPutA_u16 = analogRead(joystick_A_u8);
  outPutB_u16 = analogRead(joystick_B_u8);
  if (outPutA_u16 == outPutB_u16)
  {
     Serial.println("Ideal");
  }
  if (outPutA_u16 == 0)
  {
     Serial.println("BOTTOM");
  }
  else if (outPutA_u16 > 4000)
  {
     Serial.println("TOP");
  }
  if (outPutB_u16 == 0)
  {
     Serial.println("RIGHT");
      
  }
  else if (outPutB_u16 > 4000)
  {
     Serial.println("LEFT");
  }
  
}
