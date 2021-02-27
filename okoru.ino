#include <Servo.h>
#define SENSOR 5
#define IRU 1
#define INAI 0

Servo waiservo;

unsigned char human = IRU;
unsigned char prev_state;

void anger(void);

void setup()
{
    pinMode(SENSOR, INPUT);
    Serial.begin(9600);
    waiservo.attach(3);
}

void loop()
{
    human = digitalRead(SENSOR);
    Serial.println(human);
    Serial.println(prev_state);
    if ((human == INAI && prev_state == IRU))
    {
        for (int i = 0; i <= 30; i++)
        {
            delay(1000);
            Serial.println(i);
            if (digitalRead(SENSOR) == IRU)
            {
                break;
            }
            if (i == 30)
            {
                anger();
                i = 0;
                break;
            }
        }
    }
    delay(500);
    prev_state = human;
}

void anger(void)
{
    for (;;)
    {
        human = digitalRead(SENSOR);
        waiservo.write(0);
        delay(300);
        waiservo.write(90);
        delay(300);
        waiservo.write(180);
        delay(300);
        waiservo.write(90);
        delay(300);
        if (human == IRU)
        {
            break;
        }
    }
}