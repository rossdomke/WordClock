#include "DS3231.h";
#include "FastLED.h";
// // #include "AceButton.h";

// // using namespace ace_button;



/* ############### Button Definition ############### */
const int BUTTON_PIN = 5;
// AceButton button(BUTTON_PIN);
// void handleButtonPress(AceButton*, uint8_t, uint8_t);
/* ############### END Button Definition ############### */

/* ############### LED Definition ############### */
#define NUM_LEDS 1
#define LED_DATA_PIN 15
CRGB leds[NUM_LEDS];
/* ############### END LED Definition ############### */



/* ############### RTC Definition ############### */
DS3231 myRTC;
bool century = false;
bool h12Flag;
bool pmFlag;
/* ############### END RTC Definition ############### */

void setup() {

  // delay(2000);
  // Button Setup
  pinMode(BUTTON_PIN, INPUT);

  // Start the serial port
  Serial.begin(115200);

  // // Start the I2C interface
  Wire.begin();
  FastLED.addLeds<NEOPIXEL, LED_DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(50);

  // Serial.println("I'm Alive");

  // leds[0] = CRGB::Green;
}
int buttonState = 0;
uint8_t h = 0;
void loop() {
  // h += 1;
  // leds[0] = CHSV(h, 255, 50);
  // Serial.println("loooop");
  // // button.check();
  // FastLED.show();
  // delay(5);

  buttonState = digitalRead(BUTTON_PIN);


   if (buttonState == HIGH) {
    h = random(0, 255);
    leds[0] = CHSV(h, 255, 100);
    FastLED.show();
    Serial.print(myRTC.getYear());
    Serial.print("-");
    Serial.print(myRTC.getMonth(century));
    Serial.print("-");
    Serial.print(myRTC.getDate());
    Serial.print(" ");
    Serial.print(myRTC.getHour(h12Flag, pmFlag));  //24-hr
    Serial.print(":");
    Serial.print(myRTC.getMinute());
    Serial.print(":");
    Serial.println(myRTC.getSecond());
    delay(500);
  }
}

// void handleButtonPress(AceButton* btn, uint8_t eventType, uint8_t buttonState) {
//   Serial.println("button handler");
//   switch (eventType) {
//     case AceButton::kEventPressed:
//       leds[0] = CRGB::Red;
//       break;
//     case AceButton::kEventReleased:
//       leds[0] = CRGB::Blue;
//       break;
//   }
// }