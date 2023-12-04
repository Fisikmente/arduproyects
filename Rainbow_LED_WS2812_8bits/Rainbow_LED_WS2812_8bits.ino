#include <Adafruit_NeoPixel.h>

#define pinLed 2  // input pin Neopixel is attached to
#define leds 8    // number of neopixels in strip

Adafruit_NeoPixel reglaLeds = Adafruit_NeoPixel(leds, pinLed, NEO_GRB + NEO_KHZ800);

int delayVal = 500;  // timing delay in milliseconds
int pinFire = A0;

void setup() {
  reglaLeds.begin();  // Initialize the NeoPixel library.
  reglaLeds.show();
  Serial.begin(9600);

}

void loop() {
  int llama = analogRead(pinFire);
  Serial.print("Intensidad: ");
  Serial.println(llama);
  colorfull(reglaLeds.Color(255,255,255));  // LEDs en blanco
  delay(delayVal/2);
  
  while(llama < 100) {
    colorfull(reglaLeds.Color(255,0,0));  // LEDs en rojo
    delay(delayVal);
    llama = analogRead(pinFire);
  }
  // colorfull(reglaLeds.Color(0,0,255));
  // delay(delayVal);
}

void colorfull(uint32_t color) {
  for (int i = 0; i < reglaLeds.numPixels(); i++) {
    reglaLeds.setPixelColor(i, color);
  }
  reglaLeds.show();
}