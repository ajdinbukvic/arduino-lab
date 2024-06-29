#include <ESP8266WiFi.h>

const char* ssid = "Test";

const char* password = "12345678";

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
  auto client_count = wifi_softap_get_station_num();
  Serial.printf("Ukupno povezanih uredjaja = %d\n", client_count);
  auto i = 1;
  struct station_info *station_list = wifi_softap_get_station_info();
  while (station_list != NULL) {
    auto station_ip = IPAddress((&station_list->ip)->addr).toString().c_str();
    char station_mac[18] = {0};
    sprintf(station_mac, "%02X:%02X:%02X:%02X:%02X:%02X", MAC2STR(station_list->bssid));
    Serial.printf("%d. %s %s", i++, station_ip, station_mac);
    station_list = STAILQ_NEXT(station_list, next);
  }
  wifi_softap_free_station_info();
  delay(5000);
}