// =============================================================
// motortest.cpp – Testprogramm für die Motoren (Umsetzung)
// =============================================================
// Ablauf (jeder Schritt dauert 2 Sekunden, dazwischen 1 s Pause):
//   1. Nur MOT1 dreht "vorwärts"  -> Welches Rad ist das? Welche Richtung?
//   2. Nur MOT2 dreht "vorwärts"  -> Welches Rad ist das? Welche Richtung?
//   3. fahren(): geradeaus vorwärts
//   4. fahren(): auf der Stelle nach rechts drehen
//   Danach beginnt alles von vorne.
//
// Die Schritte 1 und 2 benutzen motorSetzen() direkt, also OHNE die
// Umkehr-Einstellungen aus motoren.cpp. Damit sieht man, wie die
// Motoren "roh" verkabelt sind.
// =============================================================
#include "motortest.h"
#include <Arduino.h>
#include "motoren.h"

namespace Motortest {

constexpr float TEST_TEMPO = 0.4f;            // nur 40 %, zur Sicherheit
constexpr unsigned long SCHRITT_MS = 2000;    // so lange läuft ein Schritt
constexpr unsigned long PAUSE_MS = 1000;      // Pause zwischen den Schritten
constexpr int ANZAHL_SCHRITTE = 4;

static int schritt = 0;                // welcher Schritt gerade dran ist (0..3)
static bool inPause = true;            // true = gerade Pause zwischen Schritten
static unsigned long startZeit = 0;    // wann der Schritt / die Pause begann
static bool gestartet = false;         // false = Test beginnt gleich neu

// Schreibt in den seriellen Monitor, was im neuen Schritt passieren soll.
static void schrittAnsagen() {
  Serial.print("[Motortest] Schritt ");
  Serial.print(schritt + 1);
  Serial.print(": ");
  switch (schritt) {
    case 0: Serial.println("nur MOT1 vorwaerts"); break;
    case 1: Serial.println("nur MOT2 vorwaerts"); break;
    case 2: Serial.println("fahren() geradeaus vorwaerts"); break;
    case 3: Serial.println("fahren() nach rechts drehen"); break;
  }
}

// Steuert die Motoren für den aktuellen Schritt an.
static void schrittAusfuehren() {
  switch (schritt) {
    case 0: Motoren::motorSetzen(1, TEST_TEMPO); break;
    case 1: Motoren::motorSetzen(2, TEST_TEMPO); break;
    case 2: Motoren::fahren(TEST_TEMPO, 0.0f); break;
    case 3: Motoren::fahren(0.0f, TEST_TEMPO); break;
  }
}

void ausfuehren(unsigned long jetzt) {
  // Beim allerersten Aufruf: mit einer Pause anfangen, damit man
  // nach dem Einschalten kurz Zeit hat.
  if (!gestartet) {
    gestartet = true;
    schritt = 0;
    inPause = true;
    startZeit = jetzt;
    Serial.println("[Motortest] startet ...");
  }

  unsigned long vergangen = jetzt - startZeit;

  if (inPause) {
    Motoren::stopp();
    if (vergangen >= PAUSE_MS) {
      // Pause vorbei: nächsten Schritt beginnen.
      inPause = false;
      startZeit = jetzt;
      schrittAnsagen();
    }
  } else {
    schrittAusfuehren();
    if (vergangen >= SCHRITT_MS) {
      // Schritt vorbei: Pause, danach der nächste Schritt.
      // "% ANZAHL_SCHRITTE" sorgt dafür, dass nach dem letzten
      // Schritt wieder Schritt 0 kommt (3 + 1 = 4, 4 % 4 = 0).
      inPause = true;
      startZeit = jetzt;
      schritt = (schritt + 1) % ANZAHL_SCHRITTE;
    }
  }
}

void zuruecksetzen() {
  gestartet = false;
}

}  // namespace Motortest
