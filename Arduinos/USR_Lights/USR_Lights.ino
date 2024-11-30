#include "Ultrasonic.h"

int s;

int i;

Ultrasonic ultrasonic(10);

void setup() {

  // put your setup code here, to run once:

  Serial.begin(9600);

for (i = 2; i <=9; i++) {

    pinMode(i, OUTPUT);

  }

}



void loop() {

  // put your main code here, to run repeatedly:



  for (i = 3; i <= 9; i++ ) {

      long RangeInCentimeters;

        RangeInCentimeters = ultrasonic.MeasureInCentimeters();

      s = RangeInCentimeters * 10 ;

      digitalWrite(i, HIGH);

      delay(s);

      digitalWrite(i, LOW);

      Serial.println(s);

  }

  for (i = 8; i >= 2; i--) {

      long RangeInCentimeters;

        RangeInCentimeters = ultrasonic.MeasureInCentimeters();

      s = RangeInCentimeters * 10 ;

      digitalWrite(i, HIGH);

      delay(s);

      digitalWrite(i, LOW);

      Serial.println(s);

  }

   

}
