#define led 2
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  for (int i = 0 ; i < 5; i++) {
    digitalWrite(led,HIGH);
    delay(250);
    digitalWrite(led,LOW);
    delay(250);
  }
  delay(750);
}
