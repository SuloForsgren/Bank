#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "login.h"


void handle_input(int *input) {
    printf("Enter a number for operations:\n1) Login\n2) Register a new account\n>>");
    scanf("%d", input);
}

void login_screen(char username[], char password[]) {
    printf("Please enter username and password!\n>>");
    scanf("%s", username);
    printf(">>");
    scanf("%s", password);
}

void read_credentials(FILE* fptr, int *login_successful, char username[], char password[]) {
    
    fptr = fopen("users.txt", "r");
    char buffer[50];
    const char *delimeter = ";";
    char * left;
    char * right;

    if (fptr == NULL) {
        printf("The file is not opened. The program will now exit.\n");
    }
    else {
        while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';
            left = strtok(buffer, delimeter);
            right = strtok(NULL, delimeter);

            if (strcmp(username, left) == 0 && strcmp(password, right) == 0) {
                *login_successful = 1;
            }
            else {
                printf("Wrong username or password!\n");
            }
        }
    }        
    fclose(fptr);
}

int write_credentials(FILE* fptr) {
    fptr = fopen("users.txt", "a");
    char username[50];
    char password[30];
    printf("Enter username and password:\n>>");
    scanf("%s", username);
    printf(">>");
    scanf("%s", password);


    fprintf(fptr, "%s;%s\n", username, password);
    fclose(fptr);
    return 1;
}