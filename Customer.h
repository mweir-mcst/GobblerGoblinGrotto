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
    // Whether the user is a guest
    bool isGuest{};
    // The user's cart
    vector<int> cart;

    // Various properties for the user
    string firstName, lastName, address, email, phone;
public:
    // Constructor
    explicit Customer(bool guest);

    // Methods
    void addToCart();
    void removeFromCart();
    void displayBill();
};

#endif