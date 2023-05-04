#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(std::string _timestamp, std::string product,  OrderBookType _type, double _price, double _quantity)
: timestamp(_timestamp), 
  product(product),
  type(_type),
  price(_price), 
  qty(_quantity)
{

}