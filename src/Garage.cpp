/* 
Author: Dheeraj Yalamanchili
Class: CS2336.001 (CPP)
Project: ParkingGarageProject
*/

#include "Garage.hpp"

Garage::Garage()
{
}

/*
Parametric constructor takes in num of levels, spots per level, and spots per row

It sets the class variables to these values and then creates an array of Spot objects each
initialized to their appropriate type based on the distribution of the types of spots in each level.

This constructor assumes the input values being fed are valid for a Garage.
*/
Garage::Garage(int num_levels, int spots_level, int spots_row)
{
    this->LEVELS = num_levels;
    this->SPOTS_L = spots_level;
    this->SPOTS_R = spots_row;

    this->ROWS_L = spots_level / spots_row;

    this->SMALL_L = 20 * SPOTS_L / 100;
    this->MEDIUM_L = 60 * SPOTS_L / 100;
    this->LARGE_L = 20 * SPOTS_L / 100;

    cout << "\nGarage created: " << endl;
    cout << "Levels: " << LEVELS << endl;
    cout << "Spots Per Level: " << SPOTS_L << endl;
    cout << "SPOTS Per Row: " << SPOTS_R << endl
         << endl;

    cout << SMALL_L << " small spots per level." << endl;
    cout << MEDIUM_L << " medium spots per level." << endl;
    cout << LARGE_L << " large spots per level." << endl
         << endl;

    cout << "Creating Spots..." << endl;

    this->size = SPOTS_L * LEVELS;
    this->spots = new Spot[size];

    for (int i = 0; i < LEVELS; i++)
    {
        for (int s = 0; s < SPOTS_L; s++)
        {

            if (s < SMALL_L)
            {
                spots[i * SPOTS_L + s] = *(new Spot(0)); // Motorcycle
            }
            else if (s < MEDIUM_L + SMALL_L)
            {
                spots[i * SPOTS_L + s] = *(new Spot(1)); // Compact
            }
            else if (s < LARGE_L + MEDIUM_L + SMALL_L)
            {
                spots[i * SPOTS_L + s] = *(new Spot(2)); // Large
            }
        }
    }

    cout << "First Compact Spot is " << findFirst(1) << endl;
    cout << "First Motorcycle Spot is " << findFirst(0) << endl;
    cout << "First Large Spot is " << findFirst(2) << endl;
}

Garage::~Garage()
{
    delete this->spots; // Free up dynamically allocated memory.
}

void Garage::clearGarage()
{

}

/*
The park tries to park a vehicle and returns the token if successful, else -1.

It uses the findFirst method to find the first spot of vehicle type and then parks it.
If the vehicle is a bus, it automatically parks the bus in the next 4 spaces as well since buses take 5 spaces.
It also has a function where if a spot of the type of the vehicle couldn't be found, it looks for a bigger spot
that could still hold the vehicle and uses that instead.
*/
int Garage::park(Vehicle *v)
{
    int t = v->getType();
    int token = -1;
    int first = this->findFirst(t);
    if (first != -1)
    { // There is an available spot
        token = first;
        if (t < 2)
        { // It is a car or motorcycle, only need one spot
            this->spots[first].parkSpot(v);
        }
        else
        {
            for (int i = 0; i < 5; i++)
            {
                this->spots[first + i].parkSpot(v);
            }
        }
    }
    return token;
}

/*
returnVehicle outputs the vehicle in a spot and removes it from it's parking Spot.

It checks if the token provided is within bounds of the garage array and then checks if there is a vehicle present.
If there is, it clears it out and outputs its ID to verify that it was the same vehicle.
If the vehicle is a bus, it also releases the next 5 spaces before returning to free up the space taken by the bus.
*/
void Garage::returnVehicle(int token)
{
    Vehicle *v;
    if (token < this->size)
    {
        cout << "Token Valid!" << endl;
        if (this->spots[token].isTaken())
        {
            cout << "Vehicle Found!" << endl;
            if (this->spots[token].getVehicleType() == 2)
            {
                for (int i = 1; i < 5; i++)
                {
                    this->spots[token + i].releaseSpot();
                }
            }
            v = this->spots[token].releaseSpot();
            cout << "Returned vehicle with ID " << v->getID() << endl;
        }
        else
        {
            cout << "There is no vehicle parked at this spot!" << endl;
        }
    }
    else
    {
        cout << "Token out of bounds!" << endl;
    }
}

/*
toString goes through each of the spots in the garage level wise and returns their status represented as a string from their
toString methods.
*/
string Garage::toString()
{
    string garageString = "\nGarage View: ";

    for (int i = 0; i < SPOTS_L * LEVELS; i++)
    {
        if (i % SPOTS_L == 0)
        {
            garageString += "\n";
            garageString += "LEVEL " + to_string(LEVELS - i / SPOTS_L) + ": ";
        }
        garageString += spots[i].toString(); //to_string(spots[i].getType());
    }
    return garageString;
}

/*
findFirst finds the first index in the parking garage where the type of spot matches the vehicle and is vacant.
If no spot can be found it tries to find a bigger spot that is vacant and could still park the vehicle.
If even that can't be found it returns -1.
*/
int Garage::findFirst(int type)
{
    int idx = -1; // Initialize to error state, returns not found
    for (int i = 0; i <= size; i++)
    {
        Spot s = this->spots[i];
        if (!s.isTaken() && s.getType() == type)
        {
            if (type < 2)
            {
                idx = i;
                break;
            }
            else if (type == 2)
            {
                bool canParkBus = true;
                for (int n = 1; n < 5; n++)
                {
                    if (this->spots[i + n].isTaken() || this->spots[i + n].getType() != type)
                        canParkBus = false;
                }
                if (canParkBus)
                {
                    idx = i;
                    break;
                }
            }
        }
    }
    if (idx == -1)
    { // Couldn't find a regular spot to park in, look for alternatives (bigger spot, smaller vehicle)
        if (type < 2)
        {
            for (int i = 0; i < size; i++)
            {
                Spot s = this->spots[i];
                if (!s.isTaken() && s.getType() > type)
                {
                    cout << "Matching spot type couldn't be found, using larger spot for small vehicle!" << endl;
                    cout << "Vehicle is type " << type << " but spot is type " << s.getType() << endl;
                    idx = i;
                    break;
                }
            }
        }
    }
    return idx;
}