#include "Scale.h"

Scale *scale = NULL;
unsigned long start;
bool isTare = false;

void setup() 
{
    Serial.begin(9600);
    scale = new Scale();
    scale->connect();

    start = millis();
}

void loop() {
  
  scale->update();
  if (scale->hasWeightChanged()) {
    Serial.print("battery: ");
    Serial.println(scale->getBattery());
    Serial.print("weight: ");
    Serial.println(scale->getWeight());
  }

  delay(1);
}

