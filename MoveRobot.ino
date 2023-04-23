// enable motor controller
int STBY = 3;

// Right Wheels
int PWMA = 5;
int AIN1 = 7;

// Left Wheels
int PWMB = 6;
int BIN1 = 8;

float t; // time in milliseconds
float v; ; // rate of linear movement = 2.45ft/sec
float w = 398; // angular velocity = 398 degrees/sec

int customMotor = 150;

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

void loop() {
  moveRobot();
  setMotorSpeed(customMotor,customMotor);
  forward(1);
  stationary(); 
  while(true) {
    
  }
}

void setMotorSpeed(int speedR, int speedL) {
  analogWrite(PWMA, speedR);
  analogWrite(PWMB, speedL);
}

void moveRobot() {
  digitalWrite(STBY, HIGH);
}

void stationary() {
  digitalWrite(STBY, LOW);
  delay(2000); 
}

void forward(float d) {
  moveRobot();
  digitalWrite(AIN1, HIGH);
  digitalWrite(BIN1, HIGH); 
  v = 0.0075*customMotor + 0.35;
  t = (d/v) * 1000; 
  delay(t);  
  stationary();
}

void backward(float d) {
  moveRobot();
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN1, LOW);
  t = (d/v) * 1000; // rate = 2.45ft/sec
  delay(t);  
  stationary(); 
}

void left(int deg) {
  moveRobot();
  digitalWrite(AIN1, HIGH);
  digitalWrite(BIN1, LOW);
  t = (deg/398.) * 1000;
  delay(t);
  stationary();
}

void right(int deg) {
  moveRobot();
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN1, HIGH);
  t = (deg/398) * 1000;
  delay(t);
  stationary();
} 

