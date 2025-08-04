
#define SW_u8 14
#define LED_u8 2
#define RESET_u8 0
#define maxDelay_u8 100
uint8_t c = RESET_u8;

void setup() {
  
  Serial.begin(9600);
  Serial.println("Push Botton");
  pinMode(SW_u8, INPUT);
  pinMode(LED_u8, OUTPUT);
}

void loop() 
{
   if (digitalRead(SW_u8))
   {
      while(digitalRead(SW_u8));
              c+=1;
   }
   delay(maxDelay_u8);
   if(c%2==0){
      digitalWrite(LED_u8, LOW);
   }
   else
   {
      digitalWrite(LED_u8, HIGH);
   }
}
