#include <iostream>
#include <string>
#include <cstdlib> // for exit(0)
using namespace std;

// Function prototypes
void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

//Global variable for menu selection
char menuInput;

int main() {
    cout << "Hi! Welcome to Mr. Zamar's ATM Machine!" << endl;
    start();
    return 0;
}

// Menu displays for the user
void printIntroMenu() {
    cout << "\nPlease select an option from the menu below:" << endl;
    cout << "l  -> Login" << endl;
    cout << "c  -> Create New Account" << endl;
    cout << "q  -> Quit" << endl;
    cout << "> ";
}

void printMainMenu() {
    cout << "\nd  -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r  -> Request Balance" << endl;
    cout << "q  -> Quit" << endl;
    cout << "> ";
}

//Display the intro menu and take user input
void start() {
    printIntroMenu();
    cin >> menuInput;

    switch(menuInput) {
        case 'l':
            login();
            break;
        case 'c':
            createAccount();
            break;
        case 'q':
            exit(0);
        default:
            cout << "Invalid input. Try again." << endl;
            start(); // Re-call the start function if input is invalid
    }
}

// Account creation and login
string userId, password;
string storedUserId, storedPassword;
double balance = 0.0;

void createAccount() {
    cout << "Please enter your user id: ";
    cin >> storedUserId;
    cout << "Please enter your password: ";
    cin >> storedPassword;
    cout << "Thank you! Your account has been created!" << endl;
    start();
}

void login() {
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    if (userId == storedUserId && password == storedPassword) {
        cout << "Access Granted!" << endl;
        printMainMenu();
        char mainMenuInput;
        cin >> mainMenuInput;
        switch(mainMenuInput) {
            case 'd': {
                double depositAmount;
                cout << "Amount of deposit: $";
                cin >> depositAmount;
                balance += depositAmount;
                break;
            }
            case 'w': {
                double withdrawAmount;
                cout << "Amount of withdrawal: $";
                cin >> withdrawAmount;
                balance -= withdrawAmount;
                break;
            }
            case 'r':
                cout << "Your balance is $" << balance << endl;
                break;
            case 'q':
                cout << "Thanks for stopping by!" << balance << endl;
                exit(0);
            default:
                cout << "Invalid option" << endl;
        }
    } else {
        cout << "******** LOGIN FAILED! ********" << endl;
        start();
    }
}