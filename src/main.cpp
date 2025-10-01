#include "../include/AlgoTradeV2/fundementalData.hpp"
#include <unistd.h>

int main() {

    
    fundementalData myData("AAPL", std::chrono::milliseconds(20000));
    myData.startData();
    sleep(60);
    myData.stopData();
    return 0;
}

