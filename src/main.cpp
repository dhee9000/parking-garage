#include <iostream>
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

            cout << "Verifiying Garage Parameters...";
        } while (!(SPOTS_PER_LEVEL >= SPOTS_PER_ROW && SPOTS_PER_LEVEL % SPOTS_PER_ROW == 0 && NUM_OF_LEVELS > 0));
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

    Garage *g = new Garage(NUM_OF_LEVELS, SPOTS_PER_LEVEL, SPOTS_PER_ROW);
    g->clearGarage();
    cout << g->toString();

    char action = 'v'; // Default to View Garage

    do
    {
        // Action legend (first letter of choice)
        cout << "Choose an action: " << endl;
        cout << "(p)ark a vehicle" << endl;
        cout << "(r)eturn a vehicle" << endl;
        cout << "(v)iew garage" << endl;
        cout << "(e)xit" << endl;

        cin >> action;
        cin.ignore(); // Safe Input

        switch(action){
            case 'v':
            {
                g->toString();
            }
            default:
            {
                cout << "Invalid Selection! Please choose again!" << endl;
                action = 'v';
            }
        }

    } while(action != 'e');
}