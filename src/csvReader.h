#pragma once

#include <vector>
#include <string>
#include "orderBookEntry.h"

class csvReader {
    public:
        csvReader();
        static std::vector<orderBookEntry> readCSV(std::string csvFile);

    private:
        static std::vector<std::string> tokenize(std::string csvLine, char delimitor);
        static orderBookEntry strs_to_OBE(std::vector<std::string> strings);
            
};