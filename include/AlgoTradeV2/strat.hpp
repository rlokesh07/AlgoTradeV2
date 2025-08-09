#include <string>
#include "marketData.hpp"

class strat{
    public:
        strat(std::string ticker, double costBasis, marketData& data) : ticker{ticker}, costBasis{costBasis}, data{data} {setPosition(-1);}; 
        void setCostBasis(double newCostBasis);
        void setPosition(int position);
        virtual int getPosition() = 0;
        double getCostBasis();
        void test();
        marketData& data;

    private:
        std::string ticker;
        double costBasis;
        int position;
        
};
