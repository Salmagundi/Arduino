#define ACCELX A0
#define ACCELY A1
#define ACCELZ A2

void setup() {
  Serial.begin(9600);
}

void loop() {
Serial.print("X " );
Serial.print(analogRead(ACCELX));
Serial.print(" Y " );
Serial.print(analogRead(ACCELY));
Serial.print(" Z " );
Serial.print(analogRead(ACCELZ));
Serial.println();
delay(250);

}
