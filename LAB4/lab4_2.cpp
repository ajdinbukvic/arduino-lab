#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xAA, 0xBB, 0xCC, 0xDD, 0x1E, 0x1F };
IPAddress ip(192,168,0,52);
EthernetServer server(5000); 
const int ledPin = 9;
char c = 0; 
char command[2] = "\0";
EthernetClient client2;
byte server2[4] = {192,168,0,51};

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  delay(3000);
  Serial.println(Ethernet.localIP());
  if (client2.connect(server2, 5002)) {
    Serial.println("Connected");
  }
  else {
    Serial.println("Connection failed");
  }
}

void loop() {
  EthernetClient client = server.available();
  if (client2) {
    while (client2.connected()) {
      char s = Serial.read();
      if (s == 'n') {
        client2.println('u');
      }
      else if (s == 'k') {
        client2.println('i');
      }
    }
  }
  client2.stop();
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