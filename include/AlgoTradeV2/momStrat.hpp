#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <string>
#include "strat.hpp"


class momStrat: public strat{
    
    public:

        momStrat(std::string ticker, double costBasis, marketData& data, int momentum) : strat(ticker, costBasis, data), momentum(momentum) {}; 
        
        int getPosition() override;

    private:

        int momentum;
};
