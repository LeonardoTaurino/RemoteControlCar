#include <Servo.h>
#include <SoftwareSerial.h>

//Serial_BT
SoftwareSerial BT(2,3); //2=tx; 3=rx
// PIN
int speedPin = 11;
int dirPin1 = 5;
int dirPin2 = 6;
int servoPin = 9;
//control var
Servo myServo;
int inputVar=0;
//variable
int speedVal=0;
int rotationVal=96;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
BT.begin(9600);
pinMode(speedPin,OUTPUT);
pinMode(dirPin1,OUTPUT);
pinMode(dirPin2,OUTPUT);
myServo.attach(servoPin);
delay(500);
}

void loop() {
  // read data from serial:
if(BT.available()>0){
  inputVar = BT.read();
}
//Serial.print("inputVar: ");
//Serial.println(inputVar);

//speed and direction
//up
if(inputVar=='1'){
  speedVal=255;
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,LOW);
}
//down
if(inputVar=='2'){
  speedVal=255;
    digitalWrite(dirPin2,HIGH);
    digitalWrite(dirPin1,LOW);
}
//reset speed
if(inputVar=='0'){
  speedVal=0;
    digitalWrite(dirPin1,HIGH);
    digitalWrite(dirPin2,LOW);
}
//rotation
//right
if(inputVar=='3'){
  rotationVal=140;
}
//reset right
if(inputVar=='5'){
  rotationVal=93;
}    
//left
if(inputVar=='4'){
  rotationVal=40;
}
//reset left
if(inputVar=='6'){
  rotationVal=98;
}

analogWrite(speedPin,speedVal);
myServo.write(rotationVal);

Serial.println(speedVal);
Serial.println(rotationVal);

}
