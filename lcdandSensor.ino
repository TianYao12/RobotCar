#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

int trigPin = 4;
int echoPin = 5;
int pingTravelTime;

unsigned long previousMillis = 0;
const long interval = 1000;
int countingTime = 10;
int currentCount = 0;
double cm;

LiquidCrystal lcd(rs, en, d4, d5, d6,  d7);

void setup() {
  lcd.begin(16,2);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    // Call the first function to measure distance
    measureDistance();
    
    // Update the previousMillis variable
    previousMillis = currentMillis;
  }
  
  // Call the second function to display counting time on LCD
  displayCountingTime();
}

void measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTravelTime = pulseIn(echoPin, HIGH);
  cm = (pingTravelTime/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343

  delay(25);
}

void displayCountingTime() {
    lcd.setCursor(0,0);
    lcd.print("Distance in cm: ");
    lcd.setCursor(0,1);
    lcd.print(cm);
    delay(1000); 
}
