#include <IRremote.h>
int sensor = 3;
int gate=8;
IRrecv ip(sensor);
decode_results results;

void setup() {
  Serial.begin(9600);
  ip.enableIRIn();
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  pinMode(gate, OUTPUT);
}

void loop()
{
  if (ip.decode(&results))
  {

    switch (results.value)
    {
      case 2160022444: digitalWrite(gate, HIGH);
        break;

      case 2160020404: digitalWrite(gate, LOW);
        break;

      default:
        {
          if (results.value != 0xFFFFFFFF)
          {
            Serial.println(results.value, DEC);
            break;
          }
        }
    }
    ip.resume();
    delay(20);
  }
}
