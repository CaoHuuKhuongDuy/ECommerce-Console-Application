#include "productType.h"
#include <iostream>

void upcase(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
}

ProductType::ProductType(string name_) : name(name_), timeIn(0), timeOut(0), haveParent(false) {}

ProductType::~ProductType() {}

string ProductType::getName() {
    return name;
}

void ProductType::addSubProductType(ProductType* productType) {
    subProductTypes.push_back(productType);
    productType->setHaveParent(true);
}

int ProductType::getNumSubProductTypes() const {
    return subProductTypes.size();
}

ProductType* ProductType::getSubProductType(int index) const {
    return subProductTypes[index];
}

void ProductType::setHaveParent(bool haveParent_) {
    haveParent = haveParent_;
}

bool ProductType::getHaveParent() const {
    return haveParent;
}

void ProductType::setTimeIn(int timeIn_) {
    timeIn = timeIn_;
}

void ProductType::setTimeOut(int timeOut_) {
    timeOut = timeOut_;
}

int ProductType::getTimeIn() const {
    return timeIn;
}

int ProductType::getTimeOut() const {
    return timeOut;
}

bool ProductType::isSubProductType(ProductType* productType) {
    return (productType->getTimeIn() >= timeIn && productType->getTimeOut() <= timeOut);
}

ListProductType::ListProductType() : root(nullptr), cnt(0) {}

ListProductType::~ListProductType() {
    for (auto it = productTypes.begin(); it != productTypes.end(); it++) delete it->second;
}

ProductType* ListProductType::getProductType(string name) const {
    upcase(name);
    if (productTypes.find(name) == productTypes.end()) return nullptr;
    return productTypes.at(name);
}

bool ListProductType::dfs(ProductType* cur) {
    cur->setTimeIn(++cnt);
    for (int i = 0; i < cur->getNumSubProductTypes(); i++) {
        ProductType* next = cur->getSubProductType(i);
        if (next->getTimeIn() == 0) {
            if (!dfs(next)) return false;
        }
        else if (next->getTimeOut() == 0) return false;
    }
    cur->setTimeOut(cnt);
    return true;
}


bool ListProductType::init() {
    root = new ProductType("ROOT");
    productTypes["ROOT"] = root;

    ifstream file("resource/productType.txt");
    if (!file.is_open()) {
        cout << "Cannot open file productType.txt" << endl;
        file.close();
        return false;
    }
    string firstProductType, secondProductType;
    int edge = 0;
    // read file line by line with format: firstProductType-secondProductType
    while (getline(file, firstProductType, '-')) {
        getline(file, secondProductType);
        upcase(firstProductType);
        upcase(secondProductType);
        edge++;
        ProductType *first = nullptr, *second = nullptr;
        if (productTypes.find(firstProductType) == productTypes.end()) {
            first = new ProductType(firstProductType);
            productTypes[firstProductType] = first;
        }
        else first = productTypes[firstProductType];
        if (productTypes.find(secondProductType) == productTypes.end()) {
            second = new ProductType(secondProductType);
            productTypes[secondProductType] = second;
        }
        else second = productTypes[secondProductType];
        first->addSubProductType(second);
    }
    file.close();
    for (auto it = productTypes.begin(); it != productTypes.end(); it++)
        if (!it->second->getHaveParent() && it->first != "ROOT") {
            root->addSubProductType(it->second);
            edge++;
        }
    if (edge != productTypes.size() - 1) return false;
    if (!dfs(root)) return false;
    for (auto it = productTypes.begin(); it != productTypes.end(); it++) 
        if (it->second->getTimeIn() == 0) return false;
    return true;
}