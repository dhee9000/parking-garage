#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Spot.hpp"

using namespace std;

class Garage {

    private:
        int LEVELS;
        int SPOTS_L;
        int SPOTS_R;
        int LARGE_L;
        int MEDIUM_L;
        int SMALL_L;
        int ROWS_L;

        vector<Spot*>* spots = new vector<Spot*>;

    public:
        Garage();
        Garage(int num_levels, int spots_level, int spots_row);
        ~Garage();

        void clearGarage();
        string toString();
};