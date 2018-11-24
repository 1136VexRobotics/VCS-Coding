#include "robot-config.h"

int forwardspeed = 25;
int turnspeed = 25;
float frdrotations = .75;
float turn = .8;

void reset_motor_rotations()
{
    LF.resetRotation();    
    RF.resetRotation();    
    RR.resetRotation();    
    LR.resetRotation();    
}    

void stopmotors()
{
    LF.stop();
    RF.stop();
    RR.stop();   
    LR.stop();       
}   

void straight()//12.56 inches of travel per rotation
{
    Brain.Screen.print("Forward ");
    Brain.Screen.print (frdrotations);
    Brain.Screen.print(" Rotations");
    Brain.Screen.newLine();
    RR.startRotateTo(-frdrotations,vex::rotationUnits::rev, forwardspeed,vex::velocityUnits::pct);
    LR.startRotateTo(frdrotations,vex::rotationUnits::rev, forwardspeed,vex::velocityUnits::pct);
    RF.startRotateTo(-frdrotations,vex::rotationUnits::rev, forwardspeed,vex::velocityUnits::pct);
    LF.startRotateTo(frdrotations,vex::rotationUnits::rev, forwardspeed,vex::velocityUnits::pct);      
while (LF.isSpinning() || RF.isSpinning())
{}
    reset_motor_rotations();
} 

void turn_90R()
{
    Brain.Screen.print("Turn Right 90 degrees");
    Brain.Screen.newLine();
    RR.startRotateTo(turn,vex::rotationUnits::rev, turnspeed,vex::velocityUnits::pct);
    LR.startRotateTo(turn,vex::rotationUnits::rev, turnspeed,vex::velocityUnits::pct);
    RF.startRotateTo(turn,vex::rotationUnits::rev, turnspeed,vex::velocityUnits::pct);
    LF.startRotateTo(turn,vex::rotationUnits::rev, turnspeed,vex::velocityUnits::pct);   
while (LF.isSpinning() || RF.isSpinning())
{}
      reset_motor_rotations();
}

void turn_90L()
{
    Brain.Screen.print("Turn Left 90 degrees");
    Brain.Screen.newLine();
    RR.startRotateTo(-turn,vex::rotationUnits::rev, turnspeed,vex::velocityUnits::pct);
    LR.startRotateTo(-turn,vex::rotationUnits::rev, turnspeed,vex::velocityUnits::pct);
    RF.startRotateTo(-turn,vex::rotationUnits::rev, turnspeed,vex::velocityUnits::pct);
    LF.startRotateTo(-turn,vex::rotationUnits::rev, turnspeed,vex::velocityUnits::pct);   
      
    while (LF.isSpinning() || RF.isSpinning())
{}
      reset_motor_rotations();
}



int main() 
{

    Brain.Screen.print("Autonomous Program has Started.");
    Brain.Screen.newLine();
    vex::task::sleep(1000);
    straight();
    vex::task::sleep(1000);
    turn_90R();
    vex::task::sleep(1000);
    straight(); 
    vex::task::sleep(1000);
    turn_90L();
     vex::task::sleep(4000);
    straight();
    
}
