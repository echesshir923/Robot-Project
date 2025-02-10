#include <FEHLCD.h>
#include <FEHUtility.h>
#include <FEHServo.h>
#include <FEHIO.h>

FEHServo servo(FEHServo::Servo0);

int main()
{
    // Declare variables
    float sensorVal, degree;
    int leftfor, rightfor, leftback, rightback;

    // Declare input pins
    AnalogInputPin Sensor1(FEHIO::P0_0);
    DigitalInputPin leftfor(FEHIO::P1_0);
    DigitalInputPin rightfor(FEHIO::P1_1);
    DigitalInputPin leftback(FEHIO::P1_2);
    DigitalInputPin rightback(FEHIO::P1_3);

    LCD.Clear();

    servo.SetMin(500);
    servo.SetMax(2370);

    while(true)
    {
        sensorVal = Sensor1.Value();
        LCD.Write(sensorVal);
        LCD.Write("\n");
        Sleep(250);

        degree = sensorVal*180/3.3;
        
        servo.SetDegree(degree);
    }

}


