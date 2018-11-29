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
    this->type = (t < 3 && t >= 0) ? t : -1; // Ensures type is within bounds.
}

Spot::~Spot()
{
}

/*
Sets the vehicle belonging to this spot and changes isTaken state of Spot.
*/
void Spot::parkSpot(Vehicle *v)
{
    this->taken = true;
    this->vehicle = v;
}

/*
Removes vehicle from spot and changes isTaken state of Spot.
*/
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

/*
getVehicleType checks if spot is occupied and if it is, it returns the type of the vehicle occupying it.
*/
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

/*
toString method returns the string representation of the current state of the Spot.
It checks if there is a vehicle present and if there is it returns the toString of the Vehicle
Else it returns the type of the Spot.
*/
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