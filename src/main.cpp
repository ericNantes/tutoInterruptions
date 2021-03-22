#include <Arduino.h>
#define PIN_BP 2
#define DELAI_SANS_REBOND 100

volatile int compteurBP = 0;

void ISR_BP() {
  static u32 precedenteIT = 0;
  u32 _millis = millis();
  if ((_millis - precedenteIT) >= DELAI_SANS_REBOND) {
    compteurBP++;
  }
  precedenteIT = _millis;
}

void setup() { 
  Serial.begin(9600);
  pinMode(PIN_BP, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_BP), ISR_BP, FALLING);
}

void loop() {
  Serial.println(compteurBP);
  Serial.println(compteurBP);
  delay(3000);
}