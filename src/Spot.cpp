#include "Spot.hpp"

Spot::Spot() {

}

Spot::Spot(int t) {
    this->type = (t<3 && t>0)? t:99;
}

Spot::~Spot() {

}

bool Spot::isTaken(){
    return (vehicle == nullptr);
}

int Spot::getType(){
    return this->type;
}