#include "orderState.h"
#include "order.h"

string ProcessingState::getStateName() {
    return "Processing";
}

void ProcessingState::processing(Order* order) {
    cout << "Processing..." << endl;
}

void ProcessingState::shipping(Order* order) {
    cout << "Shipping..." << endl;
    order->setState(new ShippingState());
    delete this;
}

void ProcessingState::delivered(Order* order) {
    cout << "Cannot deliver the order. It is still processing." << endl;
}

string ShippingState::getStateName() {
    return "Shipping";
}

void ShippingState::processing(Order* order) {
    cout << "Cannot process the order. It is shipping." << endl;
}

void ShippingState::shipping(Order* order) {
    cout << "Shipping..." << endl;
}

void ShippingState::delivered(Order* order) {
    cout << "Order is delivered." << endl;
    order->setState(new DeliveredState());
    delete this;
}

string DeliveredState::getStateName() {
    return "Delivered";
}

void DeliveredState::processing(Order* order) {
    cout << "Cannot process the order. It is delivered." << endl;
}

void DeliveredState::shipping(Order* order) {
    cout << "Cannot ship the order. It is delivered." << endl;
}

void DeliveredState::delivered(Order* order) {
    cout << "Order is delivered." << endl;
}