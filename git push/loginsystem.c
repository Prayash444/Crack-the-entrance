#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[50];
    char email[50];
    char password[20];
    char username[50];
};

int main()
{
    struct student s;
    int choice;
    FILE *p;

    p = fopen("try.txt", "ab+");

    if (p == NULL)
    {
        printf("\n The file doesn't exist");
        exit(1);
    }

    while (1)
    {
        system("cls");

        printf("\n\n******* Welcome to our authentication system ********");
        printf("\n Please choose your operation");
        printf("\n1. Signup");
        printf("\n2. Login");
        printf("\n3. Exit");
        printf("\n\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        	
        	
        	
        	
        	
            system("cls");
            fflush(stdin);
            printf("\nEnter your full name: ");
            gets(s.name);
            printf("Enter your email: ");
            gets(s.email);
            printf("Enter your username: ");
            gets(s.username);
            printf("Enter your password: ");
            gets(s.password);
            fwrite(&s, sizeof(s), 1, p);
            printf("Signup successful!\n");
            break;
        case 2:
            system("cls");
            fflush(stdin);
            printf("\nEnter username: ");
            scanf(" %s", s.username);
            printf("Enter password: ");
            scanf(" %s", s.password);

            struct student temp;
            int found = 0;

            fseek(p, 0, SEEK_SET);

            while (fread(&temp, sizeof(temp), 1, p) == 1)
            {
                if (strcmp(temp.username, s.username) == 0 && strcmp(temp.password, s.password) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (found)
            {
                printf("Login successful!\n");
            }
            else
            {
                printf("Invalid username or password.\n");
            }

            fclose(p);
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("\nInvalid input");
            break;
        }
    }

    return 0;
}