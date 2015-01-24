#include <Keypad.h>
#include <Servo.h>

const int servoPin = 10;
const int potPin = 0;
const int ccwSpin = 8, cwSpin = 175, stopSpin =88;

const byte rows = 4; //four rows
const byte cols = 3; //three columns
char keys[rows][cols] = {
  {'1','2','3'},//, 'A'},
  {'4','5','6'},//, 'B'},
  {'7','8','9'},//, 'C'},
  {'*','0','#'}//, 'D'}
};

byte rowPins[rows] = {6, 5, 4, 3}; //connect to the row pinouts of the keypad1
byte colPins[cols] = {9, 8, 7}; //connect to the column pinouts of the keypad1

Keypad keypad1 = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

int currentDirection = stopSpin;

Servo servo1;

const long debounceDelay = 50;

void setup(){
  
  Serial.begin(9600);
  
  char key = keypad1.getKey();
  
  if (key != NO_KEY){
    Serial.println(key);
  }
    
  servo1.attach(servoPin);
    
}

void loop(){
  servo1.write(currentDirection);
  // Check button 1
  int button1Reading = digitalRead(button1Pin); 
  
  if(button1Reading != button1PreviousState){
    button1LastDebounce = millis();
  }
  
  if((millis() - button1LastDebounce) > debounceDelay){
    if(button1Reading != button1State){
      button1State = button1Reading;
      if(button1State == HIGH){
        currentDirection = ccwSpin;
        digitalWrite(led1Pin, LOW);
      } else {
        digitalWrite(led1Pin, HIGH);
      }
    }
  }
  
  button1PreviousState = button1Reading;
  
  
  // Check button 2
  int button2Reading = digitalRead(button2Pin); 
  
  if(button2Reading != button2PreviousState){
    button2LastDebounce = millis();
  }
  
  if((millis() - button2LastDebounce) > debounceDelay){
    if(button2Reading != button2State){
      button2State = button2Reading;
      if(button2State == HIGH){
        currentDirection = cwSpin;
        digitalWrite(led2Pin, LOW);
      } else {
        digitalWrite(led2Pin, HIGH);
      }
    }
  }
  
  button2PreviousState = button2Reading;


  // Check button 3  
  int button3Reading = digitalRead(button3Pin); 
  
  if(button3Reading != button3PreviousState){
    button3LastDebounce = millis();
  }
  
  if((millis() - button3LastDebounce) > debounceDelay){
    if(button3Reading != button3State){
      button3State = button3Reading;
      if(button3State == HIGH){
        currentDirection = stopSpin;
        digitalWrite(led3Pin, LOW);
      } else {
        digitalWrite(led3Pin, HIGH);
      }
    }
  }
  
  button3PreviousState = button3Reading;
  
}
