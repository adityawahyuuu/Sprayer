/*
 * Aditya Wahyu Pradhana
 * Sprayer Automatic Controll
 * June 17, 2021
*/

#define IN1 0
#define IN2 2
#define button1 14
#define button2 12
//#define button3 13

const long oneSecond = 1000;
const long oneMinute = oneSecond * 60;
int duration;
int counter;
int buttonState;
int val;

void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
//  start delay
  first:
    buttonWait(button1, button2);
    delay(1000);
    Serial.println("First");
  
//  fungsi rotation
  next:
    rotation();

//  fungsi delay
  int state = LOW;
  if (state == LOW)
  {
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    delay(duration);
    goto next;
  }

  
}

//  fungsi rotation
void rotation()
{
  analogWrite(IN1, 255);
  analogWrite(IN2, 0);
  delay(500);
  int state = LOW;
  if (state == LOW)
  {
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    delay(1000);
  }
  analogWrite(IN1, 0);
  analogWrite(IN2, 255);
  delay(500);
}

//  buttonWait function
void buttonWait(int buttonPin, int buttonCounter)
{
  int buttonState1 = 0;
  int buttonState2 = digitalRead(buttonCounter);
  Serial.println("Wait pressed");
  while(1)
  {
    int val = digitalRead(buttonCounter);
    if (val != buttonState2)
    {
      if (val == LOW)
      {
        counter++;
        duration = counter*oneMinute;
        Serial.print("Duration: ");
        Serial.print(duration/oneMinute);
        Serial.println(" Minutes");
      }
    }
    buttonState2 = val;
    
    buttonState1 = digitalRead(buttonPin);
    if (buttonState1 == HIGH) 
    {
      Serial.println("Pressed");
      return;
    }
    yield();
  }
}
