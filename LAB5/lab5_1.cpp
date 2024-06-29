include <ESP8266WiFi.h>

const char* ssid = "MFZE_studenti";

const char* password = "";

IPAddress local_IP(192, 168, 11, 241);
IPAddress gateway(192, 168, 8, 1);
IPAddress subnet(255, 255, 252, 0);

void setup() {
  WiFi.config(local_IP, gateway, subnet);
  WiFiServer server(7502);
  WiFi.begin(ssid, password);
  server.begin();
  Serial.begin(115200);
  delay(5000);
  Serial.println(WiFi.localIP());
}

void loop() {
  
}