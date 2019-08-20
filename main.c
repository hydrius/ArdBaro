#include <SoftwareSerial.h>
#include <Wire.h>
#include <BaroSensor.h>


SoftwareSerial bt(2,3); // RX, TX

int thisByte = 33;
bool connected = false;

void setup() {
  bt.begin(9600);
  BaroSensor.begin();
  bt.println("ASCII Table ~ Character Map");
  unixtime = 1566289552; //2019-08-20 @ ~1830.
}

void loop() {

  // Keep this to determine what type is being transmitted.
  // Answer is dec?
  if(bt.available() > 0 ){
    bt.write(thisByte);
    bt.print(", dec: ");
    bt.print(thisByte);
    bt.print(", hex: ");
    bt.print(thisByte, HEX);
    bt.print(", oct: ");
    bt.print(thisByte, OCT);
    bt.print(", bin: ");
    bt.println(thisByte, BIN);

    // Do I need to send bytes?? 
    // Do I need to translate from ASCII to Bytes? LETS HOPE NOT!
    if(thisByte == 126) {
      thisByte = 32;
    }
    thisByte++; 


    if(!BaroSensor.isOK()) {
        Serial.print("Sensor not Found/OK. Error: "); 
        Serial.println(BaroSensor.getError());
        BaroSensor.begin(); // Try to reinitialise the sensor if we can
        bt.write("32"); // lol
      }
      else {
        Serial.print("Temperature: "); 
        Serial.println(BaroSensor.getTemperature());
        bt.write(BaroSensor.getTemperature());
        Serial.print("Pressure:    ");
        Serial.println(BaroSensor.getPressure());
        bt.write(BaroSensor.getPressure());

      }
      delay(1000);
  }

}


