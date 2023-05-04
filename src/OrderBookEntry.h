#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

enum class OrderBookType {
    bid,
    ask,
};

class OrderBookEntry {

    public:

        OrderBookEntry(std::string _timestamp, std::string product,  OrderBookType _type, double _price, double _quantity);
        
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
        OrderBookType getType() {
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
        void setOrderBookType(OrderBookType t) {
            type = t;
        }

    private:
        string timestamp;
        string product;
        OrderBookType type;
        double price;
        double qty;
};
