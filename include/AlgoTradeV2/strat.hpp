#include <set>
#include <vector>
#include <string>

class strat{
    public:
        strat(std::string ticker, double costBasis) : ticker{ticker}, costBasis{costBasis} {setPosition(-1);}; 
        void setCostBasis(double newCostBasis);
        void setPosition(int position);
        int getPosition();
        double getCostBasis();
        void test();
    
    private:
        std::string ticker;
        double costBasis;
        int position;
        
};
