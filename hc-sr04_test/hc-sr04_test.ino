// Constants
const int trigPin = 2;    // Trigger pin of HC-SR04 connected to Arduino digital pin 2
const int echoPin = 3;    // Echo pin of HC-SR04 connected to Arduino digital pin 3
const int ledPin = 13;    // LED pin connected to Arduino digital pin 13

// Variables
long duration;            // Time taken for the sound wave to travel
int distance;             // Calculated distance in centimeters

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Triggering the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measuring the echo duration
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance in centimeters
  distance = duration * 0.034 / 2;
  
  // Displaying the distance on the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Controlling the LED based on distance
  if (distance <= 10) {
    digitalWrite(ledPin, HIGH);   // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);    // Turn off the LED
  }
  
  delay(1000);  // Wait for 1 second before taking the next reading
}
