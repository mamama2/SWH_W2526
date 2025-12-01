 
/*
   SKETCHING MIT HARDWARE
     DMP - WS2526
   DEMO 3: LCD Display 16x2 ohne I2c controller
  This project demonstrates the usage of the
  LCD Display
  WIEKER-WALZ / MARTINEZ
*/

#include <LiquidCrystal.h> // include the library code: !
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
lcd.begin(16, 2); // set up the LCD's number of columns and rows: lcd.print("hello, world!”); // Print a message to the LCD.
}

void loop() {
  lcd.setCursor(0, 0);
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0): lcd.setCursor(0, 1);
lcd.print(millis()/1000); // print the number of seconds since reset:
lcd.setCursor(0,1);
lcd.print("DMP");
}
