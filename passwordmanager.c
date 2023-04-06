#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_LENGTH 100

struct password {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char encrypted_password[MAX_LENGTH];
};

void add_password(struct password *passwords, int *num_passwords);
void view_passwords(struct password *passwords, int num_passwords);

int main() {
    struct password passwords[MAX_LENGTH];
    int num_passwords = 0;
    int choice = 0;

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                view_passwords(passwords, num_passwords);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void add_password(struct password *passwords, int *num_passwords) {
    char password[MAX_LENGTH];
    printf("Website: ");
    scanf("%s", passwords[*num_passwords].website);
    printf("Username: ");
    scanf("%s", passwords[*num_passwords].username);
    printf("Password: ");
    scanf("%s", password);

    // Encrypt password using SHA-256
    unsigned char hashed_password[SHA256_DIGEST_LENGTH];
    SHA256(password, strlen(password), hashed_password);
    sprintf(passwords[*num_passwords].encrypted_password, "%s", hashed_password);

    printf("Password added successfully.\n");
    (*num_passwords)++;
}

void view_passwords(struct password *passwords, int num_passwords) {
    printf("Website\t\tUsername\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\t%s\n", passwords[i].website, passwords[i].username, passwords[i].encrypted_password);
    }
}
