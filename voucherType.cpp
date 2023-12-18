#include "voucherType.h"
#include "globalVariable.h"

bool VoucherFullProduct::checkCondition(string ProductType, Date CustomerBirthDate) {
    return true;
}


string VoucherFullProduct::getName() {
    return "VoucherFullProduct";
}

VoucherByCategory::VoucherByCategory(string categoryName_) {
    category = GlobalVariable::listProductType.getProductType(categoryName_);
}

bool VoucherByCategory::checkCondition(string ProductTypeName, Date CustomerBirthDate) {
    ListProductType *listProductType = &(GlobalVariable::listProductType);
    ProductType *productType = listProductType->getProductType(ProductTypeName);
    if (productType == nullptr) {
        cout << "productType is null" << endl;
        return false;
    }
    else cout << "productType is not null" << endl;
    cout << category->getName() << endl;
    return (category->isSubProductType(productType));
}


string VoucherByCategory::getName() {
    return "VoucherByCategory: " + category->getName();;
}

string VoucherBirthDay::getName() {
    return "VoucherBirthDay";
}

bool VoucherBirthDay::checkCondition(string ProductType, Date CustomerBirthDate) {
    return (CustomerBirthDate == CurrentDateProvider::getCurrentDate());
}

