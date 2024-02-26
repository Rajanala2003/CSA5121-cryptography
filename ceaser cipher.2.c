#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a message using the Caesar cipher
void caesarEncrypt(char *message, int shift) {
    while (*message) {
        if (isalpha(*message)) {
            char base = isupper(*message) ? 'A' : 'a';
            *message = ((int)(*message - base + shift) % 26) + base;
        }
        message++;
    }
}

// Function to decrypt a message using the Caesar cipher
void caesarDecrypt(char *message, int shift) {
    while (*message) {
        if (isalpha(*message)) {
            char base = isupper(*message) ? 'A' : 'a';
            *message = ((int)(*message - base - shift + 26) % 26) + base;
        }
        message++;
    }
}

int main() {
    char message[1000];
    int shift;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Encrypt the message
    caesarEncrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    caesarDecrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}

