// =============================================================
// ultraschall.h – 4 Ultraschallsensoren (Abstand zur Bande)
// =============================================================
// Ein Ultraschallsensor schickt einen kurzen Ton los und misst,
// wie lange das Echo braucht. Daraus folgt der Abstand.
// Mit vier Sensoren (vorne, rechts, hinten, links) wissen wir
// ungefähr, wo auf dem Feld der Roboter steht.
// =============================================================
#pragma once

namespace Ultraschall {

// "enum" gibt Zahlen einen Namen. Statt abstandCm(0) schreibt
// man abstandCm(VORNE) – das kann jeder lesen.
enum Seite { VORNE = 0, RECHTS = 1, HINTEN = 2, LINKS = 3 };
constexpr int ANZAHL_SENSOREN = 4;

// Einmal in setup() aufrufen.
void starten();

// Regelmäßig aufrufen: neue Messung(en) machen.
void lesen();

// Letzter gemessener Abstand in Zentimetern.
// Gibt -1 zurück, wenn es (noch) keinen gültigen Wert gibt.
float abstandCm(Seite seite);

}  // namespace Ultraschall
