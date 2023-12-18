#pragma once 
#include "paymentMethod.h"

class PaymentMethodFactory {
    public:
        PaymentMethodFactory();
        ~PaymentMethodFactory();
        virtual PaymentMethod *createPaymentMethod() {return nullptr;}
        PaymentMethod *createPaymentMethod(string method);
    private:
        PaymentMethodFactory *paymentMethodFactory;
};

class PaymentMethodCashFactory : public PaymentMethodFactory {
    public:
        PaymentMethod *createPaymentMethod();
};

class PaymentMethodCreditCardFactory : public PaymentMethodFactory {
    public:
        PaymentMethod *createPaymentMethod();
};

class PaymentMethodMomoFactory : public PaymentMethodFactory {
    public:
        PaymentMethod *createPaymentMethod();
};