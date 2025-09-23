#include "../include/AlgoTradeV2/fundementalData.hpp"

int main() {

    
    fundementalData myData("AAPL", std::chrono::milliseconds(20));
    myData.getPrice();
    return 0;
}

