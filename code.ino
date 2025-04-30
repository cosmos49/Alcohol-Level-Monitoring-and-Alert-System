#include <LiquidCrystal_I2C.h>

// Pin Definitions
const int mq3Pin = A0;
const int buzzerPin = 9;
const int ledPin = 8;

// Initialize LCD: I2C address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("Alcohol Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  int alcoholLevel = analogRead(mq3Pin);

  // Print to Serial Monitor
  Serial.print("Alcohol Level: ");
  Serial.println(alcoholLevel);

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Alcohol: ");
  lcd.print(alcoholLevel);
  lcd.print("    "); // Clear trailing digits

  if (alcoholLevel > 200) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("ALCOHOL DETECTED");
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: Safe     ");
  }

  delay(500);
}
