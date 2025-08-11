#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "marketData.hpp"
#include <string>


class testData: public marketData{
    
    public:
        testData(std::string ticker, std::chrono::milliseconds interval) : marketData(ticker, interval) {};

        DataPoint getPrice() override; 
           

};
