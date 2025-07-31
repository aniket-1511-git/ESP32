#define LED1_u8 2
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("LED BLINKING");
  pinMode(LED1_u8, OUTPUT);
}

void loop() {
  digitalWrite(LED1_u8, HIGH);
  delay(1000); 
  digitalWrite(LED1_u8, LOW);
  delay(1000);
}
