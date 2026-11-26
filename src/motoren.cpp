// =============================================================
// motoren.cpp – Antrieb des Roboters (Umsetzung)
// =============================================================
// Jeder Motor hängt an einem Treiber-Chip L6201 (Schaltplan Blatt 5/8).
// So steuert man ihn (Tabelle aus dem Schaltplan):
//
//   PWM (EN)  IN1   IN2   Ergebnis
//   LOW       egal  egal  Motor läuft frei aus
//   HIGH      HIGH  LOW   dreht in die eine Richtung
//   HIGH      LOW   HIGH  dreht in die andere Richtung
//   HIGH      gleich      Motor bremst
//
// Statt PWM nur HIGH oder LOW zu setzen, schalten wir es mit
// analogWrite() sehr schnell an und aus. Je länger "an", desto
// schneller dreht der Motor.
//
// STAND: motorSetzen() und stopp() funktionieren.
// fahren() fehlt noch, weil die Anordnung der Räder noch offen ist.
// =============================================================
#include "motoren.h"
#include <Arduino.h>
#include "pins.h"

namespace Motoren {

// Die Pins der 4 Anschlüsse als Tabellen. Eintrag 0 = MOT1, 1 = MOT2, ...
// So kann man mit einer Schleife alle Motoren gleich behandeln.
static const uint8_t PWM_PINS[ANZAHL_ANSCHLUESSE] = {
    PIN_MOTOR1_PWM, PIN_MOTOR2_PWM, PIN_MOTOR3_PWM, PIN_MOTOR4_PWM};
static const uint8_t IN1_PINS[ANZAHL_ANSCHLUESSE] = {
    PIN_MOTOR1_IN1, PIN_MOTOR2_IN1, PIN_MOTOR3_IN1, PIN_MOTOR4_IN1};
static const uint8_t IN2_PINS[ANZAHL_ANSCHLUESSE] = {
    PIN_MOTOR1_IN2, PIN_MOTOR2_IN2, PIN_MOTOR3_IN2, PIN_MOTOR4_IN2};

// Größter Wert für analogWrite(). Beim Teensy ist er standardmäßig
// 255 (8 Bit). 255 = immer an = Vollgas.
constexpr int PWM_MAX = 255;

void starten() {
  for (int i = 0; i < ANZAHL_ANSCHLUESSE; i++) {
    pinMode(PWM_PINS[i], OUTPUT);
    pinMode(IN1_PINS[i], OUTPUT);
    pinMode(IN2_PINS[i], OUTPUT);
  }
  stopp();   // sicher ist sicher: am Anfang bremsen

  // Motorstrom freigeben (wirkt nur, wenn JP2 durchtrennt ist).
  pinMode(PIN_MOTOR_STROM_AN, OUTPUT);
  digitalWrite(PIN_MOTOR_STROM_AN, HIGH);

  Serial.println("[Motoren] gestartet");
}

void motorSetzen(int nummer, float tempo) {
  // Falsche Nummer? Dann nichts tun, statt einen falschen Pin zu schalten.
  if (nummer < 1 || nummer > ANZAHL_ANSCHLUESSE) {
    return;
  }
  int i = nummer - 1;   // MOT1 steht in der Tabelle an Stelle 0

  // Tempo auf den erlaubten Bereich -1.0 ... +1.0 begrenzen.
  tempo = constrain(tempo, -1.0f, 1.0f);

  if (tempo > 0) {
    digitalWrite(IN1_PINS[i], HIGH);
    digitalWrite(IN2_PINS[i], LOW);
  } else if (tempo < 0) {
    digitalWrite(IN1_PINS[i], LOW);
    digitalWrite(IN2_PINS[i], HIGH);
  } else {
    // tempo == 0: beide gleich + PWM an = bremsen
    digitalWrite(IN1_PINS[i], LOW);
    digitalWrite(IN2_PINS[i], LOW);
    analogWrite(PWM_PINS[i], PWM_MAX);
    return;
  }

  // fabs() = Betrag, also ohne Minus. -0.5 wird zu 0.5.
  analogWrite(PWM_PINS[i], (int)(fabs(tempo) * PWM_MAX));
}

void fahren(float richtungGrad, float tempo, float drehung) {
  // TODO: Aus Richtung, Tempo und Drehung die Geschwindigkeit für
  // jeden einzelnen Motor ausrechnen und mit motorSetzen() ausgeben.
  // Dafür müssen wir wissen, in welchem Winkel die Räder sitzen.

  // Diese drei Zeilen tun nichts. Sie verhindern nur die Warnung
  // "Variable wird nicht benutzt", solange die Funktion leer ist.
  (void)richtungGrad;
  (void)tempo;
  (void)drehung;
}

void stopp() {
  for (int nummer = 1; nummer <= ANZAHL_ANSCHLUESSE; nummer++) {
    motorSetzen(nummer, 0.0f);
  }
}

}  // namespace Motoren
