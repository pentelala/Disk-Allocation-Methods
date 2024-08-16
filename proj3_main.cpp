#include <iostream>
#include "UserInterface.cpp"

using namespace std;

int main() {
    UserInterface ui;

    int choice;
    do {
        ui.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        ui.processUserChoice(choice);
    } while (choice != 8); // 8 corresponds to Exit in the menu

    return 0;
}