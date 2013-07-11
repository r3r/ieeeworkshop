//pin 1 is innermost pin or 1 inch mark

int pin1 =2;
int pin2 =4;
int pin3 =5;
int pin4 =7;
void setup()

{
 
 pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
   pinMode(pin3, INPUT);
    pinMode(pin4, INPUT);
    
    Serial.begin(9600);
}

void loop()

{

  int val1 = digitalRead(pin1);
  int val2 = digitalRead(pin2);
  int val3 = digitalRead(pin3);
  int val4 = digitalRead(pin4);
  
 // Serial.print(val2);
  Serial.print("\t");
   Serial.print(val4);
  Serial.print("\t");
   Serial.print(val1);
  Serial.print("\t");
   Serial.println(val2);

  
  
}

