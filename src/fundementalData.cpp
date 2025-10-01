#include <exception>
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../include/httplib/httplib.h"
#include <string>
#include <sstream>
#include "../include/json/json.hpp"
#include "../include/AlgoTradeV2/timeFunctions.hpp"
#include "../include/AlgoTradeV2/fundementalData.hpp"

using json = nlohmann::json;



DataPoint fundementalData::getPrice(){


        httplib::SSLClient cli("api.polygon.io");

        
        std::string apiKey = "QMl_WDMxCpYtHmoXM_rSkjJ9pz3ya5GF";
        
        FundamentalDataPoint dp;
        //Format the string to include the ticker
        std::ostringstream fundamentalsString;
        fundamentalsString << "/vX/reference/financials?ticker=" << getTicker() << "&order=desc&limit=1&sort=filing_date&apiKey=" << apiKey;

        std::ostringstream priceString;
        priceString << "/v3/reference/tickers/" << getTicker() << "?apiKey=" << apiKey;

        try {
            // Make GET request
            auto res = cli.Get(fundamentalsString.str());

            json fundamentalData = json::parse(res->body);

            std::string filing_date = fundamentalData["results"][0].value("filing_date", "");

            // Extract assets
            double assets = fundamentalData["results"][0]["financials"]["balance_sheet"]["assets"].value("value", 0.0);

            // Extract liabilities 
            double liabilities = fundamentalData["results"][0]["financials"]["balance_sheet"]["liabilities"].value("value", 0.0);
           
            
            res = cli.Get(priceString.str());
        
            json priceData = json::parse(res->body);
            
            double marketCap = priceData["results"].value("market_cap", 0.0);

            // Apply to the dp
            dp.assets = assets;
            dp.liabilities = liabilities;
            dp.time = currentTime();
            dp.marketCap = marketCap;

       } catch (const std::exception& e){
            std::cerr << e.what() << std::endl;
        }

        
        return dp;



}

std::deque<FundamentalDataPoint>::iterator fundementalData::begin(){ 
    return fundementalData::dataBuffer.begin();
}


std::deque<FundamentalDataPoint>::iterator fundementalData::end(){ 
    return fundementalData::dataBuffer.end();
}


