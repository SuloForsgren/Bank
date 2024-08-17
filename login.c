#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "login.h"


int main(void) {
    typedef enum {
        WAITING_FOR_INPUT,
        LOGIN,
        REGISTER,
        MAIN
    } state;    

    FILE* fptr;
    state current_state = WAITING_FOR_INPUT;
    char username[30];
    char password[50];
    int input = 0;
    int login_successful = 0;

    while (true) {
        switch(current_state) {
            case WAITING_FOR_INPUT :
                init();
                while (current_state == WAITING_FOR_INPUT) {
                    handle_input(&input);
                    if (input == 1) {
                        current_state = LOGIN;
                    }
                    else if (input == 2) {
                        current_state = REGISTER;
                    }
                    else {
                        printf("Please make a valid choice!\n");
                    }
                }
                break;
            case LOGIN :
                while (login_successful == 0) {
                    login_screen(username, password);
                    read_credentials(fptr, &login_successful, username, password);
                }
                printf("Great you got in!\n");
                current_state = WAITING_FOR_INPUT;
                break;
            case REGISTER :
                write_credentials(fptr);
                current_state = WAITING_FOR_INPUT;
            break;
            default :
                current_state = WAITING_FOR_INPUT;
                break;
        }
    }
    return 0;
}