#include <string>
#include "fundementalData.hpp"

class fundamentalStrat{
    public:
        fundamentalStrat(std::string ticker, double costBasis, fundementalData& data) : ticker{ticker}, costBasis{costBasis}, data{data} {setPosition(-1);}; 
        void setCostBasis(double newCostBasis);
        void setPosition(int position);
        virtual int getPosition() = 0;
        double getCostBasis();
        void test();
        fundementalData& data;

    private:
        std::string ticker;
        double costBasis;
        int position;
        
};
