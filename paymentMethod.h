#pragma once 

#include <string>
#include <iostream>

using namespace std;

class PaymentMethod {
    public:
        virtual string getName() = 0;
        virtual void processPayment(double amount) = 0;
};

class PaymentMethodCash : public PaymentMethod {
    public:
        string getName();
        void processPayment(double amount);
};

class PaymentMethodCreditCard : public PaymentMethod {
    public:
        string getName();
        void processPayment(double amount);
};

class PaymentMethodMomo : public PaymentMethod {
    public:
        string getName();
        void processPayment(double amount);
};