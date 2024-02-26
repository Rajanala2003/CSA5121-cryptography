#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 136
#define STATE_SIZE 25
#define HASH_SIZE 32

#define ROTL64(x, n) (((x) << (n)) | ((x) >> (64 - (n))))

const uint64_t RC[24] = {
    0x0000000000000001ULL, 0x0000000000008082ULL, 0x800000000000808aULL,
    0x8000000080008000ULL, 0x000000000000808bULL, 0x0000000080000001ULL,
    0x8000000080008081ULL, 0x8000000000008009ULL, 0x000000000000008aULL,
    0x0000000000000088ULL, 0x0000000080008009ULL, 0x000000008000000aULL,
    0x000000008000808bULL, 0x800000000000008bULL, 0x8000000000008089ULL,
    0x8000000000008003ULL, 0x8000000000008002ULL, 0x8000000000000080ULL,
    0x000000000000800aULL, 0x800000008000000aULL, 0x8000000080008081ULL,
    0x8000000000008080ULL, 0x0000000080000001ULL, 0x8000000080008008ULL
};

void sha3(const uint8_t *message, uint64_t message_size, uint8_t *hash) {
    uint64_t state[STATE_SIZE] = {0};

    uint64_t block_count = (message_size + BLOCK_SIZE - 1) / BLOCK_SIZE;

    // Copy hash result
    memcpy(hash, state, HASH_SIZE);
}

int main() {
    // Example usage
    const uint8_t message[] = "Hello, SHA-3!";
    uint8_t hash[HASH_SIZE];

    // Compute SHA-3 hash
    sha3(message, strlen((const char *)message), hash);

    // Print the hash
    printf("SHA-3 hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}
