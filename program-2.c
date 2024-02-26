#include<stdio.h>
char monocipher_encr(char);
char alpha[27][3] = { { 'a', 'f' }, { 'b', 'a' }, { 'c', 'g' }, { 'd', 'u' }, {
        'e', 'n' }, { 'f', 'i' }, { 'g', 'j' }, { 'h', 'k' }, { 'i', 'l' }, {
        'j', 'm' }, { 'k', 'o' }, { 'l', 'p' }, { 'm', 'q' }, { 'n', 'r' }, {
        'o', 's' }, { 'p', 't' }, { 'q', 'v' }, { 'r', 'w' }, { 's', 'x' }, {
        't', 'y' }, { 'u', 'z' }, { 'v', 'b' }, { 'w', 'c' }, { 'x', 'd' }, {
        'y', 'e' }, { 'z', 'h' } };
char str[20];
int main() {
    char str[20], str2[20];
    int i;
    printf("\n Enter String..");
    gets(str);
    for (i = 0; str[i]; i++) {
        str2[i] = monocipher_encr(str[i]);
    }
    str2[i] = '\0';
    printf("\n Before encryption..%s", str);
    printf("\n After encryption..%s\n", str2);
}
char monocipher_encr(char a) {
    int i;
    for (i = 0; i < 27; i++) {
        if (a == alpha[i][0])
            break;
    }
    return alpha[i][1];#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

char *remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
    return str;
}

char *encrypt(char *plaintext, char *key) {
    char *ciphertext = malloc(strlen(plaintext) + 1);
    if (ciphertext == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int plaintextLength = strlen(plaintext);
    int keyLength = strlen(key);
    int keyIndex = 0;

    for (int i = 0; i < plaintextLength; i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            int shift = tolower(key[keyIndex]) - 'a';
            ciphertext[i] = 'A' + (plaintext[i] - base + shift) % ALPHABET_SIZE;
            keyIndex = (keyIndex + 1) % keyLength;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[plaintextLength] = '\0';
    return ciphertext;
}

int main() {
    char plaintext[1000], key[100];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    remove_newline(plaintext);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    remove_newline(key);

    int plaintextLength = strlen(plaintext);
    int keyLength = strlen(key);

    if (keyLength == 0) {
        printf("Key cannot be empty.\n");
        return 1;
    }

    if (keyLength > plaintextLength) {
        printf("Key length cannot be longer than plaintext length.\n");
        return 1;
    }

    // Encrypt the plaintext using the key
    char *ciphertext = encrypt(plaintext, key);
    printf("Ciphertext: %s\n", ciphertext);

    free(ciphertext);
    return 0;
}

