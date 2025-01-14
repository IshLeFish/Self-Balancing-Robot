#include <Arduino.h>

bool i = 0;



void setup() {
    pinMode(LED_BUILTIN,OUTPUT);
    Serial.begin(115200);
}

void loop() {
    digitalWrite(LED_BUILTIN,i);
    Serial.println(i);
    i != i;
    delay(1000);
}