#include <stdio.h>
#include <stdint.h>
#define KEY_LENGTH 56
#define SUBKEY_LENGTH 48
#define LEFT_ROTATE(key, bits) (((key) << (bits)) | ((key) >> (28 - (bits))))

void generateSubkeys(uint64_t initialKey, uint64_t* subkeys) {
    uint64_t permutedKey = 0;
    int pc1[] = {57, 49, 41, 33, 25, 17, 9, 1,
                 58, 50, 42, 34, 26, 18, 10, 2,
                 59, 51, 43, 35, 27, 19, 11, 3,
                 60, 52, 44, 36, 63, 55, 47, 39,
                 31, 23, 15, 7, 62, 54, 46, 38,
                 30, 22, 14, 6, 61, 53, 45, 37,
                 29, 21, 13, 5, 28, 20, 12, 4};

   
    uint32_t leftHalf = (permutedKey >> 28) & 0xFFFFFFF;
    uint32_t rightHalf = permutedKey & 0xFFFFFFF;
    
   
    }


void decrypt(uint64_t* subkeys, uint64_t ciphertext, uint64_t* plaintext) {
    uint64_t permutedData = 0;
    int initialPermutation[] = {58, 50, 42, 34, 26, 18, 10, 2,
                                60, 52, 44, 36, 28, 20, 12, 4,
                                62, 54, 46, 38, 30, 22, 14, 6,
                                64, 56, 48, 40, 32, 24, 16, 8,
                                57, 49, 41, 33, 25, 17, 9, 1,
                                59, 51, 43, 35, 27, 19, 11, 3,
                                61, 53, 45, 37, 29, 21, 13, 5,
                                63, 55, 47, 39, 31, 23, 15, 7};

    
    uint32_t leftHalf = (permutedData >> 32) & 0xFFFFFFFF;
    uint32_t rightHalf = permutedData & 0xFFFFFFFF;
   
    uint64_t combinedData = ((uint64_t)rightHalf << 32) | leftHalf;
    uint64_t finalData = 0;
    int finalPermutation[] = {40, 8, 48, 16, 56, 24, 64, 32,
                              39, 7, 47, 15, 55, 23, 63, 31,
                              38, 6, 46, 14, 54, 22, 62, 30,
                              37, 5, 45, 13, 53, 21, 61, 29,
                              36, 4, 44, 12, 52, 20, 60, 28,
                              35, 3, 43, 11, 51, 19, 59, 27,
                              34, 2, 42, 10, 50, 18, 58, 26,
                              33, 1, 41, 9, 49, 17, 57, 25};

    

    *plaintext = finalData;
}

int main() {
    uint64_t initialKey = 0x0123456789ABCDEF; 
    uint64_t subkeys[56];
    uint64_t ciphertext = 0x85E813540F0AB405; 
    uint64_t plaintext;

    generateSubkeys(initialKey, subkeys);
    decrypt(subkeys, ciphertext, &plaintext);

    printf("Plaintext: 0x%016llX\n", plaintext);

    return 0;
}
