#include <stdio.h>
#include <stdlib.h>

#define MOD 26 


int modInverse(int a) {
   
    return -1; 
}


int determinant(int a, int b, int c, int d) {
    return (a * d - b * c + MOD) % MOD;
}


int cofactor(int num) {
    return (num % MOD + MOD) % MOD; 
}


void adjugate(int a, int b, int c, int d, int *adjA, int *adjB, int *adjC, int *adjD) {
    *adjA = d;
    *adjB = -b;
    *adjC = -c;
    *adjD = a;
}


void hillEncrypt(int key[2][2], int plaintext[2], int *ciphertext) {
    ciphertext[0] = (key[0][0] * plaintext[0] + key[0][1] * plaintext[1]) % MOD;
    ciphertext[1] = (key[1][0] * plaintext[0] + key[1][1] * plaintext[1]) % MOD;
}


void hillDecrypt(int key[2][2], int ciphertext[2], int *plaintext) {
    int det = determinant(key[0][0], key[0][1], key[1][0], key[1][1]);
    int invDet = modInverse(det);

    if (invDet == -1) {
        printf("Modular inverse does not exist. Unable to decrypt.\n");
        return;
    }

    int adjA, adjB, adjC, adjD;
    adjugate(key[0][0], key[0][1], key[1][0], key[1][1], &adjA, &adjB, &adjC, &adjD);

    int invKey[2][2] = {{adjD, -adjB}, {-adjC, adjA}};

    plaintext[0] = (invKey[0][0] * ciphertext[0] + invKey[0][1] * ciphertext[1]) % MOD;
    plaintext[1] = (invKey[1][0] * ciphertext[0] + invKey[1][1] * ciphertext[1]) % MOD;

    
    plaintext[0] = (plaintext[0] + MOD) % MOD;
    plaintext[1] = (plaintext[1] + MOD) % MOD;
}

int main() {
    int key[2][2] = {{9, 4}, {5, 7}}; 
    int plaintext[2] = {0}; 

    printf("Enter two plaintext characters (A-Z): ");
    scanf("%d %d", &plaintext[0], &plaintext[1]);

    int ciphertext[2] = {0}; 
    
    hillEncrypt(key, plaintext, ciphertext);

    printf("Ciphertext: %d %d\n", ciphertext[0], ciphertext[1]);

    int decryptedPlaintext[2] = {0}; 

    hillDecrypt(key, ciphertext, decryptedPlaintext);

    printf("Decrypted plaintext: %d %d\n", decryptedPlaintext[0], decryptedPlaintext[1]);

    return 0;
}

