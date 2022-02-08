#include <Arduino.h>
#include <FastLED.h>

#define PIN_PHOTO_SENSOR A1
#define PIN_MOVE_SENSOR 3
#define LED_PIN 5
#define LED_COUNT 27

CRGB leds[LED_COUNT];
byte counter;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_MOVE_SENSOR, INPUT);
  pinMode(LED_PIN, OUTPUT);
  FastLED.addLeds< WS2812, LED_PIN, GRB>(leds, LED_COUNT);
  FastLED.setBrightness(100);
  // put your setup code here, to run once:
}

void loop() {
int pirVal = digitalRead(PIN_MOVE_SENSOR);
Serial.println(digitalRead(PIN_MOVE_SENSOR));
 
  for (int i = 0; i < LED_COUNT; i++) {
    leds[i].setHue(counter + i * 255 / LED_COUNT);
  }
  FastLED.show();
  counter++;        // counter меняется от 0 до 255 (тип данных byte)

  if (pirVal)
  {
    FastLED.setBrightness(100);
    for (int i = 0; i < LED_COUNT; i++) {
    leds[i].setHue(counter + i * 255 / LED_COUNT);
    }
  counter++;        // counter меняется от 0 до 255 (тип данных byte)
  FastLED.show();
    delay(3000);
  }
  else{
    FastLED.setBrightness(30);
    for (int i = 0; i < LED_COUNT; i++) {
    leds[i].setHue(counter + i * 255 / LED_COUNT);
  }
  FastLED.show();
  counter++;        // counter меняется от 0 до 255 (тип данных byte)
  }

  // put your main code here, to run repeatedly:
}