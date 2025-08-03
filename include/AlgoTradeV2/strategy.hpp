#include <vector>
#include <string>
using namespace std;
class strat{
    public:
        strat(string ticker, double costBasis) : ticker{ticker}, costBasis{costBasis} {position = -1;}; 
        void setCostBasis(double newCostBasis);
        void setPosition(int position);
        int getPosition();
        double getCostBasis();
    private:
        string ticker;
        double costBasis;
        int position;
        
};
