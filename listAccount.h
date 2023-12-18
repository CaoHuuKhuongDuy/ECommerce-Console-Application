#pragma once 

#include <vector>
#include "CustomerAccount.h"

class ListAccount {
    public:
        ListAccount();
        ~ListAccount(); // remember to delete all accounts
        void addAccount(BuyerAccount *account);
        void removeAccount(BuyerAccount *account);
        int getNumAccount();
        BuyerAccount* checkAccount(string username, string password);
        BuyerAccount* getAccount(int index);
        bool init(); 
        friend ostream& operator<<(ostream& os, const ListAccount& listAccount);    
    private:
        vector <BuyerAccount*> accounts;
};