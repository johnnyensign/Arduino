const int ledPin = 12; // LED Pin 
const int button1Pin = 0; // Button Pin

int ledState = HIGH;
int buttonState;
int buttonPreviousState = LOW;

long buttonLastDebounce = 0;
long debounceDelay = 50;

void setup(){
  pinMode(ledPin, OUTPUT);
  
  pinMode(button1Pin, INPUT);
 
  digitalWrite(ledPin, ledState);
}

void loop(){
 
  int buttonReading = digitalRead(button1Pin); 
  
  if(buttonReading != buttonPreviousState){
    buttonLastDebounce = millis();
  }
  
  if((millis() - buttonLastDebounce) > debounceDelay){
    if(buttonReading != buttonState){
      buttonState = buttonReading;
      if(buttonState == HIGH){
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
    }
  }
  
  buttonPreviousState = buttonReading;
  
}

