#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  randomSeed(analogRead(0)); // Seed random function using an unconnected analog pin
}

void loop() {
  int x, y;

  for (int i = 0; i < 5; i++) {  // Fake fade-in effect at a random position
    x = random(0, SCREEN_WIDTH - 80);  // Adjust X to keep text inside the screen
    y = random(0, SCREEN_HEIGHT - 8);  // Adjust Y (text size 1 is around 8 pixels high)

    display.clearDisplay();
    display.setTextSize(1);  // Smallest text size to fit the full word
    display.setTextColor(WHITE);
    display.setCursor(x, y);
    display.print("25 FOLLOWERS");
    display.display();
    delay(200);
  }

  for (int i = 0; i < 5; i++) {  // Fake fade-out effect at the same position
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(x, y);
    display.print("25 FOLLOWERS");
    display.display();
    delay(200);
  }
}
