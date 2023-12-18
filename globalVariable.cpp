#include "globalVariable.h"

ListProductType GlobalVariable::listProductType;
ListStore GlobalVariable::listStore;
ListAccount GlobalVariable::listAccount;
ListVoucher GlobalVariable::listVoucher;
FlashSale GlobalVariable::flashSale;

bool GlobalVariable::init() {
    if (!listProductType.init()) return false;
    cout << "Pass listProductType.init()" << endl;
    if (!listStore.init()) return false;
    cout << "Pass listStore.init()" << endl;
    if (!listAccount.init()) return false;
    cout << "Pass listAccount.init()" << endl;
    if (!listVoucher.init()) return false;
    cout << "Pass listVoucher.init()" << endl;
    return true;
}