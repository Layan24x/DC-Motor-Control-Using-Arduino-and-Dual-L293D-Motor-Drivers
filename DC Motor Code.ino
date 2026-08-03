// Motor 1
int M1A = 2;
int M1B = 3;
int EN1 = 5;

// Motor 2
int M2A = 4;
int M2B = 7;
int EN2 = 6;

// Motor 3
int M3A = 8;
int M3B = 10;
int EN3 = 9;

// Motor 4
int M4A = 12;
int M4B = 13;
int EN4 = 11;

void setup() {

  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(EN1, OUTPUT);

  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  pinMode(EN2, OUTPUT);

  pinMode(M3A, OUTPUT);
  pinMode(M3B, OUTPUT);
  pinMode(EN3, OUTPUT);

  pinMode(M4A, OUTPUT);
  pinMode(M4B, OUTPUT);
  pinMode(EN4, OUTPUT);

  analogWrite(EN1,255);
  analogWrite(EN2,255);
  analogWrite(EN3,255);
  analogWrite(EN4,255);
}

void loop() {

  // ==========================
  // 1- الحركة للأمام (30 ثانية)
  // ==========================

  forward();

  delay(30000);

  // ==========================
  // 2- الحركة للخلف (60 ثانية)
  // ==========================

  backward();

  delay(60000);

  // ==========================
  // 3- يمين ويسار بالتناوب (60 ثانية)
  // ==========================

  unsigned long startTime = millis();

  while (millis() - startTime < 60000) {

    turnRight();

    delay(2000);

    turnLeft();

    delay(2000);
  }

}

void forward(){

  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,LOW);

  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,LOW);

  digitalWrite(M3A,HIGH);
  digitalWrite(M3B,LOW);

  digitalWrite(M4A,HIGH);
  digitalWrite(M4B,LOW);

}

void backward(){

  digitalWrite(M1A,LOW);
  digitalWrite(M1B,HIGH);

  digitalWrite(M2A,LOW);
  digitalWrite(M2B,HIGH);

  digitalWrite(M3A,LOW);
  digitalWrite(M3B,HIGH);

  digitalWrite(M4A,LOW);
  digitalWrite(M4B,HIGH);

}

void turnRight(){

  // اليسار للأمام
  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,LOW);

  digitalWrite(M3A,HIGH);
  digitalWrite(M3B,LOW);

  // اليمين للخلف
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,HIGH);

  digitalWrite(M4A,LOW);
  digitalWrite(M4B,HIGH);

}

void turnLeft(){

  // اليسار للخلف
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,HIGH);

  digitalWrite(M3A,LOW);
  digitalWrite(M3B,HIGH);

  // اليمين للأمام
  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,LOW);

  digitalWrite(M4A,HIGH);
  digitalWrite(M4B,LOW);

}