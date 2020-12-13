#include "DHT.h" // include the library
#define DHTPIN 2 //set DHT Pin
#define DHTTYPE DHT11   // set DHT Type
#define LED1 26 //set LED1 Pin
#define LED2 25 //set LED2 Pin
DHT dht(DHTPIN, DHTTYPE); //Creates dht object 

void setup() {
  Serial.begin(9600);// Serial Communication is starting with 9600 of baudrate speed
  pinMode(LED1, OUTPUT);//Sets the LED1 as an OUTPUT
  pinMode(LED2, OUTPUT);//Sets the LED2 as an OUTPUT
  dht.begin(); // Start dht to measurements
}

void loop() {
  delay(2000);// Wait a few seconds between measurements.
  float humi = dht.readHumidity();// Read humidity 
  float temp = dht.readTemperature();// Read temperature as Celsius 

  if (isnan(humi) || isnan(temp)) {// Check if any reads failed and exit early (to try again).
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Humidity: "));
  Serial.print(humi);
  Serial.print(F("%  Temperature: "));
  Serial.print(temp);
  Serial.println(F("°C  "));
  if (temp > 30 && humi > 80) {//Check the Temperature and Humidity
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
  } else if (temp > 25 && humi > 50) {//Check the Temperature and Humidity
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  }

}
