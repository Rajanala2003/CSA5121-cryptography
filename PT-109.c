#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 5


void decryptPlayfair(char *cipherText, char *key) {
    
    char square[SIZE][SIZE];
    int i, j, k = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            square[i][j] = key[k++];
        }
    }

    
    int posX, posY;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (square[i][j] == 'X') {
                posX = i;
                posY = j;
                break;
            }
        }
    }

    
    for (i = 0; i < strlen(cipherText); i += 2) {
        
        int pos1x, pos1y, pos2x, pos2y;
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (square[j][k] == cipherText[i]) {
                    pos1x = j;
                    pos1y = k;
                }
                if (square[j][k] == cipherText[i + 1]) {
                    pos2x = j;
                    pos2y = k;
                }
            }
        }

        
        if (pos1x == pos2x) {
            printf("%c%c", square[pos1x][(pos1y + SIZE - 1) % SIZE], square[pos2x][(pos2y + SIZE - 1) % SIZE]);
        }
        
        else if (pos1y == pos2y) {
            printf("%c%c", square[(pos1x + SIZE - 1) % SIZE][pos1y], square[(pos2x + SIZE - 1) % SIZE][pos2y]);
        }
        
        else {
            printf("%c%c", square[pos1x][pos2y], square[pos2x][pos1y]);
        }
    }
    printf("\n");
}

int main() {
    char cipherText[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char key[] = "PT109XBCDFGHKLMQRSVWYZ";

    printf("Decrypted Message: ");
    decryptPlayfair(cipherText, key);

    return 0;
}

