#indef__cplusplus
extern "C"{
#endif
uint8_t temprature_sens_read();
#indef__cplusplus
}
#endif

uint8_t temprature_sens_read();

void setup()
{
	Serial.begin(9600);
	Serial.println("Temperatur of Internal sensor");
}
void loop()
{
	uint16_t rawTemp = temprature_sens_read();
	uint16_t tempCel = (rawTemp  - 32)/1.8;
	Serial.print(tempCel );	
	Serial.println(" Cel");
			
}