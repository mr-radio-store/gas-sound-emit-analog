/*
Gas with analog emit sound

Components Needed:
    Gas Sensor: A MQ sensor (like MQ-2, MQ-7, MQ-135).
    Buzzer (either passive or active).
    Arduino: Arduino Uno, Nano, or any other compatible board.
    Jumper wires and breadboard.
Wiring the Components:

    Gas Sensor (e.g., MQ-2):
        VCC → Connect to 5V on Arduino.
        GND → Connect to GND on Arduino.
        Analog Output (A0) → Connect to Analog Pin A0 on Arduino.
        Digital Output (D0) → Connect to a Digital Pin (e.g., Pin 8) 
        on Arduino (optional, if using digital output).
    Buzzer:
        VCC → Connect to 5V (or 3.3V if you have a 3.3V buzzer).
        GND → Connect to GND on Arduino.
        Signal Pin → Connect to Digital Pin (e.g., Pin 9) on Arduino.
        Result Analog 
        Explanation:

    Explanation for Analog Output:
    Analog Pin (A0): The analogRead() function reads the gas concentration 
    level, which is a value between 0 and 1023. This value represents the 
    intensity of the detected gas.
    Threshold: The threshold (400 in this case) can be adjusted to define 
    the level at which you want the buzzer to sound. When the gas concentration 
    exceeds this threshold, the buzzer will sound.
*/


// Define pins for sensor and buzzer for analog
const int gasSensorPin = A0;  // Analog output from the gas sensor
const int buzzerPin = 9;      // Pin connected to buzzer
int sensorValue = 0;          // Variable to store the sensor reading

void setup() {
  pinMode(buzzerPin, OUTPUT);  // Set the buzzer pin as output
  Serial.begin(9600);          // Initialize Serial Monitor
}

void loop() {
  sensorValue = analogRead(gasSensorPin);  // Read the analog value from the gas sensor
  
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);  // Print the sensor value to Serial Monitor
  
  // If the gas concentration exceeds a certain threshold (e.g., 400)
  if (sensorValue > 400) {
    Serial.println("Gas detected!");
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
  } else {
    Serial.println("No gas detected.");
    digitalWrite(buzzerPin, LOW);   // Turn off the buzzer
  }
  
  delay(500);  // Delay to make it readable in the serial monitor
}

