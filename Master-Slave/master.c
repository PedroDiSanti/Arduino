#include <Wire.h>

byte codigoResultado = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
	Wire.beginTransmission(8);
	codigoResultado = Wire.endTransmission();

	if (codigoResultado == 0){
  		Serial.print ("Dispositivo I2C detectado no endereço: 8.\n");
    	Wire.requestFrom(8, 6);

    	while (Wire.available()) {
    		char c = Wire.read();
        
        	if (c != 'W' ) {
        		Serial.print(c);
        	}
    	}
    	delay(100);
	} if (codigoResultado != 0){
		Serial.print ("Dispositivo I2c não detectado no endereço: 8.\n");
	}
	delay(2000);

	Wire.beginTransmission(9);
	codigoResultado = Wire.endTransmission();

	if (codigoResultado == 0){
  		Serial.print ("Dispositivo I2C detectado no endereço: 9.\n");
    	Wire.requestFrom(9, 6);

    	while (Wire.available()) {
    		char c = Wire.read();
      
        	if (c != 'W' ) {
        		Serial.print(c);
        	}
    	}
    	delay(100);
	} if (codigoResultado != 0){
		Serial.print ("Dispositivo I2c não detectado no endereço: 9.\n");
	}
	delay(2000);
}