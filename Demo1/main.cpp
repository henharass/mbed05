#include "mbed.h"

#include "TextLCD.h"

TextLCD lcd(D2, D3, D4, D5, D6, D7);


int main()

{

      int x=30;

      lcd.printf("107061234\n");

      while(true)

      {
          if(x != -1) {
            lcd.locate(5,1);

            lcd.printf("%5i",x);    //counter display

            ThisThread::sleep_for(1s);

            x--;
          }
          else {
            
            x = 30;
            lcd.locate(5,1);

            lcd.printf("%5i",x);    //counter display

            ThisThread::sleep_for(1s);
          }

      }
}