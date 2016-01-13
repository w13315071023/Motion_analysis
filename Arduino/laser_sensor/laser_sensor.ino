/*
 * PIN MAP
 * DOUT D2
 * GND GND
 * VCC 5V
 * Dout is low,has ball
 * Dout is HIGH,no ball
 */
int laser_din = 2;
void setup() {
  pinMode(laser_din,INPUT);
  Serial.begin(9600);
}
void loop() {
  if(digitalRead(laser_din)==LOW)
    {
      Serial.println("has ball");
    }
  else
    {
      Serial.println("no ball");
    }
}
