#include "Joystick.h"

Joystick_ Joystick;

//axis of the left and right joystick with corresponding pins
int LX = A0;
int LY = A1;
int RX = A2;
int RY = A3;

//list of the digital pins for the buttons:
int digitalPins[10] = {2,3,4,5,6,7,8,9,14,15};

//list of the buttons sent to the PC:
int list[10] = {0,1,2,3,4,5,6,7,8,9};

int lastButtonState[10] = {0,0,0,0,0,0,0,0,0,0};

void setup() {
  pinMode(LX, INPUT);
  pinMode(LY, INPUT);
  pinMode(RX, INPUT);
  pinMode(RY, INPUT);

  for (int i = 0; i < 10; i++){
      pinMode(digitalPins[i], INPUT_PULLUP);
    }
  
  Joystick.begin();
}

void loop() {  
 //buttons:
  for (int i = 0; i < 10; i++)
  {
    int currentButtonState = !digitalRead(digitalPins[i]);
    if (currentButtonState != lastButtonState[i])
    {
      Joystick.setButton(list[i], currentButtonState);
      lastButtonState[i] = currentButtonState;
    }
  }

 //joysticks:
  Joystick.setXAxis(analogRead(LX));
  Joystick.setYAxis(analogRead(LY));
  Joystick.setRxAxis(analogRead(RX));
  Joystick.setRyAxis(analogRead(RY));
  
  delay(20);
}
