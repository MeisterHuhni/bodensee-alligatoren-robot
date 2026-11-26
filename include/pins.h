// =============================================================
// pins.h – Alle Pin-Nummern an EINER Stelle
// =============================================================
// Hier steht, welches Signal an welchem Pin vom Teensy 4.0 hängt.
// Quelle: Schaltplan "DasSoccerBoard-Basic V4.2", Blatt 1/8
// (Teensy-Symbol). Wenn sich an der Platine etwas ändert, muss man
// nur diese Datei anpassen und nicht im ganzen Code suchen.
//
// "constexpr" heißt: Der Wert ist eine feste Konstante, die schon
// beim Bauen bekannt ist. Das ist wie #define, nur sicherer,
// weil der Compiler den Typ (uint8_t = Zahl 0..255) kennt.
// =============================================================
#pragma once   // sorgt dafür, dass die Datei nur einmal eingebunden wird

#include <Arduino.h>

// ---------- Motoren (Blatt 5/8) ----------
// Jeder Motor hat einen Treiber-Chip L6201 mit drei Eingängen:
//   PWM (= ENABLE): wie schnell (per analogWrite)
//   IN1, IN2:       in welche Richtung
// Die Platine hat Platz für 4 Motoren. Wir benutzen 2 (linkes und
// rechtes Rad, siehe motoren.cpp). MOT3 und MOT4 sind frei.
constexpr uint8_t PIN_MOTOR1_PWM = 4;
constexpr uint8_t PIN_MOTOR1_IN1 = 0;
constexpr uint8_t PIN_MOTOR1_IN2 = 1;

constexpr uint8_t PIN_MOTOR2_PWM = 5;
constexpr uint8_t PIN_MOTOR2_IN1 = 2;
constexpr uint8_t PIN_MOTOR2_IN2 = 3;

constexpr uint8_t PIN_MOTOR3_PWM = 6;
constexpr uint8_t PIN_MOTOR3_IN1 = 7;
constexpr uint8_t PIN_MOTOR3_IN2 = 8;

constexpr uint8_t PIN_MOTOR4_PWM = 9;
constexpr uint8_t PIN_MOTOR4_IN1 = 26;
constexpr uint8_t PIN_MOTOR4_IN2 = 32;

// Schaltet den Motorstrom ein (HIGH) oder aus (LOW). Das wirkt aber
// nur, wenn auf der Platine die Brücke JP2 durchtrennt ist (Blatt 2/8).
// Sonst schaltet nur der Schalter "MOT-PWR" die Motoren.
constexpr uint8_t PIN_MOTOR_STROM_AN = 27;

// ---------- Start-Schalter (Blatt 7/8) ----------
// Schiebeschalter "START": HIGH = an, LOW = aus.
constexpr uint8_t PIN_START_SCHALTER = 10;

// ---------- I2C-Bus (Blatt 4/8) ----------
// Am I2C-Bus hängen: Kompass BNO055 (Adresse 0x28), IR-Ring über
// den Stecker I2C-Intercon J11 (Adresse noch offen), Port-Expander
// TCA9534 für Taster/Schalter (0x20), Strommessung INA219 für den
// Akku (0x40) und für den Dribbler (0x41).
// ACHTUNG: Auf unserer Platine ist das NICHT der Standard-Bus (Pins
// 18/19), sondern der zweite Bus des Teensy. Im Code heißt er "Wire1".
constexpr uint8_t PIN_I2C_SDA = 17;   // nur zur Info, Wire1 kennt die Pins selbst
constexpr uint8_t PIN_I2C_SCL = 16;

// ---------- Serielle Schnittstellen (Blatt 3/8) ----------
// Stecker UART1 (J6):     Teensy Serial6 (TX = Pin 24, RX = Pin 25)
// Stecker UART2 (J7):     Teensy Serial7 (TX = Pin 29, RX = Pin 28)
// Stecker Pixy-Kamera:    Teensy Serial3 (TX = Pin 14, RX = Pin 15)

// ---------- SPI-Stecker (Blatt 3/8) ----------
// Pins 11 (MOSI), 12 (MISO), 13 (SCK) sind der SPI-Bus.
// ACHTUNG: Pin 13 ist auch die eingebaute LED vom Teensy. Weil er auf
// unserer Platine für SPI gebraucht wird, benutzen wir die LED nicht.
constexpr uint8_t PIN_SPI_DIO0 = 19;   // DIO0 = Chip-Select (CS) am Stecker
constexpr uint8_t PIN_SPI_DIO1 = 31;
constexpr uint8_t PIN_SPI_DIO2 = 30;
constexpr uint8_t PIN_SPI_DIO3 = 21;
constexpr uint8_t PIN_SPI_DIO4 = 22;

// ---------- Sonstiges (für später) ----------
constexpr uint8_t PIN_KICKER         = 18;  // Schuss-Mechanik (Blatt 6/8)
constexpr uint8_t PIN_DRIBBLER_PWM   = 33;  // Brushless-Dribbler (Blatt 6/8)
constexpr uint8_t PIN_LICHTSCHRANKE  = 23;  // Ball im Fänger? (analog, Blatt 3/8)
constexpr uint8_t PIN_RGB_LEDS       = 20;  // WS2812B-LED-Ring (Blatt 8/8)

// ---------- Ultraschall (4 Stück) ----------
// Auf der Hauptplatine gibt es keinen eigenen Anschluss dafür.
// Wie die Sensoren angeschlossen werden, ist noch offen.
