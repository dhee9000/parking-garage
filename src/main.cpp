/* 
Author: Dheeraj Yalamanchili
Class: CS2336.001 (CPP)
Project: ParkingGarageProject
*/

/*
main.cpp description:

Driver / runner for the entire project, accepts user input, instantiates garage and performs operations on it.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Garage.hpp"

using namespace std;

/*
getInput is a template function that takes in a reference to a varible and tries to extract from
cin onto that variable.
It checks if cin enters a failure state and if it does, it corrects and tries again.
*/
template <typename myType>
void getInput(myType &inputVar)
{

    cin >> inputVar;

    while (!cin)
    {
        cin.clear();           // Restore input stream to working state
        cin.ignore(100, '\n'); // Get rid of any garbage that user might have entered
        cout << "Invalid selection! Try again: " << endl;
        cin >> inputVar; // After cin is restored and any garbage in the stream has been cleared, store user input in number again
    }
}

int main()
{

    // Garage Parameters and Interaction Variables

    int NUM_OF_LEVELS;
    int SPOTS_PER_LEVEL;
    int SPOTS_PER_ROW;

    string customGarage;

    // Begin User Interaction

    cout << "Welcome to Smart Garage" << endl;
    cout << "AUTHOR: Dheeraj Yalamanchili (DXY170002)\n" << endl;

    while (customGarage != "yes" && customGarage != "Y" && customGarage != "y" && customGarage != "YES" && customGarage != "Yes" && customGarage != "no" && customGarage != "n" && customGarage != "N" && customGarage != "No")
    {
        cout << "Would you like to define a custom garage? (yes/no)? >";

        getInput(customGarage);
    }

    if (!(customGarage != "yes" && customGarage != "Y" && customGarage != "y" && customGarage != "YES" && customGarage != "Yes"))
    {
        cout << "Please input the following garage parameters:" << endl;

        bool parametersValid = false;

        do
        {
            // Parameter Input
            cout << "Number of Levels: ";
            getInput(NUM_OF_LEVELS);

            cout << "Spots Per Level: ";
            getInput(SPOTS_PER_LEVEL);

            cout << "Spots Per Row: ";
            getInput(SPOTS_PER_ROW);

            cout << "\nVerifiying Garage Parameters..." << endl;

            // Parameter Validation and Rules Display
            if (!(SPOTS_PER_LEVEL >= SPOTS_PER_ROW && SPOTS_PER_LEVEL % SPOTS_PER_ROW == 0 && NUM_OF_LEVELS > 0 && SPOTS_PER_LEVEL >= 5 && SPOTS_PER_ROW >= 5 && SPOTS_PER_ROW % 5 == 0))
            {
                cout << "Input Parameters Invalid!" << endl;
                cout << "\nRULES: " << endl;
                cout << boolalpha;
                cout << "Spots Per Level must be greater than or equal to Spots Per Row: " << (SPOTS_PER_LEVEL >= SPOTS_PER_ROW) << endl;
                cout << "Spots Per Level must be divisible by Spots Per Row: " << (SPOTS_PER_LEVEL % SPOTS_PER_ROW == 0) << endl;
                cout << "Spots Per Level must be divisible by 5: " << (SPOTS_PER_LEVEL % 5 == 0) << endl;
                cout << "There must be at least one Level: " << (NUM_OF_LEVELS > 0) << endl;
                cout << "There must be at least five Spots Per Row: " << (SPOTS_PER_LEVEL >= 5) << endl;
                cout << "There must be at least five Spots Per Row: " << (SPOTS_PER_ROW >= 5) << endl
                     << endl;
            }
            else
            {
                parametersValid = true;
            }

        } while (!parametersValid);
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

    // Construct and clear garage with garage parameters
    Garage *myGarage = new Garage(NUM_OF_LEVELS, SPOTS_PER_LEVEL, SPOTS_PER_ROW);
    myGarage->clearGarage();
    cout << myGarage->toString() << endl;

    char action = 'v'; // Default action to View Garage

    do
    {
        // Action legend (first letter of choice)
        cout << "\nActions:: " << endl;
        cout << "(p)ark a vehicle" << endl;
        cout << "(r)eturn a vehicle" << endl;
        cout << "(v)iew garage" << endl;
        cout << "(e)xit" << endl;
        cout << "Select One: ";

        getInput(action);

        cout << endl;

        // Check and execute whichever action was selected
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

            getInput(vType);

            if (vType < 3 && vType > -1)
            {
                Vehicle *myV = new Vehicle(vType);
                cout << "\nYour vehicle has ID " << myV->getID() << endl; // Gets Vehicle ID from Vehicle

                int token = myGarage->park(myV); // Attempt Parking
                if (token != -1)                 // Parking Successful!
                {
                    cout << "Your valet token is " << setfill('0') << setw(3) << token << endl;
                }
                else // Spot couldn't be found!
                {
                    cout << "Parking lot full or no spots available for this vehicle!" << endl;
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

            getInput(token);

            cout << "\nRetrieving vehicle..." << endl;
            myGarage->returnVehicle(token);
            break;
        }
        case 'e':
        {
            string confirmation = "";
            cout << "Are you sure you'd like to exit? (yes/No): ";

            getInput(confirmation);

            if (confirmation != "yes" && confirmation != "Y" && confirmation != "y" && confirmation != "YES" && confirmation != "Yes")
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