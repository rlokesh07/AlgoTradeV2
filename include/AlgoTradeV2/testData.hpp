#pragma once

#include <chrono>
#include <iostream>
#include <fstream>
#include <thread>
#include "fxData.hpp"
#include <filesystem>

inline void generateTestData(int dataSize) {
    
    std::chrono::milliseconds interval(1000);

    fxData EURUSD("EUR_USD", interval);
    EURUSD.getPrice();

    std::cout << "Writing to: " << std::filesystem::absolute("../tests/data.txt") << std::endl; 

    for(int i = 0; i < dataSize; i++) {
        std::cout << "running" << std::endl;
        try {
            DataPoint dp = EURUSD.getPrice();

            std::ofstream outFile("../tests/data.txt", std::ios::app);
            if(!outFile.is_open()){
                std::cout << "failed to open outFile";
            }
            std::cout << dp << " ";
            outFile << dp << std::endl;
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

