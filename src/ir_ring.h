// =============================================================
// ir_ring.h – IR-Ring mit 16 Sensoren (findet den Ball)
// =============================================================
// Der Ball sendet Infrarot-Licht aus (gepulst, 40 kHz Träger).
// Die 16 Sensoren sitzen im Kreis um den Roboter. Der Sensor,
// der am meisten Licht sieht, zeigt ungefähr in Richtung Ball.
//
// Unser IR-Ring (Schaltplan "IR-Ring V1.1") hat einen EIGENEN
// Mikrocontroller (STM32). Der liest die Sensoren aus und rechnet.
// Der Teensy fragt ihn nur nach dem Ergebnis. Verbunden sind beide
// über I2C: Stecker "I2C-Intercon" (J11 auf der Hauptplatine, J3 auf
// dem Ring). Das ist derselbe Bus wie beim Kompass, also "Wire1".
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
