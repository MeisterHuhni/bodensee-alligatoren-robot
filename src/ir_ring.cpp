// =============================================================
// ir_ring.cpp – IR-Ring (Umsetzung)
// =============================================================
// STAND: Noch keine echte Logik. Der Anschluss ist klar (I2C über
// Wire1), aber die I2C-Adresse und was der Ring zurückschickt, legt
// erst das Programm auf dem STM32 fest.
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
  // TODO: Prüfen, ob der Ring auf Wire1 antwortet (Adresse kommt
  // vom STM32-Programm; frei sind z.B. nicht 0x20, 0x28, 0x40, 0x41).
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
