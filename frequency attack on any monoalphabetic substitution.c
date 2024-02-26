#include <stdio.h>
unsigned long long circularLeftShift28(unsigned long long val, int shift) {
    return ((val << shift) | (val >> (28 - shift))) & 0xFFFFFFF;
}

void generateSubkeys(unsigned long long initial_key, unsigned long long *subkeys) {
    unsigned long long key_left = (initial_key >> 28) & 0xFFFFFFF;
    unsigned long long key_right = initial_key & 0xFFFFFFF;

    
}

int main() {
    unsigned long long initial_key = 0x0123456789ABCDE;
    unsigned long long subkeys[16];

    generateSubkeys(initial_key, subkeys);

    printf("Initial Key: %llX\n", initial_key);

    
    return 0;
}
