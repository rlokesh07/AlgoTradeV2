#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <format>
#include "marketData.hpp"
#include "../httplib/httplib.h"
#include <string>
#include <sstream>
#include "../json/json.hpp"
#include "timeFunctions.hpp"



class fxData: public marketData{
    
    public:
        fxData(std::string ticker, std::chrono::milliseconds interval) : marketData(ticker, interval) {};

        DataPoint getPrice() override; 
           

};
