#include "Freenove_WS2812B_RGBLED_Controller.h"

#define I2C_ADDRESS  0x20
#define LEDS_COUNT   10

//Freenove_WS2812B_Controller strip(&Serial1,115200UL, LEDS_COUNT);
Freenove_WS2812B_Controller strip(I2C_ADDRESS, LEDS_COUNT);

void setup() {
  while (!strip.begin());
}

void loop() {
  for (int j = 0; j < 255; j += 2) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, strip.Wheel((i * 256 / LEDS_COUNT + j) & 255));
    }
    strip.show();
    delay(2);
  }  
}