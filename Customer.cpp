#include "Customer.h"

// Holds the item names
string ITEM_NAMES[] = {
        "Milk",
        "Cheese",
        "Apple",
        "Banana",
        "Orange"
};

// Holds the item prices (parallel arrays)
double ITEM_PRICES[] = {
        2.49,
        1.74,
        0.74,
        0.79,
        0.69
};

// The constructor
Customer::Customer(const bool guest) {
    // Prompt user for contact data and save it
    cout << endl << "Please update your contact info: " << endl;
    firstName = prompt_string("Enter first name: ");
    lastName = prompt_string("Enter last name: ");
    address = prompt_string("Enter address: ");
    email = prompt_string("Enter email address: ");
    phone = to_string(prompt_long("Enter phone number: "));
    // Save guest status
    isGuest = guest;
}

void Customer::addToCart() {
    // Prompt the user for what they want to buy, looping through each item and displaying it
    cout << endl << "What would you like to buy?" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  " << i + 1 << ") " << ITEM_NAMES[i] << " ($" << ITEM_PRICES[i] << ")" << endl;
    }
    int choice = prompt_int_min_max("Enter your choice (1-5): ", 1, 5) - 1;

    // Add that item to the cart
    cart.push_back(choice);
    cout << ITEM_NAMES[choice] << " added to cart." << endl;
}

void Customer::removeFromCart() {
    // If their cart is empty, print a message and return.
    if (cart.empty()) {
        cout << endl << "You can't remove something from an empty cart!" << endl;
        return;
    }

    // Loop through each item in the cart, and prompt the user to remove one of the items.
    cout << endl << "Your cart: " << endl;
    for (int i = 0; i < cart.size(); i++) {
        cout << "  " << i + 1 << ") " << ITEM_NAMES[cart[i]] << " ($" << ITEM_PRICES[cart[i]] << ")" << endl;
    }
    int choice = prompt_int_min_max("Select the item to remove (1-" + to_string(cart.size()) + "): ", 1, (int) cart.size()) - 1;

    // Remove that item
    cout << ITEM_NAMES[cart[choice]] << " removed from cart." << endl;
    cart.erase(cart.begin() + choice);
}

void Customer::displayBill() {
    // Print the user's info
    cout << endl << firstName << " " << lastName << endl;
    cout << email << " | " << phone << endl;
    cout << address << endl << endl;

    // Calculate how many of each item the user has
    int itemAmounts[5] = {0, 0, 0, 0 ,0};
    double subtotal = 0;
    for (int i : cart) itemAmounts[i]++;

    // Loop through and print each item
    for (int i = 0; i < 5; i++) {
        if (itemAmounts[i] == 0) continue;
        subtotal += ITEM_PRICES[i] * itemAmounts[i];
        cout << itemAmounts[i] << "x " << ITEM_NAMES[i] << ": $" << ITEM_PRICES[i] * itemAmounts[i] << endl;
    }

    // Print the subtotal
    cout << endl << "Subtotal: $" << subtotal << endl;
    // Add and print the 15% discount if the user is logged in
    if (!isGuest) {
        cout << "15% Logged In Discount: -$" << subtotal * .15 << endl;
        subtotal *= .85;
    }
    // Print sales tax
    cout << "New York Sales Tax (8.875%): $" << subtotal * .08875 << endl;
    // Print the total
    cout << "Total: $" << subtotal * 1.08875 << endl;
}