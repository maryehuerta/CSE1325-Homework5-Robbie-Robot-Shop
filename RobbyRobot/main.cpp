#include <iostream>

#include <iostream>
#include <vector>

#include "ComponetType.h"

#include "robotpart.h"
#include "battery.h"
#include "head.h"
#include "arm.h"
#include "locomotor.h"
#include "torso.h"
int main() {
    bool passed = true;

    //
    // Test constructor
    //

    RobotPart robot_part(
            "The Grasping Arm",
            3,
            ComponetType::torso,
            13.6,
            19.99,
            "It's an arm that can hold a cup"
    );


    if (robot_part.get_name() != "The Grasping Arm")
        passed = false;
    else if (robot_part.get_partNumber() != 3)
        passed = false;
    else if (robot_part.get_cost() != 19.99)
        passed = false;
    else if (robot_part.get_weight() != 13.6)
        passed = false;
    else if (robot_part.get_description() != "It's an arm that can hold a cup")
        passed = false;
    else
        passed = true;

    //
    // Test Robot Parts: Battery, Head, Arm, and Locomotor
    //
    new Battery (31, 33, "TheBattery5000", 43, ComponetType::battery,13.6, 19.99, "It's an arm that can hold a cup");
    new Head(true, "RobotHead",43, ComponetType::head, 13.6, 19.99, "It's an arm that can hold a cup");
    new Arm(22, 22,"RobotArm",43, ComponetType::arm, 13.6, 19.99, "It's an arm that can hold a cup");
    new Locomotor(22 ,"RobotLocomotor",43, ComponetType::locomotor, 13.6, 19.99, "It's an arm that can hold a cup");

   


    cout << (passed ? "passed" : "failed") << endl;
}
