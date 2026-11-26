// =============================================================
// main.cpp – Hauptprogramm der Bodensee Alligatoren
// =============================================================
// Jedes Arduino-Programm hat zwei Pflicht-Funktionen:
//   setup() läuft EINMAL, direkt nach dem Einschalten.
//   loop()  läuft danach IMMER WIEDER, so schnell es geht.
//
// Unser loop() folgt immer demselben Muster:
//   1. Sensoren lesen   (Wo ist der Ball? Wo bin ich?)
//   2. Entscheiden      (Was soll der Roboter jetzt tun?)
//   3. Motoren ansteuern
//
// Der Roboter fährt nur, wenn der START-Schalter auf der Platine
// an ist. So können wir ihn auf dem Feld sicher hinstellen und erst
// auf den Pfiff des Schiedsrichters starten.
//
// STAND: Motoren und Kompass können angesteuert werden. IR-Ring,
// Ultraschall und die Spiel-Logik fehlen noch.
// =============================================================
#include <Arduino.h>

#include "motoren.h"
#include "ir_ring.h"
#include "ultraschall.h"
#include "kompass.h"
#include "pins.h"

// Wie oft loop() wirklich arbeiten soll: alle 10 Millisekunden
// (also 100-mal pro Sekunde). So läuft der Roboter gleichmäßig,
// egal wie schnell der Teensy ist.
constexpr unsigned long LOOP_INTERVALL_MS = 10;

// Wie oft wir Werte zum Computer schicken (zum Testen).
constexpr unsigned long AUSGABE_INTERVALL_MS = 500;

// Zeitpunkte des letzten Durchlaufs bzw. der letzten Ausgabe.
unsigned long letzterLoop = 0;
unsigned long letzteAusgabe = 0;

// Schickt die aktuellen Sensorwerte an den seriellen Monitor.
void statusAusgeben() {
  Serial.print("Start: ");
  Serial.print(digitalRead(PIN_START_SCHALTER) == HIGH ? "an" : "aus");
  Serial.print(" | Ball gesehen: ");
  Serial.print(IrRing::ballGesehen() ? "ja" : "nein");
  Serial.print(" | Ball-Richtung: ");
  Serial.print(IrRing::ballRichtungGrad());
  Serial.print(" | Kompass: ");
  Serial.print(Kompass::richtungGrad());
  Serial.print(" | Abstand vorne: ");
  Serial.println(Ultraschall::abstandCm(Ultraschall::VORNE));
}

void setup() {
  // USB-Verbindung zum Computer starten.
  Serial.begin(115200);
  // Kurz warten (max. 2 Sekunden), damit der serielle Monitor
  // die ersten Meldungen mitbekommt. Ohne Computer geht es danach
  // einfach weiter.
  while (!Serial && millis() < 2000) {
  }
  Serial.println("Bodensee Alligatoren – Roboter startet ...");

  // Alle Module vorbereiten.
  Motoren::starten();
  IrRing::starten();
  Ultraschall::starten();
  Kompass::starten();

  // Start-Schalter als Eingang einstellen.
  pinMode(PIN_START_SCHALTER, INPUT);

  // Sicherheit: Am Anfang steht der Roboter still.
  Motoren::stopp();

  Serial.println("Bereit.");
}

void loop() {
  // millis() = Millisekunden seit dem Einschalten.
  unsigned long jetzt = millis();

  // Noch nicht Zeit für den nächsten Durchlauf? Dann sofort zurück.
  if (jetzt - letzterLoop < LOOP_INTERVALL_MS) {
    return;
  }
  letzterLoop = jetzt;

  // ---------- 1. Sensoren lesen ----------
  IrRing::lesen();
  Ultraschall::lesen();
  Kompass::lesen();

  // ---------- 2. Entscheiden ----------
  bool startAn = digitalRead(PIN_START_SCHALTER) == HIGH;

  if (!startAn) {
    // START-Schalter aus: Roboter steht.
    Motoren::stopp();
  } else {
    // TODO: Hier kommt später die Spiel-Logik hin, zum Beispiel:
    //   - Ball gesehen?  -> zum Ball fahren
    //   - Ball vorne?    -> Richtung gegnerisches Tor fahren
    //   - Ball weg?      -> zurück vors eigene Tor
    // ---------- 3. Motoren ansteuern ----------
    // Bis die Logik da ist, bleibt der Roboter auch hier stehen.
    Motoren::stopp();
  }

  // ---------- Testausgabe ----------
  if (jetzt - letzteAusgabe >= AUSGABE_INTERVALL_MS) {
    letzteAusgabe = jetzt;
    statusAusgeben();
  }
}
