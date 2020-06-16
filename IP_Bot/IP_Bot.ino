#include <NewPing.h>

//Motor Driver
#define ENA=11
#define IN1=12
#define IN2=13

#define ENB=5
#define IN3=6
#define IN4=7


//UltraSonic
#define Tx=8
#define Rx=9
#define Max_Distance=100


#Calliberating Time
unsigned long previousMillis = 0;       

const long interval = 1000;
NewPing sonar(Tx,Rx,Max_Distance);


void setup() {
  Serial.begin(115200);
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  delay(1000);
}

void loop() {
  Serial.println("Scan");
  char ch=Serial.read();
  void Move(ch);
}

void move(char para)
{
  switch(para):
  {
    case 'M' :{           //For Moving bot includes stop before 20 cm
      if(sonar.ping_cm()>=23)
      {
        digitalWrite(IN1,HIGH);
        digitalWrite(IN2,LOW);
        analogWrite(ENA,255);
        digitalWrite(IN3,HIGH);
        digitalWrite(IN4,LOW);
        analogWrite(ENB,255);
      }
    }
    case 'R' :{           //For Rotating bot
        unsigned long CurrentMillis=millis();
        if(currentMillis-previousMillis<= interval){
        previousMillis=currentMillis;
        digitalWrite(IN1,HIGH);
        digitalWrite(IN2,LOW);
        analogWrite(ENA,200);
        digitalWrite(IN3,LOW);
        digitalWrite(IN4,HIGH);
        analogWrite(ENB,200);
        }
        else{
          Serial.println("Scan"); 
        }
      }       
  }
}

