#include "productBuilder.h"

ProductBuilder::ProductBuilder() : product(nullptr) {}

ProductBuilder::~ProductBuilder() {
    delete product;
}

ProductBuilder* ProductBuilder::reset() {
    product = new Product();
    return this;
}

ProductBuilder* ProductBuilder::setName(string name_) {
    product->setName(name_);
    return this;
}

ProductBuilder* ProductBuilder::setPrice(double price_) {
    product->setPrice(price_);
    return this;
}

ProductBuilder* ProductBuilder::setType(string type_) {
    product->setType(type_);
    return this;
}

ProductBuilder* ProductBuilder::setQuantity(int quantity_) {
    product->setQuantity(quantity_);
    return this;
}

Product* ProductBuilder::getProduct() {
    Product *result = product;
    reset();
    return result;
}   