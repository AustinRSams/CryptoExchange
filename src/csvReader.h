#pragma once

#include <vector>
#include <string>
#include "orderBookEntry.h"

class csvReader {
    public:
        csvReader();
        static std::vector<orderBookEntry> readCSV(std::string csvFile);

    private:
        static std::vector<string> tokenize(std::string csvLine, char delimitor);
        static orderBookEntry stringsToOBE(std::vector<std::string> strings);
            
};