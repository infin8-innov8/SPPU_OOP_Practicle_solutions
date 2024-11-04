// Q. Write C++ program using STL for sorting and searching user defined records such 
//      as Item records (Item code, name, cost, quantity etc) using vector container.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

// Item class to store the details of each item
class Item {
public:   
    char name[10];      // Item name
    int quantity;       // Item quantity
    int cost;           // Item cost
    int code;           // Item code

    bool operator == (const Item& i1) const {
        return code == i1.code;
    }

    bool operator < (const Item& i1) const {
        return code < i1.code;
    }
};

// Global vector to hold Item records
std::vector<Item> items;

// Function to insert an item into the vector
void insert() {
    Item i1;
    std::cout << "\nEnter Item Name: ";
    std::cin >> i1.name;

    std::cout << "Enter Item Quantity: ";
    std::cin >> i1.quantity;

    std::cout << "Enter Item Cost (in Rs.): ";
    std::cin >> i1.cost;

    std::cout << "Enter Item Code: ";
    std::cin >> i1.code;

    items.push_back(i1); 
    std::cout << "Item added successfully.\n";
}

// Function to display all items in the vector
void display() {
    std::for_each(items.begin(), items.end(), [](const Item& i1) {
        std::cout << "\nItem Name: " << i1.name;
        std::cout << "\nItem Quantity: " << i1.quantity;
        std::cout << "\nItem Cost: Rs. " << i1.cost;
        std::cout << "\nItem Code: " << i1.code << "\n";
    });
}

// Function to search for an item by its code
void search() {
    int search_code;
    std::cout << "\nEnter Item Code to search: ";
    std::cin >> search_code;

    auto it = std::find_if(items.begin(), items.end(), [search_code](const Item& i1) {
        return i1.code == search_code;
    });

    if (it != items.end()) {
        std::cout << "\nItem found:";
        std::cout << "\nItem Name: " << it->name;
        std::cout << "\nItem Quantity: " << it->quantity;
        std::cout << "\nItem Cost: Rs." << it->cost;
        std::cout << "\nItem Code: " << it->code << "\n";
    } else {
        std::cout << "\nItem not found.\n";
    }
}

// Function to delete an item by its code
void dlt() {
    int del_code;
    std::cout << "\nEnter Item Code to delete: ";
    std::cin >> del_code;

    auto it = std::find_if(items.begin(), items.end(), [del_code](const Item& i1) {
        return i1.code == del_code;
    });

    if (it != items.end()) {
        items.erase(it);  
        std::cout << "\nItem deleted successfully.\n";
    } else {
        std::cout << "\nItem not found.\n";
    }
}

// Comparison function for sorting items by cost
bool compareCost(const Item &i1, const Item &i2) {
    return i1.cost < i2.cost;
}

// Main function to display menu and handle user choices
int main() {
    int choice;

    do {
        std::cout << "\n------- Menu --------";
        std::cout << "\n1. Insert";
        std::cout << "\n2. Display";
        std::cout << "\n3. Search";
        std::cout << "\n4. Sort by Cost";
        std::cout << "\n5. Delete";
        std::cout << "\n6. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                std::sort(items.begin(), items.end(), compareCost);
                std::cout << "\nItems sorted by cost.\n";
                display();
                break;

            case 5:
                dlt();
                break;

            case 6:
                std::cout << "Exiting program.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while(true);

    std::cout << "\t\t ** Program executed successfully ** " << std::endl;
    return 0;
}