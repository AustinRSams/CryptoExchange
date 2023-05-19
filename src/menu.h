#pragma once

#include <vector>
#include "orderBookEntry.h"
#include "orderBook.h"

class MainMenu {
    public:
        MainMenu();
        /** Call this to start the simluation */
        void init();

    private:
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer() ;
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        int getUserOption();
        void processUserOption(int userOption);
        orderBook orderBook{"../20200317.csv"};
        std::string currentTime;
};
