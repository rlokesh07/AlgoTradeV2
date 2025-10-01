#include "../include/AlgoTradeV2/pneStrat.hpp"
#include <cmath>

int pneStrat::getPosition(){ 
   FundamentalDataPoint lastData = *pneStrat::data.end();

   double pb = (lastData.ask)/(lastData.assets - lastData.liabilities);

   return (pb > pneStrat::threshold);



}
