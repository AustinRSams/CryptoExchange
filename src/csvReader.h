#pragma once

#include <vector>
#include <string>
#include "orderBookEntry.h"

class csvReader {
    public:
        csvReader();
        static std::vector<orderBookEntry> readCSV(std::string csvFile);
        static std::vector<std::string> tokenize(std::string csvLine, char delimitor);
        static orderBookEntry strs_to_OBE(std::string timestamp, std::string product, orderBookEntryType OrderBookType, std::string price, std::string quantity);

    private:
        static orderBookEntry strs_to_OBE(std::vector<std::string> strings);
};