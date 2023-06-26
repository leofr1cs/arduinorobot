// Motor A connections
const int motorAPin1 = 2;   // Motor A - Input 1
const int motorAPin2 = 3;   // Motor A - Input 2
const int motorAPwmPin = 9; // Motor A - PWM input

// Motor B connections
const int motorBPin1 = 4;   // Motor B - Input 1
const int motorBPin2 = 5;   // Motor B - Input 2
const int motorBPwmPin = 10; // Motor B - PWM input

// HC-SR04 sensor connections
const int trigPin = 6;      // Trigger pin of HC-SR04 connected to Arduino digital pin 6
const int echoPin = 7;      // Echo pin of HC-SR04 connected to Arduino digital pin 7

const int safeDistance = 15;  // Safe distance to avoid obstacles in centimeters

void setup() {
  // Set motor pins as outputs
  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  pinMode(motorAPwmPin, OUTPUT);
  pinMode(motorBPin1, OUTPUT);
  pinMode(motorBPin2, OUTPUT);
  pinMode(motorBPwmPin, OUTPUT);

  // Set HC-SR04 sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  int distance = measureDistance();  // Measure the distance using the HC-SR04 sensor
  
  if (distance > safeDistance) {
    moveForward();  // If the distance is safe, move forward
  } else {
    avoidObstacle();  // If an obstacle is detected, avoid it
  }
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

void avoidObstacle() {
  // Stop motors
  stopMotors();
  
  // Turn right for a short duration
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, HIGH);
  analogWrite(motorAPwmPin, 150); // Set PWM speed
  
  digitalWrite(motorBPin1, HIGH);
  digitalWrite(motorBPin2, LOW);
  analogWrite(motorBPwmPin, 150); // Set PWM speed
  
  delay(1000);  // Delay to turn right
  
  // Move backward for a short duration
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, HIGH);
  analogWrite(motorAPwmPin, 200); // Set PWM speed
  
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, HIGH);
  analogWrite(motorBPwmPin, 200); // Set PWM speed
  
  delay(1000);  // Delay to move backward
  
  // Turn left for a short duration
  digitalWrite(motorAPin1, HIGH);
  digitalWrite(motorAPin2, LOW);
  analogWrite(motorAPwmPin, 150); // Set PWM speed
  
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, HIGH);
  analogWrite(motorBPwmPin, 150); // Set PWM speed
  
  delay(1000);  // Delay to turn left
}

void stopMotors() {
  // Motor A
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, LOW);
  
  // Motor B
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, LOW);
}

int measureDistance() {
  // Triggering the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measuring the echo duration
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance in centimeters
  int distance = duration * 0.034 / 2;
  
  // Displaying the distance on the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  return distance;
}
