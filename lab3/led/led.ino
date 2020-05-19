
int led1=9,led2=11,led3=3;
int bright1=0,bright2=0,bright3=0;
//led1 红，led2 绿，led3 蓝

void setup() {
  // iterate over the notes of the melody:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  //no need to repeat the melody.
for(int j=0;j<256;j++)
  for(int i=0;i<256;i++)
    for(int k=0;k<256;++k){
      analogWrite(led1,i);//i代表红灯的亮度
      analogWrite(led2,j);//j代表绿灯的亮度
      analogWrite(led3,k);//k代表蓝灯的亮度
      delay(1);
    }
}
