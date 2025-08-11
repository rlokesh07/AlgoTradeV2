#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "marketData.hpp"
#include <string>


class fxData: public marketData{
    
    public:
        fxData(std::string ticker, std::chrono::milliseconds interval) : marketData(ticker, interval) {};

        DataPoint getPrice() override; 
           

};
