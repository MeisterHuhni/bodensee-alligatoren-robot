// =============================================================
// kompass.h – Lagesensor BNO055 (in welche Richtung schaut der Roboter?)
// =============================================================
// Der BNO055 sitzt auf einer eigenen kleinen Platine (Breakout) und
// ist über I2C mit dem Teensy verbunden. Er hat drei Sensoren eingebaut
// (Gyroskop, Beschleunigung, Magnetfeld) und rechnet selbst aus, wie
// der Roboter gedreht ist.
//
// Wir benutzen ihn im Modus "IMU": Dann nimmt er NUR Gyroskop und
// Beschleunigung, aber NICHT das Magnetfeld. Grund: Laut Regeln kann es
// auf dem Feld magnetische Störungen geben. Im IMU-Modus stören die nicht.
// Nachteil: Er weiß nicht, wo Norden ist, sondern zählt nur, wie weit
// sich der Roboter seit dem Einschalten gedreht hat. Deshalb setzen wir
// einen Nullpunkt ("so rum ist vorne").
// =============================================================
#pragma once

namespace Kompass {

// Einmal in setup() aufrufen. Gibt true zurück, wenn der BNO055
// gefunden wurde.
bool starten();

// Regelmäßig aufrufen: neuen Wert vom Sensor holen.
void lesen();

// Aktuelle Blickrichtung des Roboters in Grad, bezogen auf den
// Nullpunkt. 0 = Richtung gegnerisches Tor, Bereich -180 bis +180.
float richtungGrad();

// Aktuelle Richtung als neuen Nullpunkt speichern
// (z.B. vor dem Anstoß, wenn der Roboter zum Gegner-Tor schaut).
void nullpunktSetzen();

}  // namespace Kompass
