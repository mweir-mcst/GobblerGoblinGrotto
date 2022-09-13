#include "Customer.h"

string ITEM_NAMES[] = {
        "Milk",
        "Cheese",
        "Apple",
        "Banana",
        "Orange"
};

double ITEM_PRICES[] = {
        2.49,
        1.74,
        0.74,
        0.79,
        0.69
};

Customer::Customer(const bool guest) {
    cout << endl << "Please update your contact info: " << endl;
    firstName = prompt_string("Enter first name: ");
    lastName = prompt_string("Enter last name: ");
    address = prompt_string("Enter address: ");
    email = prompt_string("Enter email address: ");
    phone = to_string(prompt_long("Enter phone number: "));
    isGuest = guest;
}

void Customer::addToCart() {
    cout << endl << "What would you like to buy?" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  " << i + 1 << ") " << ITEM_NAMES[i] << " ($" << ITEM_PRICES[i] << ")" << endl;
    }
    int choice = prompt_int_min_max("Enter your choice (1-5): ", 1, 5) - 1;

    cart.push_back(choice);
    cout << ITEM_NAMES[choice] << " added to cart." << endl;
}

void Customer::removeFromCart() {
    if (cart.empty()) {
        cout << endl << "You can't remove something from an empty cart!" << endl;
        return;
    }
    cout << endl << "Your cart: " << endl;
    for (int i = 0; i < cart.size(); i++) {
        cout << "  " << i + 1 << ") " << ITEM_NAMES[cart[i]] << " ($" << ITEM_PRICES[cart[i]] << ")" << endl;
    }
    int choice = prompt_int_min_max("Select the item to remove (1-" + to_string(cart.size()) + "): ", 1, (int) cart.size()) - 1;
    cout << ITEM_NAMES[cart[choice]] << " removed from cart." << endl;
    cart.erase(cart.begin() + choice);
}

void Customer::displayBill() {
    cout << endl << firstName << " " << lastName << endl;
    cout << email << " | " << phone << endl;
    cout << address << endl << endl;

    int itemAmounts[5] = {0, 0, 0, 0 ,0};
    double subtotal = 0;
    for (int i : cart) itemAmounts[i]++;
    for (int i = 0; i < 5; i++) {
        if (itemAmounts[i] == 0) continue;
        subtotal += ITEM_PRICES[i] * itemAmounts[i];
        cout << itemAmounts[i] << "x " << ITEM_NAMES[i] << ": $" << ITEM_PRICES[i] * itemAmounts[i] << endl;
    }

    cout << endl << "Subtotal: $" << subtotal << endl;
    if (!isGuest) {
        cout << "15% Logged In Discount: -$" << subtotal * .15 << endl;
        subtotal *= .85;
    }
    cout << "New York Sales Tax (8.875%): $" << subtotal * .08875 << endl;
    cout << "Total: $" << subtotal * 1.08875 << endl;
}