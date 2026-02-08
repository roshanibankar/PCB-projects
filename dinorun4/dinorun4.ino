#include <Servo.h>

const int LDRPin = A0;    
const int threshold = 22; 
Servo dinoServo;
const int servoPin = 9;   

bool servoEnabled = false;  // Initially set the servo to be disabled

void setup() {
  pinMode(LDRPin, INPUT);
  dinoServo.attach(servoPin);
  dinoServo.write(90);  
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  int LDRValue = analogRead(LDRPin);
  Serial.println(LDRValue); 

  if (servoEnabled && LDRValue < threshold) {  
    jump(); 
  }

  // Check for Bluetooth commands
  if (Serial.available()) {
    char command = Serial.read();
    if (command == '1') {
      servoEnabled = true;  // Enable servo
      Serial.println("Servo Enabled");
      jump();
    } else if (command == '0') {
      servoEnabled = false;  // Disable servo
      Serial.println("Servo Disabled");
    }
  }
  
  delay(5);  // Small delay
}

void jump() {
  dinoServo.write(45);  // Dino jumps (moving the servo to 45 degrees)
  delay(250);         
  dinoServo.write(90);  
  delay(250);           
}
