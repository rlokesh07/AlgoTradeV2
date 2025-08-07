#include "../include/AlgoTradeV2/marketData.hpp"
#include <thread>
#include <iostream>

void marketData::startData(){
    running = true; 
    dataThread = std::thread(&marketData::updateDataBuffer, this);

    std::cout << "started thread" << std::endl;
}

void marketData::stopData(){
    running = false;
}

void marketData::updateDataBuffer(){
    while (running) {
        std::cout << "running" << std::endl;
        try {
            DataPoint dp = getPrice();
            if (verbose) {
                std::cout << dp << std::endl;
            }
            dataBuffer.push_back(dp);
        }
        catch (const std::exception& e) {
            std::cerr << "[updateDataBuffer] Exception: " << e.what() << std::endl;
        }
        catch (...) {
            std::cerr << "[updateDataBuffer] Unknown exception caught!" << std::endl;
        }
        std::this_thread::sleep_for(interval);
    }
}


