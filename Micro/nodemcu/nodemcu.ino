#include "DHT.h"

#define DHTPIN 4     // what digital pin the DHT22 is conected to
#define DHTTYPE DHT22   // there are multiple kinds of DHT sensors

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.setTimeout(2000);
  pinMode(2, OUTPUT); 
  while(!Serial) { }

  Serial.println("Device Started");
}

int timeSinceLastRead = 0;
void loop() {
  blinkLed(50);
  readDhtTemperature();
  readDhtHumidity();
  delay(5000);
}

void blinkLed(short timeOn){
  digitalWrite(2, LOW); 
    delay(timeOn);            
    digitalWrite(2, HIGH);
    delay(timeOn); 
}

float readDhtTemperature(){
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    Serial.println("E:01T");
    return -999;
  }

  Serial.print("T: ");
  Serial.print(t);
  Serial.println(" *C ");
  return t;
}

float readDhtHumidity(){
  // Read temperature as Celsius (the default)
  float h = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h)) {
    Serial.println("E:01H");
    return -999;
  }

  Serial.print("H: ");
  Serial.print(h);
  Serial.println(" % ");
  return h;
}

