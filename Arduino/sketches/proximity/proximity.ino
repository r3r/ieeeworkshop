#include <math.h>


int ProximRx = 7; //For Continous Chaining
int bw = 2;
int correctionFactor = 5;
int avgBoundaryDist = 70;
void setup(){
  pinMode(bw, OUTPUT);
  digitalWrite(bw, HIGH);
  initializeProxim();
  Serial.begin(9600);
}

void loop(){
  while (fabs(readProxim(A2) - readProxim(A4)) <= correctionFactor && readProxim(A2) > avgBoundaryDist - correctionFactor){}//Delay until second sensor starts reading the block
  
  while (fabs(readProxim(A2) - readProxim(A4)) > correctionFactor  ){}//Delay until first block also starts reading the block
  Serial.println("pick up block now");
}

void initializeProxim(){
 
  pinMode(ProximRx, OUTPUT);
  delay(250);
  digitalWrite(ProximRx, HIGH);
  delay(20);
  digitalWrite(ProximRx, LOW);
  delay(50);
}

int readProxim(int pin){
    digitalWrite(ProximRx, HIGH);
    delay(20);
    digitalWrite(ProximRx, LOW);
    delay(50);
    
    return analogRead(pin);
}
  
  
