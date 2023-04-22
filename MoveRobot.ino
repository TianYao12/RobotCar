// enable motor controller
int STBY = 3;

// Right Wheels
int PWMA = 5;
int AIN1 = 7;

// Left Wheels
int PWMB = 6;
int BIN1 = 8;

int delayTime = 500;

void setup() {
  // initialize 
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(BIN1, OUTPUT);
  
  digitalWrite(PWMA, HIGH);
  digitalWrite(PWMB, HIGH);
  
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
}
