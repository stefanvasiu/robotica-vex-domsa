#include "vex.h"

vex::brain       Brain;
vex::motor       LeftMotor(vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor       RightMotor(vex::PORT10, vex::gearSetting::ratio18_1, true);
vex::motor       ArmMotor(vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::controller  Controller1;

int main() {
    Brain.Screen.print("Robot Club Domșa - VEX");
    vex::task::sleep(1000);

    LeftMotor.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
    RightMotor.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
    vex::task::sleep(2000);

    LeftMotor.stop();
    RightMotor.stop();

    LeftMotor.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
    RightMotor.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
    vex::task::sleep(1000);

    ArmMotor.spinFor(vex::directionType::fwd, 90, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);

    LeftMotor.stop();
    RightMotor.stop();
    ArmMotor.stop();
}
