#include <Ultrasonic.h>
#include <Servo.h>
#define LeftP 5   //Left_P
#define LeftN 11  //Left_N
#define RightP 6  //Right_P
#define RightN 3  //Right_N
#define AnglePWM 63 //inside motor speed of car turn
#define limit 20 //cm, distance limit to obstacle
#define comp_Front 7 //front distance compensation
#define comp_Rear 4 //rear distance compensation
#define vth_Batt 7400 //mV, Low Battery

Ultrasonic ultra_Front(18, 17);   // (Trig PIN, Echo Pin)
Ultrasonic ultra_Rear(16, 15);    // (Trig PIN, Echo Pin)
Servo myservo;

String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete

int distance_Front, distance_Rear, i;
long volt_Batt;

void motor_F()//前进
{
  myservo.write(90);
  digitalWrite(LeftP,HIGH);
  digitalWrite(LeftN,LOW);
  digitalWrite(RightP,HIGH);
  digitalWrite(RightN,LOW);
}

void motor_B()//后退
{
  // 请补充代码
  myservo.write(90);
  digitalWrite(LeftP,LOW);
  digitalWrite(LeftN,HIGH);
  digitalWrite(RightP,LOW);
  digitalWrite(RightN,HIGH);
}

void motor_L()//左
{
  myservo.write(45); 
  digitalWrite(LeftP,LOW);
  digitalWrite(LeftN,LOW);
  digitalWrite(RightP,HIGH);
  digitalWrite(RightN,LOW);
}

void motor_R()//右
{
  // 请补充代码
  myservo.write(145);
  digitalWrite(LeftP,HIGH);
  digitalWrite(LeftN,LOW);
  digitalWrite(RightP,LOW);
  digitalWrite(RightN,LOW);
}


void motor_S()//停止
{
  digitalWrite(LeftP,HIGH);
  digitalWrite(LeftN,HIGH);
  digitalWrite(RightP,HIGH);
  digitalWrite(RightN,HIGH);
}

void motor_I()//Idle
{
  digitalWrite(LeftP,LOW);
  digitalWrite(LeftN,LOW);
  digitalWrite(RightP,LOW);
  digitalWrite(RightN,LOW);
}

void motor_FL()//前进左
{
  myservo.write(45);
  analogWrite(LeftP,AnglePWM);
  digitalWrite(LeftN,LOW);
  digitalWrite(RightP,HIGH);
  digitalWrite(RightN,LOW);
}

void motor_FR()//前进右
{
  // 请补充代码
  myservo.write(135);
  analogWrite(LeftP,HIGH);
  digitalWrite(LeftN,LOW);
  digitalWrite(RightP,AnglePWM);
  digitalWrite(RightN,LOW);
}

void motor_BL()//后退左
{
  myservo.write(135);
  digitalWrite(LeftP,LOW);
  analogWrite(LeftN,AnglePWM);
  digitalWrite(RightP,LOW);
  digitalWrite(RightN,HIGH);
}

void motor_BR()//后退右
{
  // 请补充代码
  myservo.write(45);
  digitalWrite(LeftP,LOW);
  analogWrite(LeftN,HIGH);
  digitalWrite(RightP,LOW);
  digitalWrite(RightN,AnglePWM);
}

void setup() {
  // initialize serial:
  Serial.begin(38400);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  pinMode(LeftP,OUTPUT);
  pinMode(LeftN,OUTPUT);
  pinMode(RightP,OUTPUT);
  pinMode(RightN,OUTPUT);
  myservo.attach(9);
  motor_I();
  myservo.write(90);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    distance_Front = ultra_Front.getDistanceInCM() - comp_Front;
    distance_Rear  =  ultra_Rear.getDistanceInCM() - comp_Rear;

    Serial.print(distance_Front);
    
    if ((distance_Front < limit) & (distance_Rear < limit)) {//前后都有障碍
      Serial.println("Close to BOTH Obstacles!");
      Serial.print("Front: ");
      Serial.print(distance_Front);
      Serial.print("cm. Rear: ");
      Serial.print(distance_Rear);
      Serial.println("cm.");
      inputString = "Stop";
      delay(20);
    }
    else if ((distance_Front < limit) & (distance_Rear >= limit)) {//前有障碍 后无障碍
      Serial.println("Close to Front Obstacle. AUTO-BACK.");
      Serial.print("Front: ");
      Serial.print(distance_Front);
      Serial.println("cm.");
      inputString = "Back";
      delay(20);
    }
    else if ((distance_Front >= limit) & (distance_Rear < limit)) {//后有障碍 前无障碍
      // 请补充代码
      Serial.println("Close to Rear Obstacle. AUTO-FRONT.");
      Serial.print("Back: ");
      Serial.print(distance_Rear);
      Serial.println("cm.");
      inputString = "Forward";
      delay(20);
    }

    volt_Batt = 0;
    for(i=0; i<100; i++) {
      volt_Batt += long(analogRead(A0));      
      delayMicroseconds(100);
    }
    volt_Batt = volt_Batt * 50 * 11 / 1024;
    if(volt_Batt < vth_Batt) {
      Serial.print("Low Battery! Voltage: ");
      Serial.print(volt_Batt);
      Serial.println("mV.");
      inputString = "Idle";
      delay(20);
      }
    if(inputString != "Idle") Serial.println(inputString);
    if(inputString == "Forward")    motor_F();
    else if(inputString == "Back")  motor_B();
    else if(inputString == "Left")  motor_L();
    else if(inputString == "Right") motor_R();
    else if(inputString == "Stop")  motor_S();
    else if(inputString == "Idle")  motor_I();
    else if(inputString == "Forward Left")  motor_FL();
    else if(inputString == "Forward Right") motor_FR();
    else if(inputString == "Back Left")     motor_BL();
    else if(inputString == "Back Right")    motor_BR();
    else if(inputString == "Read")  {
      Serial.print("Front: ");
      Serial.print(distance_Front);
      Serial.print("cm. Rear: ");
      Serial.print(distance_Rear);
      Serial.println("cm.");
      Serial.print("Battery: ");
      Serial.print(volt_Batt);
      Serial.println("mV.");
      motor_I();
    }
    else  Serial.println("Invalid Command! ' Forward / Back / Left / Right / Stop "
    "/ Idle ' only.");
    // clear the string:
    inputString = "";
    stringComplete = false;
    delay(10);
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    if ((inChar != '\r') & (inChar != '\n')) inputString += inChar;
        // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
