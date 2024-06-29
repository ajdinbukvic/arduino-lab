#include <NewPing.h>

const int trigPin1 = 9;
const int echoPin1 = 10;

const int trigPin2 = 2;
const int echoPin2 = 3;

const int MAX_DISTANCE = 400;

NewPing sonar1(trigPin1, echoPin1, MAX_DISTANCE);
NewPing sonar2(trigPin2, echoPin2, MAX_DISTANCE);

int distance1, distance2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(50);                   
  distance1 = sonar1.ping_cm();
  distance2 = sonar2.ping_cm();
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println("cm");
  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println("cm");
}