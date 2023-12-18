#include "CustomerAccount.h"



CustomerAccount::CustomerAccount(string username_, string password_) {
    username = username_;
    password = password_;
}   

string CustomerAccount::getUsername() const {
    return username;
}

string CustomerAccount::getPassword() const {
    return password;
}

Date CustomerAccount::getDateOfBirth() const {
    return dateOfBirth;
}

string CustomerAccount::getName() const {
    return name;
}

string CustomerAccount::getEmail() const {
    return email;
}

int CustomerAccount::getGender() const {
    return gender;
}

void CustomerAccount::setName(string name_) {
    name = name_;
}

void CustomerAccount::setEmail(string email_) {
    email = email_;
}

void CustomerAccount::setGender(int gender_) {
    gender = gender_;
}

void CustomerAccount::setDateOfBirth(Date dateOfBirth_) {
    dateOfBirth = dateOfBirth_;
}

istream& operator>>(istream &ci, CustomerAccount &account) {
    getline(ci, account.username);
    getline(ci, account.password);
    getline(ci, account.name);
    getline(ci, account.email);
    ci >> account.gender;
    ci >> account.dateOfBirth;
    return ci;
}

ostream& operator<<(ostream &co, CustomerAccount &account) {
    co << account.username << endl;
    co << account.password << endl;
    co << account.name << endl;
    co << account.email << endl;
    co << account.gender << endl;
    co << account.dateOfBirth << endl;
    return co;
}

BuyerAccount::BuyerAccount() : BuyerAccount("", "") {}

BuyerAccount::BuyerAccount(string username_, string password_) 
    : CustomerAccount(username_, password_), totalPaid(0), ranking(new CustomerRankingNormal()), shoppingCart(nullptr) {}

BuyerAccount::~BuyerAccount() {
    shoppingCart->cleanUp();
}

istream& operator>>(istream &ci, BuyerAccount &account) {
    ci >> (CustomerAccount&)account;
    ci >> account.totalPaid;
    account.checkRanking();
    return ci;
}

ostream& operator<<(ostream &co, BuyerAccount &account) {
    co << (CustomerAccount&)account;
    co << account.totalPaid << endl;
    
    return co;
}

CustomerRanking *BuyerAccount::getRanking() {
    return ranking;
}

void BuyerAccount::setRanking(CustomerRanking *ranking_) {
    delete ranking;
    ranking = ranking_;
}

void BuyerAccount::checkRanking() {
    if (totalPaid > 2e8) setRanking(new CustomerRankingGold());
    else if (totalPaid > 5e7) setRanking(new CustomerRankingSilver());
    else if (totalPaid > 1e7) setRanking(new CustomerRankingGold());
    else setRanking(new CustomerRankingNormal());
}

void BuyerAccount::addProductToCart(Product *product, int quantity) {
    if (quantity > product->getQuantity()) {
        cout << "Product quantity is not enough" << endl;
        return;
    }
    shoppingCart->addProduct(product, quantity);
}

void BuyerAccount::removeProductFromCart(Product *product) {
    shoppingCart->removeProduct(product);
}

void BuyerAccount::printProductsInCart() {
    cout << shoppingCart;
}



int BuyerAccount::getTotalPaid() {
    return totalPaid;
}

void BuyerAccount::setShoppingCart(ShoppingCart *shoppingCart_) {
    shoppingCart = shoppingCart_;
}

void BuyerAccount::setTotalPaid(int totalPaid_) {
    totalPaid = totalPaid_;
    checkRanking();
}

void BuyerAccount::checkout() {
    double totalPrice = shoppingCart->checkout();
    setTotalPaid(getTotalPaid() + totalPrice);
    cout << "Checkout successfully " << totalPrice << " VND" << endl;
    cout << "Payment method: " << shoppingCart->getPaymentMethod()->getName() << endl;
}
