
#include "orderBookEntry.h"

orderBookEntry::orderBookEntry(std::string _timestamp, std::string _product, orderBookEntryType _type, double _price, double _quantity)
: timestamp(_timestamp), 
  product(_product),
  type(_type),
  price(_price), 
  qty(_quantity)
{

};

orderBookEntryType orderBookEntry::str_to_OBE_type(std::string& s) {
  if (s == "ask") {
    return orderBookEntryType::ask;
  }
  else if (s == "bid") {
    return orderBookEntryType::bid;
  }
  else {
    return orderBookEntryType::max_obe_num;
  }
}

// static bool compareByTimestamp(orderBookEntry& obe1, orderBookEntry& obe2) {
  // return (obe1.getTimestamp() < obe2.getTimestamp());
// }

double orderBookEntry::getPrice() {
  return price;
}

double orderBookEntry::getQty() {
  return qty;
}

std::string orderBookEntry::getTimestamp() {
  return timestamp;
}

std::string orderBookEntry::getProduct() {
  return product;
}

orderBookEntryType orderBookEntry::getType() {
  return type;
}

void orderBookEntry::setPrice(double price) {
  this->price = price;
}

void orderBookEntry::setQty(double qty) {
  this->qty = qty;
}