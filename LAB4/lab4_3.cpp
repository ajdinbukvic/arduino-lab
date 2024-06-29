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
}

void loop() {
  EthernetClient client = server.available();
  char s = Serial.read();
  if (s == 'n') {
     if (client2.connect(server2, 5002)) {
        Serial.println("Connected");
      }
      else {
        Serial.println("Connection failed");
      }
      client2.println('u');
      client2.stop();
   }
   else if (s == 'k') {
     if (client2.connect(server2, 5002)) {
        Serial.println("Connected");
     }
     else {
        Serial.println("Connection failed");
     }
     client2.println('i');
     client2.stop();
  }
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