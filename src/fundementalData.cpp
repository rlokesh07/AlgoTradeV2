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

        httplib::SSLClient cli("https://api.polygon.io"); 
        
        std::string apiKey = "WMl_WDMxCpYtHmoXM_rSkjJ9pz3ya5GF";
        
        DataPoint dp;
        //Format the string to include the ticker
        std::ostringstream query;
        query << "/vX/reference/financials?ticker=" << getTicker() << "&order=asc&limit=10&sort=filing_date&apiKey=" << apiKey;
        try {
            // Make GET request
            auto res = cli.Get(query.str());

            json data = json::parse(res->body);
        } catch (const std::exception& e){
            std::cerr << e.what() << std::endl;
        }


        return dp;



}
