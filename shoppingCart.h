#pragma once 

#include <string>
#include <iomanip>
#include "shippingStrategy.h"
#include "paymentMethod.h"
#include "container.h"
#include "product.h"
#include "date.h"

using namespace std;

class BuyerAccount;
class Voucher;

typedef pair <Product*, int> ProductInCart;

class ShoppingCart {
    public:
        ~ShoppingCart();
        void addProduct(Product *product, int quantity_);
        void removeProduct(Product *product);
        int getNumProduct() const;
        Product* getProduct(int index);
        double getTotalPriceWithOutDiscount();
        double getTotalPriceWithDiscount();
        double checkout();
        void setShippingMethod(ShippingMethod *shippingMethod_);
        void setPaymentMethod(PaymentMethod *paymentMethod_);
        void setVoucher(Voucher *voucher_);
        PaymentMethod* getPaymentMethod();
        friend ostream& operator<<(ostream& os, ShoppingCart& shoppingCart);
        static ShoppingCart* getInstance(BuyerAccount* customerAccount_ = nullptr);
        void cleanUp();
    private:
        ShoppingCart(BuyerAccount *customerAccount_);
        BuyerAccount *customerAccount;
        static ShoppingCart* instance;
        Container <ProductInCart> products;
        Voucher *voucher;
        ShippingMethod *shippingMethod;
        PaymentMethod *paymentMethod;

};