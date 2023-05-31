#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum class orderBookEntryType {
    bid,
    ask,
    sale,
    max_obe_num,
};

class orderBookEntry {

    public:

        orderBookEntry(std::string _timestamp, std::string _product, orderBookEntryType _type, double _price, double _quantity);
        
        /** 
         * Converts a string into an orderBookEntry type 
         */
        static orderBookEntryType str_to_OBE_type(std::string& s);
        /** 
         * Compares two orderBookEntries by their timestamp 
         */
        static bool compareByTimestamp(orderBookEntry& obe1, orderBookEntry& obe2) {
              return (obe1.getTimestamp() < obe2.getTimestamp());
        }
        static bool compareByPriceAscending(orderBookEntry& obe1, orderBookEntry& obe2) {
            return obe1.getPrice() < obe2.getPrice();
        }
        static bool compareByPriceDecending(orderBookEntry& obe1, orderBookEntry& obe2) {
            return obe1.getPrice() > obe2.getPrice();
        }
        // Getters
        double getPrice();
        double getQty();
        std::string getTimestamp();
        std::string getProduct();
        orderBookEntryType getType();

        // Setters
        void setPrice(double price);
        void setQty(double qty);

    private:
        std::string timestamp;
        std::string product;
        orderBookEntryType type;
        double price;
        double qty;
};
