#include "lib_SharkWifi.h"

WiFiServer server(80);
const int Pin1 = 12;  // LED 1
const int Pin2 = 13;  // LED 2
const int Pin3 = 15;  // LED 3

String header;
unsigned long lastTime, timeout = 1000;

void setup() {
  connectWifi_SHARK();
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);

  Serial.println("");
  Serial.println("♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪");
  Serial.println("Device connected :D");
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
  Serial.print("Direccion IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪");

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    lastTime = millis();

    Serial.println("Nuevo cliente");
    String currentLine = "";

    while (client.connected() && millis() - lastTime <= timeout) {

      if (client.available()) {

        char c = client.read();
        Serial.write(c);
        header += c;

        if (c == '\n') {

          if (currentLine.length() == 0) {

            ////////// ENCABEZADO HTTP ////////////

            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();


            if (header.indexOf("GET /on1") >= 0) {
              Serial.println("GPIO 12 encendido");
              // outputState1 = "encendido";
              digitalWrite(Pin1, HIGH);
            } else if (header.indexOf("GET /off1") >= 0) {
              Serial.println("GPIO 12 apagado");
              // outputState1 = "apagado";
              digitalWrite(Pin1, LOW);
            }
            if (header.indexOf("GET /on2") >= 0) {
              Serial.println("GPIO 13 encendido");
              // outputState2 = "encendido";
              digitalWrite(Pin2, HIGH);
            } else if (header.indexOf("GET /off2") >= 0) {
              Serial.println("GPIO 13 apagado");
              // outputState2 = "apagado";
              digitalWrite(Pin2, LOW);
            }
            if (header.indexOf("GET /on3") >= 0) {
              Serial.println("GPIO 15 encendido");
              // outputState3 = "encendido";
              digitalWrite(Pin3, HIGH);
            } else if (header.indexOf("GET /off3") >= 0) {
              Serial.println("GPIO 15 apagado");
              // outputState3 = "apagado";
              digitalWrite(Pin3, LOW);
            }
            if (header.indexOf("GET /onall") >= 0) {
              Serial.println("GPIO 12, 13 y 15 encendidos");
              // outputState1 = "encendido";
              // outputState2 = "encendido";
              // outputState3 = "encendido";
              digitalWrite(Pin1, HIGH);
              digitalWrite(Pin2, HIGH);
              digitalWrite(Pin3, HIGH);
            } else if (header.indexOf("GET /offall") >= 0) {
              Serial.println("GPIO 12, 13 y 15 apagados");
              // outputState1 = "apagado";
              // outputState2 = "apagado";
              // outputState3 = "apagado";
              digitalWrite(Pin1, LOW);
              digitalWrite(Pin2, LOW);
              digitalWrite(Pin3, LOW);
            }
            //////// PAGINA WEB //////////////

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("</head>");

            client.println("<body></body>");

            client.println("</html>");

            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }

    header = "";
    client.stop();
    Serial.println("Cliente desconectado.");
    Serial.println("");
  }
}
