#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
    char city[20];
    char state[20];
} Contact;

typedef struct {
    Contact contacts[100];
    int contCount;
} AddBook;

void createContact(AddBook *addressBook);
void searchContact(AddBook *addressBook);
void editContact(AddBook *addressBook);
void deleteContact(AddBook *addressBook);
void listContacts(AddBook *addressBook, int sortCriteria);
void initialize(AddBook *addressBook);
void saveContactsToFile(AddBook *AddressBook);

#endif
