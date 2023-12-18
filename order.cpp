#include "order.h"

Order::Order(string id, vector <Product*> productsInCart, int totalProducts, double totalPrice, double totalPayment, Date orderDate, OrderState *state) {
    this->id = id;
    this->productsInCart = productsInCart;
    this->totalProducts = totalProducts;
    this->totalPrice = totalPrice;
    this->totalPayment = totalPayment;
    this->orderDate = orderDate;
    this->state = state;
}

Order::~Order() {
    delete state;
}

void Order::setState(OrderState *state) {
    this->state = state;
}

ostream& operator<<(ostream& os, const Order& order) {
    os << "Order ID: " << order.id << endl;
    os << "Products in cart: " << endl;
    for (int i = 0; i < order.productsInCart.size(); i++) {
        os << *order.productsInCart[i];
    }
    os << "Total products: " << order.totalProducts << endl;
    os << "Total price: " << order.totalPrice << endl;
    os << "Total payment: " << order.totalPayment << endl;
    os << "Order date: " << order.orderDate << endl;
    return os;
}

ListOrder::~ListOrder() {
    for (int i = 0; i < orders.size(); i++) {
        delete orders[i];
    }
}

void ListOrder::addOrder(Order *order) {
    orders.push_back(order);
}

int ListOrder::getNumSize() {
    return orders.size();
}