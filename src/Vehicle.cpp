/* 
Author: Dheeraj Yalamanchili
Class: CS2336.001 (CPP)
Project: ParkingGarageProject
*/

#include "Vehicle.hpp"

/*
getTime method returns the UNIX timestamp when it's called.
This is used to generate the Vehicle's ID.
*/
long int getTime()
{
    time_t t = std::time(0);
    long int now = static_cast<long int>(t);
    return now;
}

Vehicle::Vehicle()
{
    id = getTime(); // ID is set to current UNIX timestamp
}

Vehicle::~Vehicle()
{
}

Vehicle::Vehicle(int t)
{
    id = getTime();
    this->type = t; // If type is provided, type is also set.
}

int Vehicle::getType()
{
    return this->type;
}

/*
toString method is used in printing Car Garage. It's utility is to return a string representation
of the vehicle the instance represents.
It returns M for motorcycle, C for car, and B for bus.
*/
string Vehicle::toString()
{
    char Key[] = "MCB";
    return string() + Key[this->type];
}

long int Vehicle::getID()
{
    return this->id;
}