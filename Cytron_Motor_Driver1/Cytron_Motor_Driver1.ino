/*Example code for testing the Cytron Technologies 10A Rev 2.0 Motor Driver
 *The code uses only two pins, one for the motor direction (Pin 9) 
 * and one for the motor speed (pin 9). The speed is set using PWM. 
 * This code is meant to be run on the Arduino Uno hardware. 
 */


//Pins used to control direction and speed of the motor. Speed pin should be a pwm pin.
#define MotorDirection 8
#define MotorSpeed 9

int SpeedVal = 0;

void setup() {
  //Declaration for the pins used, both should be outputs.
  pinMode(MotorDirection, OUTPUT);
  pinMode(MotorSpeed, OUTPUT);
}

void loop() {
  
  //Ramps up the speed in the clockwise direction.
  digitalWrite(MotorDirection, LOW);                  //Loop increases the speed slowly until it reaches max speed.
  for(SpeedVal = 0; SpeedVal < 255; SpeedVal++){
      analogWrite(MotorSpeed,SpeedVal);
      delay(40);
  }
  analogWrite(MotorSpeed,0);
  //Ramps up the speed in the counter clockwise direction.  
  digitalWrite(MotorDirection, HIGH);                //Loop increases the speed slowly until it reaches max speed.
  for(SpeedVal = 0; SpeedVal < 255; SpeedVal++){
      analogWrite(MotorSpeed,SpeedVal);
      delay(40);
  } 
  analogWrite(MotorSpeed,0);
  
}
