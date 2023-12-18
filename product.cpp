#include "product.h"

Product::Product() : name(""), price(0), type("") {}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

string Product::getType() const {
    return type;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setName(string name_) {
    name = name_;
}

void Product::setPrice(double price_) {
    price = price_;
}

void Product::setType(string type_) {
    type = type_;
}

void Product::setQuantity(int quantity_) {
    quantity = quantity_;
}

istream& operator>>(istream &is, Product &product) {
    is.ignore();
    getline(is, product.name);
    is >> product.price;
    is.ignore();
    getline(is, product.type);
    is >> product.quantity;
    return is;
}

ostream &operator<<(ostream &os, const Product &product) {
    os << "Name: " << product.name << endl;
    os << "Price: " << fixed << setprecision(1) << product.price << endl;
    os << "Type: " << product.type << endl;
    os << "Quantity in store: " << product.quantity << endl;
    return os;
}

ListProduct::ListProduct() {}

ListProduct::~ListProduct() {
    for (int i = 0; i < products.size(); i++) {
        delete products[i];
    }
}

int ListProduct::getNumSize() {
    return products.size();
}

Product* ListProduct::getProduct(int index) {
    return products[index];
}

void ListProduct::addProduct(Product *product) {
    products.push_back(product);
}

int ListProduct::removeProduct(Product *product) {
    for (int i = 0; i < products.size(); i++) {
        // if (products[i]->getName() == product.getName()) {
        //     products.erase(products.begin() + i);
        //     return;
        // }
        if (products[i] == product) {
            delete products[i];
            products.erase(products.begin() + i);
            return i;
        }
    }
    return -1;
}

ostream& operator<<(ostream& os, const ListProduct& listProduct) {
    for (int i = 0; i < listProduct.products.size(); i++) {
        os << "----------------------------" << endl;
        os << "Product " << i + 1 << endl;
        os << *(listProduct.products[i]);
    }
    return os;
}

