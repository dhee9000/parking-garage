/* 
Author: Dheeraj Yalamanchili
Class: CS2336.001 (CPP)
Project: ParkingGarageProject
*/

#include "Spot.hpp"

Spot::Spot()
{
}

Spot::Spot(int t)
{
    this->type = (t < 3 && t >= 0) ? t : 99;
}

Spot::~Spot()
{
}

void Spot::parkSpot(Vehicle *v)
{
    this->taken = true;
    this->vehicle = v;
}

Vehicle *Spot::releaseSpot()
{
    this->taken = false;
    return this->vehicle;
}

bool Spot::isTaken()
{
    return (this->taken);
}

int Spot::getType()
{
    return (this->type);
}

int Spot::getVehicleType()
{
    if (this->isTaken())
    {
        return this->vehicle->getType();
    }
    else
    {
        return -1;
    }
}

string Spot::toString()
{
    if (this->isTaken())
    {
        return this->vehicle->toString();
    }
    else
    {
        string Key = "mcl";
        return string() + Key[this->type];
    }
}