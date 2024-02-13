#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class PhoneNumber {
public:
    string number;
    PhoneNumber* next;

    PhoneNumber(const string& num) : number(num), next(nullptr) {}
};

class Contact {
public:
    string name;
    PhoneNumber* phoneNumbers;
    Contact* next;

    Contact(const string& n, const string& num) : name(n), next(nullptr) {
        phoneNumbers = new PhoneNumber(num);
    }

    ~Contact() {
        // Clean up allocated memory for phone numbers
        while (phoneNumbers) {
            PhoneNumber* temp = phoneNumbers;
            phoneNumbers = phoneNumbers->next;
            delete temp;
        }
    }
};

class ContactManager {
private:
    Contact* head;

public:
    ContactManager() : head(nullptr) {}

   bool phoneNumberExists(const string& phoneNumber) const {
    Contact* current = head;

    while (current) {
        PhoneNumber* currentNumber = current->phoneNumbers;

        while (currentNumber) {
            if (currentNumber->number == phoneNumber) {
                return true; // Phone number already exists for a contact
            }
            currentNumber = currentNumber->next;
        }

        current = current->next;
    }

    return false; // Phone number not found in any contact
}

   Contact* findContact(const string& name) const {
        Contact* current = head;
        while (current) {
            if (current->name == name) {
                return current; // Return the contact node if found
            }
            current = current->next;
        }
        return nullptr; // Contact not found
    }

   void addPhoneNumber(Contact* contact, const string& phoneNumber) {
    if (!phoneNumberExists(phoneNumber)) {
        // Add phone number only if it doesn't already exist for any contact
        PhoneNumber* newPhoneNumber = new PhoneNumber(phoneNumber);
        newPhoneNumber->next = contact->phoneNumbers;
        contact->phoneNumbers = newPhoneNumber;
    } else {
        cout << "Error: Phone number '" << phoneNumber << "' already exists in the contact list.\n ";
        displayNamesForPhoneNumber(phoneNumber);
    }
}

    void addContact(const string& name, const string& phoneNumber) {
    if (phoneNumber.length() != 10) {
        cout << "Error: Phone number must be exactly ten digits.\n";
        return;
    }

    if (phoneNumberExists(phoneNumber)) {
        cout << "Error: The phone number '" << phoneNumber << "' already exists in the contact list."<<endl;
        displayNamesForPhoneNumber(phoneNumber);
        return;
    }

    Contact* existingContact = findContact(name);

    if (existingContact) {
        // Add phone number to existing contact with the same name
        addPhoneNumber(existingContact, phoneNumber);
        cout << "Phone number added to existing contact successfully!\n";
    } else {
        // Create a new contact if a contact with the same name does not exist
        Contact* newContact = new Contact(name, phoneNumber);
        newContact->next = head;
        head = newContact;
        cout << "Contact added successfully!\n";
    }
    // Sort contacts alphabetically after adding a new contact
    sortContacts();
}


    void deleteContact(const string& name) {
        Contact* current = head;
        Contact* prev = nullptr;

        while (current && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (current) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }

            delete current;
            cout << "Contact deleted successfully!\n";
        } else {
            cout << "Contact not found.\n";
        }
    }

    int countContacts() const {
        int count = 0;
        Contact* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    void sortContacts() {
        if (!head) {
            return; // No contacts to sort
        }

        bool swapped;
        Contact* last = nullptr;
        do {
            swapped = false;
            Contact* current = head;

            while (current->next != last) {
                if (current->name > current->next->name) {
                    swap(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
            last = current;

        } while (swapped);
    }

    void swap(Contact* a, Contact* b) {
        string tempName = a->name;
        a->name = b->name;
        b->name = tempName;

        PhoneNumber* tempPhoneNumbers = a->phoneNumbers;
        a->phoneNumbers = b->phoneNumbers;
        b->phoneNumbers = tempPhoneNumbers;
    }

    
void displayNamesForPhoneNumber(const string& phoneNumber) const {
    bool found = false;
    Contact* current = head;

    while (current) {
        PhoneNumber* currentNumber = current->phoneNumbers;

        while (currentNumber) {
            if (currentNumber->number == phoneNumber) {
                cout << "Names associated with phone number " << phoneNumber << ": " << current->name << "\n";
                found = true;
                break;
            }
            currentNumber = currentNumber->next;
        }

        current = current->next;
    }

    if (!found) {
        cout << "No contacts found for the phone number " << phoneNumber << "\n";
    }
}


    void displayContacts() const {
        if (!head) {
            cout << "No contacts available.\n";
        } else {
            cout << left << setw(5) << "No." << setw(20) << "Name" << setw(15) << "Phone Numbers" << "\n";
            cout << "-------------------------------------------------------------------\n";

            int contactNumber = 1;
            Contact* current = head;
            while (current) {
                cout << left << setw(5) << contactNumber++
                     << setw(20) << current->name;

                PhoneNumber* phoneNumber = current->phoneNumbers;
                while (phoneNumber) {
                    cout << phoneNumber->number << " ";
                    phoneNumber = phoneNumber->next;
                }

                cout << "\n";
                current = current->next;
            }
        }
    }

    ~ContactManager() {
        // Clean up allocated memory for contacts
        while (head) {
            Contact* temp = head;
            head = head->next;
            delete temp;
        }
    }
};



int main() {
    ContactManager contactManager;

    int choice;
 cout <<"\n\n---- Contact Management !!!----"<<endl;
    do {
        cout << "\n:\n";
        cout << "1. Insert New Contact/Phone Number.\n";
        cout << "2. Delete Contact.\n";
        cout << "3. Display Contacts.\n";
        cout << "4. Count Contacts.\n";
        cout << "5. Display Names for Phone Number.\n";
        cout << "6. Exit!\n";
        cout << "Enter your choice!: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, phoneNumber;
                cout << "Enter contact name: ";
                cin >> name;
                cout << "Enter contact phone number: ";
                cin >> phoneNumber;
                contactManager.addContact(name, phoneNumber);
                break;
            }
            case 2: {
                string name;
                cout << "Enter contact name to delete: ";
                cin >> name;
                contactManager.deleteContact(name);
                break;
            }
            case 3:
                contactManager.displayContacts();
                break;
            case 4:
                cout << "Number of contacts: " << contactManager.countContacts() << "\n";
                break;
            case 5: {
                string phoneNumber;
                cout << "Enter phone number to display associated names: ";
                cin >> phoneNumber;
                contactManager.displayNamesForPhoneNumber(phoneNumber);
                break;
            }
            case 6:
                cout << "Exiting program...\nThank you!!!";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 6);

    return 0;

}