/*Example code for testing the Cytron Technologies 10A Rev 2.0 Motor Driver
 *The code uses only two pins, one for the motor direction (Pin 9) 
 * and one for the motor speed (pin 9). The speed is set using PWM. 
 * This code also uses a potentiometer connected to pin A0 in order to control speed and direction
 * This code is meant to be run on the Arduino Uno hardware. 
 */


//Pins used to control direction and speed of the motor. Speed pin should be a pwm pin.
#define MotorDirection 8
#define MotorSpeed 9
#define PotPin A0

int SpeedVal = 0;

void setup() {
  //Declaration for the pins used, both should be outputs.
  pinMode(MotorDirection, OUTPUT);
  pinMode(MotorSpeed, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  SpeedVal = analogRead(PotPin); //Reads the position of the potentiometer

  //Makes the motor rotate in the clockwise direction.
  if(SpeedVal > 542){
    digitalWrite(MotorDirection, LOW);
    SpeedVal = map(SpeedVal, 542, 1024, 0, 255);
    analogWrite(MotorSpeed,SpeedVal);
  }
  
  //Makes the motor rotate in the counter clockwise direction. 
  else if(SpeedVal < 482){
    digitalWrite(MotorDirection, HIGH); 
    SpeedVal = map(SpeedVal, 482, 0, 0, 255);
    analogWrite(MotorSpeed,SpeedVal);
  }
  
  Serial.print("Motor Speed = ");
  Serial.println(SpeedVal);
  
}
