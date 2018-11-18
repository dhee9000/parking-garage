#include "Spot.hpp"

Spot::Spot() {

}

Spot::Spot(int t) {
    this->type = (t<3 && t>=0)? t:99;
}

Spot::~Spot() {

}

void Spot::parkSpot(Vehicle* v){
    this->taken = true;
    this->vehicle = v;
}

int Spot::releaseSpot(){
    this->taken = false;
    int statusCode = -1;
    this->vehicle = nullptr;
    return statusCode;
}

bool Spot::isTaken(){
    return (this->taken);
}

int Spot::getType(){
    return (this->type);
}

string Spot::toString(){
    if(this->isTaken()){
        return this->vehicle->toString();
    }
    else{
        string Key = "mcl";
        return string() + Key[this->type];
    }
}