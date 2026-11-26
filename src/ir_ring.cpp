// =============================================================
// ir_ring.cpp – IR-Ring (Umsetzung)
// =============================================================
// STAND: Noch keine echte Logik, weil noch offen ist, wie die
// 16 Sensoren an den Teensy angeschlossen sind.
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
  // TODO: Pins der Sensoren als Eingang einstellen.
  for (int i = 0; i < ANZAHL_SENSOREN; i++) {
    werte[i] = 0;
  }
  Serial.println("[IR-Ring] gestartet (noch ohne Funktion)");
}

void lesen() {
  // TODO: Jeden Sensor auslesen und in werte[i] speichern.
  // Danach aus allen Werten die Ballrichtung und -stärke berechnen
  // und in "gesehen", "richtung" und "staerke" speichern.
}

bool ballGesehen()      { return gesehen; }
float ballRichtungGrad() { return richtung; }
int ballStaerke()       { return staerke; }

}  // namespace IrRing
