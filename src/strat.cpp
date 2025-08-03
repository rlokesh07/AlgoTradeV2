#include "../include/AlgoTradeV2/strat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

void strat::test() {
    std::cout << "penis";
}

void strat::setCostBasis(double newCostBasis){
    if (newCostBasis < 0){
        throw std::range_error("cost basis cannot be negative");
    }
    strat::costBasis = newCostBasis;
}
double strat::getCostBasis(){
    return strat::costBasis;
}

void strat::setPosition(int position){
    if (position != 1 || position != -1){
        throw std::range_error("position can only be 1 or -1");
    }
    strat::position = position;
}

int strat::getPosition() {
    return position;
}


