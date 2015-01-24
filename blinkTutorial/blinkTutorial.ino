int redLEDPin = 1;
int greenLEDPin = 2;
int blueLEDPin = 3;

void setup(){
  // Initial configuration
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop(){
  // Main loop
  digitalWrite(redLEDPin, HIGH);
  digitalWrite(greenLEDPin, LOW);
  digitalWrite(blueLEDPin, LOW);
  
  setLights(true, false, false);
  
  delay(1000);
  
  setLights(false, true, false);
  
  digitalWrite(redLEDPin, LOW);
  digitalWrite(greenLEDPin, HIGH);
  digitalWrite(blueLEDPin, LOW);
  
  delay(1000);
  
  setLights(false, false, true);
  
  digitalWrite(redLEDPin, LOW);
  digitalWrite(greenLEDPin, LOW);
  digitalWrite(blueLEDPin, HIGH);
  
  delay(1000);
}

void setLights(boolean red, boolean green, boolean blue){
 digitalWrite(redLEDPin, red);
 digitalWrite(greenLEDPin, green);
 digitalWrite(blueLEDPin, blue); 
} 


