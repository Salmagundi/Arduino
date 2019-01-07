// Servo Driver version 2
// This sketch controls servo position via potentiometer joy stick position rate of servo position change is determined by
// the magnitude of the deflection from centre. The push button centeralises the servos
// Pin 2 digital input joy stick push switch
// Joystick x analog input pin A0, y analog input A1
// Servo x PWM pin 5, y PWM pin 3

#include <Servo.h>               // Include the servo libraries
               
Servo X_servo;                    // Create and instance to drive the X servo
Servo Y_servo;                     // Create and instance to drive the X servo

int push_sw = 0;                  // state of push switch
int joystick_X = 512;             // X value of joystick position
int joystick_Y = 512;             // Y value of joystick position
float servo_X = 90;                 // X value to servo
float servo_Y = 90;                 // Y value to servo
float DeltaX = 0;                   // Change in the position of the X servo
float DeltaY = 0;                   // Change in the position of the y servo

void setup() {
  
  pinMode (2,INPUT_PULLUP);       // Set pin 2 for potentiometer push switch input
  X_servo.attach (5);             // Connect the instance to pin 3
  Y_servo.attach (3);             // Connect the instance to pin 5
  Serial.begin (9600); 
  
}

void loop() {

  X_servo.write (servo_X);        // Drive the servos to the value of servo_X & servo_Y
  Y_servo.write (servo_Y);
  
  joystick_X = analogRead (A0);    // Read X potentiometer position
  joystick_Y = analogRead (A1) + 3;    // Read y potentiometer position ( +3 compensates for a centre error in the Y axis

  DeltaX = map (joystick_X, 0, 1023, -8, 8);    // Map joystick positions to the servo change magnitude
  DeltaY = map (joystick_Y, 0, 1023, -8, 8);

  servo_X = servo_X + DeltaX;     // Shift servo IAW joystick deflection
  servo_Y = servo_Y + DeltaY;
  
  // Limit the value of the servo position to between 0 and 180
  if (servo_X >= 180)
  {
    servo_X = 180;     
  } 
  if (servo_X <= 0) 
  {
    servo_X = 0;
  } 
  if (servo_Y >= 180) 
  {
    servo_Y = 180;
  } 
  if (servo_Y <= 0)
  {
    servo_Y = 0;
  }
  delay (50);

  // if the push button is pressed centre the servos
  if (digitalRead (2) == LOW)   
  {              
  servo_X = 90;
  servo_Y = 90;
  delay (500);
  }
  
 }
  
  // digitalWrite (13, push_sw);      // send switch state to LED on pin 13

  // Serial.println (joystick_X);    //Send X position values to the serial monitor
  // Serial.println (joystick_Y);    //Send Y position values to the serial monitor
  // Serial.println ("____");        //Print new line seperator
  // delay (500);
