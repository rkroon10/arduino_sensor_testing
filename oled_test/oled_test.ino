
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 

#define OLED_RESET     LED_BUILTIN // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  //display.display();
  //delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("begin_boot_sequence");
  display.display();
  delay(3000);
  display.println("boot_successful");
  display.display();
  delay(1000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...



  // Invert and restore display, pausing in-between
  /*display.invertDisplay(true);
  delay(1000);
  display.invertDisplay(false);
  delay(1000);
  display.clearDisplay();
 */
}







void loop() {
  testscrolltext();    // Draw scrolling text


}





void testscrolltext(void) {
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("Andriy is a Bitch"));
  display.display();      // Show initial text
  delay(100);

  // Scroll right
  display.startscrollright(0x00, 0x0F);
  delay(5000);
  //display.stopscroll();
  //delay(1000);

}
