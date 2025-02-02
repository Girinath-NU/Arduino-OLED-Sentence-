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
}

void loop() {
  String text = "500 FOLLOWERS"; // The text to animate
  int baseY = 25;  // Base Y position where the text stays centered
  int amplitude = 6; // Height of the wave motion
  int speed = 100;   // Speed of wave effect
  
  for (int t = 0; t < 360; t += 10) { // Loop through wave motion
    display.clearDisplay();
    display.setTextSize(1); 
    display.setTextColor(WHITE);
    
    int x = 10;  // Start position for the text
    
    for (int i = 0; i < text.length(); i++) {
      int yOffset = amplitude * sin((t + (i * 20)) * PI / 180); // Wave movement
      display.setCursor(x, baseY + yOffset);
      display.print(text[i]); // Print each letter with wave effect
      x += 8; // Move cursor to the right for next character
    }
    
    display.display();
    delay(speed); // Adjust speed of wave effect
  }
}
