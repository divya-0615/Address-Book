#include <stdio.h>
#include "file.h"



void saveContactsToFile(AddBook *addressBook)
{
    FILE *fp;

    fp = fopen("Contacts_list.csv", "w");

    if(fp == NULL)
    {
        perror("File opening failed");
        return;
    }

    for(int i = 0; i < addressBook->contCount; i++)
    {
        fprintf(fp, "%s,%s,%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email,
                addressBook->contacts[i].city,
                addressBook->contacts[i].state);
    }

    fclose(fp);

    printf("Contacts saved successfully.\n");
}


void loadContactsFromFile(AddBook *addressBook)
{
    FILE *fp;

    fp = fopen("Contacts_list.csv", "r");

    if(fp == NULL)
    {
        printf("File not found. Starting with empty address book.\n");
        return;
    }

    while(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                 addressBook->contacts[addressBook->contCount].name,
                 addressBook->contacts[addressBook->contCount].phone,
                 addressBook->contacts[addressBook->contCount].email,
                 addressBook->contacts[addressBook->contCount].city,
                 addressBook->contacts[addressBook->contCount].state) == 5)
    {
        addressBook->contCount++;

        if(addressBook->contCount >= MAX_CONTACTS)
        {
            break;
        }
    }

    fclose(fp);
}