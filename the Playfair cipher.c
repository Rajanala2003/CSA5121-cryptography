#include <stdio.h>

double factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    double total_permutations = factorial(25) / 4; 
    printf("Approximate number of possible keys for Playfair cipher: %.0f\n", total_permutations);
    return 0;
}

