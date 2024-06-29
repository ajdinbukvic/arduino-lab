#include <ESP8266WiFi.h>

const char* ssid = "MFZE_studenti";

const char* password = "";

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
  Serial.printf("Broj dostupnih mreza = %d\n", n);
  for (int i = 0; i < n; ++i) {
    Serial.print(i + 1);
    Serial.print("naziv mreže ");
    Serial.print(WiFi.SSID(i));
    Serial.print(" Snaga signala je:");
    Serial.print(WiFi.RSSI(i));
    Serial.println(")");
    delay(10);
  }
}