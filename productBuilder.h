#pragma once 

#include <string>
#include "product.h"

using namespace std;

class ProductBuilder {
    public:
        ProductBuilder();
        ~ProductBuilder();
        ProductBuilder* reset();
        ProductBuilder* setName(string name_);
        ProductBuilder* setPrice(double price_);
        ProductBuilder* setType(string type_);
        ProductBuilder* setQuantity(int quantity_);
        Product* getProduct();
    private:
        Product *product;
};