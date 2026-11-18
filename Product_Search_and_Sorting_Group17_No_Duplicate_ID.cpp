#include <iostream>
#include <string>
#include <utility>
using namespace std;

struct Product {
    int id;
    string name;
    int price;
};

Product p[100] = {
    {101, "Laptop", 50000},
    {102, "Mobile", 15000},
    {103, "Mouse", 500},
    {104, "Keyboard", 1200},
    {105, "Monitor", 10000}
};
int count = 5;

void addProduct() {
    if (count >= 100) {
        cout << "\nProduct list is full!\n";
        return;
    }
    int newID;
    cout << "\nEnter Product ID: ";
    cin >> newID;


    for (int i = 0; i < count; i++) {
        if (p[i].id == newID) {
            cout << "\nError: Product ID already exists! Please enter a unique ID.\n";
            return;
        }
    }

    p[count].id = newID;
    cout << "Enter Product Name (one word): ";
    cin >> p[count].name;
    cout << "Enter Product Price: ";
    cin >> p[count].price;
    count++;
    cout << "\nProduct added successfully!\n";
}

void displayProducts() {
    if (count == 0) {
        cout << "\nNo products available.\n";
        return;
    }
    cout << "\n--- Product List ---\n";
    cout << "ID\tName\t\tPrice\n";
    for (int i = 0; i < count; i++) {
        cout << p[i].id << "\t" << p[i].name
             << "\t\t" << p[i].price << endl;
    }
}

void sortByPrice() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (p[j].price > p[j + 1].price) {
                swap(p[j], p[j + 1]);
            }
        }
    }
    cout << "\nProducts sorted by price (low to high).\n";
    displayProducts();
}

void sortByName() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (p[j].name > p[j + 1].name) {
                swap(p[j], p[j + 1]);
            }
        }
    }
    cout << "\nProducts sorted by name (A to Z).\n";
    displayProducts();
}

void searchProduct() {
    string searchName;
    bool found = false;

    cout << "\nEnter product name to search: ";
    cin >> searchName;

    for (int i = 0; i < count; i++) {
        if (p[i].name == searchName) {
            cout << "\nProduct found!\n";
            cout << "ID: " << p[i].id << endl;
            cout << "Name: " << p[i].name << endl;
            cout << "Price: Rs. " << p[i].price << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nProduct not found!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== PRODUCT SEARCH AND SORTING SYSTEM =====\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Sort Products by Price\n";
        cout << "4. Sort Products by Name\n";
        cout << "5. Search Product\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: sortByPrice(); break;
            case 4: sortByName(); break;
            case 5: searchProduct(); break;
            case 6: cout << "\nThank you for using the system!\n"; break;
            default: cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
