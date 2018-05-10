#define MOISTURE_PIN A2

int soilHumidity;
int setHumidity = 50;      //Set the pump trigger threshold

void setup() {
  Serial.begin(9600);
  Serial.println("Serial started");

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}

void loop() {
  soilHumidity = map(analogRead(MOISTURE_PIN), 0, 1023, 0, 100);    //Map analog value to 0~100% soil moisture value
  if (soilHumidity < setHumidity) {
    pumpOn();
  } else {
    pumpOff();
  }
}
//open pump
void pumpOn() {
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}
//close pump
void pumpOff() {
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}
