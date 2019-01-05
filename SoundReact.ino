// Sound Reactive RGB LED Strip Sketch.
// SoundReact By Anton Grouchtchak(Teraskull).

// https://github.com/Teraskull/SoundReact


#define red 11
#define green 10
#define blue 9
#define microphone 7
#define L 13

int change = 0;
int minNum = 4000; // Generate random time to change colors, from 4000 to 15000 
int maxNum = 15000;

int x = 0;
int y = 0; // TEMP values, so that the same color doesn't repeat 3 times in a row
int z = 0;

int initFirstRGB = 500;
int initRGB = 150; // Initialize RGB Strip with 3 red and 1 green flash
int initLastRGB = 1000;

bool soundstate; // Detect sound from microphone


void setup() {
  //Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(L, OUTPUT);
  pinMode(microphone, INPUT);

  digitalWrite(L, LOW); // Turn off built-in LED
  initStrip();
}

void loop() {
  
  chooseRandomColor();
  changeRandomTime();
  //Serial.println(change);
  
  for (int i = 0; i < change; i++) {
  detectSound();

  if (soundstate == 1) {
    colorShow();
  }
  else {
    colorOff();
    }
  }
  
}

void initStrip() {
    colorRed();
    delay(initFirstRGB);
    colorOff();
    delay(initRGB);
    colorRed();
    delay(initRGB);
    colorOff();
    delay(initRGB);
    colorRed();
    delay(initRGB);
    colorOff();
    delay(initRGB);
    colorGreen();
    delay(initFirstRGB);
    colorOff();
    delay(initLastRGB);
}

void colorRed() {
  analogWrite(red, 0);
  analogWrite(green, 255);
  analogWrite(blue, 255);
}

void colorGreen() {
  analogWrite(red, 255);
  analogWrite(green, 0);
  analogWrite(blue, 255);
}

void colorBlue() {
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 0);
}

void colorYellow() {
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 255);
}

void colorCyan() {
  analogWrite(red, 255);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}

void colorPurple() {
  analogWrite(red, 0);
  analogWrite(green, 255);
  analogWrite(blue, 0);
}

void colorOff() {
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 255);
}

int chooseRandomColor() {
  while(y == x || z == x){
    x = random(1, 7);
  }

  z = y;
  y = x;
}

int changeRandomTime() {
  change = random(minNum, maxNum);
}

bool detectSound() {
  soundstate = digitalRead(microphone);
}

void colorShow() {
  if (x == 1) {
    colorRed();
  }

   if (x == 2) {
    colorGreen();
  }

   if (x == 3) {
    colorBlue();
  }

   if (x == 4) {
    colorYellow();
  }

   if (x == 5) {
    colorCyan();
  }

   if (x == 6) {
    colorPurple();
  }
}
