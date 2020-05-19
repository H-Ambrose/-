void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(A0);
  float voltage = analogValue * (5.0 / 1023.0);
  Serial.println(voltage);
  
  if(voltage>=2.5){
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else {                    
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  }
  delay(1000);        // delay in between reads for stability
}
