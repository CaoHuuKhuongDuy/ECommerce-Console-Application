#pragma once 

#include <iostream>
#include <vector>
#include "product.h"
#include "shoppingCart.h"

using namespace std;

class FlashSale {
    public:
        FlashSale();
        double getDiscountPercent();
        void reset();
        void load();
    private:
        bool flashSaleOn;
        void addProduct(Product *product);
        double discountPercent;
        vector <Product*> products;
};