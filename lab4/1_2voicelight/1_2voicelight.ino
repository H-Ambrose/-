int digital=8;
int value;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(4, OUTPUT);
  pinMode(digital, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  value=digitalRead(digital);
  if(value==HIGH){
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else if(value==LOW){                    
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  }
  //test output:
  //Serial.println(value);
  digitalWrite(4, LOW);
  delay(100);                       
}
