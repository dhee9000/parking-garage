#include "Vehicle.hpp"

long int getTime()
{
    time_t t = std::time(0);
    long int now = static_cast<long int> (t);
    return now;
}


Vehicle::Vehicle() {
    id = getTime();
}

Vehicle::~Vehicle() {

}

Vehicle::Vehicle(int t) {
    id = getTime();
    this->type = t;
}
    
int Vehicle::getType() {
    return this->type;
}

string Vehicle::toString(){
    char Key[] = "MCB";
    return  string() + Key[this->type];
}

long int Vehicle::getID(){
    return this->id;
}