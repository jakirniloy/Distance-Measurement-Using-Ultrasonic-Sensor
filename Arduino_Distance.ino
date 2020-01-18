int trigPin=13;//sonar trig pin connected to arduino pin
int echoPin=11;// sonar echo pin connected to arduino pin
float pingTime;
float targetDistance;
float speedOfSound=776.5;


void setup(){
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  }

void loop(){
digitalWrite(trigPin,LOW);
delayMicroseconds(2000);
digitalWrite(trigPin,HIGH);
delayMicroseconds(15);
digitalWrite(trigPin,LOW);

pingTime=pulseIn(echoPin,HIGH);//measure pingechotime at echo
pingTime=pingTime/1000000.0;//cnvrt ping time to sec
pingTime=pingTime/3600.0;//cnvrt ping time to hrs

targetDistance=speedOfSound*pingTime;
targetDistance=targetDistance/2;
targetDistance=targetDistance*63360;

Serial.print("The distance to the target is:");
Serial.print(targetDistance);
Serial.println("inches");
delay(1000);





  
}
