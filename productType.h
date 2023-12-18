#pragma once 

#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iomanip>

using namespace std;


class ProductType {
    public:
        ProductType() {};
        ProductType(string name_);
        ~ProductType(); // remember to delete all subProductTypes
        string getName();
        void addSubProductType(ProductType* productType);
        void setHaveParent(bool haveParent_);
        int getNumSubProductTypes() const;
        bool getHaveParent() const;
        void setTimeIn(int timeIn_);
        void setTimeOut(int timeOut_);
        int getTimeIn() const;
        int getTimeOut() const;
        bool isSubProductType(ProductType* productType);
        ProductType* getSubProductType(int index) const;
    private:
        bool haveParent;
        string name;
        int timeIn, timeOut;
        vector <ProductType*> subProductTypes;
};

class ListProductType {
    public:
        ListProductType();
        ~ListProductType(); // remember to delete all productTypes
        bool init();
        ProductType* getProductType(string name) const;
    private:
        bool dfs(ProductType *productType);
        ProductType *root;
        map <string, ProductType*> productTypes;
        int cnt = 0;
};