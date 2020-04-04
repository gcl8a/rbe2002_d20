#include <Zumo32U4Motors.h>
#include <Zumo32U4Encoders.h>

#include <button.h>       //include your button class from last week
#include <event_timer.h>  //include your shiny, new event timer class

Button buttonA(14); //button A is pin 14 on the Zumo
EventTimer timer;   //assumes you named your class EventTimer

//use the Pololu libraries for motors and encoders
Zumo32U4Motors motors;
Zumo32U4Encoders encoders; //(we're not acutally using this in this code, but we will soon)

//declare the robot states here
//...

void setup()
{
  Serial.begin(115200);
  Serial.println("Hello.");

  buttonA.Init(); //don't forget to call Init()!
}

void loop() 
{  
  //put in a simple event-driven structure
  //if(SomeEvent()) HandleSomeEvent()
  //...
}

//add you handlers here:
//handle the button press
//handle the timer expiring

//you'll want a function called Drive() to actually implement the motor commands and start the timer
void Drive(int iSeg) //pass it the number of the Segment you wish to execute
{
  //...
}
