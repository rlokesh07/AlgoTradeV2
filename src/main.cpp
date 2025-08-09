#include <iostream>
#include "../include/AlgoTradeV2/strat.hpp"
#include "../include/AlgoTradeV2/fxData.hpp"
#include <chrono>

int main() {
    std::chrono::milliseconds interval(1000);

    fxData EURUSD("EUR_USD", interval);
    EURUSD.getPrice();
    EURUSD.startData();
    EURUSD.makeVerbose();
    //test    

    
    std::chrono::milliseconds interval1(100000);
    std::this_thread::sleep_for(interval1);
    
}

