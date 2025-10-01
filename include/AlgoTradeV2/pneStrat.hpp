#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <string>
#include "strat.hpp"


class pneStrat: public strat{
    
    public:

        pneStrat(std::string ticker, double costBasis, double threshold, fundementalData& data) : fundamentalStrat(ticker, costBasis, data), threshold(threshold) {}; 
        
        int getPosition() override;

    private:

        double threshold;

};
