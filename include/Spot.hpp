#pragma once
#include "Vehicle.hpp"

class Spot {

    private:

        int type = 0;
        // type 0 = small
        // type 1 = medium
        // type 2 = large

        Vehicle* vehicle;

    public:
        Spot();
        Spot(int type);
        ~Spot();

        bool isTaken();
        int getType();
};