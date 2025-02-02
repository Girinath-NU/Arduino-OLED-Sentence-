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
  for (int size = 1; size <= 4; size++) {  // Increase text size
    display.clearDisplay();
    display.setTextSize(size);  // Zoom-in effect
    display.setTextColor(WHITE);
    
    // Center the text based on its size
    int x = SCREEN_WIDTH / 2 - (size * 6);  // Adjust X for centering
    int y = SCREEN_HEIGHT / 2 - (size * 4); // Adjust Y for centering
    
    display.setCursor(x, y);
    display.print("FOR");
    display.display();
    delay(200); // Adjust speed of zoom-in
  }
  
  delay(500); // Pause before restarting the effect
}
