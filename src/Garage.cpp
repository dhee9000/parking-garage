#include "Garage.hpp"

Garage::Garage()
{
}

Garage::Garage(int num_levels, int spots_level, int spots_row)
{
    this->LEVELS = num_levels;
    this->SPOTS_L = spots_level;
    this->SPOTS_R = spots_row;

    this->ROWS_L = spots_level/spots_row;

    this->SMALL_L = 20 * SPOTS_L / 100;
    this->MEDIUM_L = 60 * SPOTS_L / 100;
    this->LARGE_L = 20 * SPOTS_L / 100;

    cout << "\nGarage created: " << endl;
    cout << "Levels: " << LEVELS << endl;
    cout << "Spots Per Level: " << SPOTS_L << endl;
    cout << "SPOTS Per Row: " << SPOTS_R << endl << endl;
    
    cout << SMALL_L << " small spots per level." << endl;
    cout << MEDIUM_L << " medium spots per level." << endl;
    cout << LARGE_L << " large spots per level." << endl << endl;

    cout << "Creating Spots..." << endl;

    this->spots = new Spot[SPOTS_L*LEVELS];

    for (int i = 0; i < LEVELS; i++)
    {
        for (int s = 0; s < SPOTS_L; s++)
        {
            
            if(s<SMALL_L){
                spots[i*SPOTS_L + s] = *(new Spot(0));
            }
            else if(s<MEDIUM_L){
                spots[i*SPOTS_L + s] = *(new Spot(1));
            }
            else if(s<LARGE_L){
                spots[i*SPOTS_L + s] = *(new Spot(2))
                ;
            }
        }
    }
}

Garage::~Garage()
{
}

void Garage::clearGarage()
{
}

string Garage::toString()
{
    string garageString = "\nGarage View: ";

    char Key[] = "mcl";

    for (int i = 0; i < SPOTS_L*LEVELS; i++)
    {
        if (i% SPOTS_L == 0)
        {
            garageString += "\n";
            garageString += "LEVEL: " + to_string(LEVELS - i/SPOTS_L);
        }

        garageString +=  Key[spots[i].getType()];

    }
    return garageString;
}