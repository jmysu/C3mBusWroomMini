/*
 * C3mBusMini Wokwi Buzzer+Servo
 */
#include <ESP32Servo.h>
Servo myservo;  // create servo object to control a servo

const int ledPin    = 0;
const int servoPin  = 1;
const int buzzerPin = 2;

int pos = 0;    // variable to store the servo position
int freq=440;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  //Attache pin1 to servo
  myservo.attach(servoPin, 500, 2400);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  for (pos = 0; pos <= 180; pos += 15) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
   
    tone(buzzerPin, freq, 50);
    freq+=200; if (freq > 880) freq=440;                // waits 15ms for the servo to reach the position
  }

  digitalWrite(ledPin, LOW);
  for (pos = 180; pos >= 0; pos -= 15) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
 
    tone(buzzerPin, freq, 50);
    freq+=200; if (freq > 880) freq=440;                       // waits 15ms for the servo to reach the position
  }
}
