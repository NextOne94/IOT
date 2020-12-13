#include <Servo.h>  // include the library Servo by ServoESP32
#define servoPin 4  //set servo Pin 
#define pushButton1 12 //set pushButton1 pin
#define pushButton2 13 //set pushButton2 pin

int count = 0; // Creates variable for the Cycle count
Servo servo1; // Creates servo object to control your servo

void setup() {
  Serial.begin(115200);// Serial Communication is starting with 115200 of baudrate speed
  pinMode(pushButton1, INPUT_PULLUP);  //Sets the pushButton1 as an INPUT
  pinMode(pushButton2, INPUT_PULLUP);  //Sets the pushButton2 as an INPUT
  servo1.attach(servoPin); // Attach servo object with servo Pin
}

void loop() {
  if (!digitalRead(pushButton1)) { //Check the signal of pushButton1
    count += 1; // Increase the value of count
    Serial.println(count);
    while (!digitalRead(pushButton1)); //Check the signal of pushButton1
    delay(10);
  }

  if (!digitalRead(pushButton2)) { //Check the signal of pushButton2
    for (int i = 0; i < count; i++) { // Loop by value of count
      for (int posDegrees = 0; posDegrees <= 180; posDegrees++) {//servo moves from 0 - 180 degree
        servo1.write(posDegrees);//servo move to posDegrees
        delay(10);
      }

      for (int posDegrees = 180; posDegrees >= 0; posDegrees--) {//servo moves from 180 - 0 degree
        servo1.write(posDegrees);//servo move to posDegrees
        delay(10);
      }
    }
    count = 0; // reset variable
  }

}
