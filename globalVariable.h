#pragma once 

#include "productType.h"
#include "listAccount.h"
#include "store.h"
#include "voucher.h"
#include "flashSale.h"

class GlobalVariable {
    public:
        static bool init();
        static ListProductType listProductType;
        static ListStore listStore;
        static ListAccount listAccount;
        static ListVoucher listVoucher;
        static FlashSale flashSale;
    private:
};