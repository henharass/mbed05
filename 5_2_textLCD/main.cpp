//Display ADC input data

#include "mbed.h"

#include "TextLCD.h"


TextLCD lcd(D2, D3, D4, D5, D6, D7);

AnalogIn Ain(A0);


int main()

{

      float percentage;

      int D;

      while (1)

      {

            percentage = Ain * 100;

            D = int(percentage);

            float B = percentage - D;

            int C = B * 1000000;


            lcd.printf("%d.", D);

            lcd.printf("%d", C);

            ThisThread::sleep_for(250ms);

            lcd.cls();

      }

        }

    Compile and run

    $ sudo mbed compile --source . --source ~/ee2405/mbed-os-build/ -m B_L4S5I_IOT01A -t GCC_ARM -f

    Push the code to your git remote repository, and check your remote repository for new files.

3.3   Color LCD display - uLCD-144G2-AR

(From 4D Systems): The uLCD-144G2 display module is compact and cost effective and features a 1.44” LCD TFT screen. Driven by the GOLDELOX processor, the uLCD-144G2 is the compact display solution for any application requiring a small embedded screen.

    128xRGBx128 resolution, 65K true to life colours, LCD-TFT screen.
    1.44" diagonal size, 43 x 31 x 6.4mm. Active Area: 25.5mm x 26.5mm.
    Easy 10 pin interface to any external device: 3.3Vout, IO2, GND, IO1, RESET, GND, RX, TX, +5V, 5V OUT.
    10K bytes of flash memory for user code storage and 510 bytes of RAM for user variables (255 x 16bit vars).
    1 x Asynchronous hardware serial port, TTL interface, with 300 baud to 600K baud.
    On-board micro-SD memory card adaptor for storing of icons, images, animations, etc.

    Connect your LCD to mbed as the following picture .

    Please be careful about pin connections. Double check before you turn on the power.
    LCD 	mbed
    +5V 	5V
    TX 	D1
    RX 	D0
    GND 	GND
    RES 	D2

    Go to the link and read the web page carefully.

    Switch to a terminal or start a new terminal with Ctrl+Alt+T.

    Create a new Mbed project.

    $ cd ~/ee2405/mbed05

    $ mbed new 5_3_uLCD --scm none

    $ cd 5_3_uLCD

    Add "4DGL-uLCD-SE" library to the current project Note that original "4DGL-uLCD-SE" is built before Mbed OS. The following is a version modified by our EE2405 TA.

    $ git clone https://gitlab.larc-nthu.net/ee2405_2021/4dgl-ulcd-se.git

    $ rm -rf ./4dgl-ulcd-se/.git

    Start VS code to edit main.cpp.

    $ code main.cpp

    Copy the following codes into main.cpp.

#include "mbed.h"

#include "uLCD_4DGL.h"


uLCD_4DGL uLCD(D1, D0, D2);


int main()

{

      uLCD.printf("\nHello uLCD World\n"); //Default Green on black text

      ThisThread::sleep_for(30s);

    }

    Compile and run

    $ sudo mbed compile --source . --source ~/ee2405/mbed-os-build/ -m B_L4S5I_IOT01A -t GCC_ARM -f

    Push the code to your git remote repository, and check your remote repository for new files.

    uLCD functions

    There are five types of commands set up by the library for easier control. Here we introduce some of them for your reference.

    Please dive into uLCD_4DGL.h for more information of the programming interface (API).

        General functions

            uLCD.cls() clears the entire screen using the background color.

            uLCD.reset() wipes the entire screen.

            uLCD.background_color(int color) changes the background color.

            Ex. uLCD.background_color(0xFFFFFF) // white

        Graphic functions

        These functions draws simple shapes.
            uLCD.circle(int x , int y , int radius, int color)
            uLCD.triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color)
            uLCD.line(int x1, int y1 , int x2, int y2, int color)

        Text functions

            uLCD.set_font(char mode). ex. uLCD.set_font(FONT_7X8)

            This function set the size of the font(width=7, height=8).

            uLCD.locate(char col, char row). ex. uLCD.locate(0, 0)

            This function sets the location of the cursor. Then we can put our text anywhere we want to.

        Media

        This type of command is for displaying video or image from SD card. If you are interested in doing so, please go to the link and scroll to the buttom part for complete tutorial.

        Screen data

        We can get LCD hardware information via this type of command.

        Ex. int a=uLCD.type;

        Text data

        We can get text information via this type of command.

        Ex. Get cursor location: char column=uLCD.current_col;

A uLCD144G2 demo program

    Switch to a terminal or start a new terminal with Ctrl+Alt+T.

    Create a new Mbed project.

    $ cd ~/ee2405/mbed05

    $ mbed new 5_4_uLCD_demo --scm none

    $ cd 5_4_uLCD_demo

    Add "4DGL-uLCD-SE" library to the current project

    $ git clone https://gitlab.larc-nthu.net/ee2405_2021/4dgl-ulcd-se.git

    $ rm -rf ./4dgl-ulcd-se/.git

    Start VS code to edit main.cpp.

    $ code main.cpp

    Copy the following codes into main.cpp.

// uLCD-144-G2 basic text demo program for uLCD-4GL LCD driver library

//

#include "mbed.h"

#include "uLCD_4DGL.h"


uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;


int main()

{

    // basic printf demo = 16 by 18 characters on screen

    uLCD.printf("\nHello uLCD World\n"); //Default Green on black text

    uLCD.printf("\n  Starting Demo...");

    uLCD.text_width(4); //4X size text

    uLCD.text_height(4);

    uLCD.color(RED);

    for (int i=10; i>=0; --i) {

        uLCD.locate(1,2);

        uLCD.printf("%2d",i);

        ThisThread::sleep_for(500ms);

    }
