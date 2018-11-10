#include "Garage.hpp"

Garage::Garage()
{
}

Garage::Garage(int num_levels, int spots_level, int spots_row)
{
    this->LEVELS = num_levels;
    this->SPOTS_L = spots_level;
    this->SPOTS_R = spots_row;

    this->SMALL_L = (1 / 5) * spots_level;
    this->MEDIUM_L = (3 / 5) * spots_level;
    this->LARGE_L = (1 / 5) * spots_level;

    for(int lev = 0; lev <= LEVELS; lev++){

        // Create small spots in level
        for(int s = 0; s <= SMALL_L; s++){
            spots->push_back(new Spot(0));
        }
        //Create medium spots in level
        for(int m = 0; m <= MEDIUM_L; m++){
            spots->push_back(new Spot(1));
        }
        //Create large spots in level
        for(int l = 0; l <= MEDIUM_L; l++){
            spots->push_back(new Spot(1));
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
    string garageString;
    char Key[4] = "mcl";
    for(unsigned int i = 0; i < spots->size(); i++){ // Unsigned int to avoid warning when comparing to size (unsigned)
        garageString += to_string(spots->at(i)->getType());
    }
    return garageString;
}