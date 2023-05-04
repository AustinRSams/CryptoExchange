#include <vector>
#include "OrderBookEntry.h"

class MainMenu {
    public:
        MainMenu();
        /** Call this to start the simluation */
        void init();

    private:
        void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer() ;
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        int getUserOption();
        void processUserOption(int userOption);
        std::vector<OrderBookEntry> orderVec;
};
