// =============================================================
// ir_ring.h – IR-Ring mit 16 Sensoren (findet den Ball)
// =============================================================
// Der Ball sendet Infrarot-Licht aus (gepulst, 40 kHz Träger).
// Die 16 Sensoren sitzen im Kreis um den Roboter. Der Sensor,
// der am meisten Licht sieht, zeigt ungefähr in Richtung Ball.
//
// Wichtig laut Regeln: Wir dürfen selbst KEIN IR-Licht aussenden.
// Die Sensoren empfangen nur.
// =============================================================
#pragma once

namespace IrRing {

// Anzahl der Sensoren im Ring.
constexpr int ANZAHL_SENSOREN = 16;

// Einmal in setup() aufrufen.
void starten();

// In jedem loop()-Durchlauf aufrufen: alle 16 Sensoren neu auslesen.
void lesen();

// true, wenn irgendein Sensor den Ball sieht.
bool ballGesehen();

// Richtung zum Ball in Grad (0 = vorne, 90 = rechts, ...).
float ballRichtungGrad();

// Wie stark das Signal ist. Größer = Ball ist näher (ungefähr).
int ballStaerke();

}  // namespace IrRing
