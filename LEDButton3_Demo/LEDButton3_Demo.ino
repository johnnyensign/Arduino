const int led1Pin = 11, led2Pin = 12, led3Pin = 13; // LED Pins
const int button1Pin = 0, button2Pin = 1, button3Pin = 2;

int led1State = HIGH, led2State = HIGH, led3State = HIGH;
int button1State, button2State, button3State;
int button1PreviousState = LOW, button2PreviousState = LOW, button3PreviousState = LOW;

long button1LastDebounce = 0;
long button2LastDebounce = 0;
long button3LastDebounce = 0;

const long debounceDelay = 50;

void setup(){
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  
  digitalWrite(led1Pin, led1State);
  digitalWrite(led2Pin, led2State);
  digitalWrite(led3Pin, led3State);
}

void loop(){

  // Check button 1
  int button1Reading = digitalRead(button1Pin); 
  
  if(button1Reading != button1PreviousState){
    button1LastDebounce = millis();
  }
  
  if((millis() - button1LastDebounce) > debounceDelay){
    if(button1Reading != button1State){
      button1State = button1Reading;
      if(button1State == HIGH){
        toggleOutput(&led1Pin, &led1State);
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
        toggleOutput(&led2Pin, &led2State);
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
        toggleOutput(&led3Pin, &led3State);
      }
    }
  }
  
  button3PreviousState = button3Reading;
  
}

void toggleOutput(const int* pin, int* state){
  *state = !*state;
  digitalWrite(*pin, *state);
}
