#include <Servo.h>  // include the library Servo by ServoESP32
#define servoPin 4  //set servo Pin
#define pushButton1 12 //set pushButton1 pin
#define pushButton2 13 //set pushButton2 pin

int Angles = 90; // Creates variable for the Angles
Servo servo1; // Creates servo object to control your servo

void setup() {
  Serial.begin(115200);// Serial Communication is starting with 115200 of baudrate speed
  pinMode(pushButton1, INPUT_PULLUP);//Sets the pushButton1 as an INPUT
  pinMode(pushButton2, INPUT_PULLUP);//Sets the pushButton2 as an INPUT
  servo1.attach(servoPin);// Attach servo object with servo Pin
  servo1.write(Angles); //servo move to Angles
}

void loop() {
  Serial.println(Angles);
  if (!digitalRead(pushButton1)) {//Check the signal of pushButton1
    Angles += 5; //Increase the Angles
    if (Angles <= 135) {//Check the Angles
      servo1.write(Angles);//servo move to Angles
    } else {
      Angles = 135; //Set the Angles
    }
    while (!digitalRead(pushButton1));//Check the signal of pushButton1
    delay(10);
  }
  if (!digitalRead(pushButton2)) {//Check the signal of pushButton2
    Angles -= 5; //Decrease the Angles
    if (Angles >= 45) {//Check the Angles
      servo1.write(Angles);//servo move to Angles
    } else {
      Angles = 45; //Set the Angles
    }
    while (!digitalRead(pushButton2));//Check the signal of pushButton2
    delay(10);
  }
}
