#include "paymentMethodFactory.h"

PaymentMethodFactory::PaymentMethodFactory() : paymentMethodFactory(nullptr) {}

PaymentMethodFactory::~PaymentMethodFactory() {
    delete paymentMethodFactory;
}

PaymentMethod *PaymentMethodFactory::createPaymentMethod(string method) {
    if (method == "Cash") {
        paymentMethodFactory = new PaymentMethodCashFactory();
    }
    else if (method == "CreditCard") {
        paymentMethodFactory = new PaymentMethodCreditCardFactory();
    }
    else if (method == "Momo") {
        paymentMethodFactory = new PaymentMethodMomoFactory();
    }
    else {
        return nullptr;
    }
    return paymentMethodFactory->createPaymentMethod();
}



PaymentMethod *PaymentMethodCashFactory::createPaymentMethod() {
    return new PaymentMethodCash();
}

PaymentMethod *PaymentMethodCreditCardFactory::createPaymentMethod() {
    return new PaymentMethodCreditCard();
}

PaymentMethod *PaymentMethodMomoFactory::createPaymentMethod() {
    return new PaymentMethodMomo();
}