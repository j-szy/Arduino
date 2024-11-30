#include <Ultrasonic.h>

#include <SPI.h>

#include <Adafruit_GFX.h>

#include <Adafruit_PCD8544.h>

//#include <Wire.h>



#define RANGERPIN 11

Ultrasonic ultrasonic(11);



Adafruit_PCD8544 display = Adafruit_PCD8544(13,12,11,10,9);





void setup()

{  

  Serial.begin(115200);

  display.begin();

  display.clearDisplay();

  display.setContrast(50);

  display.setTextSize(1);

  display.setTextColor(BLACK);

 

}



void loop()

{

  long RangeInCentimeters;

   RangeInCentimeters = ultrasonic.MeasureInCentimeters();

  display.println("Distance in centimeters:");

  display.print(RangeInCentimeters);

  display.println("cm");

  delay(2000);





}
