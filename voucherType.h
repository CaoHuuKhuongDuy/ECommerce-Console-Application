#pragma once 
#include <string>
#include "date.h"

using namespace std;

class ProductType;

class VoucherType {
    public:
        virtual string getName() = 0;
        virtual bool checkCondition(string productType, Date CustomerBirthDate) = 0;
    private:
};

class VoucherFullProduct : public VoucherType {
    public:
        bool checkCondition(string productType, Date CustomerBirthDate);
        string getName();
};

class VoucherByCategory : public VoucherType {
    public:
        VoucherByCategory(string categoryName_);
        bool checkCondition(string productType, Date CustomerBirthDate);
        string getName();
    private:
        ProductType *category;
};

class VoucherBirthDay : public VoucherType {
    public:
        bool checkCondition(string productType, Date CustomerBirthDate);
        string getName();
};
