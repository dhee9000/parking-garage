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
        float MEDIUM_L;
        float SMALL_L;
        float ROWS_L;

        Spot* spots;
        int size;

    public:
        Garage();
        Garage(int num_levels, int spots_level, int spots_row);
        ~Garage();

        void clearGarage();
        string toString();
};