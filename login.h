void handle_input(int *input);
void login_screen(char username[], char password[]);
void read_credentials(FILE* fptr, int *login_successful, char username[], char password[]);
int write_credentials(FILE* fptr);