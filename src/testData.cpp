#include "../include/AlgoTradeV2/fxData.hpp"
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>
#include "../include/AlgoTradeV2/testData.hpp"

void generateTestData(int dataPoints) {
    
    std::chrono::milliseconds interval(1000);

    fxData EURUSD("EUR_USD", interval);
    EURUSD.getPrice();
    

    for(int i = 0; i < dataPoints; i++) {
        std::cout << "running" << std::endl;
        try {
            DataPoint dp = EURUSD.getPrice();

            std::ofstream outFile("data.txt", std::ios::app);
            outFile << dp << " ";
            outFile.close();

        }
        catch (const std::exception& e) {
            std::cerr << "[generateTestData] Exception: " << e.what() << std::endl;
        }
        catch (...) {
            std::cerr << "[generateTestData] Unknown exception caught!" << std::endl;
        }
        std::this_thread::sleep_for(interval);
    }
    



    
    
}

