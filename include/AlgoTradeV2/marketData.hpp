#include <chrono>
#include <string>
#include <ctime>
#include <deque>
#include <iostream>
#include <thread>


struct DataPoint {
    double bid;
    double ask;
    std::chrono::time_point<std::chrono::system_clock> time;
    
};



class marketData { 

    public:

        marketData(std::string ticker, std::chrono::milliseconds interval): ticker(ticker), interval(interval) {}

        virtual DataPoint getPrice() = 0;
        std::string getTicker() {return ticker;}

        const DataPoint* begin();
        const DataPoint* end();
        
        void startData();
        void stopData();
        void updateDataBuffer();
        void makeVerbose() {verbose = true;}

        std::deque<DataPoint> dataBuffer;
        std::thread dataThread;

    private:
        std::string ticker;
        bool verbose = false;
        std::chrono::milliseconds interval;

        bool running = false;
};

inline std::ostream& operator<<(std::ostream& os, const DataPoint& p) {
    os << "DataPoint{time: " << ", bid: " << p.bid << ", ask:" << p.ask << "}";
    return os;
}
