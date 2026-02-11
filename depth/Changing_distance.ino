#include <LiquidCrystal.h>
#define trigPin 10
#define echoPin 13
long previousDistance = 0;
long currentDistance = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16,2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  float time, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  time = pulseIn(echoPin, HIGH);
  distance = (time/2)*0.0344;
  
  if (distance >= 400 || distance <= 2){
    lcd.print("Out of range");
    delay(2000);
  }else {
    lcd.print("Distance= ");
    lcd.print(distance);
    lcd.println(" cm");
    delay(2000);
  }

  currentDistance = distance;
  long changeDistance = currentDistance - previousDistance;
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(currentDistance);
  lcd.print(" cm");
  lcd.setCursor(0, 1);
  lcd.print("Change: ");
  lcd.print(changeDistance);
  lcd.print(" cm      ");
  previousDistance = currentDistance; 
  delay(2000);
  lcd.clear();
}
