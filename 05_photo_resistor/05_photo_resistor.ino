#define  LDR_u8 14
void setup() {

  Serial.begin(9600);
  Serial.println("Photo Resistor");

}

void loop() {
      uint16_t analogVtg = analogRead(LDR_u8);
       Serial.print("Analog Voltage : ");
      Serial.println(analogVtg);
      delay(1000);
}
