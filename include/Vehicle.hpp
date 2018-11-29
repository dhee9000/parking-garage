/* 
Author: Dheeraj Yalamanchili
Class: CS2336.001 (CPP)
Project: ParkingGarageProject
*/

/*
Vehicle Class Description:

The Vehicle class represents the vehicles being parked in the garage.
Each vehicle has a unique ID identifier (unix timestamp is used for this purpose)
Each vehicle also has a type associated with it to represent what type of vehicle it is.
*/

#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Vehicle
{

private:
  /* 
         * 0 - Motorcycle
         * 1 - Car 
         * 2 - Bus
  */

 //TODO: Implement ENUM type to eliminate confusion of type variables.

  int type;
  long int id;

public:
  Vehicle();
  ~Vehicle();

  Vehicle(int t);

  int getType();
  long int getID();
  string toString();
};