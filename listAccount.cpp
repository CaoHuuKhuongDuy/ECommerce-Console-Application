#include "listAccount.h"

const string path = "resource/accounts.txt";

ListAccount::ListAccount() {}

ListAccount::~ListAccount() {
    ofstream file(path);
    file << accounts.size() << endl;
    for (int i = 0; i < accounts.size(); i++) {
        file << *accounts[i];
    }
    file.close();
    for (int i = 0; i < accounts.size(); i++) {
        delete accounts[i];
    }
}

bool ListAccount::init() {
    ifstream file(path);
    if (!file.is_open()) return false;
    int numberOfAccount;
    file >> numberOfAccount;
    for (int i = 0; i < numberOfAccount; i++) {
        file.ignore();
        accounts.push_back(new BuyerAccount());
        file >> *accounts[i];
    }
    file.close();
    return true;

}

ostream& operator<<(ostream& os, const ListAccount& listAccount) {
    os << "Accounts:" << endl;
    for (int i = 0; i < listAccount.accounts.size(); i++) {
        os << "======================" << endl;
        os << "Account " << i + 1 << endl;
        os << *listAccount.accounts[i];
    }
    return os;
}

void ListAccount::addAccount(BuyerAccount *account) {
    accounts.push_back(account);
}

void ListAccount::removeAccount(BuyerAccount *account) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i] == account) {
            delete accounts[i];
            accounts.erase(accounts.begin() + i);
            return;
        }
    }
}

BuyerAccount* ListAccount::checkAccount(string username, string password) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getUsername() == username && accounts[i]->getPassword() == password) {
            return accounts[i];
        }
    }
    return nullptr;
}

int ListAccount::getNumAccount() {
    return accounts.size();
}

BuyerAccount* ListAccount::getAccount(int index) {
    return accounts[index];
}