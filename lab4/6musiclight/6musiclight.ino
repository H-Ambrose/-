
void setup() {
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(A0);
  //float voltage = analogValue * (5.0 / 1023.0);
  Serial.println(analogValue);
  int brightness=analogValue/4+90;
  analogWrite(4, brightness);
  delay(1000);  
}
