
#include <iostream>
#include <sstream>
#include <vector>
#include "orderBookEntry.h"
#include "orderBook.h"
#include "menu.h"
#include "csvReader.h"

MainMenu::MainMenu() {

}

void MainMenu::init() {

    currentTime = orderBook.getEarliestTime();
    int input;
    while (true) {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MainMenu::printMenu() {
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Make an offer" << std::endl;
    std::cout << "4: Make a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "Current time is: " << MainMenu::currentTime << std::endl;
    std::cout << "Type in 1-6" << std::endl;
    return;
}

void MainMenu::printHelp() {
    std::cout << "Your aim is to make money. Analyze the market and make bids and offers." << std::endl;
}

void MainMenu::printMarketStats() {
    for (std::string const& p : orderBook.getKnownProducts()) {
        std::cout << "Product: " << p << std::endl;
        std::vector<orderBookEntry> entries = orderBook.getOrders(orderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Min ask " << orderBook::getLowPrice(entries) << std::endl;
    }
}

void MainMenu::enterOffer() {
    std::cout << "Make an offer - enter the amount" << std::endl;
}

void MainMenu::enterBid() {
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void MainMenu::printWallet() {
    std::cout << "Your wallet is empty" << std::endl;
}

void MainMenu::gotoNextTimeframe() {
    std::cout << "Going to next timeframe..." << std::endl;
    currentTime = orderBook.getNextTime(currentTime);
}

int MainMenu::getUserOption() {
    std::string input;
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
