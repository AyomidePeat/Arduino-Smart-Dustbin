#include <Servo.h> 
Servo myservo;  // 

const int trigPin = 3;  // the pins for the ultrasonic sensor
const int echoPin = 4;

long duration; 
int distance;  
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // set the trigPin as an output
  pinMode(echoPin, INPUT);  // set the echoPin as an input
  myservo.attach(9);  // attach the servo on pin 9
}

void loop() {
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH); // measure the duration of the sound wave
  distance = duration * 0.034 / 2;  // calculate the distance in centimeters

  if (distance < 20) {  // if the distance is less than 20 cm
    Serial.println("Object detected!"); 
    myservo.write(90);  // rotate the servo to 90 degrees
    delay(500);  
    myservo.write(0);  // rotate the servo back to 0 degrees
    delay(500);  
  }
}
