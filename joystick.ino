int xAxis = 0;
int yAxis = 0;
const int xPin = A0;
const int yPin = A1;
const int switchLedPin = 8;
const int fwdRgtPin = 5;
const int fwdPin = 6;
const int fwdLftPin = 7;
const int bckLftPin = 2;
const int bckPin = 3;
const int bckRgtPin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
     ; // wait for serial to initialize
  }

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9,INPUT_PULLUP);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

void loop() {
  xAxis = analogRead(xPin);
  Serial.print("X: ");
  Serial.println(xAxis, DEC);

  yAxis = analogRead(yPin);
  Serial.print("Y: ");
  Serial.println(yAxis, DEC);

  indicate(xAxis, yAxis);

  if (digitalRead(9) == LOW) {
    digitalWrite(switchLedPin, HIGH);
  } else {
    digitalWrite(switchLedPin, LOW);
  }
}

void indicate(int x, int y) {
  if (y > 510) {
    digitalWrite(bckPin, HIGH);
  } else {
    digitalWrite(bckPin, LOW);
  }

  if (x < 490 && y < 490) {
    digitalWrite(fwdLftPin, HIGH);
  } else {
    digitalWrite(fwdLftPin, LOW);
  }

  if (x > 510 && y < 490) {
    digitalWrite(fwdRgtPin, HIGH);
  } else {
    digitalWrite(fwdRgtPin, LOW);
  }

  if (x > 510 && y > 490 && y < 510) {
    digitalWrite(fwdRgtPin, HIGH);
    digitalWrite(bckRgtPin, HIGH);
  } else {
    digitalWrite(fwdRgtPin, LOW);
    digitalWrite(bckRgtPin, LOW);
  }

  if (x < 490 && y > 490 && y < 510) {
    digitalWrite(fwdLftPin, HIGH);
    digitalWrite(bckLftPin, HIGH);
  } else {
    digitalWrite(fwdLftPin, LOW);
    digitalWrite(bckLftPin, LOW);
  }

  if (x < 490 && y > 510) {
    digitalWrite(bckLftPin, HIGH);
  } else {
    digitalWrite (bckLftPin, LOW);
  }

 if (x > 510 && y > 510) {
    digitalWrite(bckRgtPin, HIGH);
  } else {
    digitalWrite (bckRgtPin, LOW);
  }

  if (y < 490) {
    digitalWrite(fwdPin, HIGH);
  } else {
    digitalWrite(fwdPin, LOW);
  }
}
