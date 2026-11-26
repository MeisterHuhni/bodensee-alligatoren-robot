// =============================================================
// kompass.h – Kompass (in welche Richtung schaut der Roboter?)
// =============================================================
// Der Kompass sagt uns, wie der Roboter gedreht ist. So kann er
// immer wieder zum gegnerischen Tor schauen.
//
// Achtung laut Regeln: Auf dem Feld kann es magnetische Störungen
// geben. Deshalb setzen wir vor dem Spiel einen Nullpunkt
// ("so rum ist vorne") und vertrauen dem Wert nicht blind.
// =============================================================
#pragma once

namespace Kompass {

// Einmal in setup() aufrufen.
void starten();

// Regelmäßig aufrufen: neuen Wert vom Sensor holen.
void lesen();

// Aktuelle Blickrichtung des Roboters in Grad, bezogen auf den
// Nullpunkt. 0 = Richtung gegnerisches Tor, Bereich -180 bis +180.
float richtungGrad();

// Aktuelle Richtung als neuen Nullpunkt speichern
// (z.B. vor dem Anstoß, wenn der Roboter zum Gegner-Tor schaut).
void nullpunktSetzen();

}  // namespace Kompass
