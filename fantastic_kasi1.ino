// Motor 1 connections
int en1 = 9;
int in1 = 8;
int in2 = 7;
// Motor 2 connections
int en2 = 3;
int in3 = 5;
int in4 = 4;

void setup() {
	// Set all the motor control pins to outputs
	pinMode(en1, OUTPUT);
	pinMode(en2, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
	
	
}

void loop() {
	directionControl();
	delay(1000);
	speedControl();
	delay(1000);
}

// This function lets you control spinning direction of motors
void directionControl() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(en1, 255);
	analogWrite(en2, 255);

	// Turn on motor 1 & 2
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
	delay(2000);
	
	// Now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	delay(2000);
	

}

// This function lets you control speed of the motors
void speedControl() {
	// Turn on motors
	
	
	// Accelerate from zero to maximum speed
	for (int i = 0; i < 256; i++) {
		analogWrite(en1, i);
		analogWrite(en2, i);
		delay(20);
	}
	
	// Decelerate from maximum speed to zero
	for (int i = 255; i >= 0; --i) {
		analogWrite(en1, i);
		analogWrite(en2, i);
		delay(20);
	}
	
	
}
