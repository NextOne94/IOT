#define LED1 12
#define LED2 13
#define LED3 14
#define button 4
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(button, INPUT_PULLUP);

}

void loop() {
  while (digitalRead(button)) {
    digitalWrite(LED1, HIGH);
    delay(250);
    digitalWrite(LED1, LOW);
    delay(250);
    digitalWrite(LED2, HIGH);
    delay(250);
    digitalWrite(LED2, LOW);
    delay(250);
    digitalWrite(LED3, HIGH);
    delay(250);
    digitalWrite(LED3, LOW);
    delay(250);
  }
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}
