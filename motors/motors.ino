// Motor A connections
const int motorAPin1 = 2;   // Motor A - Input 1
const int motorAPin2 = 3;   // Motor A - Input 2
const int motorAPwmPin = 9; // Motor A - PWM input

// Motor B connections
const int motorBPin1 = 4;   // Motor B - Input 1
const int motorBPin2 = 5;   // Motor B - Input 2
const int motorBPwmPin = 10; // Motor B - PWM input

void setup() {
  // Set motor pins as outputs
  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  pinMode(motorAPwmPin, OUTPUT);
  pinMode(motorBPin1, OUTPUT);
  pinMode(motorBPin2, OUTPUT);
  pinMode(motorBPwmPin, OUTPUT);
}

void loop() {
  // Move forward
  moveForward();
  delay(2000);
  
  // Move backward
  moveBackward();
  delay(2000);
  
  // Turn left
  turnLeft();
  delay(2000);
  
  // Turn right
  turnRight();
  delay(2000);
  
  // Stop
  stopMotors();
  delay(2000);
}

void moveForward() {
  // Motor A
  digitalWrite(motorAPin1, HIGH);
  digitalWrite(motorAPin2, LOW);
  analogWrite(motorAPwmPin, 255); // Set PWM speed
  
  // Motor B
  digitalWrite(motorBPin1, HIGH);
  digitalWrite(motorBPin2, LOW);
  analogWrite(motorBPwmPin, 255); // Set PWM speed
}

void moveBackward() {
  // Motor A
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, HIGH);
  analogWrite(motorAPwmPin, 255); // Set PWM speed
  
  // Motor B
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, HIGH);
  analogWrite(motorBPwmPin, 255); // Set PWM speed
}

void turnLeft() {
  // Motor A
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, HIGH);
  analogWrite(motorAPwmPin, 255); // Set PWM speed
  
  // Motor B
  digitalWrite(motorBPin1, HIGH);
  digitalWrite(motorBPin2, LOW);
  analogWrite(motorBPwmPin, 255); // Set PWM speed
}

void turnRight() {
  // Motor A
  digitalWrite(motorAPin1, HIGH);
  digitalWrite(motorAPin2, LOW);
  analogWrite(motorAPwmPin, 255); // Set PWM speed
  
  // Motor B
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, HIGH);
  analogWrite(motorBPwmPin, 255); // Set PWM speed
}

void stopMotors() {
  // Motor A
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, LOW);
  
  // Motor B
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, LOW);
}
