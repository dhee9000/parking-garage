#pragma once
#include "Vehicle.hpp"
#include <iostream>
#include <string>

using namespace std;

class Spot
{

  private:
    int type = 0;
    // type 0 = motorcycle
    // type 1 = compact
    // type 2 = large
    bool taken = false;
    Vehicle *vehicle;

  public:
    Spot();
    Spot(int type);
    ~Spot();

    bool isTaken();
    int getType();
    int getVehicleType();
    void parkSpot(Vehicle *v);
    Vehicle* releaseSpot();
    string toString();
};