#include <Servo.h> 
const int trigPin = 9; const int echoPin = 10; const int servoPin = 6; 
Servo myServo; 
void setup() { Serial.begin(9600); pinMode(trigPin, OUTPUT); pinMode(echoPin, 
INPUT); myServo.attach(servoPin); } 
long getDistance() { digitalWrite(trigPin, LOW); delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); delayMicroseconds(10); digitalWrite(trigPin, LOW); 
long duration = pulseIn(echoPin, HIGH); long distance = duration * 0.034 / 2; return 
distance; } 
void loop() { for (int angle = 0; angle <= 180; angle += 15) { myServo.write(angle); 
delay(300); // Wait for servo to move 
long distance = getDistance(); 
Serial.print("Angle: "); 
Serial.print(angle); 
Serial.print("°, Distance: "); 
Serial.print(distance); 
Serial.println(" cm"); 
if (distance < 20 && distance > 0) { 
 Serial.println("⚠ Object detected!"); 
 // You can activate a buzzer or LED here 
} 
} 
for (int angle = 180; angle >= 0; angle -= 15) { myServo.write(angle); delay(300); 
long distance = getDistance(); 
Serial.print("Angle: ");
Serial.print(angle); 
Serial.print("°, Distance: "); 
Serial.print(distance); 
Serial.println(" cm"); 
if (distance < 20 && distance > 0) { 
 Serial.println("⚠ Object detected!"); 
} 
} }
