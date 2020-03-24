const uint8_t buttonPin = 14; //button A on the Romi

void setup() 
{
  Serial.begin(115200);
  
  pinMode(buttonPin, INPUT_PULLUP);
}

unsigned long buttonCount = 0;

void loop() 
{
  if(CheckButtonPress()) 
  {
    Serial.println(++buttonCount);
  }
}

/*
 * This will fail because is only checks the state!
 */
bool CheckButtonPress(void)
{
  if(!digitalRead(buttonPin)) return true; //button is active LOW
  else return false;
}

/*
 * CheckButtonEvent() uses proper event checking, but no debouncing!
 * This will not work well in practice, but is used as a demonstration of 
 * the side effects of bouncing
 */
bool CheckButtonEvent(void)      
{
  static uint8_t prevButton = HIGH; //static gives prevButton global persistance
  bool returnValue = false;         //initialize a return value; carry it through

  uint8_t currButton = digitalRead(buttonPin);  //current button state; read only once!
  if(prevButton && ! currButton) returnValue = true;  //EVENT of button being pushed down

  prevButton = currButton;    //don't forget to update the previous state

  return returnValue;               //now return the result
}
