#include <map>

#include "orderBook.h"
#include "csvReader.h"

orderBook::orderBook(std::string filename) {
    orders = csvReader::readCSV(filename);
}

std::vector<std::string> orderBook::getKnownProducts() {
    std::vector<std::string> products;
    std::map<std::string, bool> productMap;
    for (orderBookEntry& e: orders) {
        productMap[e.getProduct()] = true;
    }
    for (auto const& e: productMap) {
        products.push_back(e.first);
    }
    return products;
}

std::vector<orderBookEntry> orderBook::getOrders(orderBookType type, std::string product, std::string timestamp) {
    std::vector<orderBookEntry> orders_sub;
    for (orderBookEntry& e : orders) {
        if (e.getType() == type && e.getProduct() == product && e.getTimestamp() == timestamp) {
            orders_sub.push_back(e);
        }
    }
    return orders_sub;
}

std::string orderBook::getEarliestTime() {
    return orders[0].getTimestamp();
}

std::string orderBook::getNextTime(std::string timestamp) {
    for (orderBookEntry& e : orders) {
        if (e.getTimestamp() > timestamp) {
            return e.getTimestamp();
        }
    }
    return orders[0].getTimestamp();
}


double orderBook::getHighPrice(std::vector<orderBookEntry>& orders) {
    double max = orders[0].getPrice();
    for (orderBookEntry& e : orders) {
        if (e.getPrice() > max) {
            max = e.getPrice();
        }
    }
    return max;
}

double orderBook::getLowPrice(std::vector<orderBookEntry>& orders) {
    double min = orders[0].getPrice();
    for (orderBookEntry& e : orders) {
        if (e.getPrice() < min) {
            min = e.getPrice();
        }
    }
    return min;
}
