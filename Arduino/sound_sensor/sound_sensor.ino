/*
 * PIN MAP
 * DOUT  D2
 * AOUT  A0
 * GND   GND
 * VCC   5V
 * clockwise rotation to four pins,Increase the sensitivity
 */
 
 int sound_din = 2;
 int sound_ain = A0;
 int ad_value; 
 void setup()
 {
     pinMode(sound_din,INPUT);
     pinMode(sound_ain,INPUT);
     Serial.begin(9600); //default 8N1
  }
  void loop()
  {
    ad_value = analogRead(sound_ain);
    if(digitalRead(sound_din)==LOW) //detect voice become LOW
    {
      Serial.println("detect voice");
      Serial.println(ad_value);
     } 
      delay(500); //ms   
   }
 
