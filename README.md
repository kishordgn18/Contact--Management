OVERVIEW

Overall, the code provides a simple contact management system with various functionalities, and it ensures the uniqueness of phone numbers across all contacts. The user can perform operations like adding, deleting, and displaying contacts, making it a basic but functional contact management program.


HOW TO USE!

1.Insert New Contact/Phone Number (case 1):
Get contact name and phone number from the user.
Add a new contact or add a phone number to an existing contact.
Display appropriate messages based on the result.

2.Delete Contact (case 2):
Get the contact name from the user.
Delete the contact if it exists, display a message accordingly.

3.Display Contacts (case 3):
Display all contacts in tabular form.

4.Count Contacts (case 4):
Display the total number of contacts.

5.Display Names for Phone Number (case 5):
Get a phone number from the user.
Display names associated with the given phone number.

6.Exit (case 6):
Display an exit message.
Terminate the program.

////////////////BRIEF ON HOW THIS CODE PERFORM///////////////////

Classes:
The program defines two classes: PhoneNumber and Contact.
PhoneNumber represents a phone number and is implemented as a linked list.
Contact represents a contact with a name and a linked list of phone numbers.

ContactManager Class:
Manages a linked list of contacts (Contact objects).
Provides functions for adding and deleting contacts, displaying contacts, counting contacts, displaying names for a given phone number, and sorting contacts.

PhoneNumberExists Function:
Checks whether a given phone number already exists in any contact in the list.

FindContact Function:
Searches for a contact by name in the list.

AddPhoneNumber Function:
Adds a phone number to a contact if the number is not already associated with any contact.
Displays an error message and associated names if the phone number already exists in the list.

AddContact Function:
Adds a new contact or adds a phone number to an existing contact.
Ensures that the provided phone number is unique across all contacts.
Sorts the contacts alphabetically.

DeleteContact Function:
Deletes a contact by name from the list.

CountContacts Function:
Counts the total number of contacts in the list.

SortContacts Function:
Sorts the contacts alphabetically using the bubble sort algorithm.

DisplayNamesForPhoneNumber Function:
Displays the names associated with a given phone number.

DisplayContacts Function:
Displays all contacts in tabular form, showing names and associated phone numbers.

Main Function:
Contains the main menu loop where the user can choose various actions.
Actions include adding/deleting contacts, displaying contacts, counting contacts, displaying names for a phone number, and exiting the 
program.

User Interaction:
The program interacts with the user, accepting input for menu choices, contact names, and phone numbers.
Error messages are displayed for invalid inputs, duplicate phone numbers, and other relevant scenarios.

Memory Management:
Proper memory management is implemented for deallocating memory used by contacts and phone numbers when necessary.

Exit Condition:
The program continues to execute the menu until the user chooses to exit. 
