#include <SimpleDHT.h>
#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>

// Sambungan antara LCD dan board, tengok sendiri di board. SCL ke SCL, SDA ke SDA
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_PCF8574 lcd(0x27);
int pinDHT11 = 2; // pin D2 di NANO Board
SimpleDHT11 dht11(pinDHT11);
 
void setup()
{
    // initialize the LCD
    lcd.begin(16,2);
 
    // Turn on the blacklight and print a message.
    lcd.setBacklight(0);
    lcd.print("  Stesen cuaca");
    lcd.setCursor(0,1);
    lcd.print("    9W2KEY");
  delay(1000);
 
 // yang ni tak de apa2 pun, saje nak bagi nampak ada animasi sikit
 
  lcd.clear();
  lcd.print("Sistem bermula");
 
  lcd.setCursor(0,1);
  lcd.print(".");
  delay(1000);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
}
 
void loop()
{
  delay(1000); //wait a sec (recommended for DHT11)
  byte temperature = 0;
  byte humidity = 0;
  dht11.read(&temperature, &humidity, NULL);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Suhu C      = ");
  lcd.print(temperature);
  lcd.setCursor(0,1);
  lcd.print("Klembapan % = ");
  lcd.print(humidity);

}
