int ledPin = 4;                // Pin LED is connected to
int buzzerPin = 3;             // Pin Piezo Buzzer is connected to
int pirSensorPin = 2;          // Pin PIR Sensor is connected to

int motionDetected = LOW;      // Start MotionDetected as LOW (No motion detected)
unsigned long lastMotionTime = 0;  // Store last motion detection time
const int cooldownTime = 5000; // Cooldown time (5 seconds)

void setup() {
  pinMode(ledPin, OUTPUT);  
  pinMode(pirSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600); 
  Serial.println("Starting");
  delay(30000); // Allow time for the PIR Sensor to calibrate
}

void loop(){
  motionDetected = digitalRead(pirSensorPin);  // Read the PIR sensor

  if (motionDetected == HIGH && millis() - lastMotionTime > cooldownTime) {      
    Serial.println("Motion Detected");
    lastMotionTime = millis();  // Update the last motion time
    
    // Turn on LED and buzzer for a short duration
    digitalWrite(ledPin, HIGH);
    analogWrite(buzzerPin, 200);
    delay(100);
    
    digitalWrite(ledPin, LOW);
    analogWrite(buzzerPin, 25);
    delay(100);
    
    digitalWrite(buzzerPin, LOW);
  }

  delay(50);  // Small delay to stabilize readings
}
