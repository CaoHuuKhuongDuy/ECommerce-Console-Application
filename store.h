#pragma once 

#include <string>
#include <vector>
#include "date.h"
#include "product.h"

using namespace std;

class Store {
    public:
        Store() {};
        Store(string name_, Date joinDate_);
        string getName();
        Date getJoinDate();
        void addProduct(Product *product);
        void removeProduct(Product *product);
        int getNumProduct();
        Product* getProduct(int index);
        friend istream& operator>>(istream& ci, Store &store);
        friend ostream& operator<<(ostream& os, const Store& store);

    private:
        string name;
        Date joinDate;
        ListProduct products;
};

class ListStore {
    public:
        ListStore();
        ~ListStore(); // remember to delete all stores
        bool init();
        void addStore(Store *store);
        void removeStore(Store *store);
        int getNumStore();
        Store *getStore(int index);
        friend ostream& operator<<(ostream& os, const ListStore& listStore);

    private:
        vector <Store*> stores;
};