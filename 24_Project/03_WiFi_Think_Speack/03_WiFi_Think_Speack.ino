#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

#include<Wire.h>
#include<HTTPClient.h>

#define UT_trig_u8 5
#define UT_echo_u8 18


const char* ssid = "aniket";
const char * pwd="aniket1818";
const char * servName = "http://api.thingspeak.com/update";
String apiKey = "H1ILTMLFD72YD6Q3";

void setup() {
  Serial.begin(9600);
  pinMode(UT_trig_u8,OUTPUT);
  pinMode(UT_echo_u8,INPUT);
  Serial.println("Ultra_Sonic With ESP32!");

  WiFi.begin(ssid ,pwd);
  Serial.println("Connecting...");
  while(WiFi.status()!= WL_CONNECTED)
  {
	delay(500);
	Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi Network with IP Address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
 
  if(WiFi.status()== WL_CONNECTED)
  {
     digitalWrite(UT_trig_u8,LOW);
    delay(2);
    digitalWrite(UT_trig_u8,HIGH);
    delay(10);
    digitalWrite(UT_trig_u8,LOW);
  
    uint32_t time = pulseIn(UT_echo_u8,HIGH);
    uint32_t dist = (time /2)/29;
    
    WiFiClient client;
    HTTPClient http;
    http.begin(client,servName);
    if(40>dist)
    {

    http.addHeader("Content-Type","application/x-www-form-urlencoded");
    String httpReqData = "api_key=" + apiKey + "&field1= " +String(dist);
    // int httpRespCode = http.POST(httpReqData);
    // Serial.print("HTTP Response Code : ");
    // Serial.println(httpRespCode);
    http.end();
    Serial.print("Distance :- ");
    Serial.print(dist);
    Serial.println(" cm");
    }
   
  }
  else
  {
    Serial.println("WiFi - Disconnected");
  }


}
