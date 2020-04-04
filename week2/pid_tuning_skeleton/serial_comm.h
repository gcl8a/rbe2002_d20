/*
 * For managing input over the serial stream (USB for the 32U4).
 * 
 * Be sure to set your Serial Monitor to append a NEWLINE character to each line.
 * (See the dropdown near the bottom of the Serial Monitor.)
 * 
 * Format is a single letter, followed by a number. The number represents either
 * a target speed or a PID gain; see ParseSerialInput() below for what is what.
 * 
 * Examples:
 * 
 * Sending  R10    will set the target speed of the right wheel to 10
 * Sending  I1.2   will set the Ki term to 1.2
 * 
 * IT DOES NO ERROR CHECKING! 
 * You won't break anything if the format is wrong, but neither will it work.
 * 
 * Also, I didn't break it up into .h and .cpp files. You'll want to do that
 * if you incorporate this into other code.
 */

#ifndef __SERIAL_COMM_H
#define __SERIAL_COMM_H

String serialInput;

bool CheckSerialInput(void)
{
  if(Serial.available())
  {
    char c = Serial.read();
    serialInput += c;
    if(c == '\n') return true;
  }

  return false;
}

void ParseSerialInput(void)
{
  switch(serialInput[0])
  {
    case 'P':
      Kp = serialInput.substring(1).toFloat();
      Serial.print("Setting Kp to: ");
      Serial.println(Kp);
      break;
    case 'I':
      Ki = serialInput.substring(1).toFloat();
      Serial.print("Setting Ki to: ");
      Serial.println(Ki);
      break;
    case 'D':
      Kd = serialInput.substring(1).toFloat();
      Serial.print("Setting Kd to: ");
      Serial.println(Kd);
      break;
    case 'L': //target speed
      targetLeft = serialInput.substring(1).toFloat();
      Serial.print("Setting left target to: ");
      Serial.println(targetLeft);
      break;
    case 'R': //target speed
      targetRight = serialInput.substring(1).toFloat();
      Serial.print("Setting right target to: ");
      Serial.println(targetRight);
      break;
  }

  serialInput = "";
}

#endif
