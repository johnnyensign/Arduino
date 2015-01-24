#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

boolean button1CurrentState, button2CurrentState, button3CurrentState, 
        button1PreviousState = false, button2PreviousState = false, button3PreviousState = false;
    
int button1Pin, button2Pin, button3Pin;

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;

int servoPin, redPin, yellowPin, greenPin;
int redState, yellowState, greenState;

int currentScreen = 0;

//char[][] = {{"View 1: LEDs"},{"R: 0  Y: 0  G: 0"}};

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Welcome!");
}

void loop() {
  // If cycleScreenButton is pressed, cycleScreen();
  button1CurrentState = digitalRead(button1Pin);
  
  if(button1CurrentState != button1PreviousState){
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  
  digitalWrite(ledPin, ledState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  button1PreviousState = button1CurrentState;

}

void cycleScreen(){
  currentScreen++;
  if(currentScreen == 3){
    currentScreen = 0;
  }
}

void updateScreen(){
  if(currentScreen == 0){
    
    lcd.setCursor(0,0);
            // ________________
    lcd.print("View 1: LEDs    ");
    lcd.setCursor(0,1); 
            // ________________
    lcd.print("R: 0  Y: 0  G: 0");
  
  } else if(currentScreen == 1){
    
    lcd.setCursor(0,0);
            // ________________
    lcd.print("View 2: Blinking");
    lcd.setCursor(0,1); 
            // ________________
    lcd.print(">Slow Fast Cycle");
    
  } else {
    
    lcd.setCursor(0,0);
            // ________________
    lcd.print("View 3: Servo   ");
    lcd.setCursor(0,1); 
            // ________________
    lcd.print("R: 0  Y: 0  G: 0");
    
  }
   
}

// ________________
// View 1: LEDs
// R: 0  Y: 0  G: 0

// View 2: Blinking
// >Slow Fast Cycle

// View 3: Servo
// Position: 360deg
