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

// Einmal in setup() aufrufen: Pins vorbereiten.
void starten();

// Roboter fahren lassen.
//   richtungGrad: wohin fahren (0 = nach vorne, 90 = nach rechts, ...)
//   tempo:        wie schnell, von 0.0 (steht) bis 1.0 (Vollgas)
//   drehung:      wie stark drehen, von -1.0 (links) bis +1.0 (rechts)
void fahren(float richtungGrad, float tempo, float drehung);

// Alle Motoren sofort anhalten.
void stopp();

}  // namespace Motoren
