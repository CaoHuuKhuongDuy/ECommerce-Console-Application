#include "shippingStrategy.h"

string ShippingMethodStandard::getShippingMethodName() {
    return "Standard";
}

double ShippingMethodStandard::calculateShippingCost() {
    return 30000;
}

string ShippingMethodExpress::getShippingMethodName() {
    return "Express";
}

double ShippingMethodExpress::calculateShippingCost() {
    return 100000;
}