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
int soundbuzzer 3;
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
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/5) / 29.1;
 
  if (distanceincm < 50) {
      digitalWrite(LEDlampGreen, HIGH);
}
  else {
      digitalWrite(LEDlampGreen,  LOW);
  }
  
  if (distanceincm < 20) {
    digitalWrite(LEDlampBlue,  HIGH);
}
  else {
    digitalWrite(LEDlampBlue,LOW);
  }
  if (distanceincm < 5) {
    digitalWrite(LEDlampRed, HIGH);
    sound = 1000;
}
  else  {
    digitalWrite(LEDlampRed,LOW);
  }
 
  if (distanceincm > 5 ||  distanceincm <= 0){
    Serial.println("Outside the permissible range of distances");
    noTone(soundbuzzer);
  }
  else {
    Serial.print(distanceincm);
    Serial.println("  cm");
    tone(soundbuzzer, sound);
  }
  
  delay(300);
}
