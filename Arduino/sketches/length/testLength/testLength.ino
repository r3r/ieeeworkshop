int pin1 = 2;
int pin2 = 4;
int pin3 = 5;
int pin4 = 7;


void setup(){
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.print(digitalRead(pin1)); Serial.print("\t");
  Serial.print(digitalRead(pin2)); Serial.print("\t");
  Serial.print(digitalRead(pin3)); Serial.print("\t");
  Serial.println(digitalRead(pin4)); 
  
}
