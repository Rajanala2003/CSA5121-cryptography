#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void generateCipherSequence(char *keyword, char *cipherSeq) {
    int keywordLength = strlen(keyword);
    int i, j, k;
    char alphabet[ALPHABET_SIZE + 1] = "abcdefghijklmnopqrstuvwxyz";
    char temp[ALPHABET_SIZE + 1];

    
    for (i = 0, k = 0; i < keywordLength; i++) {
        if (!isalpha(keyword[i])) continue;
        keyword[i] = tolower(keyword[i]);
        if (strchr(temp, keyword[i]) == NULL) {
            temp[k++] = keyword[i];
        }
    }
    temp[k] = '\0';

   
    strcat(temp, alphabet);
    
    
    for (i = 0; i < ALPHABET_SIZE; i++) {
        for (j = 0; j < ALPHABET_SIZE; j++) {
            if (temp[j] == 'a' + i || temp[j] == 'A' + i) {
                cipherSeq[i] = temp[j];
                break;
            }
        }
    }
    cipherSeq[ALPHABET_SIZE] = '\0';
}


void encrypt(char *plaintext, char *cipherSeq, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = toupper(cipherSeq[plaintext[i] - 'A']);
            } else {
                ciphertext[i] = cipherSeq[plaintext[i] - 'a'];
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "hello world";
    char cipherSeq[ALPHABET_SIZE + 1];
    char ciphertext[100];

    generateCipherSequence(keyword, cipherSeq);
    printf("Generated Cipher Sequence: %s\n", cipherSeq);

    encrypt(plaintext, cipherSeq, ciphertext);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

