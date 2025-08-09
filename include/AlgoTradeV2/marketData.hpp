#include <chrono>
#include <string>
#include <ctime>
#include <deque>
#include <iostream>
#include <thread>
#include <mutex>

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
    
        std::deque<DataPoint>::iterator begin();
        std::deque<DataPoint>::iterator end();
        int size();
        
        void startData();
        void stopData();
        void updateDataBuffer();
        void makeVerbose() {verbose = true;}

        std::deque<DataPoint> dataBuffer;
        std::thread dataThread;
        std::mutex dataBufferLock;

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
