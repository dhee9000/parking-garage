/* 
Author: Dheeraj Yalamanchili
Class: CS2336.001 (CPP)
Project: ParkingGarageProject
*/

#include "Garage.hpp"

Garage::Garage()
{
}

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
                cout << "MSpot" << endl;
            }
            else if (s < MEDIUM_L + SMALL_L)
            {
                spots[i * SPOTS_L + s] = *(new Spot(1)); // Compact
                cout << "CSpot" << endl;
            }
            else if (s < LARGE_L + MEDIUM_L + SMALL_L)
            {
                spots[i * SPOTS_L + s] = *(new Spot(2)); // Large
                cout << "LSpot" << endl;
            }
        }
    }

    cout << "First Compact Spot is " << findFirst(1) << endl;
    cout << "First Motorcycle Spot is " << findFirst(0) << endl;
    cout << "First Large Spot is " << findFirst(2) << endl;
}

Garage::~Garage()
{
}

void Garage::clearGarage()
{
}

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

string Garage::toString()
{
    string garageString = "\nGarage View: ";

    for (int i = 0; i < SPOTS_L * LEVELS; i++)
    {
        if (i % SPOTS_L == 0)
        {
            garageString += "\n";
            garageString += "LEVEL: " + to_string(LEVELS - i / SPOTS_L) + ": ";
        }
        garageString += spots[i].toString();
    }
    return garageString;
}

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
            for (int i = 0; i <= size; i++)
            {
                Spot s = this->spots[i];
                cout << s.getType() << " ";
                if (!s.isTaken() && s.getType() > type)
                {
                    cout << "Matching spot type couldn't be found, using larger spot for small vehicle!" << endl;
                    cout << "Vehicle is size " << type << " but spot is size " << s.getType() << endl;
                    idx = i;
                    break;
                }
            }
        }
    }
    return idx;
}