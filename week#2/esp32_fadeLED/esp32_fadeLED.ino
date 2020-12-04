
#define led_builtin 2
#define led_red 13
#define led_green 12
#define led_yellow 14

const int freq1 = 100;
const int freq2 = 50;
const int freq3 = 10;
const int ledChannel1 = 0;
const int ledChannel2 = 1;
const int ledChannel3 = 2;
const int resolution = 8;

void setup() {
  ledcSetup(ledChannel1, freq1, resolution);
  ledcSetup(ledChannel2, freq2, resolution);
  ledcSetup(ledChannel3, freq3, resolution);
  ledcAttachPin(led_builtin, ledChannel1);
  ledcAttachPin(led_red, ledChannel2);
  ledcAttachPin(led_green, ledChannel3);
  ledcAttachPin(led_yellow, ledChannel3);

}

void loop() {
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++ ) {
    ledcWrite(ledChannel1, dutyCycle);
    ledcWrite(ledChannel2, dutyCycle);
    ledcWrite(ledChannel3, dutyCycle);
    delay(15);
  }


  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(ledChannel1, dutyCycle);
    ledcWrite(ledChannel2, dutyCycle);
    ledcWrite(ledChannel3, dutyCycle);
    delay(15);
  }
}
