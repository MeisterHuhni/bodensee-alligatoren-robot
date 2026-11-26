// =============================================================
// ir_ring.cpp – IR-Ring (Umsetzung)
// =============================================================
// STAND: Noch keine echte Logik, weil noch offen ist, über welchen
// Anschluss (UART, SPI oder I2C) der Ring mit dem Teensy redet und
// was das Programm auf dem STM32 des Rings zurückschickt.
// =============================================================
#include "ir_ring.h"
#include <Arduino.h>
#include "pins.h"

namespace IrRing {

// "static" heißt hier: Diese Variablen sieht nur diese Datei.
// Andere Dateien kommen nur über die Funktionen oben an die Werte.
static int werte[ANZAHL_SENSOREN];   // ein Messwert pro Sensor
static bool gesehen = false;
static float richtung = 0.0f;
static int staerke = 0;

void starten() {
  // TODO: Verbindung zum IR-Ring starten (z.B. Serial6.begin(...)).
  for (int i = 0; i < ANZAHL_SENSOREN; i++) {
    werte[i] = 0;
  }
  Serial.println("[IR-Ring] gestartet (noch ohne Funktion)");
}

void lesen() {
  // TODO: Neue Daten vom IR-Ring abholen und in werte[i] speichern.
  // Danach (oder schon auf dem Ring) Ballrichtung und -stärke
  // berechnen und in "gesehen", "richtung" und "staerke" speichern.
}

bool ballGesehen()      { return gesehen; }
float ballRichtungGrad() { return richtung; }
int ballStaerke()       { return staerke; }

}  // namespace IrRing
