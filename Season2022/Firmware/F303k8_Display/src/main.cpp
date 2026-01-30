#include <mbed.h>
#include "Adafruit_ILI9341.h"

Adafruit_ILI9341 tft = Adafruit_ILI9341(D4,D3,D5);
Timer t;

int main() {
    tft.begin();
    t.start();
    tft.fillScreen(ILI9341_BLACK);
    tft.setTextSize(2);
    tft.setRotation(-45);
    while(1) {
      tft.setCursor(0,0);
      tft.print("Hello LCD!!");
    }
}