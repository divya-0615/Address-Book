#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"


void listContacts(AddBook *addressBook, int sortCriteria)
{
    Contact temp;

    // Sorting
    for(int i = 0; i < addressBook->contCount - 1; i++)
    {
        for(int j = 0; j < addressBook->contCount - i - 1; j++)
        {
            int result = 0;

            switch(sortCriteria)
            {
                case 1:
                    result = strcmp(addressBook->contacts[j].name,
                                    addressBook->contacts[j + 1].name);
                    break;

                case 2:
                    result = strcmp(addressBook->contacts[j].phone,
                                    addressBook->contacts[j + 1].phone);
                    break;

                case 3:
                    result = strcmp(addressBook->contacts[j].state,
                                    addressBook->contacts[j + 1].state);
                    break;

                default:
                    printf("Invalid sorting choice!\n");
                    return;
            }

            if(result > 0)
            {
                temp = addressBook->contacts[j];

                addressBook->contacts[j] =
                    addressBook->contacts[j + 1];

                addressBook->contacts[j + 1] = temp;
            }
        }
    }

    // Display
    printf("\n===================================== All Contact List =====================================\n");

    for(int i = 0; i < addressBook->contCount; i++)
    {
        printf("Id: %d\n", i);

        printf("Name  : %-15s    Phone : %-15s    Email : %-20s    City: %-15s    State: %-15s\n",
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email,
               addressBook->contacts[i].city,
               addressBook->contacts[i].state);
    }
}



void initialize(AddBook *addressBook) {
    addressBook->contCount = 0;

    loadContactsFromFile(addressBook);
    
}



void saveAndExit(AddBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}



void createContact(AddBook *addressBook)
{

    printf("Enter name: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contCount].name);

    printf("Enter phone: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contCount].phone);

    printf("Enter email: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contCount].email);

    printf("Enter City: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contCount].city);

    printf("Enter State: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contCount].state);

    addressBook->contCount++;

    printf("Done... \n");
    
}



void searchContact(AddBook *addressBook) 
{
    int choice;
    char search[50];
    int flag = 0;

    while(1){
        printf("\n Search Contact By:\n");
        printf("1. Name \n");
        printf("2. Phone \n");
        printf("3. Email \n");
        printf("4. city \n");
        printf("5. State \n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice>=1 && choice<=5){
            break;
        }
        printf("\nEnter correct choise number...! ");
    }

    printf("Enter search value: ");
    scanf(" %[^\n]", search);


    for (int i = 0; i < addressBook->contCount; i++)
    {
        if (choice==1 && strcasestr(addressBook->contacts[i].name, search)!=NULL)
        {
            printf("\nContact Found!\n");
            printf("Id: %d \n",i);
            printf("Name  : %s    Phone : %s    Email : %s      City: %s    State: %s \n", 
                addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email, 
                addressBook->contacts[i].city, addressBook->contacts[i].state);

            flag = 1;
        }

        else if (choice==2 && strcasestr(addressBook->contacts[i].phone, search)!=NULL)
        {
            printf("\nContact Found!\n");
            printf("Id: %d \n",i);
            printf("Name  : %s    Phone : %s    Email : %s      City: %s    State: %s \n", 
                addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email, 
                addressBook->contacts[i].city, addressBook->contacts[i].state);
            flag = 1;
        }

        else if (choice==3 && strcasestr(addressBook->contacts[i].email, search)!=NULL)
        {
            printf("\nContact Found!\n");
            printf("Id: %d \n",i);
            printf("Name  : %s    Phone : %s    Email : %s      City: %s    State: %s \n ", 
                addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email, 
                addressBook->contacts[i].city, addressBook->contacts[i].state);
            flag = 1;
        }

        else if(choice==4 && strcasestr(addressBook->contacts[i].city, search)!=NULL){
            printf("\nContact Found!\n");
            printf("Id: %d \n",i);
            printf("Name  : %15s    Phone : %15s    Email : %15s      City: %15s    State: %15s \n", 
                addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email, 
                addressBook->contacts[i].city, addressBook->contacts[i].state);
            flag = 1;
        }

        else if(choice==5 && strcasestr(addressBook->contacts[i].state,search)!=NULL){
            printf("\nContact Found!\n");
            printf("Id: %d \n",i);
            printf("Name  : %s    Phone : %s    Email : %s      City: %s    State: %s \n", 
                addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email, 
                addressBook->contacts[i].city, addressBook->contacts[i].state);
            flag = 1;
        }
    }

    if (flag==0)
    {
        printf("\nContact not found..!\n");
    }

}



void editContact(AddBook *addressBook)
{
	int know_id;
    printf("\nI know which ID number should be EDIT ");
    printf("\n Yes=> 1 \n NO=> 0 \n");
    scanf("%d",&know_id);
    if(know_id==0){
        searchContact(addressBook);
    }

    int edit_id;
    printf("Enter the ID Number of the contact that should be Edit: ");
    scanf("%d",&edit_id);

    if(edit_id<0 || edit_id>=addressBook->contCount)
    {
        printf("Invalid ID!\n");
        return;
    }

    int choice;
    char edit[50];
    int flag = 0;

    while(1){
        printf("\nEDIT Contact By:\n");
        printf("1. Name \n");
        printf("2. Phone \n");
        printf("3. Email \n");
        printf("4. city \n");
        printf("5. State \n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice>=1 && choice<=5){
            break;
        }
        printf("\nEnter correct choise number...!");
    }

    

    printf("Enter New Edit value: ");
    scanf(" %[^\n]", edit);

    switch(choice){
        case 1:
            strcpy(addressBook->contacts[edit_id].name,edit);
            break;
        
        case 2:
            strcpy(addressBook->contacts[edit_id].phone,edit);
            break;
        
        case 3:
            strcpy(addressBook->contacts[edit_id].email,edit);
            break;

        case 4:
            strcpy(addressBook->contacts[edit_id].city,edit);
            break;

        case 5:
            strcpy(addressBook->contacts[edit_id].state,edit);
            break;

        default:
            printf("Wrong choice...!");
    }
}



void deleteContact(AddBook *addressBook)
{
    int know_id;
    printf("\nI know which ID number should Delete ");
    printf("\n Yes=> 1 \n NO=> 0 \n");
    scanf("%d",&know_id);
    if(know_id==0){
        searchContact(addressBook);
    }

    int del;
    printf("\nEnter the ID Number of the contact that should be Deleted: ");
    scanf("%d",&del);

    if(del < 0 || del >= addressBook->contCount)
    {
        printf("Invalid ID!\n");
        return;
    }
    
    for(int i=del;i<addressBook->contCount;i++){
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contCount--;

    printf("Done... \n");
}
