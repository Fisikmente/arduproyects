#include <Servo.h>

Servo myservo;  // crea el objeto servo
int pos;    // posicion del servo
int dtServo = 15;

const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
int ledPin = 4;

int dtRead = 500;

void setup() {
  
  myservo.attach(8);  // vincula el servo al pin digital 9

  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  digitalWrite(ledPin, LOW);
}

void loop()
{

  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm

  if (d < 10) {
    digitalWrite(ledPin, HIGH);
    delay(dtRead); 
    pos = 90;
    myservo.write(pos);
    // delay(dtServo);

  } else {
    digitalWrite(ledPin, LOW);
    pos = 0;
    myservo.write(pos);
  }

  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  // delay(dtRead);          //Hacemos una pausa de 100ms
}
