#include "voucher.h"

const string path = "resource/vouchers.txt";

Voucher::Voucher(string id_, VoucherType *voucherType_, int discountPercent_, double maxDiscount_) {
    id = id_;
    voucherType = voucherType_;
    discountPercent = discountPercent_;
    maxDiscount = maxDiscount_;
}

Voucher::~Voucher() {
    delete voucherType;
}

string Voucher::getId() {
    return id;
}

double Voucher::getDiscount(Product *product, Date CustomerBirthDate) {
    double res = 0;
    if (voucherType->checkCondition(product->getType(), CustomerBirthDate)) 
        res = product->getPrice() * discountPercent / 100;
    return res;
}

double Voucher::getMaxDiscount() {
    return maxDiscount;
}

VoucherType* Voucher::getVoucherType() {
    return voucherType;
}

ostream& operator<<(ostream& os, const Voucher& voucher) {
    os << "ID: " << voucher.id << endl;
    os << "Voucher type: " << voucher.voucherType->getName() << endl;
    os << "Discount percent: " << voucher.discountPercent << endl;
    os << "Max discount: " << fixed << setprecision(2) << voucher.maxDiscount << endl;
    return os;
}

istream& operator>>(istream& is, Voucher& voucher) {
    is >> voucher.id;
    int voucherType;
    is >> voucherType;
    if (voucherType == 0) {
        voucher.voucherType = new VoucherFullProduct();
    } else if (voucherType == 1) {
        string category;
        is.ignore();
        getline(is, category);
        voucher.voucherType = new VoucherByCategory(category);
    } else {
        voucher.voucherType = new VoucherBirthDay();
    }
    is >> voucher.discountPercent;
    is >> voucher.maxDiscount;
    return is;
}

ListVoucher::ListVoucher() {}

ListVoucher::~ListVoucher() {
    for (int i = 0; i < vouchers.size(); i++) {
        delete vouchers[i];
    }
}

bool ListVoucher::init() {
    ifstream fin(path);
    // cout << "Number voucher: " << numberVoucher << endl; // "Number voucher: 3
    if (!fin.is_open()) return false;
    int numberVoucher;
    fin >> numberVoucher;
    for (int i = 0; i < numberVoucher; i++) {
        Voucher *voucher = new Voucher();
        fin >> *voucher;
        vouchers.push_back(voucher);
    }
    fin.close();
    return true;
}

void ListVoucher::addVoucher(Voucher *voucher) {
    vouchers.push_back(voucher);
}

void ListVoucher::removeVoucher(Voucher *voucher) {
    for (int i = 0; i < vouchers.size(); i++) {
        if (vouchers[i] == voucher) {
            delete vouchers[i];
            vouchers.erase(vouchers.begin() + i);
            return;
        }
    }
}

int ListVoucher::getNumVoucher() {
    return vouchers.size();
}

Voucher* ListVoucher::getVoucher(int index) {
    return vouchers[index];
}

ostream& operator<<(ostream& os, const ListVoucher& listVoucher) {
    os << "Vouchers:" << endl;
    for (int i = 0; i < listVoucher.vouchers.size(); i++) {
        os << "======================" << endl;
        os << "Voucher " << i + 1 << endl;
        os << *listVoucher.vouchers[i];
    }
    return os;
}