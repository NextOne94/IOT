#include <Ultrasonic.h>// include the library Ultrasonic by Erick Simões
#define ledPin 26 //set led Pin
#define pbPin 13 //set pb Pin
#define trigPin 18 //set trig Pin
#define echoPin 19 //set echo Pin

Ultrasonic ultrasonic(trigPin, echoPin); //Creates ultrasonic object
int distance; //Creates variable for distance
bool modeState = true;
// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
  Serial.begin(9600);// Serial Communication is starting with 9600 of baudrate speed
  pinMode(pbPin, INPUT_PULLUP);//Sets the pbPin as an INPUT
  pinMode(ledPin, OUTPUT);//Sets the ledPin as an OUTPUT
  ledcSetup(ledChannel, freq, resolution);// configure LED PWM functionalitites
  ledcAttachPin(ledPin, ledChannel); // attach the channel to the GPIO to be controlled
}

void loop() {
  if (!digitalRead(pbPin)) {//Check the signal of pushButton1
    modeState = !modeState; //Change to the opposite of the value
    Serial.println(modeState);
    while (!digitalRead(pbPin));//Check the signal of pushButton1
  }
  distance = ultrasonic.read();// Read distance from the ultrasonic sensor
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  if (modeState) {//Check modeState
    int dutyCycle = 0; //Creates variable for dutyCycle
    if (distance >= 3 && distance <= 10) { //Check distance between 3 and 10 cm
      dutyCycle = map(distance, 10, 3, 0, 255);
    }
    Serial.print("dutyCycle: ");
    Serial.println(dutyCycle);
    ledcWrite(ledChannel, dutyCycle);
  } else {
    int delayTime = 0;//Creates variable for delayTime
    if (distance >= 3 && distance <= 10) {//Check distance between 3 and 10 cm
      delayTime = map(distance, 3, 10, 10, 1000);
    }
    Serial.print("delayTime: ");
    Serial.println(delayTime);
    ledcWrite(ledChannel, 255);
    delay(delayTime );
    ledcWrite(ledChannel, 0);
    delay(delayTime );
  }
  delay(500);
}
