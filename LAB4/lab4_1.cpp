#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xAA, 0xBB, 0xCC, 0xDD, 0x1E, 0x1F };
IPAddress ip(192,168,0,52);
EthernetServer server(5000);
const int ledPin = 9;
char c = 0;
char command[2] = "\0";

void setup() {
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
Ethernet.begin(mac, ip);
server.begin();
delay(5000);
Serial.println(Ethernet.localIP());
}

void loop() {
EthernetClient client = server.available();
if (client) {
while (client.connected()) {
if (client.available()) {
char c = client.read();
Serial.println(c);
if (c == 'u') {
digitalWrite(ledPin, HIGH);
}
else if (c == 'i') {
digitalWrite(ledPin, LOW);
}
}
}
}
}