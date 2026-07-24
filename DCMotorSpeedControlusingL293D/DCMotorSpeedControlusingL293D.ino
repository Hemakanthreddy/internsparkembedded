const int ENA = 9;
const int IN1 = 8;
const int IN2 = 7;

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void loop() {

  // Increase Speed
  for(int speed = 0; speed <= 255; speed++) {
    analogWrite(ENA, speed);
    delay(20);
  }

  delay(1000);

  // Decrease Speed
  for(int speed = 255; speed >= 0; speed--) {
    analogWrite(ENA, speed);
    delay(20);
  }

  delay(1000);
}