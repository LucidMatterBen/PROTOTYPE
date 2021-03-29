/* Example sketch to control a stepper motor with TB6600 stepper motor driver and Arduino without a library: continuous rotation. More info: https://www.makerguides.com */

// Define stepper motor connections:
#define dirPin 2
#define stepPin 3

char inChar;
int onOff = 0;
int test;

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Set the spinning direction CW/CCW:
  digitalWrite(dirPin, HIGH);

  Serial.begin(9600);
}



void loop() {
  // These four lines result in 1 step:
  
    inChar=Serial.read();

    if (inChar == '1') { 
        onOff = 1;
    }
    else if (inChar == '2') {
        onOff = 0;
    }   

    if (onOff == 1) { 
   
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);

    }
    else if (onOff == 0) {

      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
    }
}
