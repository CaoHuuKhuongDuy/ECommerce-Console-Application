#include "store.h"

const string path = "resource/stores.txt";

Store::Store(string name_, Date joinDate_) : name(name_), joinDate(joinDate_) {}

string Store::getName() {
    return name;
}

Date Store::getJoinDate() {
    return joinDate;
}

void Store::addProduct(Product *product) {
    products.addProduct(product);
}

void Store::removeProduct(Product *product) {
    products.removeProduct(product);
}

int Store::getNumProduct() {
    return products.getNumSize();
}

Product* Store::getProduct(int index) {
    return products.getProduct(index);
}

istream& operator>>(istream& is, Store &store) {
    is.ignore();
    getline(is, store.name);
    is >> store.joinDate;
    int numberProduct;
    is >> numberProduct;
    for (int i = 0; i < numberProduct; i++) {
        Product *product = new Product();
        is >> *product;
        store.products.addProduct(product);
    }
    return is;
}

ostream& operator<<(ostream& os, const Store& store) {
    os << store.name << endl;
    os << store.joinDate << endl;
    os << store.products;
    return os;
}

ListStore::ListStore() {}

ListStore::~ListStore() {
    for (int i = 0; i < stores.size(); i++) {
        delete stores[i];
    }
}

void ListStore::addStore(Store *store) {
    stores.push_back(store);
}

void ListStore::removeStore(Store *store) {
    for (int i = 0; i < stores.size(); i++) {
        if (stores[i] == store) {
            delete stores[i];
            stores.erase(stores.begin() + i);
            return;
        }
    }
}

int ListStore::getNumStore() {
    return stores.size();
}

Store* ListStore::getStore(int index) {
    return stores[index];
}

bool ListStore::init() {
    ifstream file(path);
    if (!file.is_open()) return false;
    int numberOfStore;
    file >> numberOfStore;
    for (int i = 0; i < numberOfStore; i++) {
        Store *store = new Store();
        file >> *store;
        stores.push_back(store);
    }
    file.close();
    return true;
}

ostream& operator<<(ostream& os, const ListStore& listStore) {
    os << "Stores:" << endl;
    for (int i = 0; i < listStore.stores.size(); i++) {
        os << "======================" << endl;
        os << "Store " << i + 1 << endl;
        os << *listStore.stores[i];
    }
    return os;
}