//
// Created by Mary Huerta on 10/11/16.
//

#include "controller.h"
#include "shop.h"
#include "view.h"
#include "arm.h"
#include "battery.h"
#include "ComponetType.h"
#include "head.h"
#include "locomotor.h"
#include "RobotModel.h"
#include "RobotPart.h"
#include "torso.h"
#include <iostream>
#include <string>

using namespace std;

// Have user input a Character Command
void Controller::cli() {
    char cmd = 'Z';
    while (cmd != 'Q') {
        view.show_main_menu();
        cout << "Command? ";
        cin >> cmd;
        cin.ignore();
        cliSubMenu(cmd); // Send to another Menu
    }
}
void Controller::cliSubMenu(char cmd){
    char subCmd = 'Z';
    if (cmd == 'C'){ // Ask user for command from Create Menu
        view.create_menu();
        cout << "Command? ";
        cin >> subCmd;
        cin.ignore();
        execute_cmd_create(subCmd);
    }
    else if (cmd == 'Q'){

    }
    else {
        cerr << "Invalid Command" << endl << endl;

    }

}

// Users command executed
void Controller::execute_cmd_create(char cmd) {
    if (cmd == 'C') {
        /* name(rp_name),
            partNumber(rp_partNumber),
            componentType(rp_componentType),
            weight(rp_weight),
            cost(rp_cost),
            description(rp_description) { } */
        String name, description;
        int partNumber, type, maxHeads;
        double weight, cost;

        cout << "name? ";
        getline(cin, name);

        cout << "description? " ;
        getline(cin, description);

        cout << "PartNumber? #";
        cin >> partNumber;
        cin.ignore();

        cout << "weight? ";
        cin >> weight;
        cin.ignore();

        cout << "cost? $";
        cin >> cost;
        cin.ignore();

        cout << "Robot Part Types:" << endl;
        cout << "   1. Head  2.Locomotor 3.Torso 4.Arm 5.Battery" << endl;

        cout << "type? ";
        cin >> type;
        cin.ignore();

        if (type == 1){
            cout << "maxheads?";
            cin >> maxHeads;
            cin.ignore();
            shop.createRobotPart(new Head(true, name, partNumber, ComponetType::head, weight, cost, description));

        }
        if (type == 2){
            cout << "MaxSpeed?";
            cin >> maxHeads;
            cin.ignore();
            shop.createRobotPart(new Locomotor(true, name, partNumber, ComponetType::head, weight, cost, description));

        }
        if (type == 3){
            bool goodAmount = false;
            int batteryCompartments = 0;
            while (!goodAmount) {
                cout << "batteryCompartments(1 to 3)?";
                cin >> batteryCompartments;
                cin.ignore();
                if (batteryCompartments > 0 && batteryCompartments < 4) { goodAmount = true; }

            }

        }
        if (type == 4){
            int energy;
            int maxPower;
            cout << "energy?";
            cin >> energy;
            cin.ignore();
            cout << "maxPower?";
            cin >> maxPower;
            cin.ignore();
            shop.createRobotPart(new Arm(energy, maxPower ,name, partNumber, ComponetType::head, weight, cost, description));

        }
        if (type == 5){
            int energy;
            int maxPower;
            cout << "energy?";
            cin >> energy;
            cin.ignore();
            cout << "maxPower?";
            cin >> maxPower;
            cin.ignore();
            shop.createRobotPart(new Battery(energy, maxPower ,name, partNumber, ComponetType::head, weight, cost, description));

        }

    }
    else if (cmd == 'Q'){
        cout << "Going back to Main Menu" << endl;
    }

    else {
        cerr << "Invalid command - going back to Main Menu" << endl << endl;
    }





}

