#pragma once 
#include "voucherType.h"
#include "product.h"
#include <fstream>
#include <vector>

using namespace std;

class Voucher {
    public:
        Voucher() {};
        Voucher(string id_, VoucherType *voucherType_, int discountPercent_, double maxDiscount_);
        ~Voucher();
        double getDiscount(Product *product, Date CustomerBirthDate);
        double getMaxDiscount();
        string getId();
        VoucherType* getVoucherType();
        friend ostream& operator<<(ostream& os, const Voucher& voucher);
        friend istream& operator>>(istream& is, Voucher& voucher);
    private:
        string id;
        VoucherType *voucherType;
        int discountPercent;
        double maxDiscount;   
};
class ListVoucher {
    public:
        bool init();
        ListVoucher();
        ~ListVoucher();
        void addVoucher(Voucher *voucher);
        void removeVoucher(Voucher *voucher);
        int getNumVoucher();
        Voucher* getVoucher(int index);
        friend ostream& operator<<(ostream& os, const ListVoucher& listVoucher);
    private:
        vector <Voucher*> vouchers;
};