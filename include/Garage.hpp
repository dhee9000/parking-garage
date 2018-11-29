/* 
Author: Dheeraj Yalamanchili
Class: CS2336.001 (CPP)
Project: ParkingGarageProject
*/

/*
Garage Class Description:

The Garage Class represents a Parking garage and consists of Spots which can hold Vehicles.
The Garage Class holds information about a Parking Garage like the parameters with which it was built
and information about its current state like the first available spot for different types of vehicles.
*/

#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Spot.hpp"

using namespace std;

class Garage
{

private:
  int LEVELS;
  int SPOTS_L;
  int SPOTS_R;
  int LARGE_L;
  float MEDIUM_L;
  float SMALL_L;
  float ROWS_L;

  Spot *spots;
  int size;

public:
  Garage();
  Garage(int num_levels, int spots_level, int spots_row);
  ~Garage();

  void clearGarage();
  string toString();
  int park(Vehicle *v);
  void returnVehicle(int token);
  int findFirst(int type);
};