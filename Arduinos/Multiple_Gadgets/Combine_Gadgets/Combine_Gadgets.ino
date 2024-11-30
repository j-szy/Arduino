#include <SPI.h>

#include <Adafruit_GFX.h>

#include <Adafruit_PCD8544.h>

#include <Wire.h>





int menuitem = 1;

int page = 1;

int checkLights = digitalRead(7);





Adafruit_PCD8544 display = Adafruit_PCD8544(7,6,5,4,3);



void setup()   {

  Serial.begin(115200);



  display.begin();

  display.setContrast(50);

  display.clearDisplay();

  display.setTextSize(1);

  display.setTextColor(BLACK);

  display.setCursor(10,10);

  delay(5000);

  display.display();

}



void drawMenu()

  {

      

  if (page==1) 

  {    

    display.setTextSize(1);

    display.clearDisplay();

    display.setTextColor(BLACK, WHITE);

    display.setCursor(15, 0);

    display.print("MAIN MENU");

    display.drawFastHLine(0,10,83,BLACK);

    display.setCursor(0, 15);

   

    if (menuitem==1) 

    { display.setTextColor(WHITE, BLACK);}

    else 

    {display.setTextColor(BLACK, WHITE);}

    display.print(">Show Message");

    display.setCursor(0, 25);

   

    if (menuitem==2) 

    {display.setTextColor(WHITE, BLACK);}

    else 

    {display.setTextColor(BLACK, WHITE);}    

    display.print(">Show Distance");

    

    if (menuitem==3) 

    { 

      display.setTextColor(WHITE, BLACK);

    }

    else 

    {display.setTextColor(BLACK, WHITE);}  

    display.setCursor(0, 35);

    display.print(">Control Lights");

    display.display();

  }

}



void loop(){

drawMenu();



 //X Axis

  int xAxis = analogRead(A0);



  //Y Axis

  int yAxis = analogRead(A1);



if (page != 1 && xAxis < 270) {

  page = 1;

}



if (menuitem == 1 && xAxis > 730 )

{page = 2;}



if (menuitem == 2 && xAxis > 730 )

{page = 3;}



if (menuitem == 3 && xAxis > 730 )

{page = 4;}



if (menuitem == 1 && yAxis < 260) 

{menuitem = 2;}



else if (menuitem == 2 && yAxis < 260) 

{menuitem = 3;}



else if (menuitem == 3 && yAxis > 750) 

{menuitem = 2;}



else if (menuitem == 2 && yAxis > 750) 

{menuitem = 1;}



delay(200);

}
