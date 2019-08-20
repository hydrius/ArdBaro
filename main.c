#include <SoftwareSerial.h>
#include <Wire.h>
#include <BaroSensor.h>


SoftwareSerial bt(2,3); // RX, TX

int thisByte = 33;

void setup() {
  bt.begin(9600);
  BaroSensor.begin();
  bt.println("ASCII Table ~ Character Map");
}

void loop() {

  bt.write(thisByte);
  bt.print(", dec: ");
  bt.print(thisByte);
  bt.print(", hex: ");
  bt.print(thisByte, HEX);
  bt.print(", oct: ");
  bt.print(thisByte, OCT);
  bt.print(", bin: ");
  bt.println(thisByte, BIN);

  if(thisByte == 126) {
    thisByte = 32;
  }
  thisByte++;



//test

 if(!BaroSensor.isOK()) {
    Serial.print("Sensor not Found/OK. Error: "); 
    Serial.println(BaroSensor.getError());
    BaroSensor.begin(); // Try to reinitialise the sensor if we can
  }
  else {
    Serial.print("Temperature: "); 
    Serial.println(BaroSensor.getTemperature());
    Serial.print("Pressure:    ");
    Serial.println(BaroSensor.getPressure());
  }
  delay(1000);



}


void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
 
}