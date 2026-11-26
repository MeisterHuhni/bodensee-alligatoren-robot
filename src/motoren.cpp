// =============================================================
// motoren.cpp – Antrieb des Roboters (Umsetzung)
// =============================================================
// STAND: Noch keine echte Logik, weil Motormodell, Motortreiber,
// Anzahl der Motoren und Pins noch nicht feststehen.
// =============================================================
#include "motoren.h"
#include <Arduino.h>
#include "pins.h"

namespace Motoren {

void starten() {
  // TODO: pinMode(...) für alle Motor-Pins, sobald sie in pins.h stehen.
  Serial.println("[Motoren] gestartet (noch ohne Funktion)");
}

void fahren(float richtungGrad, float tempo, float drehung) {
  // TODO: Aus Richtung, Tempo und Drehung die Geschwindigkeit für
  // jeden einzelnen Motor ausrechnen und per analogWrite() ausgeben.
  // Wie das genau geht, hängt davon ab, wie die Räder angeordnet sind.

  // Diese drei Zeilen tun nichts. Sie verhindern nur die Warnung
  // "Variable wird nicht benutzt", solange die Funktion leer ist.
  (void)richtungGrad;
  (void)tempo;
  (void)drehung;
}

void stopp() {
  // TODO: Alle Motoren auf Tempo 0 setzen.
}

}  // namespace Motoren
