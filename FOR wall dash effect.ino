#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define OLED display size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Halt
  }
  display.clearDisplay();
}

void loop() 
{
  int direction = 1; // 1 = right, -1 = left
  int x = 0;

  while (true) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(x, 25);
    display.print("JUST");
    display.display();
    
    x += direction; // Move left or right
    if (x >= SCREEN_WIDTH - 40 || x <= 0) direction *= -1; // Reverse direction
    
    delay(30);
  }
}


