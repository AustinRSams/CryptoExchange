#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum class orderBookType {
    bid,
    ask,
    max_obe_num,
};

class orderBookEntry {

    public:

        orderBookEntry(std::string _timestamp, std::string _product, orderBookType _type, double _price, double _quantity);
        
        /** 
         * Converts a string into an orderBookEntry type 
         */
        static orderBookType str_to_OBE_type(std::string& s);
        
        // Getters
        double getPrice();
        double getQty();
        std::string getTimestamp();
        std::string getProduct();
        orderBookType getType();

    private:
        std::string timestamp;
        std::string product;
        orderBookType type;
        double price;
        double qty;
};
