const int LedPin = 13;
int ledState = 0;

void setup()
{ 
  pinMode(LedPin, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop()
{ 
    unsigned char receiveVal;   
   
    if(Serial.available() > 0)
    {        
        receiveVal = Serial.read();
        
       if(receiveVal == 66)  
       {
        Serial.write(88); 
        ledState = 1; 
        }  
       else
          ledState = 0;  
    }   
     
    digitalWrite(LedPin, ledState); 
      
    delay(50);    
}
