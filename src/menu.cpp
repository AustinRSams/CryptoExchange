
#include <iostream>
#include <sstream>
#include <vector>
#include "OrderBookEntry.h"
#include "menu.h"

MainMenu::MainMenu() {

}

void MainMenu::init() {
    loadOrderBook();
    int input;
    while (true) {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MainMenu::printMenu() {
    std::cout << "1: Print help" << endl;
    std::cout << "2: Print exchange stats" << endl;
    std::cout << "3: Make an offer" << endl;
    std::cout << "4: Make a bid" << endl;
    std::cout << "5: Print wallet" << endl;
    std::cout << "6: Continue" << endl;
    std::cout << "=======================" << endl;
    std::cout << "Type in 1-6" << endl;
    return;
}

void MainMenu::loadOrderBook() {
    OrderBookEntry order("2020/03/17 17:01:24.884492","ETH/BTC",OrderBookType::bid,0.02186299,0.1);
    orderVec.push_back(order);
}

void MainMenu::printHelp() {
    std::cout << "Your aim is to make money. Analyze the market and make bids and offers." << endl;
}

void MainMenu::printMarketStats() {
    std::cout << "OrderBook contains: " << orderVec.size() << " entries" << endl;
}

void MainMenu::enterOffer() {
    std::cout << "Make an offer - enter the amount" << endl;
}

void MainMenu::enterBid() {
    std::cout << "Make a bid - enter the amount" << endl;
}

void MainMenu::printWallet() {
    std::cout << "Your wallet is empty" << endl;
}

void MainMenu::gotoNextTimeframe() {
    std::cout << "Going to next timeframe" << endl;
}

int MainMenu::getUserOption() {
    string input;
    int ans;
    
    std::cin >> input;
    std::stringstream ss(input);
    
    ss >> ans;
    return ans;
}

void MainMenu::processUserOption(int userOption) {
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
