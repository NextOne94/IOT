
void setup() {
  for(int i = 12;i<15;i++){
    pinMode(i,OUTPUT);
    }

}

void loop() {
   for(int i = 12;i<15;i++){
    digitalWrite(i,HIGH);
    delay(250);
    digitalWrite(i,LOW);
    delay(250);
    }

}
