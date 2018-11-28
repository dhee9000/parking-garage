#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Garage.hpp"

using namespace std;

int main()
{

    // Garage Parameters and Interaction Variables

    int NUM_OF_LEVELS;
    int SPOTS_PER_LEVEL;
    int SPOTS_PER_ROW;

    string customGarage;

    // Begin User Interaction

    cout << "Welcome to Smart Garage v0.0.1" << endl;

    while (customGarage != "yes" && customGarage != "no")
    {
        cout << "Would you like to define a custom garage? (yes/no)? >";
        cin >> customGarage;
    }

    if (customGarage == "yes")
    {
        cout << "Please input the following garage parameters:" << endl;
        do
        {
            cout << "Number of Levels: ";
            cin >> NUM_OF_LEVELS;

            cout << "Spots Per Level: ";
            cin >> SPOTS_PER_LEVEL;

            cout << "Spots Per Row: ";
            cin >> SPOTS_PER_ROW;

            cout << "Verifiying Garage Parameters..." << endl;
        } while (!(SPOTS_PER_LEVEL >= SPOTS_PER_ROW && SPOTS_PER_LEVEL % SPOTS_PER_ROW == 0 && NUM_OF_LEVELS > 0 && SPOTS_PER_LEVEL > 0 && SPOTS_PER_ROW > 0 && SPOTS_PER_ROW <= SPOTS_PER_LEVEL));
    }
    else
    {
        cout << "Constructing garage with default parameters..." << endl;
        NUM_OF_LEVELS = 5;
        SPOTS_PER_LEVEL = 30;
        SPOTS_PER_ROW = 10;
    }

    // Garage Parameters are valid, display message to user and proceed.

    cout << "Valid Garage Parameters!" << endl;

    Garage *myGarage = new Garage(NUM_OF_LEVELS, SPOTS_PER_LEVEL, SPOTS_PER_ROW);
    myGarage->clearGarage();
    cout << myGarage->toString() << endl;

    char action = 'v'; // Default to View Garage

    do
    {
        // Action legend (first letter of choice)
        cout << "\nActions:: " << endl;
        cout << "(p)ark a vehicle" << endl;
        cout << "(r)eturn a vehicle" << endl;
        cout << "(v)iew garage" << endl;
        cout << "(e)xit" << endl;
        cout << "Select One: ";

        cin >> action;
        cin.ignore(); // Safe Input

        cout << endl;

        switch (action)
        {
        case 'v':
        {
            cout << myGarage->toString() << endl;
            break;
        }
        case 'p':
        {
            int vType;
            cout << "What type of vehicle?" << endl;
            cout << "0 - Motorcycle" << endl;
            cout << "1 - Car" << endl;
            cout << "2 - Bus" << endl;
            cout << "3 - Other" << endl;
            cin >> vType;

            if (vType < 4 && vType > -1)
            {
                Vehicle *myV = new Vehicle(vType);
                cout << "\nYour vehicle has ID " << myV->getID() << endl;

                int token = myGarage->park(myV);
                if (token != -1)
                {
                    cout << "Your valet token is " << setfill('0') << setw(3) << token << endl;
                }
                else
                {
                    cout << "Parking Lot Full!" << endl;
                }
            }
            else
            {
                cout << "This garage currently doesn't support that vehicle type!" << endl;
            }
            break;
        }
        case 'r':
        {
            int token;
            cout << "Enter the token of the vehicle to return" << endl;
            cin >> token;
            cout << "Retrieving vehicle..." << endl;
            myGarage->returnVehicle(token);
            break;
        }
        case 'e':
        {
            string confirmation = "";
            cout << "Are you sure you'd like to exit? (yes/No): ";
            cin >> confirmation;

            if (confirmation != "yes")
            {
                action = 'v';
            }
            break;
        }
        default:
        {
            cout << "Invalid Selection! Please choose again!" << endl;
            action = 'v';
        }
        }

    } while (action != 'e');

    cout << "\nProgram Exiting!" << endl;
}