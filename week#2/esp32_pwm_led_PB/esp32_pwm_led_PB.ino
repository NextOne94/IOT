#define led_builtin 2
#define led_red 13
#define led_green 12
#define led_yellow 14
#define pb 5
#define pot 15
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
int potValue;
void setup() {
  pinMode(led_builtin, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(pb, INPUT_PULLUP);
  //ledcSetup(ledChannel, freq, resolution);
  //ledcAttachPin(led_builtin, ledChannel);
  Serial.begin(9600);
  digitalWrite(led_builtin, LOW);
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, LOW);
  digitalWrite(led_yellow, LOW);
}

void loop() {
  potValue = analogRead(pot);
  //potValue = map(analogRead(pot), 0, 4095, 0, 255);
  Serial.println(potValue);
  //ledcWrite(ledChannel, potValue);


  if (analogRead(pot) >= 0 && analogRead(pot) < 1024) {
   // Serial.println("1");
    digitalWrite(led_builtin, HIGH);
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, LOW);
  } else if (analogRead(pot) >= 1024 && analogRead(pot) < 2048) {
    //Serial.println("2");
    digitalWrite(led_builtin, LOW);
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, LOW);
  } else if (analogRead(pot) >= 2048 && analogRead(pot) < 3072) {
    //Serial.println("3");
    digitalWrite(led_builtin, LOW);
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_yellow, LOW);
  } else if (analogRead(pot) >= 3072 && analogRead(pot) < 4096) {
    //Serial.println("4");
    digitalWrite(led_builtin, LOW);
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, HIGH);
  }
  delay(25);
}
