// =============================================================
// ultraschall.cpp – Ultraschall (Umsetzung)
// =============================================================
// STAND: Noch keine echte Logik, weil Sensormodell und Pins
// noch nicht feststehen.
// =============================================================
#include "ultraschall.h"
#include <Arduino.h>
#include "pins.h"

namespace Ultraschall {

static float abstaende[ANZAHL_SENSOREN];   // ein Abstand pro Sensor

void starten() {
  // TODO: Trigger-Pins als Ausgang, Echo-Pins als Eingang einstellen.
  for (int i = 0; i < ANZAHL_SENSOREN; i++) {
    abstaende[i] = -1.0f;   // -1 = noch kein gültiger Wert
  }
  Serial.println("[Ultraschall] gestartet (noch ohne Funktion)");
}

void lesen() {
  // TODO: Sensoren nacheinander messen (nicht gleichzeitig,
  // sonst hört ein Sensor das Echo eines anderen).
}

float abstandCm(Seite seite) {
  return abstaende[seite];
}

}  // namespace Ultraschall
