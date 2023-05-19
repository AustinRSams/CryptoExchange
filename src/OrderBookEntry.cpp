
#include "orderBookEntry.h"

orderBookEntry::orderBookEntry(std::string _timestamp, std::string _product, orderBookType _type, double _price, double _quantity)
: timestamp(_timestamp), 
  product(_product),
  type(_type),
  price(_price), 
  qty(_quantity)
{

};

orderBookType orderBookEntry::str_to_OBE_type(std::string& s) {
  if (s == "ask") {
    return orderBookType::ask;
  }
  else if (s == "bid") {
    return orderBookType::bid;
  }
  else {
    return orderBookType::max_obe_num;
  }
}

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

orderBookType orderBookEntry::getType() {
  return type;
}
