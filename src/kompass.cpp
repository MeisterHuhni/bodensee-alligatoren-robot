// =============================================================
// kompass.cpp – Lagesensor BNO055 (Umsetzung)
// =============================================================
// Wir sprechen direkt mit dem Chip, ohne fremde Bibliothek. So ist
// der Code kurz und wir können jede Zeile erklären.
//
// Wie I2C funktioniert (vereinfacht): Der Teensy ruft den Sensor über
// seine Adresse (0x28) auf. Der Sensor hat viele "Register", das sind
// nummerierte Speicherplätze. Man schreibt in ein Register, um etwas
// einzustellen, und liest aus einem Register, um Messwerte zu bekommen.
// Die Register-Nummern stehen im Datenblatt des BNO055.
// =============================================================
#include "kompass.h"
#include <Arduino.h>
#include <Wire.h>
#include "pins.h"

namespace Kompass {

// Auf unserer Platine hängt der I2C-Bus an Pin 16/17. Das ist beim
// Teensy der ZWEITE I2C-Bus, im Code "Wire1" (nicht "Wire").
static TwoWire& bus = Wire1;

// Adresse des BNO055 (Brücke JP1 auf dem Breakout offen = 0x28).
constexpr uint8_t ADRESSE = 0x28;

// Register aus dem Datenblatt
constexpr uint8_t REG_CHIP_ID   = 0x00;  // enthält immer 0xA0
constexpr uint8_t REG_HEADING   = 0x1A;  // Drehwinkel, 2 Bytes
constexpr uint8_t REG_OPR_MODE  = 0x3D;  // Betriebsart
constexpr uint8_t CHIP_ID       = 0xA0;
constexpr uint8_t MODUS_CONFIG  = 0x00;  // Einstellungs-Modus
constexpr uint8_t MODUS_IMU     = 0x08;  // Gyroskop + Beschleunigung

static bool gefunden = false;
static float rohwert = 0.0f;    // Wert direkt vom Sensor (0..360 Grad)
static float nullpunkt = 0.0f;  // gespeicherter Nullpunkt

// Ein Byte in ein Register schreiben.
static void schreiben(uint8_t reg, uint8_t wert) {
  bus.beginTransmission(ADRESSE);
  bus.write(reg);
  bus.write(wert);
  bus.endTransmission();
}

// Ein Byte aus einem Register lesen.
static uint8_t lesenByte(uint8_t reg) {
  bus.beginTransmission(ADRESSE);
  bus.write(reg);
  bus.endTransmission(false);   // false = Verbindung offen lassen
  bus.requestFrom(ADRESSE, (uint8_t)1);
  return bus.available() ? bus.read() : 0;
}

bool starten() {
  bus.begin();

  // Der BNO055 braucht nach dem Einschalten ca. 0,65 s zum Hochfahren.
  // Wir fragen bis zu 1 Sekunde lang, ob er schon antwortet.
  unsigned long beginn = millis();
  while (lesenByte(REG_CHIP_ID) != CHIP_ID) {
    if (millis() - beginn > 1000) {
      Serial.println("[Kompass] FEHLER: BNO055 nicht gefunden!");
      gefunden = false;
      return false;
    }
    delay(10);
  }

  // Betriebsart umstellen: erst in den Einstellungs-Modus, dann IMU.
  // Die Pausen verlangt das Datenblatt beim Wechsel der Betriebsart.
  schreiben(REG_OPR_MODE, MODUS_CONFIG);
  delay(25);
  schreiben(REG_OPR_MODE, MODUS_IMU);
  delay(20);

  gefunden = true;
  Serial.println("[Kompass] BNO055 gefunden, IMU-Modus aktiv");
  return true;
}

void lesen() {
  if (!gefunden) {
    return;
  }
  // Der Winkel steht in 2 Bytes: erst das niedrige, dann das hohe.
  bus.beginTransmission(ADRESSE);
  bus.write(REG_HEADING);
  bus.endTransmission(false);
  bus.requestFrom(ADRESSE, (uint8_t)2);
  if (bus.available() < 2) {
    return;   // keine Antwort: alten Wert behalten
  }
  uint8_t niedrig = bus.read();
  uint8_t hoch = bus.read();

  // Beide Bytes zu einer Zahl zusammensetzen ("<< 8" schiebt das hohe
  // Byte 8 Stellen nach links). Der Sensor zählt in 1/16 Grad.
  int16_t roh = (int16_t)((hoch << 8) | niedrig);
  rohwert = roh / 16.0f;
}

float richtungGrad() {
  // Unterschied zum Nullpunkt ausrechnen ...
  float winkel = rohwert - nullpunkt;
  // ... und in den Bereich -180 bis +180 bringen.
  // Beispiel: 350 Grad ist das Gleiche wie -10 Grad.
  while (winkel > 180.0f)  winkel -= 360.0f;
  while (winkel < -180.0f) winkel += 360.0f;
  return winkel;
}

void nullpunktSetzen() {
  nullpunkt = rohwert;
}

}  // namespace Kompass
