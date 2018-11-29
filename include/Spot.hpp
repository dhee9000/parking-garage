/* 
Author: Dheeraj Yalamanchili
Class: CS2336.001 (CPP)
Project: ParkingGarageProject
*/

/*
Spot Class Description

The Spot class represents each parking spot in the garage.
Each spot has a type representing the spots capacity (type).
Each spot can also hold a vehicle and release a vehicle.
*/

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
  Vehicle *releaseSpot();
  string toString();
};