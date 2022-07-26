#include <Arduino.h>
#include <Servo.h>

// Analog pins
const int SvM = 5;
const int TmpS = 4;
// Servo varible
Servo servoM;
// D or DigitalPin 
const int Rly = 8;
const int R = 9;
const int G = 10;
const int B = 11;



void RlyOn(bool i) {
    if (i == true){
        digitalWrite(Rly, HIGH);
    }else
    {
        digitalWrite(Rly, LOW);
    }
    
}

void ReadTemp() {
    Serial.print("The Temp is" + analogRead(TmpS) + '\n');
}

void RGB() {
    digitalWrite(B,LOW);
    digitalWrite(R,HIGH);
    digitalWrite(G,LOW);
    delay(1000);
    digitalWrite(R,LOW);
    digitalWrite(G,HIGH);
    delay(1000);
    digitalWrite(G,LOW);
    digitalWrite(B,HIGH);
    delay(1000);
}

void RLYT(int i){
    // Relay Timer
    RlyOn(true);
    delay(i);
    RlyOn(true);
    delay(i);
}


void initailise() {
    Serial.begin(9600);
    Serial.print("Startup Initialisted And Ready");
    Serial.print("\nStatus 200 OK");
    servoM.attach(SvM);
}

void setup() {
    initailise();
}

void loop() {
    RlyOn(true);
    ReadTemp();
    RGB();
}