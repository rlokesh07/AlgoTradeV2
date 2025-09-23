#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <string>
#include "strat.hpp"


class pnbStrat: public strat{

    
    public:

        pnbStrat(std::string ticker, double costBasis, marketData& data) : strat(ticker, costBasis, data) {}; 
        
        int getPosition() override;

    private:

};
