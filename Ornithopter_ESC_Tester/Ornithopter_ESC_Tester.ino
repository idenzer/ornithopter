#include <ESC.h>

ESC esc(4, 1000, 2000, 500);

void setup()
{
  esc.arm();
  Serial.begin(9600);
  Serial.println("Setup complete");
  delay(5000);
}

void loop()
{
  Serial.println("enter value");
  long s = 0;
  while (s == 0)
  {
    s = Serial.parseInt();
  }
  Serial.print("value: ");
  Serial.println(s);
  esc.speed(s);
  delay(10000);
  esc.stop();
  Serial.println("End Loop");
}
