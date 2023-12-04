int ledPin = 7;
int buttonMas = A0;
int buttonMenos = A1;
int ledBright = 0;
int stateMas;
int stateMenos;
int dt1 = 100;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  stateMas = digitalRead(buttonMas);
  stateMenos digitalRead(buttonMenos);
  delay(dt1);
  if (stateMas == 0 && ledBright < 255) {
    if (ledState == 0) {
      digitalWrite(ledPin, 1);
      ledState = 1;
    } else {
      digitalWrite(ledPin, 0);
      ledState = 0;
    }
  }
  Serial.print(buttonNew);
  Serial.print(" - ");
  Serial.println(ledState);
  buttonOld = buttonNew;
}