#include <Arduino.h>
#include <Wire.h>        // I2C communication
#include <WiFi.h>
#include <HTTPClient.h>  // Required to install
#include "AmbiMate.h"
#include <stdio.h>


char ssid[]    =  "YOUR_WIFI_SSID";
char password[] = "YOUR_WIFI_PASSWORD" ;

AmbiMate sensor;
HTTPClient http;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  sensor.init();

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected.");
}

void loop() {

  sensor.scanAll();
  delay(200);
  sensor.sampleAll();
  
  float temperature = sensor.getTemperature();
  float humidity    = sensor.getHumidity();
  float light       = sensor.getLight();

  // REST  => JSON
  /*  {
   *    "temperature" : 23.3,
   *    "humidity"    : 50,
   *    "light"       : 323
   *  }
   */
  char buff[256];
  sprintf(buff, "{ \"temperature\": %2.2f, \"humidity\" : %2.2f, \"light\" : %2.2f }", temperature, humidity, light);

//  http.begin("http://192.168.1.103:7070/message");
  http.begin("http://demo.thingsboard.io:80/api/v1/c7QPEJTdGy43pSfsBLcW/telemetry");  // Requires your device token here
  http.addHeader("Content-Type", "application/json");
  
  int code = http.POST(buff);

  if (code > 0) {
    String payload = http.getString();
    Serial.println(payload);
    // payload can be checked
  }
  http.end();
  
  Serial.println(buff);

  delay(1000);
}
