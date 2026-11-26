// =============================================================
// kompass.cpp – Kompass (Umsetzung)
// =============================================================
// STAND: Noch keine echte Logik, weil das Kompass-Modell noch
// nicht feststeht.
// =============================================================
#include "kompass.h"
#include <Arduino.h>
#include "pins.h"

namespace Kompass {

static float rohwert = 0.0f;    // Wert direkt vom Sensor (0..360 Grad)
static float nullpunkt = 0.0f;  // gespeicherter Nullpunkt

void starten() {
  // TODO: Verbindung zum Sensor aufbauen (wahrscheinlich I2C mit Wire.h).
  Serial.println("[Kompass] gestartet (noch ohne Funktion)");
}

void lesen() {
  // TODO: Neuen Wert vom Sensor lesen und in "rohwert" speichern.
}

float richtungGrad() {
  // Unterschied zum Nullpunkt ausrechnen ...
  float winkel = rohwert - nullpunkt;
  // ... und in den Bereich -180 bis +180 bringen.
  // Beispiel: 350 Grad ist das Gleiche wie -10 Grad.
  while (winkel > 180.0f)  winkel -= 360.0f;
  while (winkel < -180.0f) winkel += 360.0f;
  return winkel;
}

void nullpunktSetzen() {
  nullpunkt = rohwert;
}

}  // namespace Kompass
