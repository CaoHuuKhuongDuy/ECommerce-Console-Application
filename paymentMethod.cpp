#include "paymentMethod.h"

string PaymentMethodCash::getName() {
    return "PaymentMethodCash";
}

void PaymentMethodCash::processPayment(double ammount) {
    cout << "You have paid " << ammount << " by cash" << endl;
}

string PaymentMethodCreditCard::getName() {
    return "PaymentMethodCreditCard";
}

void PaymentMethodCreditCard::processPayment(double ammount) {
    cout << "You have paid " << ammount << " by credit card" << endl;
}

string PaymentMethodMomo::getName() {
    return "PaymentMethodMomo";
}

void PaymentMethodMomo::processPayment(double ammount) {
    cout << "You have paid " << ammount << " by momo" << endl;
}

