//Programmer: Patrick Condon
//Date: 3.16.2023
//Program: Blind Spot Monitor

/*This Program will determine distances to 
 *approaching vehicles that are in your
 *blind spot*/

int trigPin = 7;
int echoPin = 6;
int LEDlampGreen = 9;
int  LEDlampRed = 10;
int LEDlampBlue = 11;
int soundbuzzer = 3;
int sound  = 500;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampBlue,  OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}
void  loop() {
  long durationindigit, distanceinft;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceinft = (durationindigit/5) / 29.1;

  if (distanceinft > 10) {
    Serial.println("We have not detected anything in your blind spot - Change lanes when needed");
    delay(2000);
}
  else {
        if (distanceinft < 10) {
            digitalWrite(LEDlampGreen, HIGH);
            Serial.println("Be cautious when changing lanes");
}
        else {
            digitalWrite(LEDlampGreen,  LOW);
  }
  
        if (distanceinft < 7.5) {
          digitalWrite(LEDlampBlue,  HIGH);
          Serial.println("Be very cautious when changing lanes");
}
        else {
          digitalWrite(LEDlampBlue,LOW);
  }
        if (distanceinft < 5) {
          digitalWrite(LEDlampRed, HIGH);
          sound = 1000;
          Serial.println("DO NOT CHANGE LANES");
}
        else  {
          digitalWrite(LEDlampRed,LOW);
  }
       Serial.print(distanceinft);
    Serial.println("  ft away");
  delay(2000);
}}
