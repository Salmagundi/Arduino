// Servo Driver
// This sketch controls servo position via proportional potentiometer joy stick position
// Pin 2 digital input joy stick push switch
// Joystick x analog input pin A0, y analog input A1
// Servo x PWM pin 3, y PWM pin 5

#include <Servo.h>               // Include the servo libraries
               
Servo X_servo;                    // Create and instance to drive the X servo
Servo Y_servo;                     // Create and instance to drive the X servo

int push_sw = 0;                  // state of push switch
int joystick_X = 512;             // X value of joystick position
int joystick_Y = 512;             // Y value of joystick position
int servo_X = 90;                 // X value to servo
int servo_Y = 90;                 // Y value to servo

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
  joystick_Y = analogRead (A1);    // Read y potentiometer position

  servo_X = map (joystick_X, 0, 1023, 1, 180);    // Map joystick positions to the servo positions
  servo_Y = map (joystick_Y, 0, 1023, 1, 180);
  
  // push_sw = digitalRead (2);       // Read push switch
  // digitalWrite (13, push_sw);      // send switch state to LED on pin 13

  // Serial.println (joystick_X);    //Send X position values to the serial monitor
  // Serial.println (joystick_Y);    //Send Y position values to the serial monitor
  // Serial.println ("____");        //Print new line seperator
  // delay (500);

}
