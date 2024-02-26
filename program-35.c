#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALPHABET_SIZE 26

void generate_key(int length, int key[]) {
    srand(time(NULL));
    
}

char encrypt_letter(int key[], int index, char p) {
    int shift = key[index];
    return 'a' + ((p - 'a' + shift) % ALPHABET_SIZE);
}

int main() {
    int key[100], length;
    char plaintext[100], ciphertext[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, 100, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    length = strlen(plaintext);
    generate_key(length, key);

    
    ciphertext[length] = '\0';

    printf("Ciphertext: %s\n", ciphertext);
    printf("Key: ");
    
    printf("\n");

    return 0;
}