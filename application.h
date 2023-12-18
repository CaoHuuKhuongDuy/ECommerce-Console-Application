#pragma once 
#include "globalVariable.h"
#include "paymentMethodFactory.h"

class Application {
    public:
        Application();
        void runApp();
    private:
        bool init();
        bool login();
        void showMenu();
        void showStore();
        void showProducts();
        void showCart();
        void checkOut();
        BuyerAccount *customer;
        Store *currentStore;
};