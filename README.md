# AlgoTradeV2

A C++ algorithmic trading framework for implementing and backtesting trading strategies with support for real-time market data feeds and fundamental analysis.

## Overview

AlgoTradeV2 is a modular, multi-threaded trading framework that provides:

- Real-time market data collection from multiple sources
- Extensible strategy framework for both technical and fundamental analysis
- Thread-safe data buffering with mutex-protected access
- Support for forex and equity markets
- Fundamental data integration (assets, liabilities, market cap)

## Architecture

The framework is built around two core abstractions:

### Market Data Layer

The `marketData` base class provides a unified interface for fetching and buffering market data:

- **DataPoint**: Core data structure containing bid/ask prices and timestamps
- **FundamentalDataPoint**: Extended data structure including balance sheet metrics
- Thread-safe data buffer with automatic updates at configurable intervals
- Iterator support for historical data analysis

#### Implemented Data Sources

- **fxData**: Foreign exchange market data
- **fundementalData**: Fundamental company data including financial metrics

### Strategy Layer

Two strategy base classes enable different trading approaches:

- **strat**: Base class for technical trading strategies
- **fundamentalStrat**: Base class for fundamental analysis strategies

#### Implemented Strategies

- **momStrat**: Momentum-based trading strategy
- **pnbStrat**: Price-to-Net-Book ratio strategy
- **pneStrat**: Price-to-Net-Equity ratio strategy

Each strategy maintains position tracking and cost basis calculations.

## Features

- **Multi-threaded Architecture**: Separate threads for data collection and strategy execution
- **Real-time Data Feeds**: Configurable polling intervals for market data updates
- **Thread Safety**: Mutex-protected data structures for concurrent access
- **Extensible Design**: Easy to add new data sources and strategies
- **Data Persistence**: Built-in serialization for DataPoint structures
- **Verbose Logging**: Optional detailed logging for debugging

## Dependencies

- **C++17** or later
- **CMake 3.16+**
- **OpenSSL**: For HTTPS API requests
- **cpp-httplib**: Included as header-only HTTP library
- **nlohmann/json**: Included for JSON parsing
- **pthread**: For multi-threading support

## Building

```bash
# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

# Run the executable
./my_project
```

## Project Structure

```
AlgoTradeV2/
├── include/
│   ├── AlgoTradeV2/          # Core framework headers
│   │   ├── marketData.hpp     # Base market data class
│   │   ├── fxData.hpp         # Forex data implementation
│   │   ├── fundementalData.hpp # Fundamental data implementation
│   │   ├── strat.hpp          # Base strategy class
│   │   ├── fundamentalStrat.hpp # Fundamental strategy base
│   │   ├── momStrat.hpp       # Momentum strategy
│   │   ├── pnbStrat.hpp       # Price-to-Net-Book strategy
│   │   ├── pneStrat.hpp       # Price-to-Net-Equity strategy
│   │   └── timeFunctions.hpp  # Time utilities
│   ├── httplib/              # HTTP library
│   └── json/                 # JSON library
├── src/                      # Implementation files
├── tests/                    # Test files and data
├── pythonGraph/              # Python visualization tools
└── CMakeLists.txt
```

## Usage Example

```cpp
#include "AlgoTradeV2/fundementalData.hpp"
#include <unistd.h>

int main() {
    // Create fundamental data feed for Apple with 20-second intervals
    fundementalData myData("AAPL", std::chrono::milliseconds(20000));

    // Start data collection thread
    myData.startData();

    // Run for 60 seconds
    sleep(60);

    // Stop data collection
    myData.stopData();

    return 0;
}
```

### Creating a Custom Strategy

```cpp
#include "AlgoTradeV2/strat.hpp"

class MyStrategy : public strat {
public:
    MyStrategy(std::string ticker, double costBasis, marketData& data)
        : strat(ticker, costBasis, data) {}

    int getPosition() override {
        // Implement your strategy logic here
        // Return: 1 (long), 0 (neutral), -1 (short)

        // Access historical data through data.dataBuffer
        if (data.size() < 10) return 0;

        // Your custom logic...
        return 1;
    }
};
```

## Data Access

The framework provides iterator-based access to historical market data:

```cpp
fundementalData data("TICKER", std::chrono::milliseconds(5000));
data.startData();

// Iterate through historical data
for (auto& point : data) {
    std::cout << "Bid: " << point.bid
              << " Ask: " << point.ask
              << std::endl;
}
```

## Thread Safety

All market data buffers are protected by mutexes. The framework automatically handles:

- Concurrent reads from strategy threads
- Asynchronous data updates from API threads
- Safe iterator access to data buffers

## Configuration

Market data polling intervals are configurable at instantiation:

```cpp
// Update every 5 seconds
fxData fastData("EUR/USD", std::chrono::milliseconds(5000));

// Update every minute
fundementalData slowData("AAPL", std::chrono::milliseconds(60000));
```

## License

[Add your license here]

## Contributing

[Add contribution guidelines here]

## Future Enhancements

- Backtesting engine
- Performance analytics
- Risk management modules
- Order execution system
- Additional data sources (cryptocurrency, options)
- Python visualization dashboard
- Real-time P&L tracking
