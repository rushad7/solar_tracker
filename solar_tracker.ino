#include <Servo.h>
Servo servo;

int val0;
int val180;
int val90;
int val270;
int diff1;
int diff2;
int diff3;
int diff4;


void setup()
{

  Serial.begin(9600);
  servo.attach(9, 600, 2400);

}

void loop()
{

  val0 = analogRead(0);
  val180 = analogRead(1);
  val90 = analogRead(2);
  val270 = analogRead(3);
 
    Serial.print(val0);
    Serial.print(" ");
    Serial.print(val180);
    Serial.print(" ");
    Serial.print(val90);
    Serial.print(" ");
    Serial.println(val270);

  

  diff1  = val0  - val180;
  diff2  = val90  - val270;
  diff3  = val180 - val0;
  diff4  = val270 - val90;


  if (diff1 < 50 && diff2 < 50 && diff3 < 50 && diff4 < 50 )
  {
    servo.writeMicroseconds(1500);
  }

  else
  {

    if (val0 > 900)
    {
      servo.writeMicroseconds(1575);

    }

    else if (val180 > 900)
    {
      servo.writeMicroseconds(1630);
    }

    else if (val90 > 900)
    {
      servo.writeMicroseconds(1705);
    }
    else if (val270 > 900)
    {
      servo.writeMicroseconds(1500);
    }
  }




}
