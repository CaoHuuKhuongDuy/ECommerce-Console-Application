#pragma once 

#include <iostream>
#include "shoppingCart.h"
#include "customerRanking.h"
#include "date.h"

using namespace std;

class CustomerAccount {
    public:
        CustomerAccount(string username, string password);
        void setName(string name);
        void setEmail(string email);
        void setGender(int gender);
        void setDateOfBirth(Date dateOfBirth);
        string getName() const;
        string getEmail() const;
        int getGender() const;
        Date getDateOfBirth() const;
        virtual ~CustomerAccount() {};
        virtual CustomerRanking* getRanking() = 0;
        friend class ListAccount;  
        friend istream& operator>>(istream &is, CustomerAccount &account);
        friend ostream& operator<<(ostream &os, CustomerAccount &account);
    private:
        string getUsername() const;
        string getPassword() const;        
        string username, password;
        string name, email;
        int gender; // 0 : male, 1 : female
        Date dateOfBirth;
};

class BuyerAccount : public CustomerAccount {
    public:
        BuyerAccount();
        BuyerAccount(string username, string password);
        ~BuyerAccount();
        void addProductToCart(Product *product, int quantity);
        void removeProductFromCart(Product *product);
        void printProductsInCart();
        CustomerRanking* getRanking();
        int getTotalPaid();
        void setTotalPaid(int totalPaid);
        void setRanking(CustomerRanking *ranking);
        void setShoppingCart(ShoppingCart *shoppingCart);
        void checkRanking();
        void checkout();
        friend istream& operator>>(istream &is, BuyerAccount &account);
        friend ostream& operator<<(ostream &os, BuyerAccount &account);
    private:
        int totalPaid;
        ShoppingCart *shoppingCart;
        CustomerRanking *ranking;
};