#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 24 // 3DES key size

void encrypt_3des_cbc(const unsigned char *plaintext, int plaintext_len, const unsigned char *key, const unsigned char *iv, unsigned char *ciphertext) {
  

    // Split the 24-byte key into three 8-byte parts
    memcpy(key1, key, 8);
    memcpy(key2, key + 8, 8);
    memcpy(key3, key + 16, 8);

    // Set up the key schedules
    DES_set_key_unchecked(&key1, &ks1);
    DES_set_key_unchecked(&key2, &ks2);
    DES_set_key_unchecked(&key3, &ks3);

    DES_cblock ivec;
    memcpy(ivec, iv, 8);

    DES_ede3_cbc_encrypt(plaintext, ciphertext, plaintext_len, &ks1, &ks2, &ks3, &ivec, DES_ENCRYPT);
}

int main() {
    unsigned char key[KEY_SIZE] = "123456789012345678901234"; // 24-byte key
    unsigned char iv[8] = "randomIV"; // 8-byte IV
    unsigned char plaintext[] = "Hello, world!";
    int plaintext_len = strlen((char *)plaintext);

    // Calculate the required buffer size for the ciphertext
    int ciphertext_len = ((plaintext_len + 7) / 8) * 8;
    unsigned char *ciphertext = malloc(ciphertext_len);

    encrypt_3des_cbc(plaintext, plaintext_len, key, iv, ciphertext);

    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    free(ciphertext);

    return 0;
}

