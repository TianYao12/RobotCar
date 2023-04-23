// enable motor controller
int STBY = 3;

// Right Wheels
int PWMA = 5;
int AIN1 = 7;

// Left Wheels
int PWMB = 6;
int BIN1 = 8;

float t; // time in milliseconds
float rate = 2.45; // rate of linear movement = 2.45ft/sec
float w = 398; // angular velocity = 398 degrees/sec

void setup() {
  // initialize 
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(BIN1, OUTPUT);
  
  digitalWrite(PWMA, HIGH);
  digitalWrite(PWMB, HIGH);
}

void moveRobot() {
  digitalWrite(STBY, HIGH);
}

void stationary(float t) {
  digitalWrite(STBY, LOW);
  delay(t*1000); 
}

void forward(float d) {
  moveRobot();
  digitalWrite(AIN1, HIGH);
  digitalWrite(BIN1, HIGH); 
  t = (d/2.45) * 1000; 
  delay(t);  
  stationary(1);
}

void backward(float d) {
  moveRobot();
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN1, LOW);
  t = (d/2.45) * 1000; // rate = 2.45ft/sec
  delay(t);  
  stationary(1); 
}

void left(int deg) {
  moveRobot();
  digitalWrite(AIN1, HIGH);
  digitalWrite(BIN1, LOW);
  t = (deg/398.) * 1000;
  delay(t);
  stationary(1);
}

void right(int deg) {
  moveRobot();
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN1, HIGH);
  t = (deg/398) * 1000;
  delay(t);
  stationary(1);
} 

void loop() {
  moveRobot();
  left(90);
  stationary(1); 
  while(true) {
    
  }
}
