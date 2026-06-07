#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <regex>
#include "Vehicle.h"
using namespace std;

bool validateEmail(const string& email) {
    return regex_match(email, regex("^[^@\\s]+@[^@\\s]+\\.[^@\\s]+$"));
}

bool validatePhone(const string& phone) {
    return regex_match(phone, regex("^\\+250[0-9]{9}$"));
}

bool validatePlate(const string& plate) {
    return regex_match(plate, regex("^[A-Z]{3}[0-9]{3}[A-Z]$"));
}

void addRecord() {
    string plate, type, name, email, phone;
    int year;

    cout << "Enter Plate Number (e.g., RAA123A): ";
    cin >> plate;
    while (!validatePlate(plate)) {
        cout << "Invalid plate format. Try again: ";
        cin >> plate;
    }

    cout << "Enter Vehicle Type: ";
    cin >> type;

    cout << "Enter Year: ";
    cin >> year;

    cin.ignore();
    cout << "Enter Owner Name: ";
    getline(cin, name);

    cout << "Enter Email: ";
    cin >> email;
    while (!validateEmail(email)) {
        cout << "Invalid email. Try again: ";
        cin >> email;
    }

    cout << "Enter Phone (+250...): ";
    cin >> phone;
    while (!validatePhone(phone)) {
        cout << "Invalid phone. Try again: ";
        cin >> phone;
    }

    VehicleOwner owner(name, email, phone);
    Vehicle v(plate, type, year, owner);

    ofstream file("records.txt", ios::app);
    file << v.getPlateNumber() << "," << v.getType() << "," << v.getYear() << ","
         << v.getOwner().getName() << "," << v.getOwner().getEmail() << ","
         << v.getOwner().getPhone() << endl;
    file.close();

    cout << "Record added successfully!\n";
}

void displayRecords() {
    ifstream file("records.txt");
    string line;

    cout << left << setw(10) << "Plate" << setw(10) << "Type" << setw(6) << "Year"
         << setw(15) << "Owner" << setw(20) << "Email" << setw(15) << "Phone" << endl;
    cout << string(76, '-') << endl;

    while (getline(file, line)) {
        stringstream ss(line);
        string plate, type, yearStr, name, email, phone;
        getline(ss, plate, ',');
        getline(ss, type, ',');
        getline(ss, yearStr, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        int year = stoi(yearStr);

        cout << left << setw(10) << plate << setw(10) << type << setw(6) << year
             << setw(15) << name << setw(20) << email << setw(15) << phone << endl;
    }
    file.close();
}

void searchRecord() {
    string searchPlate;
    cout << "Enter Plate Number to search: ";
    cin >> searchPlate;

    ifstream file("records.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string plate, type, yearStr, name, email, phone;
        getline(ss, plate, ',');
        getline(ss, type, ',');
        getline(ss, yearStr, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');

        if (plate == searchPlate) {
            cout << "Vehicle Found:\n";
            cout << "Plate: " << plate << "\nType: " << type << "\nYear: " << yearStr
                 << "\nOwner: " << name << "\nEmail: " << email << "\nPhone: " << phone << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Vehicle not found.\n";
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n--- Vehicle Registration System ---\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Search Record\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
