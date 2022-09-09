#include "Customer.h"

Customer::Customer(const bool guest) {
    cout << endl << "Please update your contact info: ";
    firstName = prompt_string("Enter first name: ");
    lastName = prompt_string("Enter last name: ");
    address = prompt_string("Enter address: ");
    email = prompt_string("Enter email address: ");
    phone = prompt_string("Enter phone number: ");

    isGuest = guest;
}

void Customer::addToCart() {

}

void Customer::removeFromCart() {

}

void Customer::displayBill() {

}