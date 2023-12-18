#pragma once 
#include <iostream>
#include "date.h"
#include "product.h"
#include "orderState.h"

using namespace std;

class Order {
    public:
        Order(string id, vector <Product*> productsInCart, int totalProducts, double totalPrice, double totalPayment, Date orderDate, OrderState *state);
        ~Order();
        void setState(OrderState *state);
        friend ostream& operator<<(ostream& os, const Order& order);
    private:
        string id;
        vector <Product*> productsInCart;
        int totalProducts;
        double totalPrice, totalPayment;
        Date orderDate;
        OrderState *state;
};

class ListOrder {
    public:
        ~ListOrder(); // remember to delete all orders
        void addOrder(Order *order);
        int getNumSize();
        friend ostream& operator<<(ostream& os, const ListOrder& listOrder);
    private:
        vector <Order*> orders;
};