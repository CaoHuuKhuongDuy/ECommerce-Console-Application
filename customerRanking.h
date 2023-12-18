#pragma once 

#include <iostream>

using namespace std;

class CustomerRanking {
    public:
        virtual string getCustomerRankingName() = 0;
        virtual double calculateDiscount() = 0;
};

class CustomerRankingNormal : public CustomerRanking {
    public:
        string getCustomerRankingName();
        double calculateDiscount();
};

class CustomerRankingBronze : public CustomerRanking {
    public:
        string getCustomerRankingName();
        double calculateDiscount();
};

class CustomerRankingSilver : public CustomerRanking {
    public:
        string getCustomerRankingName();
        double calculateDiscount();
};

class CustomerRankingGold : public CustomerRanking {
    public:
        string getCustomerRankingName();
        double calculateDiscount();
};
