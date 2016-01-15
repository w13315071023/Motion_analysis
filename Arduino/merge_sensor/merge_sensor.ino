/*
 * 14.Jan.2016:
 * combine sound sensor with laser sensor to one project
 * detect hit ball motion
 * send a signal num to PC by uart 9600 8N1
 * send to PC signal num explanation:
 * 0: no ball no hit
 * 1: has ball no hit
 * 2: has ball hit valid
 * 3; has ball hit invalid
 * sound sensor pinMap:
 * PIN MAP
 * DOUT  D2
 * AOUT  A0
 * GND   GND
 * VCC   5V
 * laser sensor pinMap:
 * DOUT D12
 * GND  GND
 * VCC  5V
 */
int sound_din = 2;
int sound_ain = A0;
int sound_advalue; 
int laser_din = 12;
int connect_en = 0;
const int LedPin = 13;
void setup() {
     pinMode(sound_din,INPUT);
     pinMode(sound_ain,INPUT);
     pinMode(laser_din,INPUT);
     Serial.begin(9600); //default 8N1
}
void loop() 
{  
 // Serial.write(9);  //connect PC hook
  if(digitalRead(laser_din)==LOW) //has ball
    {   
      if(digitalRead(sound_din)==LOW) //detect hit
        {
            sound_advalue = analogRead(sound_ain);
            if(sound_advalue>450) //adjust sensitivity
              {
                 Serial.write(2);
               }
             else
               {
                Serial.write(3);           
               }
         } 
       else
        {
           Serial.write(1);
         }
    }
  else  //no ball
    {
      Serial.write(0);
     }
 delay(500); //ms 
}
