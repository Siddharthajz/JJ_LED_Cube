/*
  [   (x,y)-Pin      Array Position]

    (1,1)-13        0
    (1,2)-12        1
    (1,3)-11        2
    (1,4)-10        3
    (2,1)-9         4
    (2,2)-8         5
    (2,3)-7         6
    (2,4)-6         7
    (3,1)-5         8
    (3-2)-4         9
    (3-3)-3         10
    (3,4)-2         11
    (4,1)-1         12
    (4,2)-0         13
    (4,3)-A5        14
    (4,4)-A4        15

  [   layer-Pin        Array Position]

    a-A0            3
    b-A1            2
    c-A2            1
    d-A3            0
*/
int layer[4] = {A3, A2, A1, A0}; //initializing and declaring led layers
int column[16] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, A5, A4}; //initializing and declaring led columns

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 16; i++) {
    pinMode(column[i], OUTPUT);  //setting columns to ouput
  }

  for (int i = 0; i < 4; i++) {
    pinMode(layer[i], OUTPUT);  //setting layers to output
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  turnOff();
  turnOn();
  delay(2000);

  // Siddhartha's Work
  flicker();      // All LEDs are on at the end
  randomLED();    // One LED is on at the end
  
  // Aryan's Work
  raining();
}

// Turns every LED on
void turnOn() {
  for (int i = 0; i < 16; i++) {
    digitalWrite(column[i], LOW);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(layer[i], HIGH);
  }
}

// Turns every LED off
void turnOff() {
  for (int i = 0; i < 16; i++) {
    digitalWrite(column[i], HIGH);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(layer[i], LOW);
  }
}

// Siddhartha's Work
// Flickers the LEDs
void flicker() {
  turnOff();
  int timeLeft = 300;                 // in millisecs (was 150)
  int rateChangeOfTimeLeft = 5;       // in millisecs
  while (timeLeft != 0) {
    turnOn();
    delay(timeLeft);
    turnOff();
    delay(timeLeft);
    timeLeft -= rateChangeOfTimeLeft;
  }
  turnOn();
}

// Turns on random LEDs
void randomLED() {
  turnOff();
  int timeOn = 10;    // in millisecs
  int cycles = 1000;   // Total no. of LED that will turn on (was 100)
  int randomlayer;

  int randomColumn;
  for (int i = 0; i < cycles; i++) {
    turnOff();
    randomlayer = random(0, 4);
    randomColumn = random(0, 16);
    digitalWrite(layer[randomlayer], HIGH);
    digitalWrite(column[randomColumn], LOW);
    delay(timeOn);
  }
}

// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// Aryan's Work
void raining() {
  int dropDelay = 100;

  for (int i = 0; i < 16; i++) {
    digitalWrite(column[i], LOW);
    for (int j = 0; j < 4; j++)  {
      digitalWrite(layer[j], HIGH);
      delay(dropDelay);
    }
    delay(dropDelay);
  }
}
