#include "Customer.h"

string USERNAME = "Hello";
string PASSWORD = "World";

int main() {
    cout << "  1) Login to your account" << endl;
    cout << "  2) Continue as a guest" << endl;
    cout << "  3) Exit" << endl;

    int choice = prompt_int_min_max("Enter your choice (1-2): ", 1, 2);

    if (choice == 1) {
        if (prompt_string("Enter username: ") != USERNAME) {
            cout << "That user does not exist.";
            return 0;
        }

        if (prompt_string("Enter password: ") != PASSWORD) {
            cout << "The specified password is incorrect";
            return 0;
        }
    } else if (choice == 3) return 0;

    Customer customer(choice == 2);

    while (true) {
        cout << endl << "Welcome to the Gobbler Goblin Grotto!" << endl;
        cout << "  1) Add item to cart" << endl;
        cout << "  2) Remove item from cart" << endl;
        cout << "  3) Check out" << endl;
        cout << "  4) Exit" << endl;

        choice = prompt_int_min_max("Enter your choice (1-2): ", 1, 2);
        switch (choice) {
            case 1:
                customer.addToCart();
                break;
            case 2:
                customer.removeFromCart();
                break;
            case 3:
                customer.displayBill();
            case 4:
                return 0;
            default:
                break;
        }
    }

}
