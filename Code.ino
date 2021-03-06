int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);

}

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  
  int speed = 0;
  if(cm>255){speed = 255;}
  else{speed = cm;}
  
  if(speed<=50){
    analogWrite(11, 0);
    digitalWrite(2, 1);
    }
  else{
    analogWrite(11, speed);
    digitalWrite(2, 0);
  }
  Serial.print(cm);
  Serial.println("cm");
  delay(100); 
}
