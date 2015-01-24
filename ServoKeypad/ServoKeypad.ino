#include <Keypad.h>
#include <Servo.h>

const int led1Pin = 11, led2Pin = 12, led3Pin = 13;
const int button1Pin = 19, button2Pin = 18, button3Pin = 2;
const int servoPin = 10;
const int potPin = 0;
const int ccwSpin = 8, cwSpin = 175, stopSpin = 88;

const byte rows = 4; //four rows
const byte cols = 3; //three columns
char keys[rows][cols] = {
  {'1','2','3'},//, 'A'},
  {'4','5','6'},//, 'B'},
  {'7','8','9'},//, 'C'},
  {'*','0','#'}//, 'D'}
};

byte rowPins[rows] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad1
byte colPins[cols] = {5, 4, 3}; //connect to the column pinouts of the keypad1

Keypad keypad1 = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

const int pinLength = 4;
char password[pinLength] = {'4','5','1','5'};
char pin[pinLength];
boolean enteringPin = false;
int pinCount = 0;

int currentDirection = stopSpin;

int led1State = HIGH, led2State = HIGH, led3State = HIGH;
int button1State, button2State, button3State;
int button1PreviousState = LOW, button2PreviousState = LOW, button3PreviousState = LOW;

long button1LastDebounce = 0;
long button2LastDebounce = 0;
long button3LastDebounce = 0;

Servo servo1;

const long debounceDelay = 50;

void setup(){
  
  //Serial.begin(9600);
  
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  
  servo1.attach(servoPin);
    
  digitalWrite(led1Pin, led1State);
  digitalWrite(led2Pin, led2State);
  digitalWrite(led3Pin, led3State);
  
}

void loop(){
  
  char key = keypad1.getKey();
  
  if (key != NO_KEY){
    if(!enteringPin){
      //Serial.println(key);
    }
    if(key == '*'){
      enteringPin = true;
      //Serial.println("Entering pin!");
    }
    if(key == '#'){
      //Serial.println("PIN cleared");
      pinCount = 0;
      enteringPin = false;
    }
    if(enteringPin && key != '*' && key != '#'){
      pin[pinCount] = key;
      pinCount++;
    }
    
    if(pinCount == pinLength){
      //Serial.println(pin);
      //Serial.println(password);
      int count = 0;
      for(int i = 0; i < pinLength; i++){
        if(pin[i] == password[i]){
          count++;
          //Serial.println('Y');
          continue;
        } else {
          //Serial.println('N');
          break;
        }
      }
      //Serial.println(count);
      if(count == pinLength){
      //Serial.println("yay");
        if(currentDirection == ccwSpin){
          currentDirection = cwSpin;
        } else if (currentDirection == cwSpin){
          currentDirection = ccwSpin;
        } else {
          currentDirection = ccwSpin;
        }
      }
      enteringPin = false;
      pinCount = 0;
    }
  }
  
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
