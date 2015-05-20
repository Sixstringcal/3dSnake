int s[999];
int a = 1;
int old = 1;
int wState = LOW;
int aState = LOW;
int sState = LOW;
int dState = LOW;
int upState = LOW;
int downState = LOW;
int directions = 0;
int count;
int reset = 1;

void setup() {
  while (a < 33) {
    pinMode(a, OUTPUT);
    a++;
  }
  a = 1;
  pinMode(38, INPUT);
  pinMode(39, INPUT);
  pinMode(40, INPUT);
  pinMode(41, INPUT);
  pinMode(42, INPUT);
  pinMode(43, INPUT);

}

void loop() {
  wState = LOW;
  aState = LOW;
  sState = LOW;
  dState = LOW;
  upState = LOW;
  downState = LOW;
  if (count == 1) {
    wState = digitalRead(38);
    aState = digitalRead(39);
    sState = digitalRead(40);
    dState = digitalRead(41);
    upState = digitalRead(42);
    downState = digitalRead(43);
    count = 0;
  }


  decide();
  if (a + directions < 33 && a + directions > 0) {
    movement();
  }
  /*else {
    while (reset < 33) {
      digitalWrite(reset, LOW);
      reset++;
    }
    a = 1;
  }*/


  delay(100);

}

int decide() {
  if (wState == HIGH) {
    directions = 4;
    count++;
  }
  else if (aState == HIGH) {
    directions = -1;
    count++;
  }
  else if (sState == HIGH) {
    directions = -4;
    count++;
  }
  else if (dState == HIGH) {
    directions = 1;
    count++;
  }
  else if (upState == HIGH) {
    directions = 16;
    count++;
  }
  else if (downState == HIGH) {
    directions = -16;
    count++;
  }
  else {
    directions  = 0;
    count++;
  }

  wState = LOW;
  aState = LOW;
  sState = LOW;
  dState = LOW;
  upState = LOW;
  downState = LOW;
  return directions;
  return count;
}

int movement() {
  a += directions;
  digitalWrite(a, HIGH);
  if (old == a) {
    a = a;
  }
  else if (a > 32) {
    digitalWrite(old, LOW);
  }
  else {

    digitalWrite(old, LOW);
  }
  old = a;
  return a;

}

int edgeDetection() {
  if (a % 4 == 1 || a % 4 == 0) {
    int mod = a % 4;
    if (mod == 1) {
      if (directions == 1) {
        a = old - 3;
        digitalWrite(a, HIGH);
      }
      else {
        digitalWrite(a, HIGH);
      }
    }
    else if (mod == 0) {
      if (directions == -1) {
        a = old + 3;
        digitalWrite(a, HIGH);
      }
      else {
        digitalWrite(a, HIGH);
      }
    }
  }
  else if(a <21 && a > 16){
    if(directions == 4){
      a = old - 15;
      digitalWrite(a,HIGH);
    }
    else{
      digitalWrite(a,HIGH);
    }
  }
  else if(a<17 && a > 12){
    if(directions == -4){
      a = old +15;
      digitalWrite(a,HIGH);
    }
    else {
      digitalWrite(a,HIGH);
    }
  }
  else if(a>-16 && a < 1){
    if(directions == -16){
      a = old+16;
      digitalWrite(a,HIGH);
    }
    else{
      digitalWrite(a,HIGH);
    }
  }
  else if(a<49 && a >32){
    if(directions == 16){
      a = old-16;
      digitalWrite(a,HIGH);
    }
    else{
      digitalWrite(a,HIGH);
    }
  }
}
