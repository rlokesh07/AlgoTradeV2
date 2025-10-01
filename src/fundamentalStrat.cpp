#include "../include/AlgoTradeV2/fundamentalStrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

void fundamentalStrat::test() {
    std::cout << "penidfs";
}

void fundamentalStrat::setCostBasis(double newCostBasis){
    if (newCostBasis < 0){
        throw std::range_error("cost basis cannot be negative");
    }
    fundamentalStrat::costBasis = newCostBasis;
}
double fundamentalStrat::getCostBasis(){

    return fundamentalStrat::costBasis;
}

void fundamentalStrat::setPosition(int position){
    if (position != 1 || position != -1){
        throw std::range_error("position can only be 1 or -1");
    }
    fundamentalStrat::position = position;
}

int fundamentalStrat::getPosition() {
    return position;
}


