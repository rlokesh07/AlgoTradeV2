#include <chrono>
#include <iomanip>
#include <istream>
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

inline std::ostream& operator<<(std::ostream& os, const DataPoint& dp) {
    //convert system time to local time
    std::time_t time_t_val = std::chrono::system_clock::to_time_t(dp.time);
    std::tm* tm_val = std::localtime(&time_t_val);


    os << "DataPoint{time: " << std::put_time(tm_val, "%Y-%m-%d %H:%M:%S") << ", bid: " << dp.bid << ", ask:" << dp.ask << "}";
    return os;
}

inline std::istream& operator>>(std::istream& is, DataPoint& dp) {

    std::string discard;
    char comma1, comma2, brace;
    std::tm tm = {};
    double bid, ask;
    

    is >> discard >> discard; //remove "DataPoint{time:"
    
    is >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S"); //get time

    is >> comma1 >> discard >> bid >> comma2 >> discard >> ask; //get bid and ask
    

    std::time_t time_t_val = std::mktime(&tm); //convert the time back to system time


    dp.time = std::chrono::system_clock::from_time_t(time_t_val);

    dp.bid = bid;
    dp.ask = ask;

    return is;
}
