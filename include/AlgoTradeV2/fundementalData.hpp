#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "marketData.hpp"
#include <string>


class fundementalData: public marketData{
    
    public:
        fundementalData(std::string ticker, std::chrono::milliseconds interval) : marketData(ticker, interval) {};

        DataPoint getPrice() override; 
           

};
