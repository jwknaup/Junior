#include "HX711.h"

HX711 load1(52, 53);
HX711 load2(50, 51);
HX711 load3(48, 49);
HX711 load4(46, 47);

double cal1 = -893000;
double cal2 = -886000;
double cal3 = -901000;
double cal4 = -875000;

void setup() {
  Serial.begin(9600);
  Serial.println("Force Plate");

  load1.set_scale(cal1); 
  load1.tare();
  load2.set_scale(cal2); 
  load2.tare(); 
  load3.set_scale(cal3); 
  load3.tare(); 
  load4.set_scale(cal4); 
  load4.tare(); 

  Serial.println("Readings:");
}

void loop() {
  float force1 = load1.get_units();
  float force2 = load2.get_units();
  float force3 = load3.get_units();
  float force4 = load4.get_units();

  double average = (force1+force2+force3+force4)/4.0;

  //Serial.print("Reading: ");
  //Serial.print(average, 4); //scale.get_units() returns a float
  //Serial.print(" kgs"); //You can change this to kg but you'll need to refactor the calibration_factor
//  Serial.print(force1);
//  Serial.print(", ");
//  Serial.print(force2);
//  Serial.print(", ");
//  Serial.print(force3);
//  Serial.print(", ");
//  Serial.println(force4);
  Serial.println(force1+force2+force3+force4, 5);
  delay(100);
}
