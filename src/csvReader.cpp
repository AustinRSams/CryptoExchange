
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "orderBookEntry.h"
#include "csvReader.h"

csvReader::csvReader() {
    
}
std::vector<orderBookEntry> csvReader::readCSV(std::string csvFile) {
    std::vector<orderBookEntry> entries;

    return entries;
}
std::vector<string> csvReader::tokenize(std::string csvLine, char delimitor) {
    std::vector<string> tokens;
    std::string t;
    signed int start, end;
    start = csvLine.find_first_not_of(delimitor, 0);

    do {
        end = csvLine.find_first_of(delimitor, start);

        if (start == csvLine.length() || start == end) {
            break;
        }
        // We've founda token
        if (end >= 0) {
            t = csvLine.substr(start, end - start);
        }
        else {
            t = csvLine.substr (start, csvLine.length() - start);
        }
        tokens.push_back(t);
        start = end + 1;
    }
     while (end != std::string::npos);
    return tokens;
}
orderBookEntry csvReader::stringsToOBE(std::vector<std::string> strings) {
    orderBookEntry obe{"","",orderBookType::bid,0,0};

    return obe;
}