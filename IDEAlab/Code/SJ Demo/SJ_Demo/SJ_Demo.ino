void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);//en
  pinMode(3, OUTPUT);//ph
  
  pinMode(6, OUTPUT);//en
  pinMode(7, OUTPUT);//ph

//  while(!Serial.available()){
//    delay(20);
//  }

  analogWrite(2,255);
  digitalWrite(3,0);
  
  analogWrite(6,255);
  digitalWrite(7,1);

  for(int i=0; i<100;i++){
    //if(Serial.available()){
      //if(Serial.read()){
        Serial.write(2);
        //delay(1);
     // }
   // }
    
 }
 Serial.write('\n');
}

void loop() {
  // put your main code here, to run repeatedly:

  
  analogWrite(2,0);
  analogWrite(6,0);
}

float readCurrent(int A){
  float voltage = 3.3*analogRead(A)/4092.0;
  return voltage;
}

