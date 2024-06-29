#include <ESP8266WiFi.h>

const char* ssid = "MFZE_studenti";

const char* password = "";

float najveci = -999;

void setup() {
  WiFiServer server(7502);
  WiFi.begin(ssid, password);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  server.begin();
  Serial.begin(115200);
  delay(5000);
  Serial.println(WiFi.localIP());
}

void loop() {
  int n = WiFi.scanNetworks();
  for (int i = 0; i < n; ++i) {
    if (WiFi.SSID(i) == "Berlin_BB") {
      Serial.print(WiFi.RSSI(i));
      Serial.print(" | ");
      if (WiFi.RSSI(i) > najveci) {
        najveci = WiFi.RSSI(i);
      }
      Serial.println(najveci);
    }
    delay(10);
  }
}