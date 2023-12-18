#pragma once 

#include <string>

using namespace std;

class ShippingMethod {
    public:
        virtual string getShippingMethodName() = 0;
        virtual double calculateShippingCost() = 0;
};

class ShippingMethodStandard : public ShippingMethod {
    public:
        string getShippingMethodName();
        double calculateShippingCost();
};

class ShippingMethodExpress : public ShippingMethod {
    public:
        string getShippingMethodName();
        double calculateShippingCost();
};