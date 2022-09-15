/**
 * Name: Matthew Weir
 * Program Name: Gobbler Goblin Grotto
 * Date: 9/21/22
 * Extra Thing: Error trapping (you said this could be an extra) and item removal
 */

#include "Customer.h"

// Default username and password
string USERNAME = "Hello";
string PASSWORD = "World";

int main() {
    // Set precision to 2 decimal places
    cout.setf(ios::fixed);
    cout << setprecision(2);

    cout << "  1) Login to your account" << endl;
    cout << "  2) Continue as a guest" << endl;
    cout << "  3) Exit" << endl;

    // Prompt user to log in or continue as guest
    int choice = prompt_int_min_max("Enter your choice (1-3): ", 1, 3);

    if (choice == 1) {
        // If logging in, have them enter username and password, and make sure they are correct.
        if (prompt_string("Enter username: ") != USERNAME) {
            cout << "That user does not exist.";
            return 0;
        }

        if (prompt_string("Enter password: ") != PASSWORD) {
            cout << "The specified password is incorrect";
            return 0;
        }
    } else if (choice == 3) return 0;

    // Create the customer class, with the guest property set depending on what they chose.
    Customer customer(choice == 2);

    while (true) {
        // Main menu
        cout << endl << "Welcome to the Gobbler Goblin Grotto!" << endl;
        cout << "  1) Add item to cart" << endl;
        cout << "  2) Remove item from cart" << endl;
        cout << "  3) Check out" << endl;
        cout << "  4) Exit" << endl;

        // Prompt user for their choice from the main menu
        choice = prompt_int_min_max("Enter your choice (1-4): ", 1, 4);
        switch (choice) {
            case 1:
                // If 1, add an item to the cart and repeat
                customer.addToCart();
                break;
            case 2:
                // If 2, remove an item from the cart and repeat
                customer.removeFromCart();
                break;
            case 3:
                // If 3, display the bill and exit
                customer.displayBill();
            case 4:
                // If 4, exit
                return 0;
            default:
                cout << endl << "Achievement get: How did we get here?" << endl;
                break;
        }
    }

}
