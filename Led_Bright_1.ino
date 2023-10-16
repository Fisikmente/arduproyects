int ledPin = 6;
int buttonMas = A0;
int buttonMenos = A1;
int ledBright = 0;
int jump = 50;
int stateMas;
int stateMenos;
int dt1 = 100;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonMas, INPUT);
  pinMode(buttonMenos, INPUT);
}

void loop() {
  stateMas = digitalRead(buttonMas);
  delay(dt1);
  stateMenos = digitalRead(buttonMenos);
  delay(dt1);

  if (stateMas == 0 && ledBright < 250) {
    ledBright = ledBright + jump;
  }

  if (stateMenos == 0 && ledBright > 0) {
    ledBright = ledBright - jump;
  }

  if (ledBright < 0) {
    ledBright = 0;
  }

  if (ledBright > 250) {
    ledBright = 250;
  }

  analogWrite(ledPin, ledBright);

  Serial.print("Brightness: ");
  Serial.print(ledBright);
  Serial.print(" - More: ");
  Serial.print(stateMas);
  Serial.print(" Minus: ");
  Serial.println(stateMenos);

  //buttonOld = buttonNew;
}