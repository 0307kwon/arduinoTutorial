float maxCm = 90;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  int duration, cm;

  digitalWrite(2,HIGH);
  delayMicroseconds(10); //10us 만큼 입력
  digitalWrite(2,LOW);

  duration = pulseIn(3,HIGH); // echo 핀의 HIGH->LOW 시간을 측정, 초기 시작상태 HIGH에서 LOW로 떨어질때까지 대기
  cm = getMicrosecondsToCm(duration);

  getLightON(cm);
  
/*  Serial.print(cm);
  Serial.println("cm");
*/
  delay(300);
}

void getLightON(int cm){
  float temp;
  if(cm > maxCm){
    temp = 255;
  }else{
    temp = cm/maxCm*255;
  }
  Serial.println(temp);
  analogWrite(5,temp);
}

int getMicrosecondsToCm(int duration){
  return duration/29/2;
}
