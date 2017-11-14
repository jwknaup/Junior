#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Encoder.h>

  Adafruit_INA219 ina219;
  Encoder leftEnc(4, 5);
  
void setup() {
  Serial.begin(115200);

  //analogReadResolution(12);
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);//en
  pinMode(3, OUTPUT);//ph
  
  pinMode(6, OUTPUT);//en
  pinMode(7, OUTPUT);//ph

  uint32_t currentFrequency;
  
  ina219.begin();

  //Serial.println("Measuring voltage and current with INA219 ...");

  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }

  analogWrite(2,255);
  digitalWrite(3,0);
  
  analogWrite(6,255);
  digitalWrite(7,1);
  
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  int leftCount=0;
  

  while(1){
  

    shuntvoltage = ina219.getShuntVoltage_mV();
    busvoltage = ina219.getBusVoltage_V();
    current_mA = ina219.getCurrent_mA();
    loadvoltage = busvoltage + (shuntvoltage / 1000);

    leftCount = leftEnc.read();

    transmit = String(loadvoltage,DEC)+String(" ")+String(current_mA,DEC)+String(" ")+String(leftCount, DEC);
  Serial.println(transmit);

//        Serial.print(loadvoltage); Serial.print(' ');
//        Serial.print(current_mA);
//        Serial.write('\n');
    
    //delay(1);
    
 }
  analogWrite(2,0);
  analogWrite(6,0);
}

void loop() {
  // put your main code here, to run repeatedly:

}

