#include <FEHLCD.h>
#include <FEHUtility.h>
#include <FEHServo.h>
#include <FEHIO.h>
#include <FEHMotor.h>

// declare motor on motor port 0 and 1, set maximum voltage to 9.0 V
FEHMotor drive_motorleft(FEHMotor::Motor2,9.0);
FEHMotor drive_motorright(FEHMotor::Motor3,9.0);
//FEHServo servo(FEHServo::Servo0);

int main()
{
    // Declare variables
    //float sensorVal, degree;
    
    bool run = false, partonedone=false, partonenotdone=true; 


    // Declare input pins
    //AnalogInputPin Sensor1(FEHIO::P0_0);
    DigitalInputPin leftf(FEHIO::P0_0);
    DigitalInputPin rightf(FEHIO::P0_1);
    DigitalInputPin leftb(FEHIO::P0_2);
    DigitalInputPin rightb(FEHIO::P3_7);

    bool leftfor = leftf.Value();
    bool rightfor = rightf.Value();
    bool leftback = leftb.Value();
    bool rightback = rightb.Value();
    int a;
 

    LCD.Clear();

    while (true){

        if (LCD.Touch(&a,&a)){
            //run = true;
            drive_motorleft.SetPercent(25);
            drive_motorright.SetPercent(25);
            LCD.Write("hey");
        }
        LCD.Write("please");
        if(!leftfor){
            LCD.Write("left");
            drive_motorleft.Stop();
            drive_motorright.Stop();
            Sleep(3000);
        }
        while (run){
            if (!leftfor && !rightfor && partonenotdone){
                drive_motorleft.Stop();
                drive_motorright.Stop();
                Sleep(3000);
                drive_motorright.SetPercent(-25);
            }
            if (!leftback  && !rightback && partonenotdone){
                drive_motorright.Stop();
                drive_motorleft.SetPercent(25);
                drive_motorright.SetPercent(25);
                partonedone=true;
                partonenotdone = false;
            }
            if(leftback == 0 && rightback == 0 && partonedone){
                drive_motorleft.Stop();
                drive_motorright.Stop();
                drive_motorleft.SetPercent(-25);
            }
            if(leftback == 0 && rightback == 0 && partonedone){
                drive_motorleft.Stop();
                drive_motorleft.SetPercent(25);
                drive_motorright.SetPercent(25);
                run = false;
            }
        }

    }


// // drive motor forward at 85% motor power
// drive_motor.SetPercent(85);
// Sleep(5.0);
// drive_motor.Stop();
// Sleep(0.1);
// // drive motor backward at 65% motor power
// drive_motor.SetPercent(-65);
// Sleep(5.0);
// drive_motor.Stop();
// Sleep(0.1);

    // servo.SetMin(500);
    // servo.SetMax(2370);

    // while(true)
    // {
    //     sensorVal = Sensor1.Value();
    //     LCD.Write(sensorVal);
    //     LCD.Write("\n");
    //     Sleep(250);

    //     degree = sensorVal*180/3.3;
        
    //     servo.SetDegree(degree);
    // }

}


