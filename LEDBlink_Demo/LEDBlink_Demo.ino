
int greenLEDPin = 11, yellowLEDPin = 12, redLEDPin = 13;

void setup(){
  pinMode(greenLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  
  digitalWrite(greenLEDPin, HIGH);
  digitalWrite(yellowLEDPin, HIGH);
  digitalWrite(redLEDPin, HIGH);
}

void loop(){
  digitalWrite(greenLEDPin, LOW);
  delay(100);
  digitalWrite(greenLEDPin, HIGH);
  digitalWrite(yellowLEDPin, LOW);
  delay(100);
  digitalWrite(yellowLEDPin, HIGH);
  digitalWrite(redLEDPin, LOW);
  delay(100);
  digitalWrite(redLEDPin, HIGH);
}
