#include <iostream>
#include <vector>
#include <string>
#include<stdlib.h>
using namespace std;

// Define the Contact class
class Contact {
public:
    string name;
    string phoneNumber;

    Contact(string n, string p) : name(n), phoneNumber(p) {}
};

// Function to add a contact
void addContact(vector<Contact>& contacts) {
    string name, phoneNumber;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);

    contacts.push_back(Contact(name, phoneNumber));
    cout << "Contact added successfully.\n";
}

// Function to view all contacts
void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to display.\n";
        return;
    }

    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". " << contacts[i].name << " - " << contacts[i].phoneNumber << "\n";
    }
}

// Function to delete a contact
void deleteContact(vector<Contact>& contacts) {
    int index;
    cout << "Enter the number of the contact to delete: ";
    cin >> index;

    if (index < 1 || index > contacts.size()) {
        cout << "Invalid contact number.\n";
        return;
    }

    contacts.erase(contacts.begin() + index - 1);
    cout << "Contact deleted successfully.\n";
}

// Display the menu
void displayMenu() {
    cout << "\nContact Management System\n";
    cout << "1. Add Contact\n";
    cout << "2. View Contacts\n";
    cout << "3. Delete Contact\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() 
{
    vector<Contact> contacts;
    while (true)
    {
    int choice;
    cout <<"************************* MAIN MENU *************************"<<endl<<endl;
    cout <<"PRESS 1 TO ADD CONTACT"<<endl;
    cout <<"PRESS 2 TO DISPLAY CONTACT"<<endl;
    cout <<"PRESS 3 TO DELETE CONTACT"<<endl;
    cout <<"PRESS 0 TO EXIT"<<endl;
    cout <<"ENTER YOUR CHOICE: ";
    cin >> choice;

    if (choice == 1)
    {
       system("cls");
       cout <<"************************* ENTER CONTACT *************************"<<endl<<endl;
       addContact(contacts);
       system("pause");
       system("cls");
    }
    else if (choice == 2)
    {
        system("cls");
        cout <<"************************* DISPLAYING CONTACT *************************"<<endl<<endl;
        viewContacts(contacts);
        system("pause");
        system("cls");
    }
    else if (choice == 3)
    {
        system("cls");
        cout <<"************************* DELETE CONTACT *************************"<<endl<<endl;
        deleteContact(contacts);
        system("pause");
        system("cls");
       
    }
    else if (choice == 0)
    {
        system("cls");
        cout << "Exiting...\n";
        return 0;
    }
    else
    {
        system("cls");
        cout << "Invalid choice. Please try again.\n";
    }
    }

    return 0;
}
