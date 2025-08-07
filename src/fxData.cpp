#include <exception>
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../include/httplib/httplib.h"
#include <string>
#include <sstream>
#include "../include/json/json.hpp"
#include "../include/AlgoTradeV2/timeFunctions.hpp"
#include "../include/AlgoTradeV2/fxData.hpp"


using json = nlohmann::json;



DataPoint fxData::getPrice(){

        httplib::SSLClient cli("api-fxpractice.oanda.com"); 

        DataPoint dp;

        httplib::Headers headers = {
            { "Authorization", "Bearer b2c8c6f52d45760ece40f3752aee83ed-5c3dbf9c1a0c9eb0bb54452b664a2a36" }
        };
        
        //Format the string to include the ticker
        //
        std::ostringstream query;
        query << "/v3/accounts/101-001-36012340-001/pricing?instruments=" << getTicker();
        try {
            // Make GET request
            auto res = cli.Get(query.str(), headers);

            std::cout << res->status << std::endl;

            json data = json::parse(res->body);

            std::cout << data.dump(4) << std::endl;
            dp.time = currentTime();
            dp.ask = std::stod(data["prices"][0]["closeoutAsk"].get<std::string>());
            dp.bid = std::stod(data["prices"][0]["closeoutBid"].get<std::string>());
        } catch (const std::exception& e){
            std::cerr << e.what() << std::endl;
        }


        return dp;



}
