#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "console.h"

using namespace std;

class Customer {
private:
    bool isGuest{};
    vector<int> cart;

    string firstName, lastName, address, email, phone;
public:
    explicit Customer(bool guest);

    void addToCart();
    void removeFromCart();
    void displayBill();
};

#endif