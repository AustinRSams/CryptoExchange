#pragma once

#include <string>
#include <vector>
#include "orderBookEntry.h"
#include "csvReader.h"

class orderBook {

    public:
        /** 
         * Constructor, reading a csv data file 
         */
        orderBook(std::string filename);
        /** 
         * inserts an orderBookEntry into the orderBook 
         */
        void insertOrder(orderBookEntry& order);
        /** 
         * return vector of all kown products in the dataset 
         */
        std::vector<std::string> getKnownProducts();
        /** 
         * return vector of orders according to the sent filters 
         */
        std::vector<orderBookEntry> getOrders(orderBookEntryType type, std::string product, std::string timestamp);
        /** 
         * Retrieves the earliest timeframe in the simulation 
         */
        std::string getEarliestTime();
        /** 
         * Steps simulation to next timeframe.  
         * Returns the 1st timestamp if no next is found 
         */
        std::string getNextTime(std::string timestamp);
        /** 
         * Returns the highest price in the current timeframe 
         */
        static double getHighPrice(std::vector<orderBookEntry>& orders);
        /** 
         * Returns the lowest price in the current timeframe 
         */
        static double getLowPrice(std::vector<orderBookEntry>& orders);
        std::vector<orderBookEntry> matchAsksToBids(std::string product, std::string timestamp);

    private:
        std::vector<orderBookEntry> orders;
};
