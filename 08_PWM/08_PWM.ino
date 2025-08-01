#define  LED_u8  12
#define PWM_Freq_u16 5000
#define PWM_resol_u8 8
#define PWM_MAX_Duty_Cycle_u16 500
#define PWM_MIN_Duty_Cycle_u8 00
void setup() {
  ledcAttach(LED_u8,PWM_Freq_u16,PWM_resol_u8);
}

void loop() {

  uint16_t dutyCycle;
  for(dutyCycle = PWM_MIN_Duty_Cycle_u8;dutyCycle < PWM_MAX_Duty_Cycle_u16; dutyCycle++)
  {
      ledcWrite(LED_u8,dutyCycle);
      delay(100);
  }
  for(;dutyCycle >= PWM_MIN_Duty_Cycle_u8; dutyCycle--)
  {
      ledcWrite(LED_u8,dutyCycle);
      delay(100);
  }
}
