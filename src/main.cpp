#include <Arduino.h>
#include <FastLED.h>

#define PIN_PHOTO_SENSOR A1
#define PIN_MOVE_SENSOR 3
#define LED_PIN 5
#define LED_COUNT 27

CRGB leds[LED_COUNT];
byte counter;
uint32_t myTimer;
uint32_t myTimer1;
uint32_t myTimer2;
double bright = 1;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_MOVE_SENSOR, INPUT);
  pinMode(LED_PIN, OUTPUT);
  FastLED.addLeds< WS2812, LED_PIN, GRB>(leds, LED_COUNT);
  FastLED.setBrightness(100 * bright);
  FastLED.showColor(HUE_RED);
  // put your setup code here, to run once:
}

void loop() {
int pirVal = digitalRead(PIN_MOVE_SENSOR);
 
  for (int i = 0; i < LED_COUNT; i++) {
    leds[i].setHue(counter + i * 255 / LED_COUNT);
  }
  FastLED.show();
  counter++;        // counter меняется от 0 до 255 (тип данных byte)

  if (pirVal)
  {
    myTimer = millis();
    myTimer1 = millis();
    myTimer2 = millis();
    activeMode();
  }
  else if(millis() - myTimer >=10000){
    waitingMode();     // counter меняется от 0 до 255 (тип данных byte)
  }

  // put your main code here, to run repeatedly:
}

void activeMode(){
  FastLED.setBrightness(100 * bright);
  if(millis() - myTimer1 >= 500){
    for (int i = 0; i < LED_COUNT; i++) {
    leds[i].setHue(counter + i * 255 / LED_COUNT);
    }
  counter++;        // counter меняется от 0 до 255 (тип данных byte)
  FastLED.show();
  }
}

void waitingMode(){
  FastLED.setBrightness(30 * bright);
  if(millis() - myTimer2 >= 500){
    for (int i = 0; i < LED_COUNT; i++) {
    leds[i].setHue(counter + i * 255 / LED_COUNT);
    }
    FastLED.show();
    counter++;
  }
}