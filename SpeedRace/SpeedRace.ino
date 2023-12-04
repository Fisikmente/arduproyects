
const int pinS1 = 4;
const int pinS2 = 6;
const int pinS3 = 8;
const int pinS4 = 10;

int Sensor_1 = 1;
int Sensor_2 = 1;
int Sensor_3 = 1;
int Sensor_4 = 1;
unsigned long Tiempo_1;
unsigned long Tiempo_2;
unsigned long Tiempo_3;
unsigned long Tiempo_4;

float t1;
float t2;
float t3;
float VT;

void setup() {
  Tiempo_1 = 0;
  Tiempo_2 = 0;
  Tiempo_3 = 0;
  Tiempo_4 = 0;
  // Velocidad = 0;
  pinMode(pinS1, INPUT);
  pinMode(pinS2, INPUT);
  pinMode(pinS3, INPUT);
  pinMode(pinS4, INPUT);
  Serial.begin(9600);
}

void loop() {
  Sensor_1 = digitalRead(pinS1);
  
  while (Sensor_1 = 0) {
    if (Sensor_1 == 0) {
      Tiempo_1 = millis() / 1000;
    }
    
    Sensor_2 = digitalRead(pinS2);

    if (Sensor_2 == 0) {
      Tiempo_2 = millis() / 1000;
    }
    
    Sensor_3 = digitalRead(pinS3);

    if (Sensor_3 == 0) {
      Tiempo_3 = millis() / 1000;
    }
    
    Sensor_4 = digitalRead(pinS4);

    if (Sensor_4 == 0) {
      Tiempo_4 = millis() / 1000;
    }
    
    VT = 0.4 / (Tiempo_4 - Tiempo_1);
    t1 = Tiempo_2 - Tiempo_1;
    t2 = Tiempo_3 - Tiempo_2;
    t3 = Tiempo_4 - Tiempo_3;

    Serial.print("Trayecto 1: ");
    Serial.print(t1);
    Serial.print(" - Trayecto 2: ");
    Serial.print(t2);
    Serial.print(" - Trayecto 3: ");
    Serial.print(t3);
    Serial.print(" - Vel: ");
    Serial.println(VT);
  }
  // Recalcula VT justo antes de usarlo


  // if (VT != 0) {
  //   Velocidad = 40 / VT;
  //   Serial.print(Tiempo_1 " - ");
  //   Serial.print(Tiempo_2 " - ");
  //   Serial.print(Tiempo_3 " - ");
  //   Serial.print(Tiempo_4 " - ");
  //   Serial.println(Velocidad);
  // }

  delay(15);
}
