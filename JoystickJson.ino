#include <JoystickShield.h> // include JoystickShield Library
JoystickShield joystickShield; // create an instance of JoystickShield object
#include <ArduinoJson.h> //json
StaticJsonDocument<200> doc;
void setup() 
{
  Serial.begin(9600);
  delay(100);
}

void loop() {
  joystickShield.processEvents();
  if (joystickShield.isJoystickButton()) {
     Serial.println("Joystick Clicked") ;
  }

  if (joystickShield.isUpButton()) {
     Serial.println("Up Button Clicked") ;
  }

  if (joystickShield.isRightButton()) {
     Serial.println("Right Button Clicked") ;
  }

  if (joystickShield.isDownButton()) {
     Serial.println("Down Button Clicked") ;
  }

  if (joystickShield.isLeftButton()) {
     Serial.println("Left Button Clicked") ;
  }

  // new eventfunctions
  if (joystickShield.isEButton()) {
     Serial.println("E Button Clicked") ;
  }

  if (joystickShield.isFButton()) {
     Serial.println("F Button Clicked") ;
  }  
  
  
  // Đọc analog joystick
    int x = map(analogRead(A0),0,685,0,20);
    int y = map(analogRead(A1)+23,0,685,20,0);
    Serial.println(x);
    Serial.print("Y: ");
    Serial.println(y);
    if(x<10)
    {
    int left = abs(x-10);
    char buf[10];
    sprintf(buf, "%d", left);
    doc["spd"] = left;
    serializeJson(doc, buf);
    byte a[]="CC";
}
}
