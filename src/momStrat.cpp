#include "../include/AlgoTradeV2/momStrat.hpp"
#include <deque>
#include <cmath>
#include <algorithm>

int momStrat::getPosition(){ 
    
    std::deque<DataPoint> lastN(momStrat::data.end() - std::min(momStrat::data.size(), momStrat::momentum), momStrat::data.end());
    
    double returnSum = 0;
    for(int i = 1; i < lastN.size(); i++){
        try{ 
            returnSum += std::log(lastN[i].ask/lastN[i-1].ask);
        }
        catch (const std::exception& e) {
            std::cerr << "[momStrat] Exception: " << e.what() << std::endl;

        }
    }

    if(returnSum <= 0){
        return -1;
    } else{
        return 1;
    }


}
