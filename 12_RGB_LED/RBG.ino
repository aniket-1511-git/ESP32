#define red_u8 12
#define blue_u8 13
#define green_u8 14


void setup() {
  pinMode(red_u8,OUTPUT);
  pinMode(blue_u8,OUTPUT);
  pinMode(green_u8,OUTPUT);
}

void loop() {
  digitalWrite(red_u8,HIGH);
  delay(1000);
  digitalWrite(red_u8,LOW);
  digitalWrite(blue_u8,HIGH);
  delay(1000);
  digitalWrite(blue_u8,LOW);
  digitalWrite(green_u8, HIGH);
  delay(1000); 
  digitalWrite(green_u8,LOW); 
}
