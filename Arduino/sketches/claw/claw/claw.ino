/*
API - SERVO
USAGE:
Use Serial Monitor to open and close claw, send any input to the chip after loading script
Author: Ritesh Reddy
*/

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int change = 0;

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(115200);
  
} 
 
 
 
void loop() 
{ 
  
  // send data only when you receive data:
  if (Serial.available() > 0) {
    if (change){
        openClaw();
      }
      else
      {
        closeClaw();
      }
      change = !change;
  }
}

void openClaw(){
  for(pos = 43; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}

void closeClaw(){
  for(pos = 0; pos < 42; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}
