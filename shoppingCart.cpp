#include "shoppingCart.h"
#include "CustomerAccount.h"
#include "voucher.h"

ShoppingCart* ShoppingCart::instance = nullptr;

ShoppingCart::ShoppingCart(BuyerAccount *customerAccount_) 
    : voucher(nullptr), customerAccount(customerAccount_) {}

ShoppingCart::~ShoppingCart() {
    delete shippingMethod;
    delete paymentMethod;
}

ShoppingCart* ShoppingCart::getInstance(BuyerAccount *customerAccount_) {
    if (instance == nullptr) {
        instance = new ShoppingCart(customerAccount_);
    }
    return instance;
}

void ShoppingCart::cleanUp() {
    delete instance;
    instance = nullptr;
}

void ShoppingCart::setVoucher(Voucher *voucher_) {
    voucher = voucher_;
}

void ShoppingCart::addProduct(Product *product, int quantity_) {
    products.add({product, quantity_});
    cout << "Add product to cart successfully" << endl;
}

void ShoppingCart::removeProduct(Product *product) {
    Iterator<ProductInCart, Container<ProductInCart>> *it = products.CreateIterator();
    int cnt = 0;
    for (it->First(); !it->IsDone(); it->Next()) {
        ProductInCart curData = *it->Current();
        if (curData.first == product) {
            products.erase(cnt);
            break;
        }
        cnt++;
    }
    delete it;
}

int ShoppingCart::getNumProduct() const{
    return products.size();
}

double ShoppingCart::checkout() {
    
    Iterator<ProductInCart, Container<ProductInCart>> *it = products.CreateIterator();

    for (it->First(); !it->IsDone(); it->Next()) {
        ProductInCart curData = *it->Current();
        if (curData.first->getQuantity() < curData.second) {
            cout << "Product quantity is not enough" << endl;
            return 0;
        }
    }
    for (it->First(); !it->IsDone(); it->Next()) {
        ProductInCart &curData = *it->Current();
        curData.first->setQuantity(curData.first->getQuantity() - curData.second);
    }
    double res = getTotalPriceWithDiscount() + shippingMethod->calculateShippingCost();
    cout << "Shipping cost: " << shippingMethod->calculateShippingCost() << endl;
    products.clear();
    delete it;
    return res;
}

Product* ShoppingCart::getProduct(int index){
    return products[index].first;
}

void ShoppingCart::setShippingMethod(ShippingMethod *shippingMethod_) {
    shippingMethod = shippingMethod_;
}

void ShoppingCart::setPaymentMethod(PaymentMethod *paymentMethod_) {
    paymentMethod = paymentMethod_;
}

PaymentMethod* ShoppingCart::getPaymentMethod() {
    return paymentMethod;
}

ostream& operator<<(ostream& os, ShoppingCart& shoppingCart) {
    cout << "Products in cart:" << endl;
    for (int i = 0; i < shoppingCart.getNumProduct(); i++) {
        cout << "======================" << endl;
        cout << "Product " << i + 1 << endl;
        cout << *shoppingCart.getProduct(i);
        cout << "Quantity: " << shoppingCart.products[i].second << endl;
        cout << "Total price: " << shoppingCart.products[i].first->getPrice() * shoppingCart.products[i].second << endl;
    }
    cout << "--------------------------------" << endl;
    cout << "Total price without discount: " << shoppingCart.getTotalPriceWithOutDiscount() << endl;
    cout << "Total price with discount: " << shoppingCart.getTotalPriceWithDiscount() << endl;
    return os;
}

double ShoppingCart::getTotalPriceWithDiscount() {
    double totalPrice = getTotalPriceWithOutDiscount();
    Iterator<ProductInCart, Container<ProductInCart>> *it = products.CreateIterator();
    double discountAmount = 0;
    if (voucher) {
        for (it->First(); !it->IsDone(); it->Next()) {
            ProductInCart curData = *it->Current();
            discountAmount += curData.second * voucher->getDiscount(curData.first, customerAccount->getDateOfBirth());
        }
        discountAmount = min(discountAmount, voucher->getMaxDiscount());
    }
    totalPrice = max(0.0, totalPrice - discountAmount);
    totalPrice *= customerAccount->getRanking()->calculateDiscount();
    return totalPrice;
}

double ShoppingCart::getTotalPriceWithOutDiscount() {
    double totalPrice = 0;
    Iterator<ProductInCart, Container<ProductInCart>> *it = products.CreateIterator();
    for (it->First(); !it->IsDone(); it->Next()) {
        ProductInCart curData = *it->Current();
        totalPrice += curData.first->getPrice() * curData.second;
    }
    delete it;
    return totalPrice;
}