
void setup() {
  pinMode(4, OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop() {
  int voicepitch=digitalRead(8);
  int analogValue = analogRead(A0);
  float voltage = analogValue * (5.0 / 1023.0);
  Serial.println(voicepitch);
  Serial.println(voltage);
  if(voicepitch=HIGH&&voltage>=3){
    digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(5000);
    digitalWrite(4, LOW); 
  }
  delay(1000);  
}
