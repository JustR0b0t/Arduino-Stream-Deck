// Arduino Stream Deck:
// Konfigurierbares DIY Stream Deck,
// welches AutoHotKey nutzt um auf dem PC Aktionen durchzuführen
// 
// Knöpfe:
// Programm öffnen
// Discord Mikrofon Ein/Aus
// Discord Audio Ein/Aus
// Bestimmte Lautstärke setzen
// Speichern
// Panic Button / Auf Desktop wechseln
// und ein EasterEgg

// Arduino Bibliotheken
#include <Keyboard.h> // Erlaubt es dem Arduino sich als Tastatur auszugeben
#include <Adafruit_NeoPixel.h> // Erlaubt es die LEDs anzusprechen

// Konfiguration und Spezifikation der LEDs für die Adafruit Bibliothek
#define LED_PIN   8 // Digitaler Pin für die LED
#define LED_COUNT 8 // Anzahl LEDs
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

 // Digitale Pin Zuweisung
const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;

// Variabel um das Debuggen einfacher zu machen
int buttonState_highlow = HIGH;
int times = 0;
const int buttonPress_delay = 1000; // Sorgt dafür dass die Knöpfe nicht x-mal gedrückt werden
int blink_loop_time = 5; // Anzahl Blinken bei Knopfdruck
int blink_delay = 100; // Pause zwischen dem Blinken

// Generische Farb Codes
uint32_t red = pixels.Color(255, 0, 0);
uint32_t green = pixels.Color(0, 255, 0);
uint32_t blue = pixels.Color(0, 0, 255);
uint32_t pink = pixels.Color(255, 0, 127);
uint32_t white = pixels.Color(255, 225, 255);
// Applikations Farb Codes
uint32_t Discord = pixels.Color(114, 137, 217);
uint32_t EarTrumpet = pixels.Color(255, 197, 4);

// Drucktaster Farbzuweisung
uint32_t colorA = EarTrumpet;
uint32_t colorB = Discord;
uint32_t colorC_copy = red;
uint32_t colorC_paste = pink;
uint32_t colorD = blue;
uint32_t colorE = green;
uint32_t colorF = white;

void setup() {
  Serial.begin(9600);
  pinMode(pinA, INPUT); //Definiert die Drucktaster-Pins als Inputs
  pinMode(pinB, INPUT);
  pinMode(pinC, INPUT);
  pinMode(pinD, INPUT);
  pinMode(pinE, INPUT);
  pinMode(pinF, INPUT);
  pixels.begin(); // Initialisiert die LEDs
  pixels.show();
}

