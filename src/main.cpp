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

        OrderBookEntry(std::string _timestamp, std::string product,  OrderBookType _type, double _price, double _quantity)
        :   timestamp(_timestamp), 
            product(product),
            type(_type),
            price(_price), 
            qty(_quantity)
        {

        }

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

int main() {
    OrderBookEntry order("2020/03/17 17:01:24.884492","ETH/BTC",OrderBookType::bid,0.02186299,0.1);
    std::vector<OrderBookEntry> orderVec;
    orderVec.push_back(order);
}