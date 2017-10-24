void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);//en
  pinMode(3, OUTPUT);//ph
  
  pinMode(6, OUTPUT);//en
  pinMode(7, OUTPUT);//ph

  while(!Serial.available()){
    delay(20);
  }

  analogWrite(2,255);
  digitalWrite(3,0);
  
  analogWrite(6,255);
  digitalWrite(7,1);

  delay(2000);
  analogWrite(2,0);
  
  analogWrite(6,0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
