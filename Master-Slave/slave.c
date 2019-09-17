#include <Wire.h>

int LED = 13;
byte codigoResultado = 0;

void setup() {
  pinMode (LED, OUTPUT);
  Wire.begin(9); 
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int bytes) {
  codigoResultado = Wire.read();
}

void loop() {
  if (codigoResultado == 0) {
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
  if (codigoResultado != 0) {
    digitalWrite(LED, HIGH);
    delay(400);
    digitalWrite(LED, LOW);
    delay(400);
  }
}
