#include <chrono>
#include <string>
#include <ctime>

using namespace std;

struct DataPoint {
    double price; 
    chrono::time_point<chrono::system_clock> time;
    
};



class marketData { 
    public:
        marketData(string ticker): ticker(ticker) {}
        virtual DataPoint getPrice() = 0;
        
    private:
        string ticker;

};
