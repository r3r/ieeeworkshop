int pin1 =2;
int pin2 =4;
int pin3 =5;
int ProximRx = 7; //For Continous Chaining

void setup(){
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
   initializeProxim();

  Serial.begin(9600);
  
}

void loop(){
  int val1 = digitalRead(pin1);
  int val2 = digitalRead(pin2);
  int val3 = digitalRead(pin3);
  
  Serial.print("\t");
  Serial.print(val1);
  Serial.print("\t");
  Serial.print(val2);
  Serial.print("\t");
  Serial.print(val3);
  Serial.print(readProxim(A2)); Serial.print("\t");
  Serial.println(readProxim(A4));
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
  
