#include <ArduinoJson.h>
#include <SoftwareSerial.h>
SoftwareSerial ble(11, 12);

int spd = 255;
//dau xe
//dau xe trai
const int in1 = 2;
const int in2 = 3;
//dau xe phai
const int in3 = 4;
const int in4 = 5;
//duoi xe
const int in5 = 6;
const int in6 = 7;

const int in7 =9;
const int in8 =8;
//global
bool flag = 0;
unsigned long past = 0;
void setup() {
 Serial.begin(9600);
 ble.begin(9600);
 pinMode(LED_BUILTIN, OUTPUT);
 Serial.println("Ready!");
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(in3,OUTPUT);
 pinMode(in4,OUTPUT);
 pinMode(in5,OUTPUT);
 pinMode(in6,OUTPUT);
 pinMode(in7,OUTPUT);
 pinMode(in8,OUTPUT);
}

void backward(int spd)
{
  analogWrite(in1,spd);
  analogWrite(in2,0);
  analogWrite(in3,spd);
  analogWrite(in4,0);
  analogWrite(in5,spd);
  analogWrite(in6,0);
  analogWrite(in7,spd);
  analogWrite(in8,0);
}
void brake()
{
  analogWrite(in1,0);
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,0);
  analogWrite(in5,0);
  analogWrite(in6,0);
  analogWrite(in7,0);
  analogWrite(in8,0);
}
void right(int spd)
{
  analogWrite(in1,spd);
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,spd);
  
  analogWrite(in5,0);
  analogWrite(in6,spd);
  analogWrite(in7,spd);
  analogWrite(in8,0);
}
void left(int spd)
{
  analogWrite(in1, 0);
  analogWrite(in2,spd);
  analogWrite(in3,spd);
  analogWrite(in4,0);
  
  analogWrite(in5,spd);
  analogWrite(in6,0);
  analogWrite(in7,0);
  analogWrite(in8,spd);
}
void forward(int spd)
{
  analogWrite(in1,0);
  analogWrite(in2,spd);
  analogWrite(in3,0);
  analogWrite(in4,spd);
  
  analogWrite(in5,0);
  analogWrite(in6,spd);
  analogWrite(in7,0);
  analogWrite(in8,spd);
}
void forward_left(int spd)
{
  digitalWrite(in1,100);
  digitalWrite(in2,0);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,0);
  digitalWrite(in5,100);
  digitalWrite(in6,0);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,0);
}
void loop() {
//  if(flag==1&&millis()-past>=300)
//  { 
//   brake();
//    flag=0;
//  }
 if(ble.available()>0) 
 {
  digitalWrite(LED_BUILTIN, LOW);
  char letter = ble.read();
  if(isDigit(letter))
    spd = (letter - '0')*25+30;
  Serial.println(letter);
  switch (letter){
    case 'B': //change
      forward(spd);
      flag = 1;
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 'F': //change
      backward(spd);
      flag = 1;
      past = millis();
      break;
    case 'L':
      left(spd);
      break;
    case 'R':
      right(spd);
      break;

    case 'S':
      brake();
      break;
    case 'G':
      forward_left(spd);
      break;
    case '+':
      ble.readString();
      break;
    case 'q':
      spd = 255;
      break;
  }
 }
}
