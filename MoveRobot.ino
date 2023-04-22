// enable motor controller
int STBY = 3;

// Right Wheels
int PWMA = 5; // speed of right motors
int AIN1 = 7; // direction of right motors

// Left Wheels
int PWMB = 6; // speed of left motors
int BIN1 = 8; // direction of left motors

int delayTime = 500;

void setup() {
  // initialize 
  pinMode(STBY, OUTPUT); 
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(BIN1, OUTPUT);
  
  digitalWrite(PWMA, HIGH); // set speed of right motors to max
  digitalWrite(PWMB, HIGH); // set speed of left motors to max
  
  delay(delayTime);
}

void forward() {
  digitalWrite(AIN1, HIGH);  
  digitalWrite(BIN1, HIGH);  
}

void backward() {
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN1, LOW);
}

void moveRobot() {
  digitalWrite(STBY, HIGH);
  delay(delayTime);
}

void stationary() {
  digitalWrite(STBY, LOW);
  delay(delayTime);
}

void left() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(BIN1, LOW);
}

void right() {
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN1, HIGH);
}

void loop() {
  forward();
  moveRobot();
  stationary();
  }
