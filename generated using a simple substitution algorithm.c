#include <stdio.h>
#include <string.h>

// Function to decrypt the ciphertext based on the provided substitution key
void decrypt(char *ciphertext, char *substitutionKey) {
    int i;
    int length = strlen(ciphertext);

    for (i = 0; i < length; i++) {
        // If the character is a printable ASCII character
        if (ciphertext[i] >= 32 && ciphertext[i] <= 126) {
            // Lookup the substitution character and replace
            printf("%c", substitutionKey[ciphertext[i] - 32]);
        } else {
            // Keep non-printable characters as they are
            printf("%c", ciphertext[i]);
        }
    }
}

int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    char substitutionKey[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,!?:;-()";

    printf("Decrypted message:\n");
    decrypt(ciphertext, substitutionKey);

    return 0;
}

