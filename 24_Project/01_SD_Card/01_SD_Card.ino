#include <SPI.h>
#include "SD.h"
#include "time.h"
#include <WiFi.h>
#include "time.h"
#include<Wire.h>

#define UT_trig_u8 12
#define UT_echo_u8 13
#define CS_u8 5

File ut_file;

const char* ssid = "aniket";
const char* password = "aniket1818";

const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 19800;  
const int daylightOffset_sec = 0;
void utDataWriteInFlash(const char *path, float dist) 
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) 
  {
    Serial.println("Failed to obtain time");
    return;
  }

  ut_file = SD.open(path, FILE_APPEND);
  if (ut_file) 
  {
    char timestamp[30];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &timeinfo);

    ut_file.println("Time: " + String(timestamp) + "  Distance: " + String(dist) + " cm");
    ut_file.close();
  } 
  else 
  {
    Serial.println("Failed to open file for writing.");
  }
}

void setup() {
  Serial.begin(9600);    
  delay(500);
// SD card init
 Serial.println("Initializing SD card...");
  if (!SD.begin(CS_u8)) 
  {
    Serial.println("SD card initialization failed!");
    while (1);
  }
  Serial.println("SD card initialized.");
  // UT .. 
  pinMode(UT_trig_u8,OUTPUT);
  pinMode(UT_echo_u8,INPUT);
   // Connect to WiFi
  Serial.printf("Connecting to %s", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected.");

  // Clock
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  Serial.println("Waiting for time...");
  struct tm timeinfo;
  while (!getLocalTime(&timeinfo)) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nTime synchronized.");
  ut_file = SD.open("/ut_log_data.txt", FILE_WRITE);
  ut_file.println("\tTime \t\t  Distance ");
}

void loop() {
   digitalWrite(UT_trig_u8,LOW);
  delay(2);
  digitalWrite(UT_trig_u8,HIGH);
  delay(10);
  digitalWrite(UT_trig_u8,LOW);
  
  uint32_t time = pulseIn(UT_echo_u8,HIGH);
  uint32_t dist = (time /2.0)/29.1;
    if(20<dist&& 40> dist)
  {
    utDataWriteInFlash("/ut_log_data.txt",dist);
    Serial.println(dist);
  }
}
