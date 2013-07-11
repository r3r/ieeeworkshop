#include <ADJDS311.h>
#include <Wire.h>
#include <Math.h>

int sensorLed_pin = 2; //LED on the ADJDS-311
ADJDS311 colorSensor(sensorLed_pin);



RGBC SUN_YELLOW_RGB(1023, 877, 571);
RGBC REAL_ORANGE_RGB(1023, 837, 552);
RGBC KONA_BROWN_RGB(1012,810,545);
RGBC HUNTER_GREEN_RGB(1023, 954, 602);
RGBC COLONIAL_RED_RGB(931,750,492);
RGBC BRILLIANT_BLUE_RGB(1023,894,591);

RGBC RGB[] = {SUN_YELLOW_RGB, REAL_ORANGE_RGB, KONA_BROWN_RGB, HUNTER_GREEN_RGB, COLONIAL_RED_RGB, BRILLIANT_BLUE_RGB};

int SUN_YELLOW = 0;
int REAL_ORANGE = 1;
int KONA_BROWN = 2;
int HUNTER_GREEN =3 ;
int COLONIAL_RED = 4;
int BRILLIANT_BLUE = 5;


//if using an RGB LED (Needs PWM Pins)
int redPin = 3;
int greenPin = 5;
int bluePin = 6;

void setup(){
  Serial.begin(9600);
  colorSensor.ledOn(); //turn LED on
  colorSensor.init();
  
  
  
  //Calibrate white 
  //Need to hold white card in front (1-3mm) of it to calibrate from
  colorSensor.calibrate(); 
  colorSensor.ledOff(); //turn LED off
}

void loop(){
  if(Serial.available()){
    Serial.read();
    colorSensor.ledOn(); //turn LED on
  
    RGBC color = colorSensor.read(); //read the color
    colorSensor.ledOff();
    Serial.print(color.red);
    Serial.print(" | ");
    Serial.print(color.green);
    Serial.print(" | ");
    Serial.print(color.blue);
    Serial.print(" | ");
    Serial.print(color.clear);
    Serial.print(" | ");
    //lightLED(color); //send color to the LED
    Serial.println(getColor(color));
  }  
 
  
}

void lightLED(RGBC color){
  //RGBC is an array of red/green/blue/clear readings 
  //Take a RGBC, and try to reproduce it on an RGB LED
  //This does not work very well as is because of how colors/our eyes work
  
  analogWrite(redPin, map(color.red, 0, 1024, 0, 255));
  analogWrite(greenPin, map(color.green, 0, 1024, 0, 255));
  analogWrite(bluePin, map(color.blue, 0, 1024, 0, 255));
}

int getColor(RGBC color){
  float minimum = 1000;
  int minColor = 0;
  for (int i = 0; i< 6; i++){
    int test = getDifference(color, i);
    if (test < minimum){
      minimum = test;
      minColor = i;
    }
  }
  return minColor;
}

float getDifference(RGBC color, int i){
  RGBC tColor = RGB[i];
  
  float r = square(color.red - tColor.red);
  float g = square(color.green - tColor.green);
  float b = square(color.blue - tColor.blue);

  return sqrt(r + g + b);
}
      

int getColorCode(RGBC color){
    int minimum = 1000;
    int minColor = SUN_YELLOW;
    
    int tolerance = 1;
    boolean found = false;
    while (!found){
      for(int i = 0; i<6; i++){
        int match = colorMatch(color, i, tolerance);
        if(match < minimum && match != -1){
          found = true;
          minimum = match;
          minColor = i;
        }
      }
      if (!found)
        tolerance += 1;        
    }
    return minColor;
}

int colorMatch(RGBC c, int i, int tolerance){
     int match = -1;
     RGBC testC = RGB[i];
    
     byte red = fabs(testC.red- c.red);
     byte green = fabs(testC.green - c.green);
     byte blue = fabs(testC.blue- c.blue);
     if(red <= tolerance && green <= tolerance && blue <= tolerance){
       match = red + green + blue;
     }
     
     return match;
}  
      
   
          
