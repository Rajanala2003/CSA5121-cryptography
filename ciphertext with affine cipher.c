#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to count the frequency of letters in the ciphertext
void countFrequency(const char *ciphertext, int *frequency) {
    
}

// Function to find the most frequent letter and its index in the frequency array
void findMostFrequent(const int *frequency, int *maxFreq, int *maxIndex) {
    *maxFreq = 0;
    *maxIndex = 0;
    
}

// Function to find the modular multiplicative inverse of a number 'a' modulo 'm'
int modInverse(int a, int m) {
    a = a % m;
   
    return -1; // Modular inverse doesn't exist
}

int main() {
    char ciphertext[] = "BUBUBUBUBUBUBUBUBUBUBUBUBUBUBUBUBUBUBUBUBUBUBUBUBU"; // Example ciphertext
    int frequency[ALPHABET_SIZE] = {0}; // Array to store frequency of each letter
    int maxFreq, maxIndex; // Variables to store the most frequent letter and its index
    int secondMaxFreq, secondMaxIndex; // Variables to store the second most frequent letter and its index
    int a, b; // Variables for affine cipher key

    // Count frequency of letters in the ciphertext
    countFrequency(ciphertext, frequency);

    // Find the most frequent letter and its index
    findMostFrequent(frequency, &maxFreq, &maxIndex);

    // Set the second most frequent letter and its index to initial values
    secondMaxFreq = 0;
    secondMaxIndex = 0;

    // Find the second most frequent letter and its index
   
    // Calculate the key 'b'
    b = (maxIndex - ('B' - 'A') + ALPHABET_SIZE) % ALPHABET_SIZE;

    // Calculate the key 'a' using the second most frequent letter
    // The formula used here exploits the fact that 'U' is likely to be mapped to 'A' after decryption
    int secondMaxMapped = (secondMaxIndex - b + ALPHABET_SIZE) % ALPHABET_SIZE;
    int secondMaxMappedInverse = modInverse(secondMaxMapped, ALPHABET_SIZE);
    a = ((secondMaxMappedInverse * ('A' - 'A')) % ALPHABET_SIZE + ALPHABET_SIZE) % ALPHABET_SIZE;

    printf("Keys found: a = %d, b = %d\n", a, b);

    return 0;
}

