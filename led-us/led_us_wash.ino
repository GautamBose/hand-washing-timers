const int trigPin = 9;
const int echoPin = 10;

const int pinRangeBottom = 1;
const int pinRangeTop = 6;
int washCount = 0;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  for (int i = pinRangeBottom; i <= pinRangeTop; i++) {
    pinMode(i, OUTPUT);
  }

  for (int i = pinRangeBottom; i <= pinRangeTop; i++) {
    digitalWrite(i, HIGH);
  }


  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.println(distance);

    if (distance < 200) {
      washCount++;
    }
    else {
      washCount = 0;
    }
  
   if (washCount > 5) {
     washCount = 0;
      countUp();
    }
  
   delay(100);
}

void countUp() {
  Serial.println("Counting up");
  int time = 20;
  int count = 0;
  boolean currLEDstate = true;
  while ( time > 0) {

    if (count % 4 == 0) {
      time--;
      Serial.println("tick");
    }
    digitalWrite(2, HIGH);
    
    if (time > 15) {

      if (currLEDstate) {
        digitalWrite(3, HIGH);
      }
      else {

        digitalWrite(3,  LOW);
      }
      currLEDstate = !currLEDstate;
      if (time == 16) {
        digitalWrite(3, HIGH);
      }
    }
    if (time > 10 && time <= 15) {
      if (currLEDstate) {
        digitalWrite(4, HIGH);
      }
      else {

        digitalWrite(4,  LOW);
      }
      currLEDstate = !currLEDstate;
      if (time == 11) {
        digitalWrite(4, HIGH);
      }
    }

    if (time > 5 && time <= 10) {
      if (currLEDstate) {
        digitalWrite(5, HIGH);
      }
      else {

        digitalWrite(5,  LOW);
      }
      currLEDstate = !currLEDstate;
      if (time == 6) {
        digitalWrite(5, HIGH);
      }
    }

    if (time > 0 && time <= 5) {
      if (currLEDstate) {
        digitalWrite(6, HIGH);
      }
      else {

        digitalWrite(6,  LOW);
      }
      if (time == 1) {
        digitalWrite(6, HIGH);
      }
      currLEDstate = !currLEDstate;

    }
    delay(250);
    count++;
  }

  for (int i = 0; i <= 10; i++) {

    for (int i = pinRangeBottom; i <= pinRangeTop; i++) {
      digitalWrite(i, LOW);
    }
    delay(100);
    for (int i = pinRangeBottom; i <= pinRangeTop; i++) {
      digitalWrite(i, HIGH);
    }
    delay(100);
  }
  for (int i = pinRangeBottom; i <= pinRangeTop; i++) {
    digitalWrite(i, LOW);
  }

  delay(1000);
}
