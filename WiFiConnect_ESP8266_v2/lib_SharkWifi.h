#include <WiFiManager.h>
#include <strings_en.h>
#include <wm_consts_en.h>
#include <wm_strings_en.h>
#include <wm_strings_es.h>

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

#include <Ticker.h>
#define pinLedWifi D4

Ticker ticker;  //Crea instancia Ticker

void blinkLedWifi() {
  byte state = digitalRead(pinLedWifi);
  digitalWrite(pinLedWifi, !state);  //Cambia el estado del LED WiFi
}

void connectWifi_SHARK() {
  Serial.begin(115200);

  pinMode(pinLedWifi, OUTPUT);

  ticker.attach(0.2, blinkLedWifi);  //Empieza el temporizador que hara parpader al LED Wifi

  WiFiManager wifiManager;  //Crea instanaia de la clase WiFiManager

  //wifiManager.resetSettings();  //Limpiar la EEPROM de la tarjeta

  if (!wifiManager.autoConnect("SHARK_ESP8266", "SHARK8266")) {  //Crea AP y portal esclavo si no se puede conectar a una Wifi anterior
    Serial.println("Error of connection :( (timeout)");
    ESP.reset();
    delay(1000);
  }

  Serial.println("You are connected");

  ticker.detach();

  digitalWrite(pinLedWifi, HIGH);
}