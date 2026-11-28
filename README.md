# Bodensee Alligatoren – Roboter-Code

Code für den Fußball-Roboter der Roboter-AG am BZM Markdorf
(RoboCup Junior Soccer Entry, Regeln 2026).

- **Mikrocontroller:** Teensy 4.0 auf unserer eigenen Hauptplatine
- **Programmierung:** C++ mit PlatformIO in VS Code (Arduino-Framework)
- **Sensoren:** IR-Ring mit 16 Sensoren (eigener STM32, über I2C), 4 Ultraschallsensoren,
  Lagesensor BNO055 als Kompass (I2C)
- **Antrieb:** 2 Räder (Differentialantrieb), Motortreiber L6201 auf der Hauptplatine
- **Akku:** Hacker Eco-X 2400, 2S LiPo, 7,4 V (Hauptplatine dafür angepasst)

> **Stand:** Grundgerüst. Die Pins sind aus dem Schaltplan der Hauptplatine
> (DasSoccerBoard-Basic V4.2) eingetragen. Fahren (2 Räder) und Kompass (BNO055)
> sind programmiert, IR-Ring, Ultraschall und Spiel-Logik fehlen noch.

## Ordner und Dateien

```
bodensee-alligatoren-robot/
├── platformio.ini          Projekt-Einstellungen: Board (Teensy 4.0) und Framework
├── include/
│   └── pins.h              Alle Pin-Nummern an einer Stelle
├── src/
│   ├── main.cpp            Hauptprogramm: setup() und loop()
│   ├── motoren.h/.cpp      Antrieb (fahren, drehen, stoppen)
│   ├── ir_ring.h/.cpp      IR-Ring: Wo ist der Ball?
│   ├── ultraschall.h/.cpp  Abstände zu den Banden
│   ├── kompass.h/.cpp      Blickrichtung des Roboters
│   └── motortest.h/.cpp    Testprogramm für die Motoren
├── .gitignore              Dateien, die Git ignorieren soll (z.B. Build-Ordner)
└── README.md               Diese Datei
```

**Warum `.h` und `.cpp`?** Die `.h`-Datei (Header) ist das Inhaltsverzeichnis:
Sie sagt, *welche* Funktionen es gibt. Die `.cpp`-Datei enthält, *wie* sie
funktionieren. `main.cpp` bindet nur die Header ein und muss nicht wissen,
wie z.B. der Kompass intern funktioniert.

**Was ist `namespace`?** Alle Funktionen eines Moduls stehen in einer Gruppe,
z.B. `Motoren::fahren(...)` oder `Kompass::richtungGrad()`. So sieht man
sofort, zu welchem Teil des Roboters eine Funktion gehört.

## Wie das Programm abläuft

1. `setup()` läuft einmal nach dem Einschalten: USB-Verbindung starten,
   alle Module vorbereiten, Motoren aus.
2. `loop()` läuft danach immer wieder, alle 10 ms:
   1. **Sensoren lesen** (IR-Ring, Ultraschall, Kompass)
   2. **Entscheiden**, was der Roboter tun soll (kommt noch)
   3. **Motoren ansteuern**
3. Alle 0,5 s werden Messwerte an den seriellen Monitor geschickt (zum Testen).

## Einrichten in VS Code

Einmalig nötig:

1. [VS Code](https://code.visualstudio.com/) und [Git](https://git-scm.com/) installieren.
2. In VS Code links auf **Erweiterungen** klicken und **PlatformIO IDE** installieren.
3. Für den Teensy unter Windows: nichts weiter nötig. Unter Linux die
   Teensy-udev-Regeln installieren (siehe PlatformIO-Doku).

Repo auf den eigenen Computer holen ("klonen"):

1. In VS Code `Strg+Umschalt+P` drücken und **Git: Clone** eingeben.
2. Die Adresse einfügen: `https://github.com/MeisterHuhni/bodensee-alligatoren-robot`
3. Einen Ordner auswählen und danach **Öffnen** klicken.
4. PlatformIO erkennt die `platformio.ini` automatisch. Beim ersten Mal lädt es
   die Teensy-Werkzeuge herunter, das dauert ein paar Minuten.

## Bauen und Hochladen

Unten in der blauen Leiste von VS Code:

| Symbol | Was es macht |
|---|---|
| ✓ Häkchen | **Bauen**: prüft und übersetzt den Code |
| → Pfeil | **Hochladen**: baut und spielt den Code auf den Teensy |
| 🔌 Stecker | **Serieller Monitor**: zeigt, was der Teensy über `Serial.print` sendet |

## Motortest

In `src/main.cpp` steht `MOTORTEST_AKTIV`. Bei `true` fährt der Roboter
statt Fußball ein Testprogramm, sobald der START-Schalter an ist:

1. nur MOT1 vorwärts
2. nur MOT2 vorwärts
3. `fahren()` geradeaus vorwärts
4. `fahren()` nach rechts drehen

Jeder Schritt dauert 2 s, im seriellen Monitor steht, was passieren soll.
Beim ersten Mal den Roboter aufbocken, damit die Räder in der Luft sind.

## Arbeiten mit Git (Kurzfassung)

1. Code ändern und speichern.
2. Links auf **Quellcodeverwaltung** (Symbol mit drei Punkten und Linien) klicken.
3. Bei den geänderten Dateien auf **+** klicken (= für den Commit vormerken).
4. Oben eine kurze Nachricht schreiben, z.B. `Kompass auslesen`, und **Commit** klicken.
5. **Änderungen synchronisieren** klicken (= zu GitHub hochladen).

Vor dem Arbeiten immer zuerst **Pull** (bzw. synchronisieren), damit man den
neuesten Stand hat.

## Wichtige Regeln für den Code

- Bau und Programmierung nur durch uns Schüler. **Keine Beispielprogramme von
  Kits**, auch nicht verändert.
- Im Interview müssen wir jeden Teil des Codes erklären können. Deshalb lieber
  einfach und gut kommentiert als kompliziert.
- Keine eigenen IR-Sender (keine ToF-, LiDAR- oder IR-Abstandssensoren, keine IR-LEDs).
- Dem Kompass nicht blind vertrauen: Auf dem Feld kann es magnetische Störungen geben.

## Noch offen

- [ ] Liga festlegen (Infrared League oder Standard Kit League), davon hängt die
      Anzahl der Motoren ab
- [x] `Motoren::fahren()` für 2 Räder schreiben
- [ ] Beim ersten Test prüfen: Ist MOT1 links, MOT2 rechts, und muss ein Motor umgedreht werden?
- [ ] Motormodell klären (wichtig für die Standard Kit League: nur Motoren von der Liste erlaubt)
- [x] Pins in `include/pins.h` eintragen
- [x] Kompass (BNO055) auslesen
- [x] Anschluss IR-Ring klären: I2C über J11 (Wire1)
- [ ] I2C-Adresse und Datenformat des IR-Rings festlegen (STM32-Programm), dann auslesen
- [ ] Ultraschallsensoren: Modell und Anschluss klären (noch nicht vorhanden), dann auslesen
- [ ] Spiel-Logik in `loop()` schreiben
