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