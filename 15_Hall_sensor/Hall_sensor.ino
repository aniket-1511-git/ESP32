uint16_t hallVtg_u16;
void setup() {
  
  Serial.begin(9600);

}

void loop() {

  hallVtg_u16 = hallRead();   
  Serial.print(" Hall Voltage : ");
  Serial.println(hallVtg_u16);
  delay(1000); 
}