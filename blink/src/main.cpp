#ifdef ENERGIA
  #include "Energia.h"
#else
  #include "Arduino.h"
#endif

#ifndef LED_PIN
  // Most Arduino boards already have a LED attached to pin 13 on the board itself
  #define LED_PIN 4
#endif

void setup()
{
  pinMode(LED_PIN, OUTPUT);     // set pin as output
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);  // set the LED on
  delay(500);                  // wait for a second
  digitalWrite(LED_PIN, LOW);   // set the LED off
  delay(200);                  // wait for a second
}
