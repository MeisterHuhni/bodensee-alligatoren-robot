// =============================================================
// motortest.h – Testprogramm für die Motoren
// =============================================================
// Lässt die Motoren nacheinander ein festes Programm abfahren und
// schreibt in den seriellen Monitor, was gerade passieren SOLL.
// So sieht man sofort, ob Verkabelung und Drehrichtung stimmen.
//
// Eingeschaltet wird der Test in main.cpp mit MOTORTEST_AKTIV = true.
// =============================================================
#pragma once

namespace Motortest {

// In jedem loop()-Durchlauf aufrufen, solange der Test laufen soll.
//   jetzt: aktuelle Zeit von millis()
void ausfuehren(unsigned long jetzt);

// Test wieder von vorne beginnen lassen (z.B. wenn START aus ist).
void zuruecksetzen();

}  // namespace Motortest
