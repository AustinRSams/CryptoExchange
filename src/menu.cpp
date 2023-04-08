#include <iostream>
#include <sstream>
using namespace std;

void printMenu() {
    std::cout << "1: Print help" << endl;
    std::cout << "2: Print exchange stats" << endl;
    std::cout << "3: Make an offer" << endl;
    std::cout << "4: Make a bid" << endl;
    std::cout << "5: Print wallet" << endl;
    std::cout << "6: Continue" << endl;
    std::cout << "=======================" << endl;
    std::cout << "Type in 1-6" << endl;
}

void printHelp() {
    std::cout << "Your aim is to make money. Analyze the market and make bids and offers." << endl;
}

void printMarketStats() {
    std::cout << "Market looks good!" << endl;
}

void enterOffer() {
    std::cout << "Make an offer - enter the amount" << endl;
}

void enterBid() {
    std::cout << "Make a bid - enter the amount" << endl;
}

void printWallet() {
    std::cout << "Your wallet is empty" << endl;
}

void gotoNextTimeframe() {
    std::cout << "Going to next timeframe" << endl;
}

int getUserOption() {
    string input;
    int ans;
    
    std::cin >> input;
    std::stringstream strm(input);
    
    strm >> ans;
    return ans;
}

void processUserOption(int userOption) {
    switch (userOption) {
        case 1:
            printHelp();
            return;
        case 2:
            printMarketStats();
            return;
        case 3:
            enterOffer();
            return;
        case 4:
            enterBid();
            return;
        case 5:
            printWallet();
            return;
        case 6:
            gotoNextTimeframe();
            return;
        default:
            return;
    };
}

int main() {
    while (true) {
        printMenu();
        long userOption = getUserOption();
        processUserOption(userOption);       
    }
    return 0;
}