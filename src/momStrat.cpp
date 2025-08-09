#include "../include/AlgoTradeV2/momStrat.hpp"
#include <deque>

#include <algorithm>

int momStrat::getPosition(){ 
    
    std::deque<DataPoint> lastN(momStrat::data.end() - std::min(momStrat::data.size(), momStrat::momentum), momStrat::data.end());
    
    int denom = 0;
    double numer = 0;

    for(auto i: lastN){
        denom++;
        numer += i.ask;

    }



}
