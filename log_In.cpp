#include <iostream>
#include <fstream>
using namespace std;

void login();
void registration();
void forgot();

int main() {
    int choice;

    while (true) {
        cout << "\n\t\t\t_____________________________________________\n";
        cout << "\t\t\t         Welcome to the Login Page\n";
        cout << "\t\t\t_____________________________________________\n\n";

        cout << "\t[1] Log in\n";
        cout << "\t[2] Register\n";
        cout << "\t[3] Forgot Password\n";
        cout << "\t[4] Exit\n";
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                registration();
                break;
            case 3:
                forgot();
                break;
            case 4:
                cout << "\n\tThank you for using the system. Goodbye!\n";
                return 0;
            default:
                cout << "\n\tInvalid choice. Try again.\n";
        }
    }
}

void login() {
    int count = 0;
    string userId, password, id, pass;

    system("cls"); // use "clear" on Linux/Mac
    cout << "\t\t\tLOGIN PAGE\n";
    cout << "\t\tUsername: ";
    cin >> userId;
    cout << "\t\tPassword: ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1) {
        cout << "\n\tLogin successful. Welcome, " << userId << "!\n";
    } else {
        cout << "\n\tLogin error. Invalid username or password.\n";
    }
}

void registration() {
    string ruserId, rpassword;
    system("cls");
    cout << "\t\t\tREGISTRATION PAGE\n";
    cout << "\tEnter new username: ";
    cin >> ruserId;
    cout << "\tEnter new password: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    f1.close();

    cout << "\n\tRegistration successful!\n";
}

void forgot() {
    int option;
    system("cls");
    cout << "\t\t\tFORGOT PASSWORD PAGE\n";
    cout << "\t[1] Search by username\n";
    cout << "\t[2] Back to main menu\n";
    cout << "\tEnter your choice: ";
    cin >> option;

    switch (option) {
        case 1: {
            int count = 0;
            string suserId, sId, spass;
            cout << "\n\tEnter your remembered username: ";
            cin >> suserId;

            ifstream f2("records.txt");
            while (f2 >> sId >> spass) {
                if (sId == suserId) {
                    count = 1;
                    break;
                }
            }
            f2.close();

            if (count == 1) {
                cout << "\n\tAccount found! Your password is: " << spass << endl;
            } else {
                cout << "\n\tSorry, username not found.\n";
            }
            break;
        }

        case 2:
            return;

        default:
            cout << "\tInvalid choice. Try again.\n";
    }
}
