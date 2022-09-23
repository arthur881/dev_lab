#include <Arduino.h>
#include <LiquidCrystal.h>


#define echoPin 8
#define trigPin 9

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


long duration;
int distance;


void setup() {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
    Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
    lcd.begin(16, 1);
}

void loop() {
    // Clears the trigPin condition
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    lcd.clear();

    if (distance < 70){
        lcd.print("reculez");
    }
    else if (distance > 70 && distance < 130)
    {
        lcd.print("don't move");

    }
    else{
        lcd.print("avancez");
    }
    Serial.println(" cm");
    

    delay(2000);
}