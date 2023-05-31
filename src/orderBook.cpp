#include <map>
#include <algorithm>
#include "orderBook.h"
#include "csvReader.h"

orderBook::orderBook(std::string filename) {
    orders = csvReader::readCSV(filename);
}

void orderBook::insertOrder(orderBookEntry& order) {
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), orderBookEntry::compareByTimestamp);
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

std::vector<orderBookEntry> orderBook::getOrders(orderBookEntryType type, std::string product, std::string timestamp) {
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

std::vector<orderBookEntry> orderBook::matchAsksToBids(std::string product, std::string timestamp) {
    std::vector<orderBookEntry> asks = getOrders(orderBookEntryType::ask, product, timestamp);
    std::vector<orderBookEntry> bids = getOrders(orderBookEntryType::bid, product, timestamp);
    std::vector<orderBookEntry> sales;
    std::sort(asks.begin(), asks.end(), orderBookEntry::compareByPriceAscending);
    std::sort(bids.begin(), bids.end(), orderBookEntry::compareByPriceDecending);
    for (orderBookEntry& a : asks) {
        for (orderBookEntry& b : bids) {
            if (b.getPrice() >= a.getPrice()) {
                orderBookEntry fill{timestamp, product, orderBookEntryType::sale, a.getPrice(), a.getQty()};
                if (b.getQty() == a.getQty()) {
                    fill.setQty(a.getQty());
                    b.setQty(0);
                    sales.push_back(fill);
                    break;
                }
                if (b.getQty() > a.getQty()) {
                    fill.setQty(a.getQty());
                    b.setQty(b.getQty() - a.getQty());
                    sales.push_back(fill);
                    break;
                }
                if (b.getQty() < a.getQty()) {
                    fill.setQty(b.getQty());
                    a.setQty(a.getQty() - b.getQty());
                    b.setQty(0);
                    sales.push_back(fill);
                    continue;
                }
            }
        }
    }
    return sales;
}
