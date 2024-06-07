#include <ezButton.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//  button objects
ezButton button1(13);
ezButton button2(33);
ezButton button3(14);
ezButton button4(27);
ezButton button5(26);

int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0;

int flag = 0;

void setup()
{
  Serial.begin(9600);

  button1.setDebounceTime(25);
  button2.setDebounceTime(25);
  button3.setDebounceTime(25);
  button4.setDebounceTime(25);
  button5.setDebounceTime(25);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  };

  delay(2000);         // wait two seconds for initializing
  oled.clearDisplay(); // clear display
  oled.setTextSize(2);         // set text size
  oled.setTextColor(WHITE);    // set text color

  oled.setCursor(2, 5); 
  oled.println("Start");       // set position to display
  oled.setCursor(2, 21); 
  oled.println("voting..");   
  oled.display();             // display on OLED
  delay(2000);
}

void loop() {

  button1.loop();
  button2.loop();
  button3.loop();
  button4.loop();
  button5.loop();

  if (flag == 0) {
   // set text
    oled.clearDisplay(); // clear display
    oled.setTextSize(2);         // set text size
    oled.setTextColor(WHITE);    // set text color

    oled.setCursor(2, 0);       // set position to display
    oled.println("A - Green ");
    oled.setCursor(2, 16);       // set position to display
    oled.println("B - Yellow");
    oled.setCursor(2, 32);       // set position to display
    oled.println("C - Red");     // display on OLED
    oled.setCursor(2, 48);       // set position to display
    oled.println("D - Orange");
    oled.display();
    flag=1;
    
  }

  delay(10);
}