void loop() {
  // Überprüft ob die Knöpfe gedrückt sind
  // Knopf A
  if (digitalRead(pinA) == buttonState_highlow) {
    Serial.print("1  Programm öffnen "); // Sended die Knopfdruck Beschreibung an die Konsole, fürs Debuggen
    Keyboard.press(KEY_LEFT_CTRL); // Drückt die Ctrl Taste
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('1');
    Keyboard.releaseAll(); // Hört auf die oben dargestellten Tasten zu drücken
    // LED Blinken als Indikator
    for (times=0; times < blink_loop_time; times++)
    {
      pixels.fill(colorA);
      pixels.show();
      delay(blink_delay);
      pixels.clear();
      pixels.show();
      delay(blink_delay);
    }
    pixels.fill(colorA);
    pixels.show();
    delay(buttonPress_delay);
  }
  
  // Knopf B
  if (digitalRead(pinB) == buttonState_highlow) {
    Serial.print("2 Discord Mute Toggle ");
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('2');
    Keyboard.releaseAll();
    for (times=0; times < blink_loop_time; times++)
    {
      pixels.fill(colorB);
      pixels.show();
      delay(blink_delay);
      pixels.clear();
      pixels.show();
      delay(blink_delay);
    }
    pixels.fill(colorB);
    pixels.show();
    delay(buttonPress_delay);
  }
  
  // Knopf C
  if (digitalRead(pinC) == buttonState_highlow) {
    Serial.print("3 Discord Deafen Toggle ");
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('3');
    Keyboard.releaseAll();
    for (times=0; times < blink_loop_time; times++)
    {
      pixels.fill(colorC_copy);
      pixels.show();
      delay(blink_delay);
      pixels.clear();
      pixels.show();
      delay(blink_delay);
    }
    pixels.fill(colorC_paste);
    pixels.show();
    delay(buttonPress_delay);
  }
  
 // Knopf D
 if (digitalRead(pinD) == buttonState_highlow) {
    Serial.print("4 Lautstärke setzen "); 
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('4');
    Keyboard.releaseAll();
    for (times=0; times < blink_loop_time; times++)
    {
      pixels.fill(colorD);
      pixels.show();
      delay(blink_delay);
      pixels.clear();
      pixels.show();
      delay(blink_delay);
    }
    pixels.fill(colorD);
   pixels.show();
    delay(buttonPress_delay);
  }
  
  // Knopf E
  if (digitalRead(pinE) == buttonState_highlow) {
    Serial.print("5 Speichern ");
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('s');
    Keyboard.releaseAll();
    for (times=0; times < blink_loop_time; times++)
    {
      pixels.fill(colorE);
      pixels.show();
      delay(blink_delay);
      pixels.clear();
      pixels.show();
      delay(blink_delay);
    }
    pixels.fill(colorE);
    pixels.show();
    delay(buttonPress_delay);
  }
  
  // Knopf F
  if (digitalRead(pinF) == buttonState_highlow) {
    Serial.print("6 Panic Button "); 
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('d');
    Keyboard.releaseAll();
    for (times=0; times < blink_loop_time; times++)
    {
      pixels.fill(colorF);
      pixels.show();
      delay(blink_delay);
      pixels.clear();
      pixels.show();
      delay(blink_delay);
    }
    pixels.fill(colorF);
    pixels.show();
    delay(buttonPress_delay);
    // Easter Egg
    if (digitalRead(pinF) == buttonState_highlow) {
      delay(5000);
      if (digitalRead(pinF) == buttonState_highlow) {
        Serial.print("7 RickRoll Easter Egg");
        pixels.fill(colorF);
        pixels.show();
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('[');
        Keyboard.releaseAll();
        // Never Gonna Give you up Refrain Songtext
        // Zeitgleich wird auf dem PC Never gonna give you up geöffnet
        pixels.clear();
		    pixels.show();
        delay(1000);
        pixels.setPixelColor(6, red);
        pixels.show();
        delay(180);// Jedes Wort in ms
		    pixels.clear();
		    pixels.show();
        pixels.setPixelColor(7, red);
        pixels.show();
        delay(370);
		    pixels.clear();
		    pixels.show();
        pixels.setPixelColor(7, red);
        pixels.show();
        delay(260);
		    pixels.clear();
		    pixels.show();
        pixels.setPixelColor(1, red);
        pixels.show();
        delay(360);
		    pixels.clear();
		    pixels.show();
        pixels.setPixelColor(5, red);
        pixels.show();
        delay(1140);
		    pixels.clear();
		    pixels.show();
        pixels.setPixelColor(6, red);
        pixels.show();
        delay(210);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(7, red);
        pixels.show();
        delay(200);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(4, red);
        pixels.show();
        delay(500);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(1, red);
        pixels.show();
        delay(380);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(4, red);
        pixels.show();
        delay(770);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(6, red);
        pixels.show();
        delay(280);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(7, red);
        pixels.show();
        delay(290);
	    	pixels.clear();
        pixels.show();
        pixels.setPixelColor(2, red);
        pixels.show();
        delay(470);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(1, red);
        pixels.show();
        delay(850);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(1, red);
        pixels.show();
        delay(570);
	    	pixels.clear();
    		pixels.show();
        pixels.setPixelColor(4, red);
        pixels.show();
        delay(580);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(1, red);
        pixels.show();
        delay(1140);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(6, red);
        pixels.show();
        delay(340);
    		pixels.clear();
    		pixels.show();
        pixels.setPixelColor(7, red);
        pixels.show();
        delay(300);
    		pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(5, red);
        pixels.show();
        delay(530);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(1, red);
        pixels.show();
        delay(420);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(3, red);
        pixels.show();
        delay(700);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(6, red);
        pixels.show();
        delay(240);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(7, red);
        pixels.show();
        delay(310);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(3, red);
        pixels.show();
        delay(470);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(7, red);
        pixels.show();
        delay(1000);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(6, red);
        pixels.show();
        delay(290);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(7, red);
        pixels.show();
        delay(370);
		    pixels.clear();
		    pixels.show();
        pixels.setPixelColor(4, red);
        pixels.show();
        delay(690);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(1, red);
        pixels.show();
        delay(880);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(4, red);
        pixels.show();
        delay(310);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(1, red);
        pixels.show();
        delay(500);
	    	pixels.clear();
	    	pixels.show();
        pixels.setPixelColor(8, red);
        pixels.show();
        delay(420);
    		pixels.clear();
    		pixels.show();
        pixels.setPixelColor(1, red);
        pixels.show();
        delay(450);
	    	pixels.clear();
	    	pixels.show();
        delay(1000);
      }
    }
  }
}
