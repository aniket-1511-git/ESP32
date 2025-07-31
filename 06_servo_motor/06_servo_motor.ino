#include <ESP32Servo.h>

Servo servoMotor;
#define servoPin_u8 18
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  Serial.println("Servo Motor");
  servoMotor.attach(servoPin_u8);
}

void loop() {
  servoMotor.write(0);
  delay(1000);
  servoMotor.write(90);
  delay(1000); 
  servoMotor.write(180);
  delay(1000);
}
