// =============================================================
// pins.h – Alle Pin-Nummern an EINER Stelle
// =============================================================
// Hier steht später, welches Kabel an welchem Pin vom Teensy 4.0
// hängt. Wenn sich an der Platine etwas ändert, muss man nur
// diese Datei anpassen und nicht im ganzen Code suchen.
//
// STAND: Die Pins sind noch NICHT festgelegt. Deshalb steht
// überall PIN_UNBEKANNT. Solange ein Pin unbekannt ist, benutzt
// der Code ihn absichtlich nicht.
//
// "constexpr" heißt: Der Wert ist eine feste Konstante, die schon
// beim Bauen bekannt ist. Das ist wie #define, nur sicherer,
// weil der Compiler den Typ (uint8_t = Zahl 0..255) kennt.
// =============================================================
#pragma once   // sorgt dafür, dass die Datei nur einmal eingebunden wird

#include <Arduino.h>

// Platzhalter für "noch nicht festgelegt". 255 gibt es am Teensy 4.0
// nicht als Pin (er hat Pins 0 bis 39), deshalb ist das sicher erkennbar.
constexpr uint8_t PIN_UNBEKANNT = 255;

// ---------- Motoren ----------
// Wie viele Motoren es werden, hängt von der Liga ab
// (Infrared League: max. 3, Standard Kit League: max. 2).
// Pro Motor braucht man meist einen PWM-Pin (Tempo) und einen
// oder zwei Pins für die Richtung – je nach Motortreiber.
constexpr uint8_t PIN_MOTOR_1_PWM  = PIN_UNBEKANNT;
constexpr uint8_t PIN_MOTOR_1_DIR  = PIN_UNBEKANNT;
constexpr uint8_t PIN_MOTOR_2_PWM  = PIN_UNBEKANNT;
constexpr uint8_t PIN_MOTOR_2_DIR  = PIN_UNBEKANNT;
constexpr uint8_t PIN_MOTOR_3_PWM  = PIN_UNBEKANNT;
constexpr uint8_t PIN_MOTOR_3_DIR  = PIN_UNBEKANNT;

// ---------- Ultraschall (4 Stück) ----------
// Viele Ultraschallsensoren haben einen Trigger-Pin (Signal senden)
// und einen Echo-Pin (Antwort empfangen).
constexpr uint8_t PIN_US_VORNE_TRIG   = PIN_UNBEKANNT;
constexpr uint8_t PIN_US_VORNE_ECHO   = PIN_UNBEKANNT;
constexpr uint8_t PIN_US_RECHTS_TRIG  = PIN_UNBEKANNT;
constexpr uint8_t PIN_US_RECHTS_ECHO  = PIN_UNBEKANNT;
constexpr uint8_t PIN_US_HINTEN_TRIG  = PIN_UNBEKANNT;
constexpr uint8_t PIN_US_HINTEN_ECHO  = PIN_UNBEKANNT;
constexpr uint8_t PIN_US_LINKS_TRIG   = PIN_UNBEKANNT;
constexpr uint8_t PIN_US_LINKS_ECHO   = PIN_UNBEKANNT;

// ---------- IR-Ring (16 Sensoren) ----------
// Wie die 16 Sensoren angeschlossen sind (direkt an 16 Pins oder
// über einen Multiplexer), ist noch offen. Das tragen wir später ein.

// ---------- Kompass ----------
// Die meisten Kompass-Module nutzen I2C. Beim Teensy 4.0 sind das
// standardmäßig Pin 18 (SDA) und Pin 19 (SCL) – das prüfen wir,
// sobald das Kompass-Modell feststeht.
