#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "menu.h"
#include "orderBookEntry.h"
#include "csvReader.h"

using namespace std;

int main() {
    MainMenu app{};
    app.init();
}


/*
int main() {
    std::vector<std::string> tokens;
    std::string line;
    // std::string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";
    // tokens = tokenize(s, ',');
    // for (std::string& t : tokens) {
        // std::cout << t << std::endl;
    // }
    std::ifstream csvFile("20200317.csv");
    if (csvFile.is_open()) {
        std::cout << "File open" << std::endl;
        csvFile.close();
        while (std::getline(csvFile, line)) {
            tokens = csvReader::tokenize(line, ',');
            if (tokens.size() != 5) {
                std::cout << "Not enough tokens in this line. Skipping..." << std::endl;
            }
            try {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
            } catch(std::exception& e) {
                std::cout << "Bad float!" << std::endl;
                continue;
            }
        }
    } 
    else{ 
        std::cout << "Could not open file" << std::endl;
    }
    return 0;
}
*/