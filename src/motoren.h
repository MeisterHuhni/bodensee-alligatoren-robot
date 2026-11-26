// =============================================================
// motoren.h – Antrieb des Roboters
// =============================================================
// Eine .h-Datei ("Header") ist wie ein Inhaltsverzeichnis:
// Sie sagt, WELCHE Funktionen es gibt. WIE sie funktionieren,
// steht in der passenden .cpp-Datei (motoren.cpp).
//
// "namespace Motoren" packt alle Funktionen in eine Gruppe.
// Man ruft sie dann so auf: Motoren::starten();
// So sieht man im Code sofort, zu welchem Teil eine Funktion gehört.
// =============================================================
#pragma once

namespace Motoren {

// Anzahl der Motor-Anschlüsse auf der Platine (MOT1 bis MOT4).
constexpr int ANZAHL_ANSCHLUESSE = 4;

// Einmal in setup() aufrufen: Pins vorbereiten, alles steht still.
void starten();

// EINEN Motor ansteuern (gut zum Testen, ob alles richtig verkabelt ist).
//   nummer: 1 bis 4 (wie auf der Platine: MOT1 ... MOT4)
//   tempo:  -1.0 (volle Kraft rückwärts) bis +1.0 (volle Kraft vorwärts),
//           0.0 = bremsen
void motorSetzen(int nummer, float tempo);

// Roboter fahren lassen.
//   richtungGrad: wohin fahren (0 = nach vorne, 90 = nach rechts, ...)
//   tempo:        wie schnell, von 0.0 (steht) bis 1.0 (Vollgas)
//   drehung:      wie stark drehen, von -1.0 (links) bis +1.0 (rechts)
void fahren(float richtungGrad, float tempo, float drehung);

// Alle Motoren sofort bremsen.
void stopp();

}  // namespace Motoren
