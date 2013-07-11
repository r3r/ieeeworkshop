//pin 1 is innermost pin or 1 inch mark
int determineLength(int pin1, int pin2, int pin3, int pin4){
  int val1 = digitalRead(pin1);
  int val2 = digitalRead(pin2);
  int val3 = digitalRead(pin3);
  int val4 = digitalRead(pin4);
  
  if (val4) 
    return 4;
  else
    if(val3)
      return 3;
    else
      if(val2)
        return 2;
      else
        if(val1)
          return 1;
        else
          return 0;
   
    
