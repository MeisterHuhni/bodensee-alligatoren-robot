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

// Roboter fahren lassen. Unser Roboter hat 2 Räder (links und rechts),
// wie ein Panzer: Er kann nur vor/zurück fahren und sich drehen, aber
// nicht seitwärts. Man nennt das "Differentialantrieb".
//   tempo:   -1.0 (rückwärts) bis +1.0 (vorwärts), 0.0 = nicht vor/zurück
//   drehung: -1.0 (links herum) bis +1.0 (rechts herum), 0.0 = geradeaus
// Beispiele: fahren(1.0, 0.0) = Vollgas geradeaus
//            fahren(0.0, 0.5) = auf der Stelle nach rechts drehen
//            fahren(0.6, 0.3) = vorwärts in einer Rechtskurve
void fahren(float tempo, float drehung);

// Alle Motoren sofort bremsen.
void stopp();

}  // namespace Motoren
