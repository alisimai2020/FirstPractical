  // Include NewPing Library
  //int x=0;
#include <NewPing.h>
// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 12
#define ECHO_PIN 3

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 4000

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int thingDistance ;
int ldrstatus = 0 ;
const int ledPin = 8;
const int ldrPin = A0;

int lightstatus =0;

void setup() {
  
  // put your setup code here, to run once:
    Serial.begin(38400);
    pinMode(ledPin,OUTPUT);
    digitalWrite(ledPin, HIGH);
    pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Distance = ");

 thingDistance = sonar.ping_cm();
  Serial.print(thingDistance);
  Serial.println(" cm");


   ldrstatus = analogRead(A0);
     Serial.print("ldr: ");
     Serial.print(ldrstatus);
     Serial.print(" Status: ");
     Serial.println(lightstatus);
  
    if (ldrstatus <= 100 ) {
      
      Serial.println(" - dark");
      if(thingDistance <=100 && lightstatus ==0  && thingDistance != 0){
        lightstatus = 1;
         digitalWrite(ledPin, LOW);
      }else if(thingDistance >100 && lightstatus ==1){
         digitalWrite(ledPin, HIGH);
         lightstatus = 0;
      }
    
     
  } else if(ldrstatus >100  && lightstatus ==1){
      lightstatus = 0;
      digitalWrite(ledPin, HIGH);
      Serial.println("- bright ");

  }
//    if (x==0){
//    thingDistance++;
//    }else{
//      thingDistance--;
//    }
//    
//    if(thingDistance>110){
//      x=1;
//    }else if(thingDistance<=90){
//      x=0;
////    }


  delay(1000);



}
