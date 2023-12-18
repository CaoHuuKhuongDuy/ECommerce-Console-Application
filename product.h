#pragma once 

#include <string>
#include <vector>
#include <iostream>
#include "productType.h"
#include "HandleStringData.h"

using namespace std;

class Product {
    public:
        Product();
        string getName() const;
        double getPrice() const;
        string getType() const;
        int getQuantity() const;
        void setName(string name_);
        void setPrice(double price_);
        void setType(string type_);
        void setQuantity(int quantity_);
        friend istream& operator>>(istream& is, Product& product);
        friend ostream& operator<<(ostream& os, const Product& product);
    private:
        string name;
        double price;
        string type;
        int quantity;
};

class ListProduct {
    public:
        ListProduct();
        ~ListProduct(); // remember to delete all products
        void addProduct(Product *product);
        int removeProduct(Product *product);
        int getNumSize();
        Product* getProduct(int index);
        friend ostream& operator<<(ostream& os, const ListProduct& listProduct);
    private:
        vector <Product*> products;
};