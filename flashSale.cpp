#include "flashSale.h"

FlashSale::FlashSale() {
    discountPercent = 10;
    flashSaleOn = false;
}

void FlashSale::addProduct(Product *product) {
    products.push_back(product);
    product->setPrice(product->getPrice() * discountPercent / 100);
}

double FlashSale::getDiscountPercent() {
    return discountPercent;
}

void FlashSale::load() {
    if (flashSaleOn) return;
    cout << "FLASH SALE UP 90%" << endl;
    flashSaleOn = true;
    for (int i = 0; i < ShoppingCart::getInstance()->getNumProduct(); i++) {
        Product* tmpProduct = ShoppingCart::getInstance()->getProduct(i);
        addProduct(tmpProduct);
    }
}

void FlashSale::reset() {
    if (!flashSaleOn) return;
    cout << "FLASH SALE OFFF" << endl;
    flashSaleOn = false;
    for (int i = 0; i < products.size(); i++) {
        products[i]->setPrice(products[i]->getPrice() / discountPercent * 100);
    }
    products.clear();
}