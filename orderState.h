#pragma once 

#include <iostream>

using namespace std;

class Order;

class OrderState {
    public:
        virtual string getStateName() = 0;
        virtual void processing(Order*) = 0;
        virtual void shipping(Order*) = 0;
        virtual void delivered(Order*) = 0;
};

class ProcessingState : public OrderState {
    public:
        string getStateName();
        void processing(Order*);
        void shipping(Order*);
        void delivered(Order*);
};

class ShippingState : public OrderState {
    public:
        string getStateName();
        void processing(Order*);
        void shipping(Order*);
        void delivered(Order*);
};

class DeliveredState : public OrderState {
    public:
        string getStateName();
        void processing(Order*);
        void shipping(Order*);
        void delivered(Order*);
};

