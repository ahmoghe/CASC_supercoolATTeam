#include <Servo.h>

#define Button_Pin 4 //The button pin gpio4 

#define IN1 2 //L298N pin2
#define IN2 5 //L298N pin5

#define Travel_Time 3000 //the travel time taken 

bool isExtended = false; //current state of linear actuator
bool lastButtonState = HIGH; //

void setup(){
  Serial.begin(115200);
  pinMode(Button_Pin, INPUTPULLUP);
  pinMode(IN1, output);
  pinMode(IN2, output);

  stopActuator();


}
void loop() {
    bool ButtonState = digitalRead(Button_Pin);

  if (lastButtonState == HIGH && ButtonState == LOW){
    delay(50);

    if(!isExtended){
      extend();
      isExtended = true;
    }
    else
    {
      retract();
      isExtended = false;
    }
    lastButtonState = ButtonState;
  }
}
void extend(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2,LOW);
  delay(Travel_Time);
  stopActuator();

}
void retract(){
digitalWrite(IN1, LOW);
digitalWrite(IN2,HIGH);
delay(Travel_Time);
stopActuator();
}
void stopActuator(){
digitalWrite(IN1, LOW);
digitalWrite(IN2,LOW);
}



