#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

enum class orderBookType {
    bid,
    ask,
};

class orderBookEntry {

    public:

        orderBookEntry(std::string _timestamp, std::string product,  orderBookType _type, double _price, double _quantity);
        
        // Getters
        double getPrice() {
            return price;
        }
        double getQty() {
            return qty;
        }
        string getTimestamp() {
            return timestamp;
        }
        string getProduct() {
            return product;
        }
        orderBookType getType() {
            return type;
        }

        // Setters
        void setPrice(double p) {
            price = p;
        }
        void setQty(double q) {
            qty = q;
        }
        // TODO: split date and time into separate fields
        void setTimestamp(string ts) {
            timestamp = ts;
        }
        // TODO: make enum for accepted product
        void setProduct(string u) {
            product = u;
        }
        void setorderBookType(orderBookType t) {
            type = t;
        }

    private:
        string timestamp;
        string product;
        orderBookType type;
        double price;
        double qty;
};
