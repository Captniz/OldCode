int pinInStart = 4;
int pinOut = 3;
bool active = false;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(pinInStart, INPUT);
  pinMode(pinOut, OUTPUT);
}

void loop() {
  if(digitalRead(pinInStart)){
    delay(1000);
    active = !active;
  }
  Serial.println(active);
  int speed = analogRead(A0);
  //Calcolo voltaggio corrispondente a lettura analoga della velocità | 0 - 1023u -> 0 - 5v
  float voltSpeed = active * speed * (255.0/ 1023.0);
  Serial.println(voltSpeed);
  analogWrite(pinOut, voltSpeed);      
}