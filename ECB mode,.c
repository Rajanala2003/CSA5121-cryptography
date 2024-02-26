#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 16


void encrypt_block(unsigned char *block) {
    
    
}

void decrypt_block(unsigned char *block) {
    
    
}

int main() {
    unsigned char plaintext[] = "Hello, ECB mode!";
    unsigned char ciphertext[sizeof(plaintext)];

    int num_blocks = sizeof(plaintext) / BLOCK_SIZE;

    
    printf("Encrypted Text (ECB mode): ");
    
    printf("\n");

    
    printf("Decrypted Text (ECB mode): %s\n", plaintext);

    return 0;
}

