
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
    std::ifstream file{csvFile};
    std::string line;

    if (file.is_open()) {
        while(std::getline(file, line)) {
            try {
                orderBookEntry obe = strs_to_OBE(tokenize(line, ','));
                entries.push_back(obe);
            } catch (const std::exception& e) {
                std::cout << "Bad data!" << line << std::endl;
            }
        }
    }
    return entries;
}
std::vector<std::string> csvReader::tokenize(std::string csvLine, char delimitor) {
    std::vector<std::string> tokens;
    std::string t;
    signed int start, end;
    start = csvLine.find_first_not_of(delimitor, 0);

    do {
        end = csvLine.find_first_of(delimitor, start);

        if (start == csvLine.length() || start == end) {
            break;
        }
        // We've found a token
        if (end >= 0) {
            t = csvLine.substr(start, end - start);
        }
        else {
            t = csvLine.substr(start, csvLine.length() - start);
        }
        tokens.push_back(t);
        start = end + 1;
    } while (end != std::string::npos);
    return tokens;
}

orderBookEntry csvReader::strs_to_OBE(std::string timestamp, std::string product, orderBookEntryType type, std::string priceStr, std::string quantityStr) {
    double price, qty;

    try {
        price = std::stod(priceStr);
        qty = std::stod(quantityStr);
    }
    catch (const std::exception& e) {
        throw;
    }

    orderBookEntry obe{timestamp, product, type, price, qty};
    return obe;
}

orderBookEntry csvReader::strs_to_OBE(std::vector<std::string> tokens) {
    double price, amount;
    orderBookEntryType type;
    if (tokens.size() != 5) {
        std::cout << "Bad line" << std::endl;
        throw std::exception{};
    }
    try {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception& e) {

    }
    orderBookEntry obe{tokens[0], tokens[1], orderBookEntry::str_to_OBE_type(tokens[2]), price, amount};

    return obe;
}
