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
    
    bool run = false, partonedone=false, finish=false; 


    // Declare input pins
    //AnalogInputPin Sensor1(FEHIO::P0_0);
    DigitalInputPin leftf(FEHIO::P0_0);
    DigitalInputPin rightf(FEHIO::P0_1);
    DigitalInputPin leftb(FEHIO::P0_2);
    DigitalInputPin rightb(FEHIO::P3_7);

    int a;
 

    LCD.Clear();

    while (true){

        if (LCD.Touch(&a,&a)){
            run = true;
            drive_motorleft.SetPercent(25);
            drive_motorright.SetPercent(25);
            LCD.Write("hey");
        }
        while (run){
            if (!leftf.Value() && !rightf.Value() && !partonedone){
                drive_motorleft.Stop();
                drive_motorright.Stop();
                Sleep(1000);
                drive_motorright.SetPercent(-25);
            }
            if (!leftb.Value()  && !rightb.Value() && !partonedone){
                drive_motorright.Stop();
                Sleep(1000);
                drive_motorleft.SetPercent(25);
                drive_motorright.SetPercent(25);
                partonedone=true;
            }
            if(!leftf.Value() && !rightf.Value() && partonedone){
                drive_motorleft.Stop();
                drive_motorright.Stop();
                Sleep(1000);
                drive_motorleft.SetPercent(-25);
            }
            if(!leftb.Value() && !rightb.Value() && partonedone){
                drive_motorleft.Stop();
                Sleep(1000);
                drive_motorleft.SetPercent(25);
                drive_motorright.SetPercent(25);
                finish=true;
            }
            if(!leftf.Value() && !rightf.Value() && finish){
                drive_motorleft.Stop();
                drive_motorright.Stop();
                run=false;
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
