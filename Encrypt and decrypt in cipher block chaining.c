#include <stdio.h>
#include <stdlib.h>

#define NUM_ROUNDS 2
#define BLOCK_SIZE 8


int IP[] = {2, 6, 3, 1, 4, 8, 5, 7};


int IP_inverse[] = {4, 1, 3, 5, 7, 2, 8, 6};


int EP[] = {4, 1, 2, 3, 2, 3, 4, 1};


int P[] = {2, 4, 3, 1};


int S[][4][4] = {
    { {1, 0, 3, 2},
      {3, 2, 1, 0},
      {0, 2, 1, 3},
      {3, 1, 3, 2} },

    { {0, 1, 2, 3},
      {2, 0, 1, 3},
      {3, 0, 1, 0},
      {2, 1, 0, 3} }
};


void generate_keys(int key, int *K1, int *K2) {
    int P10[] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    int P8[] = {6, 3, 7, 4, 8, 5, 10, 9};

   
    int temp_key = 0;
    

    
    int left = (temp_key >> 5) & 0x1F;
    int right = temp_key & 0x1F;

    
    left = ((left << 1) | (left >> 4)) & 0x1F;
    right = ((right << 1) | (right >> 4)) & 0x1F;

    
    int combined_key = (left << 5) | right;
    *K1 = 0;
   
    
    left = ((left << 2) | (left >> 3)) & 0x1F;
    right = ((right << 2) | (right >> 3)) & 0x1F;

    
    combined_key = (left << 5) | right;
    *K2 = 0;
    
}


int sdes_encrypt(int plaintext, int key) {
    int K1, K2;
    generate_keys(key, &K1, &K2);

    
    int IP_result = 0;
    

    
    int left = (IP_result >> 4) & 0xF;
    int right = IP_result & 0xF;

    
    int expanded_right = 0;
    
    expanded_right ^= K1;

    int sbox_result = 0;
    int row, col;
    
    int permuted_result = 0;
    

    left ^= permuted_result;

    
    left ^= right;
    right ^= left;
    left ^= right;

    
    expanded_right = 0;
    
    expanded_right ^= K2;

    sbox_result = 0;
    

    permuted_result = 0;
    

    left ^= permuted_result;

    
    int ciphertext = ((right << 4) | left);
    int encrypted_text = 0;
    

    return encrypted_text;
}


int cbc_encrypt(int plaintext, int key, int iv) {
    int ciphertext = plaintext ^ iv;
    return sdes_encrypt(ciphertext, key);
}


int cbc_decrypt(int ciphertext, int key, int iv) {
    int plaintext = sdes_encrypt(ciphertext, key) ^ iv;
    return plaintext;
}

int main() {
    int plaintext = 0b0000000100100011;
    int key = 0b0111111101;
    int iv = 0b10101010;

    int ciphertext = cbc_encrypt(plaintext, key, iv);
    printf("Encrypted Text: %04X\n", ciphertext);

    int decrypted_text = cbc_decrypt(ciphertext, key, iv);
    printf("Decrypted Text: %04X\n", decrypted_text);

    return 0;
}

